/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:46:44 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/24 19:40:26 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*tetra_new(void const *content, char a, size_t content_size
	, t_tetra *prev)
{
	t_tetra	*new_list;

	new_list = NULL;
	new_list = (t_tetra*)malloc(sizeof(t_tetra) * 1);
	if (new_list == NULL)
		return (NULL);
	new_list->next = NULL;
	if (content == NULL)
	{
		new_list->data = NULL;
		new_list->c = a;
	}
	else
	{
		new_list->prev = prev;
		new_list->c = a;
		new_list->data = (void*)malloc(content_size);
		if (new_list->data == NULL)
		{
			free(new_list);
			return (NULL);
		}
		ft_memcpy(new_list->data, content, content_size);
	}
	return (new_list);
}

t_tetra		*tetra_add(t_tetra *alst, t_tetra *new)
{
	if (alst != NULL || new != NULL)
	{
		alst->next = new;
		return (new);
	}
	return (NULL);
}

t_tetra		**tetra_head(t_tetra **new)
{
	while ((*new)->prev != NULL)
		*new = (*new)->prev;
	return (new);
}

void		tetradel(t_tetra **alst)
{
	if ((*alst)->next != NULL)
	{
		tetradel(&((*alst)->next));
		free((*alst)->next);
	}
	free(((*alst)->data));
	(*alst)->data = NULL;
	(*alst)->next = NULL;
	(*alst)->prev = NULL;
}
