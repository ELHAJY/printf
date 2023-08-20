#include "main.h"



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
