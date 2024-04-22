/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:22:27 by ismail            #+#    #+#             */
/*   Updated: 2024/04/22 03:57:31 by ismail           ###   ########.fr       */
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
}
void	sb(t_list **b)
{
	 t_list	*tmp;
	 t_list	*tmp2;

	tmp = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = tmp;
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
}

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
}

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	int in;
// 	int	i[5] = {0, 1, 2, 3, 4};

// 	b = NULL;
// 	a = NULL;
// 	in = 0;
// 	while (in < 5)
// 	{
// 		ft_lstadd_front(&a, ft_lstnew(&i[in]));
// 		in++;
// 	}
// 	ft_lstadd_front(&b, ft_lstnew(&i[4]));
// 	pa(&a, &b);
// 	while (a)
// 	{
// 		printf("a : %i\n", *(int*)a->content);
// 		a = a->next;
// 	}
// 	while (b)
// 	{
// 		printf("b : %i\n", *(int*)b->content);
// 		b = b->next;
// 	}
// 	free(a);
// }
