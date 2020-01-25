/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:08:13 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/24 18:39:22 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkdig(int *m, int c)
{
	int j;
	int good;

	c = 0;
	good = 0;
	while (c < 7)
	{
		j = 0;
		while (j < 4)
		{
			if (((((m[c] + 1) == m[j * 2]) && (m[c + 1] == m[2 * j + 1]))
			|| (((m[c]) == m[j * 2]) && ((m[c + 1] + 1) == m[2 * j + 1])))
			&& ((c != 2 * j)))
				good++;
			if (((((m[c] - 1) == m[j * 2]) && (m[c + 1] == m[2 * j + 1]))
			|| (((m[c]) == m[j * 2]) && ((m[c + 1] - 1) == m[2 * j + 1])))
			&& ((c != 2 * j)))
				good++;
			j++;
		}
		c = c + 2;
	}
	return (good);
}

int		diagonal_check(t_tetra *now)
{
	int		*mass;
	int		i;
	int		counter;

	while (now != NULL)
	{
		i = 0;
		counter = 0;
		mass = (int*)now->data;
		if (checkdig(mass, 0) < 6)
			return (0);
		mass = NULL;
		now = now->next;
	}
	return (1);
}
