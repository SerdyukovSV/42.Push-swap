#include "includes/push_swap.h"

int     debugging_moded()
{
    char    *line;
    int     ret;

    ret = 1;
    // if (!(stack->opt & OPT_V) && !(stack->opt & OPT_F))
    //     return (ret);
    ft_printf("Select debugging mode:\n1 - %s\n2 - %s\n", "AUTO", "MANUAL");
    if (get_next_line(0, &line) > 0)
    {
        if (!ft_strcmp(line, "2"))
            ret = 2;
        free(line);
        if (ret == 2)
            return (ret);
    }
    ft_printf("Error: repeat entry\n");
    return (debugging_moded());
}

int main()
{
    int i;

    i = debugging_moded();
    return (0);
}