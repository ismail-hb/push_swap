/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:07:27 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/29 17:46:27 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_sort(t_list **a, t_list **b)
{
    if (pile_len(a) == 3)
        sort_for_three(a);
    else if (pile_len(a) == 4)
        sort_for_four(a, b);
    else if (pile_len(a) == 5)
        sort_for_five(a, b);
}

static void	sort_for_three(t_list **a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (is_sorted(a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if (head->next->index == min)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

static void	sort_for_four(t_list **a, t_list **b)
{
	int	distance;

	if (is_sorted(a))
		return ;
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_fot_five(t_list **a, t_list **b)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}
