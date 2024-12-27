#include <iostream>

int main()
{
    std::cout << "cmake_exp test\n";
#ifdef TEST1
    std::cout << TEST1 << '\n';
#endif
    return 0;
}