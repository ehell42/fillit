/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:49:41 by ehell             #+#    #+#             */
/*   Updated: 2019/12/26 22:00:18 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_clash(char **square, t_tetra **tmp, int x, int y)
{
	int	i;
	int n;
	int	*elem;

	elem = (int*)((*tmp)->data);
	n = size(square);
	i = 0;
	while (i < 4)
	{
		if (x + elem[2 * i] >= n || y + elem[2 * i + 1] >= n)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4 && (square[elem[2 * i + 1] + y][elem[2 * i] + x]) != '\n')
	{
		if ((square[elem[2 * i + 1] + y][elem[2 * i] + x]) != '.')
			return (0);
		i++;
	}
	if (i != 4)
		return (-2);
	return (1);
}

int		req_function(char ***square, t_tetra **tmp, int x, int y)
{
	int	check;

	check = check_clash(*square, tmp, x, y);
	if (check == 1)
	{
		push_figure(square, tmp, x, y);
		if (specialagent(square, tmp, x, y) == 0)
		{
			free_letter(square, (*tmp)->c, size(*square));
			if (koord_changer(&x, &y, size(*square)) == 1)
				return (req_function(square, tmp, x, y));
			if ((*tmp)->c == 'A')
			{
				new_square(square, size(*square) + 1);
				return (req_function(square, tetra_head(tmp), x, y));
			}
			else
				return (0);
		}
		return (1);
	}
	else
		return (newguy(square, tmp, x, y));
}

int		newguy(char ***square, t_tetra **tmp, int x, int y)
{
	int a;
	int n;

	n = size(*square);
	a = koord_changer(&x, &y, n);
	if (a == 1)
	{
		return (req_function(square, tmp, x, y));
	}
	else
	{
		if ((*tmp)->c == 'A')
		{
			new_square(square, size(*square) + 1);
			return (req_function(square, tetra_head(tmp), x, y));
		}
		return (0);
	}
}

int		specialagent(char ***square, t_tetra **tmp, int x, int y)
{
	int n;

	n = size(*square);
	if ((*tmp)->next)
	{
		x = 0;
		y = 0;
		return (req_function(square, &(*tmp)->next, x, y));
	}
	return (1);
}

int		find_min_square(char ***square, t_tetra **elem)
{
	t_tetra			**tmp;
	int				x;
	int				y;

	x = 0;
	y = 0;
	tmp = elem;
	if (*tmp)
	{
		req_function(square, tmp, x, y);
	}
	return (size(*square));
}
