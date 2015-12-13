#include <iostream>
#include "easylogging++.h"
using namespace std;

INITIALIZE_EASYLOGGINGPP


int main() {
    LOG(INFO) << "My first info log using default logger";

    cout << "Hello, World!" << endl;
    return 0;
}