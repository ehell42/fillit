/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:19:05 by alexzudin         #+#    #+#             */
/*   Updated: 2020/01/22 17:23:22 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

int							get_next_line(const int fd, char **line);
int							first_check(int fd, int *c);
int							second_check(int fd, int count);
int							size(char **square);

typedef struct				s_tetraminos
{
	void					*data;
	char					c;
	struct s_tetraminos		*next;
	struct s_tetraminos		*prev;

}							t_tetra;
struct						s_koord
{
	int						x;
	int						y;
	int						nbr;
};

t_tetra						*tetra_add(t_tetra *alst, t_tetra *new);
t_tetra						*tetra_new(void const *content, char a,
	size_t content_size, t_tetra *prev);
t_tetra						**tetra_head(t_tetra **new);
void						tetradel(t_tetra **alst);
void						tomass(int fd, int **mass);
int							read_to_mass(int fd, int count, t_tetra **head);
int							make_minimal(t_tetra **head);
void						find_minimal(int **mass);
int							diagonal_check(t_tetra *head);
char						**create_square(int n);
void						print_square(int n, char **square);
int							find_min(t_tetra *elem);
void						solver(t_tetra **elem);
int							check_clash(char **square,
	t_tetra **tmp, int x, int y);
void						push_figure(char ***square,
	t_tetra **tmp, int x, int y);
void						new_square(char ***square, int n);
int							req_function(char ***square,
	t_tetra **tmp, int x, int y);
int							find_min_square(char ***square, t_tetra **elem);
int							specialagent(char ***square,
	t_tetra **tmp, int x, int y);
int							newguy(char ***square, t_tetra **tmp, int x, int y);
int							make_minimal(t_tetra **head);
void						free_letter(char ***square, char c, int n);
int							koord_changer(int *x, int *y, int n);

# define BUFF_SIZE 8
#endif
