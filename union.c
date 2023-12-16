#include <unistd.h>

int    check(char c, char *str, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int a;

    i = 0;
    a = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            if (check(av[1][i], av[1], i) == 0)
                write(1, &av[1][i], 1);
            i++;
        }
        while (av[2][a])
        {
            if (check(av[2][a], av[1], i) == 0)
            {
                if (check(av[2][a], av[2], a) == 0)
                    write(1, &av[2][a], 1);
            }
            a++;
        }
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}