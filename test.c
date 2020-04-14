#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int i = 4;

    if (i < 6 < 7)
        printf("true\n");
    return (0);
}

// int main(int ac, char *av[])
// {
//     char buf[4096];
//     int fd;
//     int ret;

//     fd = open(av[1], O_RDONLY);
//     while ((ret = read(fd, &buf, 100)) > 0)
//         printf("%s\n", buf);
//     close(fd);
//     return (0);
// }