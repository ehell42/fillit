/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koord_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:15:31 by ehell             #+#    #+#             */
/*   Updated: 2019/12/14 22:34:46 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				find_max_y(char **square, int x, int nbr)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (i < nbr && square[i][x] != '.')
	{
		if (square[i][x] != '.')
			max = i;
		i++;
	}
	if (max + 1 != nbr)
		return (max);
	return (-1);
}

struct s_koord	*push_x0_y_change(struct s_koord *my_coord)
{
	my_coord->y = my_coord->y + 1;
	return (my_coord);
}

struct s_koord	*push_x_change_y(char **square, struct s_koord *my_coord)
{
	my_coord->x = my_coord->x + 1;
	while ((my_coord->y = find_max_y(square, my_coord->x, my_coord->nbr)) < 0
		&& my_coord->x < my_coord->nbr)
		my_coord->x += 1;
	return (my_coord);
}

struct s_koord	*push_x0_change_y(char **square, struct s_koord *my_coord)
{
	my_coord->x = 0;
	while ((my_coord->y = find_max_y(square, my_coord->x, my_coord->nbr)) < 0
		&& my_coord->x < my_coord->nbr)
		my_coord->x += 1;
	return (my_coord);
}

void			free_letter_sq(char ***square, char c, struct s_koord my_coord)
{
	int	i;
	int	j;

	i = 0;
	while (i < my_coord.nbr)
	{
		j = 0;
		while (j < my_coord.nbr)
		{
			if ((*square)[i][j] == c)
				(*square)[i][j] = '.';
			j++;
		}
		i++;
	}
}
