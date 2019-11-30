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

char    **create_square(int n)
{
    char    **squar;
    int     i;
    int     j;

    i = 0;
    squar = (char **)malloc(sizeof(char *) * n);
    while (i++ < n)
        *squar[i] = (char*)malloc(sizeof(char) * n);
    i = 0;
    j = 0;
    while (i < n)
        while (j < n)
        {
            squar[i][j] = '.';
            i++;
            j++;
        }
    return (squar);
}

void    print_square(int n, char **square)
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

int     *find_min(t_tetra *elem)
{
    int     i;

    i = 0;
    while (elem)
    {
        elem = elem->next;
        i++;
    }
    return (i * 4);
}

void solver(t_tetra *elem)
{
    char    **square;
    int     n;

    n = find_min(elem);
    squar = create_square(n, square);
    n = find_min_square(square, elem, n);
    print_square(n, squar);
}