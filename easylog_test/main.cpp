#include <iostream>
#include "easylogging++.h"
#include "easylog.h"
using namespace std;



int main() {
    config_easylog();
    config_init("/mnt/home/feng/workspace/testlib/easylog_test/easylog.config");
    cout << "Hello, World!" << endl;
    return 0;
}