#include <iostream>
void B();

int main()
{
    B();
    std::cout << "in main STATIC=" << STATIC << '\n';
    return 0;
}
