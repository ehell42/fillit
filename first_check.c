/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:55:56 by alexzudin         #+#    #+#             */
/*   Updated: 2019/12/23 13:39:28 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	checkline(char *line, int *strok, int *reshotki, int *count)
{
	if (line[0])
		(*strok)++;
	else
	{
		if (*strok != 4)
			return (0);
		*strok = 0;
		if (*reshotki != 4)
			return (0);
		*reshotki = 0;
		(*count)++;
	}
	return (1);
}

int	lastcheck(int i, char **line)
{
	if (i != 4 && (*line)[0])
	{
		ft_strdel(line);
		return (0);
	}
	ft_strdel(line);
	return (1);
}

int	absolutlylastcheck(int strok, int reshotki, int *count, char **line)
{
	ft_strdel(line);
	if (strok != 4)
		return (0);
	if (reshotki != 4)
		return (0);
	(*count)++;
	if (*count > 26 || *count == 0)
		return (0);
	return (1);
}

int	fresher(char **line)
{
	ft_strdel(line);
	return (0);
}

int	first_check(int fd, int *count)
{
	int		reshotki;
	char	*line;
	int		strok;
	int		i;

	line = NULL;
	reshotki = 0;
	strok = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		if (checkline(line, &strok, &reshotki, count) == 0)
			return (fresher(&line));
		while (line[i])
		{
			if (line[i] != '#' && line[i] != '.')
				return (fresher(&line));
			if (line[i] == '#')
				reshotki++;
			i++;
		}
		if (lastcheck(i, &line) == 0)
			return (0);
	}
	return (absolutlylastcheck(strok, reshotki, count, &line));
}
