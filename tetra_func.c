/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:46:44 by aguiller          #+#    #+#             */
/*   Updated: 2019/12/14 17:31:36 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*tetra_new(void const *content, char a, size_t content_size)
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

t_tetra		*tetra_add_content(t_tetra *new_list, void const *content,
	size_t content_size)
{
	if (content == NULL)
	{
		new_list->data = NULL;
	}
	else
	{
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
