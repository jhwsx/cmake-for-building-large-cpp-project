#include <iostream>
#include "xlog.h"
#include "xthread.hpp"
#include "xtest.h"

int main(int argc, char const *argv[])
{
    xlog();
    testxlog();
    xthread();
    xtest();
    std::cout << "test auto source head\n";
    return 0;
}
