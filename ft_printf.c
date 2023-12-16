#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c, int *count)
{
    *count += write(1, &c, 1);
}

void    ft_putstr(char *str, int *count)
{
    int i;

    i = 0;
    if (!str)
        str = "(null)";
    while (str[i] != '\0')
    {
        ft_putchar(str[i], &count);
        i++;
    }
}

void    ft_putnbr(long nbr, int *count)
{
    if (nbr < 0)
    {
        ft_putchar('-', &count);
        
    }
}

int ft_printf(const char *fmt, ...)
{
    int i;
    int count;
    va_list args;

    va_start(args, fmt);
    while (fmt[i])
    {
        if (fmt[i] == '%')
        {
            i++;
            if (fmt[i] == 's')
                ft_putstr(va_arg(args, char *), &count);
            else if (fmt[i] == 'd')
                ft_putnbr(va_arg(args, int), &count);
            else if (fmt[i] == 'x')
                ft_puthexa(va_arg(args, unsigned int), &count);
            else
                ft_putchar(fmt[i], &count);
        }
        else
            ft_putchar(fmt[i], &count);
        i++;
    }
    va_end(args);
    return (count);
}
