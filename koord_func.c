#include "fillit.h"

int     find_max_y(const char **sqaure, int x, int nbr) /*мб несколько по другому? могут быть пустоты*/
{
    int i;
    int max;

    i = 0;
    max = 0;
    while (i < nbr)
    {
        if (square[i][x] != '.')
            max = i;
        i++;
    }
    if (max + 1 != nbr)
        return (max);
    return (-1);
}