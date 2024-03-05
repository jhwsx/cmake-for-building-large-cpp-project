#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "test cmake property\n";
#ifdef PARA1
    std::cout << "PARA1 = " << PARA1 << '\n';
#endif
    
#ifdef PARA2
    std::cout << "PARA2 = " << PARA2 << '\n';
#endif

#ifdef PARA3
    std::cout << "PARA3 = " << PARA3 << '\n';
#endif
       
#ifdef PARA4
    std::cout << "PARA4 = " << PARA4 << '\n';
#endif

#ifdef PARA5
    std::cout << "PARA5 = " << PARA5 << '\n';
#endif
    return 0;
}
