#include "main.h"

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
