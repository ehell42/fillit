/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:08:13 by aguiller          #+#    #+#             */
/*   Updated: 2019/12/14 22:33:42 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

void	this_ismistke(int ***massive)
{
	(*massive)[0] = I_PIECE;
	(*massive)[1] = IH_PIECE;
	(*massive)[2] = O_PIECE;
	(*massive)[3] = L_PIECE;
	(*massive)[4] = LR_PIECE;
	(*massive)[5] = LD_PIECE;
	(*massive)[6] = LL_PIECE;
	(*massive)[7] = J_PIECE;
	(*massive)[8] = JR_PIECE;
	(*massive)[9] = JD_PIECE;
	(*massive)[10] = JL_PIECE;
	(*massive)[11] = T_PIECE;
	(*massive)[12] = TR_PIECE;
	(*massive)[13] = TD_PIECE;
	(*massive)[14] = TL_PIECE;
	(*massive)[15] = S_PIECE;
	(*massive)[16] = SR_PIECE;
	(*massive)[17] = Z_PIECE;
	(*massive)[18] = ZR_PIECE;
}

int		intequ(int *s1, int *s2)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int		cleanmass(int **massive)
{
	int i;

	i = 0;
	while (i < 19)
	{
		free((massive)[i]);
		i++;
	}
	massive = NULL;
	return (1);
}

int		diagonal_check(t_tetra **head)
{
	int		*mass;
	int		i;
	int		counter;
	int		**massive;
	t_tetra	*now;

	massive = (int**)malloc(sizeof(int*) * 19);
	this_ismistke(&massive);
	now = *head;
	while (now != NULL)
	{
		i = 0;
		counter = 0;
		mass = (int*)now->data;
		while (i < 19)
		{
			if (intequ(mass, massive[i]) == 1)
				counter++;
			i++;
		}
		if (counter == 0)
			return (0);
		now = now->next;
	}
	return (1);
}
