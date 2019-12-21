/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:19:05 by alexzudin         #+#    #+#             */
/*   Updated: 2019/12/21 19:27:56 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 8

int							get_next_line(const int fd, char **line);
int							first_check(int fd, int *c);
int							second_check(int fd, int count);

typedef struct				s_tetraminos
{
	void					*data;
	char					c;
	struct s_tetraminos		*next;

}							t_tetra;
struct						s_koord
{
	int						x;
	int						y;
	int						nbr;
};
t_tetra						*tetra_add(t_tetra *alst, t_tetra *new);
t_tetra						*tetra_new(void const *content,
	char a, size_t content_size);
void						tomass(int fd, int **mass);
int							read_to_mass(int fd, int count, t_tetra **head);
int							make_minimal(t_tetra **head);
void						find_minimal(int **mass);
int							diagonal_check(t_tetra **head);
char						**create_square(int n);
void						print_square(int n, char **square);
int							find_min(t_tetra *elem);
void						solver(t_tetra **elem);
int							check_clash(char **square,
	t_tetra **tmp, struct s_koord my_coord);
void						push_figure(char ***square,
	const int *elem, char c, struct s_koord my_coord);
void						new_square(char ***square,
	struct s_koord *my_coord);
int							req_function(char ***square,
	t_tetra **tmp, struct s_koord *my_coord);
int							find_min_square(char ***square,
	t_tetra **elem, int n);
int							find_max_y(char **square, int x, int nbr);
struct s_koord				*push_x0_y_change(struct s_koord *my_coord);
struct s_koord				*push_x_change_y(char **square,
	struct s_koord *my_coord);
struct s_koord				*push_x0_change_y(char **square,
	struct s_koord *my_coord);
void						free_letter_sq(char ***square,
	char c, struct s_koord my_coord);
struct s_koord				*change_x_change_y(char **square, struct
	s_koord *my_coord);
int							try_function(char ***square, t_tetra **tmp,
	struct s_koord *my_coord);
# define I_PIECE (int [8]){0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]){0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]){0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]){0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]){0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]){0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]){2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]){1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]){0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]){0,0,1,0,0,1,0,2}
# define JL_PIECE (int [8]){0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]){1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]){0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]){0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]){1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]){1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]){0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]){0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]){1,0,0,1,1,1,0,2}

#endif
