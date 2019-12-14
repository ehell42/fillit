/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:49:41 by ehell             #+#    #+#             */
/*   Updated: 2019/12/14 23:35:10 by ehell            ###   ########.fr       */
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
/*
void	req_function(char ***square, t_tetra **tmp,
	struct s_koord *my_coord, t_tetra **head)
{
	int	check;

	check = check_clash(*square, tmp, *my_coord);
	if (check == 1)
	{
		push_figure(square, (int *)(*tmp)->data, (*tmp)->c, *my_coord);
		if ((*tmp)->next)
			req_function(square, &(*tmp)->next,
				push_x0_change_y(*square, my_coord), head);///////////////
	}
	else if (check == -2 ||
		(check == -1 && my_coord->x == my_coord->nbr))
	{
		if ((*head)->c == 'A')
		{
			new_square(square, my_coord);
			tmp = head;
			req_function(square, tmp, my_coord, head);
		}
		else
		{
			free_letter_sq(square, (*head)->c, *my_coord);//изменить координаты текущей фигуры
			req_function(square, tmp, my_coord, head);//передать нужный хедер
		}
	}
	else if (check == 0)
		req_function(square, tmp, push_x0_y_change(my_coord), head);
	else if (check == -1)
		req_function(square, tmp, push_x_change_y(*square, my_coord), head);
}*/

void	req_function(char ***square, t_tetra **tmp,
	struct s_koord *my_coord, t_tetra **head)
{
	if ((*tmp)->next)
	{
		req_function(square, (*tmp)->next, my_coord, tmp);
	}
	else
	{
		/*размещаю последний*/	
		if (/*не поставили*/ && /*header->c != A*/)
		{
			tmp = head; 
			free_letter_sq();
			/*сместили координаты*/
		}
		else
		{
			new_square();
		}
	}
	
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
		req_function(square, tmp, &my_koord, elem);
	}
	return (my_koord.nbr);
}
