/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:30:40 by aguiller          #+#    #+#             */
/*   Updated: 2019/12/26 21:53:51 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		new_square(char ***square, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free((*square)[i]);
		i++;
	}
	free(*square);
	*square = create_square(n);
}

int			size(char **square)
{
	int i;

	i = 0;
	while (square[0][i] != '\n')
	{
		i++;
	}
	return (i);
}

void		push_figure(char ***square, t_tetra **tmp, int x, int y)
{
	int		i;
	int		*elem;

	elem = (int *)(*tmp)->data;
	i = 0;
	while (i < 4)
	{
		(*square)[elem[2 * i + 1] + y][elem[2 * i] + x] = (*tmp)->c;
		i++;
	}
}
