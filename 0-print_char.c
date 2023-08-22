#include "main.h"

int _putch(char ch)
/*
 *0-print_char.c this is name of the file
 *@s: first string.
 *@accept: second string.
 *Return: a pointer to the byte in s that matches one of the
 *byte in accept, or NULL if no such byte i found.
 */ 
{
    (write(1, &ch, 1));
    return 1;
}

