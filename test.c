#include <stdio.h>

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        av += 1;
        printf("%s\n", *av);
    }
    return (0);
}