#include <stdio.h>

void func()
{
    printf("in func var1 = %d\n", var1);

    return;
}

int var1 = 5;

int main()
{
    func();

    return 0;
}