/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:53 by ehell             #+#    #+#             */
/*   Updated: 2019/11/30 17:42:00 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **create_square(int n)  /*создает квадрат размера n и забивает его "."*/
{
    char    **squar;
    int     i;
    int     j;

    i = 0;
    squar = (char **)malloc(sizeof(char *) * (n + 1));
    while (i++ < n)
        *squar[i] = (char*)malloc(sizeof(char) * (n + 1));
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            squar[i][j] = '.';
            j++;
        }
        squar[i][j] = '\n';
        i++;
    }
    squar[n] = NULL;
    return (squar);
}

void    print_square(int n, char **square)  /*выводит квадрат на экран*/
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < n)
    {
        while (j < n)
        {
            ft_putchar(square[i][j]);
            j++;
        }
    ft_putchar('\n');
    i++;
    }
}

int     *find_min(t_tetra *elem)    /*минимальная площадь изначального квадрата*/
{
    int     i;
    int     min;

    i = 0;
    while (elem)
    {
        elem = elem->next;
        i++;
    }
    min = i * 4;
    if (min % 2 == 0)
        return (min / 2);
    else
        return (min / 2 + 1);

}

void solver(t_tetra *elem)
{
    char    **square;
    int     n;

    n = find_min(elem);
    square = create_square(n);
    n = find_min_square(&square, elem, n);
    print_square(n, &square);
}