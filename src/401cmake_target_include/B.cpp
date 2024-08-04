#include <iostream>
void A();
void B(){
    A();
    std::cout << "in B A_VAR=" << A_VAR << '\n'; 
    // std::cout << "in B STATIC=" << STATIC << '\n'; // error: ‘STATIC’ was not declared in this scope
}
