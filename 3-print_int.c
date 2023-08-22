#include "main.h"

int print_nombre(int n)
{
    int v = 0;
    if (n == -2147483648)
    {
        _putch('-');
        _putch('2');
        _putch('1');
        _putch('4');
        n = 7483648;
    }
    while (n < 0)
    {
        n = - n;
        _putch('-');
    }
    if (n < 10)
    {
        _putch(n + '0');
    }
    else if (n >= 10)
    {
        print_nombre(n / 10);
        print_nombre(n % 10);
    }
    return (5);
}
