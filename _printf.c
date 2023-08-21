#include "main.h"

int _putch(char ch)
{
    (write(1, &ch, 1));
    return 1;
}

int print_str(char *string)
{
    int v = 0;

    if (!string)
    {
        print_str("(null)");
        return;
    }
    else
    {
        while (*string)
        {
            _putch(*string);
            string++;
            v++;
        }
    }
    return (v);
}
int long_nbr(int nbr)
{
    if (nbr == 0)
        return 0;
    int n = 1 + long_nbr(nbr / 10);
    return (n);
}
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


int _printf(const char *format, ...)
{
    int co = 0;

    va_list args;
    va_start(args, format);
    if (!format || !format[0])
        return (-1);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c') // print character
            {
                char cha = va_arg(args, int);
                _putch(cha);
                co++;
                format++;
            }
            else if (*format == 's') // print argument string
            {
                char *string =  va_arg(args, char*);
                int a = print_str(string);
                co += a;
                format++;
            }
            else if (*format == '%') //for %% print %
            {
                _putch('%');
                co++;
                format++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int nombre = va_arg(args, int);
                int nco;
                if (nombre < 0)
                    co++;
                nco = long_nbr(nombre);
                format++;
                co =co + nco;
                print_nombre(nombre);
            }
            else // %string or other character
            {
                if (*format)
                {
                    format--;
                    _putch(*format);
                    format++;
                }
                co++;
            }
        }
        else
        {
            _putch(*format);
            co++;
            format++;
        }
    }
    return co;
}
