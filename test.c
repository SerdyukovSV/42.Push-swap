#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/push_swap.h"
#include <execinfo.h>

#define BUF_SIZE 1000
#define OPT "psrab"

int ft_instr(char *haystack, char *needle)
{
    while (*haystack)
    {
        while (*needle && *haystack == *needle)
        {
            haystack++;
            needle++;
        }
        if (*needle == '\0')
            return (1);
        haystack++;
    }
    return (0);
}

int main(int ac, char *av[])
{
    char *str;
    int *a;
    int i = NULL;

    // a = &i;
    printf("i = %d\n", i);
    return (0);

}