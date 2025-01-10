#include <iostream>
void A() 
{
#ifdef VAR_A
    std::cout << "in A: " << VAR_A << std::endl;
#else
    std::cout << "in A: VAR_A is not defined\n";
#endif
}
