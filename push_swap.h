/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:09:05 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/22 04:09:05 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

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
void			put_index(t_list **a);
void			big_sort(t_list **a, t_list **b);
int				pile_len(t_list *lst);
static t_list	*get_min(t_list **a);


# endif
