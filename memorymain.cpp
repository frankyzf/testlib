#include "MemoryDetector.h" //就是上面封装的MemoryDetector类
#include <thread>
using namespace std;
uint64_t MemoryDetector::address_ = 0;
int MemoryDetector::len_ = 0;
int MemoryDetector::fd_ = 0;
///////////////////////////////////////
int *p = NULL;
void g()
{
  usleep(2000000);
  char *q = reinterpret_cast<char *>(p);
  *(q+2) = 111;//非法篡改！！！
}
void f()
{
  p = new int(1);
  MemoryDetector::protect(p, 4);
}
int main()
{
  const char *path = "result.tmp";//调用栈信息存放路径
  MemoryDetector::init(path);
  std::thread t1(f);
  std::thread t2(g);
  t1.join();
  t2.join();
  MemoryDetector::finish();
  return 0;
}
