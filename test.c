#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/push_swap.h"
#include <execinfo.h>

#define BUF_SIZE 1000
#define OPT "psrab"

typedef void (*simpleFP);
typedef struct functionMETA {
    simpleFP funcPtr;
    char * funcName;
} functionMETA;

// functionMETA arrFuncPtrs[6] = {
//     {f1, "f"},
//     {f2, "ff"},
//     {push, "p"},
//     {swap, "s"},
//     {rotate, "r"},
//     {revrotate, "rr"}

// };

// void f1(int s1, int s2, int print) {
//     printf("s1 = %s | s2 = %s | print = %d", s1, s2, print);
// }
// void f2(int s1, int s2, int print) {
//     printf("s1 = %s | s2 = %s | print = %d", s1, s2, print);
// }

// int main()
// {
//     char *str = "fa";
//     int s1 = 1;
//     int s2 = 2;
//     int ln;

//     if (ft_strchr(str, 'b'))
//     {
//         s1 = 2;
//         s2 = 1;
//     }
        

//     for(int i=0; i<3; i++)
//     {
//         ln = ft_strlen(str);
//         // if (ft_strchr(str, 'a') || ft_strchr(str, 'b'))
//         if (ft_strnstr(str, arrFuncPtrs[i].funcName, ln - 1))
//             if (ft_strchr(++str, arrFuncPtrs[i].funcName + 1))
//     }
// }

int main(void)
{
    int i = 5;
    while (i--)
    {
        printf("%d\n", i);
        system("sleep 0.5");
        
    }
    return (0);

}


// int main(int ac, char *av[])
// {
//     char buf[1024] = {0};
//     char *tmp = NULL;
//     int line = 0;
//     int i = 0;
//     int k = 0;
//     int fd;

//     fd = open(av[1], O_RDONLY);
//     while ((i = read(fd, buf, BUF_SIZE)))
//     {
//         buf[i] = '\0';
//         k = -1;
//         if (tmp)
//             tmp = ft_strjoin(tmp, buf);
//         else
//             tmp = ft_strdup(buf);
//         while (tmp[++k] != '\0')
//             if (tmp[k] == '\n')
//             {
//                 tmp[k] = '\0';
//                 printf("Line #%d : %s\n", line++, tmp);
//                 tmp += k + 1;
//                 k = -1;
//             }
//         if (tmp[k] == '\0' && i < BUF_SIZE)
//             printf("Line #%d : %s\n", ++line, tmp);
//     }
//     return (0);
// }