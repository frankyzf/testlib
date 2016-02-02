#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/user.h>
#include <execinfo.h>
class MemoryDetector
{
public:
  typedef void (*segv_handler) (int sig, siginfo_t *si, void *unused);
  static void init(const char *path)
  {
    register_handler(handler);
    fd_ = open(path, O_RDWR|O_CREAT, 777);
  }
  static int protect(void *p, int len)
  {
    address_ = reinterpret_cast<uint64_t>(p);
    len_ = len;
    uint64_t start_address = (address_ >> PAGE_SHIFT) << PAGE_SHIFT;
    return mprotect(reinterpret_cast<void *>(start_address), PAGE_SIZE, PROT_READ);
  }
  static int umprotect(void *p, int len)
  {
    uint64_t tmp_address_ = reinterpret_cast<uint64_t>(p);
    uint64_t start_address = (tmp_address_ >> PAGE_SHIFT) << PAGE_SHIFT;
    return mprotect(reinterpret_cast<void *>(start_address), PAGE_SIZE, PROT_READ | PROT_WRITE);
  }
  static int umprotect()
  {
    uint64_t start_address = (address_ >> PAGE_SHIFT) << PAGE_SHIFT;
    return mprotect(reinterpret_cast<void *>(start_address), PAGE_SIZE, PROT_READ | PROT_WRITE);
  }
  static void finish()
  {
    close(fd_);
  }
private:
  static void register_handler(segv_handler sh)
  {
    struct sigaction act;
    act.sa_sigaction = sh;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    if(sigaction(SIGSEGV, &act, NULL) == -1){
      perror("Register hanlder failed");
      exit(EXIT_FAILURE);
    }
  }
  static void handler(int sig, siginfo_t *si, void *unused)
  {
    uint64_t address = reinterpret_cast<uint64_t>(si->si_addr);
    if (address >= address_ && address < address_ + len_) {
      umprotect(si->si_addr, PAGE_SIZE);
      my_backtrace();
    }
  }
  static void my_backtrace()
  {
    const int N = 100;
    void* array[100];
    size_t size = backtrace(array, N);
    backtrace_symbols_fd(array, size, fd_);
  }
  static uint64_t address_;
  static int len_;
  static int fd_;
};
