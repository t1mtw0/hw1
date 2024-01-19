#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ulliststr.h"

// Use this file to test your ulliststr implementation before running the test
// suite

int main(int argc, char *argv[]) {
    ULListStr dat;
    dat.push_back("2");
    dat.push_front("1");
    dat.push_back("3");
    std::cout << dat.size() << "\n";
    dat.pop_front();
    dat.pop_back();
    std::cout << dat.back() << "\n";
    std::cout << dat.get(0) << "\n";
    dat.clear();
    dat.push_front("test1");
    dat.push_front("test0");
    dat.set(0, "test00");
    std::cout << dat.front() << "\n";
}
