/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:49:41 by ehell             #+#    #+#             */
/*   Updated: 2019/11/30 18:49:43 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     check_clash(const char **square, const int *elem, struct s_koord my_coord) /* проверяет столкновения */
{
    int     i;

    /*
     * 0 - столкновение,
     * 1 - все верно,
     * -1 - не проходит по высоте или ширине
     * -2 - не проходит по ширине
     * n - высота переданного прямоугольника
     */
    i = 0;
    if (my_coord.nbr - (my_coord.y + 1) < elem[8])
        return (-1);
    while (i < 4 && square[elem[2 * i] + my_coord.y][elem[2 * i + 1] + my_coord.x] != '\n')
    {
        if (square[elem[2 * i] + my_coord.y][elem[2 * i + 1] + my_coord.x] == '#')
            return (0);
        i++;
    }
    if (i != 3)
        return (-1);
    return (1);
}

void   push_figure(char ***square, const int *elem, char c, int x, int y)   /*записывает очередную фигуру в нужный квадрат*/
{
    while (i < 4)
    {
        *square[elem[2 * i] + y][elem[2 * i + 1] + x] = c;
        i++;
    }
}

/*
 * берет первый, находит минимальный игрик, чекает, записывает
 * берет следующий, находит минимальный игрик, чекает
 * если не проходит -> либо вернул ноль, тогда сдивгаем на одну строку вниз и заново
 *                  -> вернуль минус единицу, находим минимальный игрик в следующей строке и заново
 *                  -> вернуль минус двойку -> не можем записать эту фигуру -> удаляем текущий квадрат и создаем на 1 больше
 * */

void    free_square(char ***square, int n)  /*освобождает двумерный массив*/
{
    int     i;

    i = 0;
    while (i < n)
    {
        free(*square[i]);
        i++
    }
    free(*square);
}

void    req_function(char ***square, t_tetra *tmp, struct s_koord *my_koord, t_tetra *head) /*функция с рекурсией*/
{
    if (check_clash(*square, (int *)tmp->data, *my_coord) == 1)
    {
        push_figure(*square, (int *)tmp->data, tmp->c, my_coord->x, my_coord->y);
        if (tmp->next)
        {
            my_coord->x = 0;
            while ((my_coord->y = find_max_y(sqaure, my_koord->x, my_koord->nbr)) < 0)
                my_koord->x += 1;
            req_function(square, tmp->next, my_coord, head);
        }
    }
    else if (check_clash(*square, (int *)tmp->data, *my_coord) == 0)
    {
        my_coord->y += 1;
        my_coord->x = 0;
        req_function(square, tmp->next, my_coord, head);
    }
    else if (check_clash(*square, (int *)tmp->data, *my_coord) == -1)
    {
        my_coord->x += 1;
        while ((my_coord->y = find_max_y(sqaure, my_koord->x, my_koord->nbr)) < 0)
            my_koord->x += 1;
        req_function(square, tmp, my_coord, head);
    }
    else if (check_clash(*square, (int *)tmp->data, *my_coord) == -2)
    {
        free_square(square, my_coord->nbr);
        my_coord->nbr++;
        square = create_square(my_coord->nbr);
        tmp = head;
        my_coord->x = 0;
        my_coord->y = 0;
        req_function(&square, tmp, my_coord, head);
    }
}

int     find_min_square(char ***square, t_tetra *elem, int n, int count)
{
    t_tetra         *tmp;
    int             i;
    struct s_koord  my_koord;

    my_koord.nbr = n;
    tmp = elem;
    my_koord.x = 0;
    my_koord.y = 0;
    if (tmp)
        req_function(square, tmp, &my_koord);
    return (my_koord.nbr);
}