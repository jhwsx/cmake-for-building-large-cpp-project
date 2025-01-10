#include <iostream>
void A();
void B(){
    A();
#ifdef VAR_A
    std::cout << "in B: " << VAR_A << std::endl;
#else
    std::cout << "in B: VAR_A is not defined\n";
#endif
}
