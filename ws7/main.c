#include <stdio.h>

#include "g.h"

int Foo(void);

int main()
{
    int a = 0;
    printf("g_s is %d\n", g_s);
    a = Foo();
    printf("g_s is %d\n", a);

    return (0);
}


