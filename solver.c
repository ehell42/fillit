/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:53 by ehell             #+#    #+#             */
/*   Updated: 2019/12/14 22:33:17 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_square(int n)
{
	char	**squar;
	int		i;
	int		j;

	i = 0;
	squar = (char**)malloc(sizeof(char *) * (n + 1));
	while (i < n)
	{
		squar[i] = (char*)malloc(sizeof(char) * (n + 1));
		i++;
	}
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

void	print_square(int n, char **square)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(square[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		find_min(t_tetra *elem)
{
	int	i;
	int	min;

	i = 0;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	min = i * 4;
	i = 1;
	while (i * i < min)
		i++;
	return (i);
}

void	solver(t_tetra **elem)
{
	char	**square;
	int		n;
	t_tetra	*tmp;

	tmp = *elem;
	n = find_min(tmp);
	square = create_square(n);
	n = find_min_square(&square, elem, n);
	print_square(n, square);
}
