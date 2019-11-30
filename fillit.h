/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:19:05 by alexzudin         #+#    #+#             */
/*   Updated: 2019/11/30 18:12:20 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 8

int		get_next_line(const int fd, char **line);
int		first_check(int fd, int *c);
int 	second_check(int fd, int count);

typedef struct 				s_tetraminos
{
	void 			*data;
	char			c;
	struct s_tetraminos 	*next;

}							t_tetra;
t_tetra		*tetra_add(t_tetra *alst, t_tetra *new);
t_tetra		*tetra_new(void const *content, char a, size_t content_size);
void 	tomass(int fd, int **mass);
int 	read_to_mass(int fd, int count, t_tetra **head);
int 	make_minimal(t_tetra **head);

#endif
