/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:22:27 by ismail            #+#    #+#             */
/*   Updated: 2024/04/26 03:05:47 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	 t_list	*tmp;
	 t_list	*tmp2;

	tmp = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = tmp;
	write(1, "sa\n", 3);
}
void	sb(t_list **b)
{
	 t_list	*tmp;
	 t_list	*tmp2;

	tmp = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = tmp;
	write(1, "sb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	(*a) = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	t_list	*tmp;

	if (!a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	(*b) = tmp;
	write(1, "pb\n", 3);
}
