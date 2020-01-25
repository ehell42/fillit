/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:54 by alexzudin         #+#    #+#             */
/*   Updated: 2020/01/24 19:16:42 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_to_mass(int fd, int count, t_tetra **head)
{
	t_tetra *now;
	t_tetra *prev;
	int		*mass;
	char	s;

	s = 'A';
	prev = NULL;
	if (!(mass = (int*)malloc(sizeof(int) * 8)))
		return (0);
	if (count > 0)
	{
		tomass(fd, &mass);
		now = tetra_new(mass, s++, 8 * sizeof(int), prev);
		*head = now;
	}
	while (count - 1 > 0)
	{
		prev = now;
		tomass(fd, &mass);
		now = tetra_add(now, tetra_new(mass, s, 8 * sizeof(int), prev));
		count--;
		s++;
	}
	free(mass);
	return (1);
}

void	cln(char **s)
{
	if (*s)
		ft_strdel(s);
}

void	tomass(int fd, int **mass)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		get_next_line(fd, &s);
		while (s[j])
		{
			if (s[j] == '#')
			{
				(*mass)[k++] = j;
				(*mass)[k++] = i;
			}
			j++;
		}
		i++;
		cln(&s);
	}
	get_next_line(fd, &s);
	cln(&s);
}

void	find_minimal(int **mass)
{
	int i;
	int min_y;
	int	min_x;

	min_x = 9999;
	min_y = 9999;
	i = 0;
	while (i < 8)
	{
		if ((i + 1) % 2 == 1 && (*mass)[i] < min_x)
			min_x = (*mass)[i];
		if ((i + 1) % 2 == 0 && (*mass)[i] < min_y)
			min_y = (*mass)[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if ((i + 1) % 2 == 1)
			(*mass)[i] = (*mass)[i] - min_x;
		else
			(*mass)[i] = (*mass)[i] - min_y;
		i++;
	}
}

int		second_check(int fd, int count)
{
	t_tetra	*head;
	t_tetra *now;

	head = NULL;
	if (read_to_mass(fd, count, &head) == 0)
		return (0);
	close(fd);
	make_minimal(&head);
	now = head;
	if (diagonal_check(now) == 0)
	{
		tetradel(&head);
		free(head);
		return (0);
	}
	solver(&head);
	tetradel(&head);
	free(head);
	head = NULL;
	return (1);
}
