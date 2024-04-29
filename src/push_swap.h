/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:09:05 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/29 19:36:13 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_info
{
    int num;
    int size;
    int max_num;
    int max_bit;
}   t_info;


bool			pile_is_sorted(t_list *a);
bool			parse(int argc, char **argv, t_list **a);
bool			parse_arg(char *str, t_list **a);
bool			fit_in_int(char *final);
bool			is_number(char *final);
bool			is_in_list(int	digit, t_list *a);
void			free2D(char **final);
void			sa(t_list **a);
void			sb(t_list **b);
void			pa(t_list **a, t_list **b);
void			pb(t_list **b, t_list **a);
void			ra(t_list **a);
void			rb(t_list **b);
void            rra(t_list **a);
void			put_index(t_list **a);
void			big_sort(t_list **a, t_list **b);
void            small_sort(t_list **a, t_list **b);
int				pile_len(t_list *lst);
static int      get_min2(t_list **a, int val);
static void     sort_for_four(t_list **a, t_list **b);
static void     sort_for_three(t_list **a);
void            sort_for_five(t_list **a, t_list **b);


# endif
