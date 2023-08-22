#include "main.h"

int long_nbr(int nbr)
{
    if (nbr == 0)
        return 0;
    int n = 1 + long_nbr(nbr / 10);
    return (n);
}
