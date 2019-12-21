/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:49:41 by ehell             #+#    #+#             */
/*   Updated: 2019/12/21 20:20:48 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_clash(char **square, t_tetra **tmp, struct s_koord my_coord)
{
	int	i;
	int	*elem;

	elem = (int*)((*tmp)->data);
	/*
	 * 0 - столкновение,
	 * 1 - все верно,
	 * -1 - не проходит по высоте
	 * -2 - не проходит по ширине
	 * n - высота переданного прямоугольника
	 */
	i = 0;
	if (my_coord.nbr - (my_coord.y) < elem[7] + 1 || my_coord.y == -1)
		return (-1);
	while (i < 4 && (square[elem[2 * i + 1]
		+ my_coord.y][elem[2 * i] + my_coord.x]) != '\n')
	{
		if ((square[elem[2 * i + 1] +
			my_coord.y][elem[2 * i] + my_coord.x]) != '.')
			return (0);
		i++;
	}
	if (i != 4)
		return (-2);
	return (1);
}

void	push_figure(char ***square, const int *elem,
	char c, struct s_koord my_coord)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*square)[elem[2 * i + 1] + my_coord.y][elem[2 * i] + my_coord.x] = c;
		i++;
	}
}

void	new_square(char ***square, struct s_koord *my_coord)
{
	int	i;

	i = 0;
	while (i < my_coord->nbr)
	{
		free((*square)[i]);
		i++;
	}
	free(*square);
	my_coord->nbr = my_coord->nbr + 1;
	*square = create_square(my_coord->nbr);
	my_coord->x = 0;
	my_coord->y = 0;
}

int	try_function(char ***square, t_tetra **tmp,
	struct s_koord *my_coord)
{
	int				check;
	struct s_koord	temp;

	temp.x = my_coord->x;
	temp.y = my_coord->y;
	check = check_clash(*square, tmp, *my_coord);
//	ft_putstr("here");
//	ft_putnbr(check);
	if (check == 1)
	{
	//	push_figure(square, (int *)(*tmp)->data, (*tmp)->c, *my_coord);
	//	print_square(my_coord->nbr, *square);
	//	ft_putchar('\n');
	//	free_letter_sq(square, (*tmp)->c, *my_coord);
		return (1);
	}
	else if (check == -2 ||
		(check == -1 && my_coord->x == my_coord->nbr))
	{
		my_coord->x = temp.x;
		my_coord->y = temp.y;
		return (0);
	}
	else if (check == 0)
		try_function(square, tmp, push_x0_y_change(my_coord));
	else if (check == -1)
		try_function(square, tmp, push_x_change_y(*square, my_coord));
	return (0);
}

int	req_function(char ***square, t_tetra **tmp,
	struct s_koord *my_coord)
{
	int k = 0;
static int i = 0;
i++;
if (i > 30)
{
	ft_putstr("iterat\n");
	return (1);
}
//	ft_putchar((*tmp)->c);
	if ((*tmp))
	{
		if ((*tmp)->next && try_function(square, tmp, my_coord) == 1)	//если есть следующий и я могу поставить текущий
		{
		//	ft_putchar((*tmp)->c);
			push_figure(square, (int *)(*tmp)->data, (*tmp)->c, *my_coord);	//ставлю текущий
		//	print_square(my_coord->nbr, *square);
			if ((k = try_function(square, &(*tmp)->next, my_coord)) == 0)
			{
			//	ft_putchar((*tmp)->c);
				ft_putnbr(k);
				free_letter_sq(square, (*tmp)->c, *my_coord);
				return (req_function(square, tmp, change_x_change_y(*square, my_coord)));//меняю текущий
			}
			else
			{
				ft_putnbr(k);
			//	ft_putchar((*tmp)->c);
				return (req_function(square, &(*tmp)->next, my_coord));
			}
		}
		else if (try_function(square, tmp, my_coord) == 0 && (*tmp)->c == 'A')	//не могу поставить первый -> меняю его площадь
		{
		//	print_square(my_coord->nbr, *square);
		//	ft_putchar((*tmp)->c);
			new_square(square, my_coord);
			return (req_function(square, tmp, my_coord));
		}
		else if (try_function(square, tmp, my_coord) == 1)
			{
				ft_putstr("here\n");
				push_figure(square, (int *)(*tmp)->data, (*tmp)->c, *my_coord);
				return (1);
			}
	//	ft_putchar((*tmp)->c);
	}
	return (0);
}


int		find_min_square(char ***square, t_tetra **elem, int n)
{
	t_tetra			**tmp;
	struct s_koord	my_koord;

	my_koord.nbr = n;
	tmp = elem;
	my_koord.x = 0;
	my_koord.y = 0;
	if (*tmp)
	{
		req_function(square, tmp, &my_koord);
	}
	return (my_koord.nbr);
}
