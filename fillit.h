/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:19:05 by alexzudin         #+#    #+#             */
/*   Updated: 2019/12/08 13:04:23 by aguiller         ###   ########.fr       */
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
typedef struct              s_koord
{
    int                     x;
    int                     y;
    int                     nbr;
};
t_tetra		*tetra_add(t_tetra *alst, t_tetra *new);
t_tetra		*tetra_new(void const *content, char a, size_t content_size);
void 	tomass(int fd, int **mass);
int 	read_to_mass(int fd, int count, t_tetra **head);
int 	make_minimal(t_tetra **head);
void	find_minimal(int **mass);
int		diagonal_check(t_tetra **head);
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
