/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:04:57 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/29 15:54:13 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*first_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first_node = *a;
	*a = (*a)->next;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_node;
	first_node->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*first_node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_node = *b;
	*b = (*b)->next;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_node;
	first_node->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*first_node;
	t_list	*before_last;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	first_node = *a;
	before_last = *a;
	while(tmp->next)
		tmp = tmp->next;
	while(before_last->next != tmp)
		before_last = before_last->next;
	tmp->next = first_node;
	before_last->next = NULL;
	*a = tmp;
	write(1, "rra\n", 4);
}
