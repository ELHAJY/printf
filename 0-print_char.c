#include "main.h"

int _putch(char ch)
{
    (write(1, &ch, 1));
    return 1;
}

