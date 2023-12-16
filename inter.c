#include <unistd.h>

int check(char c, char *str, int index)
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

    a = 0;
    i = 0;
    if (ac == 3)
    {
        while (av[2][a])
            a++;
        while (av[1][i])
        {
            if (check(av[1][i], av[2], a) == 1)
            {
                if (check(av[1][i], av[1], i) == 0)
                    write(1, &av[1][i], 1);
            }
            i++;
        }
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
}