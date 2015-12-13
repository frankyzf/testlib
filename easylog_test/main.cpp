#include <iostream>
#include <unistd.h>
#include "easylogging++.h"
#include "easylog.h"
using namespace std;

void performHeavyTask(int iter) {
    TIMED_FUNC(timerObj);
    // Some initializations
    // Some more heavy tasks
    usleep(5000);
    while (iter-- > 0) {
        TIMED_SCOPE(timerBlkObj, "heavy-iter");
        // Perform some heavy task in each iter
        // Notice following sleep varies with each iter
        usleep(iter * 1000);
        if (iter % 3) {
            PERFORMANCE_CHECKPOINT(timerBlkObj);
        }
    }
}


int main() {
    config_easylog();
    config_init("/mnt/home/feng/workspace/testlib/easylog_test/easylog.config");
    cout << "Hello, World!" << endl;

    performHeavyTask(10);
    return 0;
}