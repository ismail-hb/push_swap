/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:07:27 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/30 15:45:43 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_sort(t_list **a, t_list **b)
{
    if (pile_len(*a) == 3)
        sort_for_three(a);
    else if (pile_len(*a) == 4)
        sort_for_four(a, b);
    else if (pile_len(*a) == 5)
        sort_for_five(a, b);
}

static void	sort_for_three(t_list **a)
{
	t_list	*tmp;
	int		min;
	int		next_min;

	tmp = *a;
	min = get_min2(a, -1);
	next_min = get_min2(a, min);
	if (pile_is_sorted(*a))
		return ;
	if (tmp->index == min && tmp->next->index != next_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (tmp->index == next_min)
	{
		if (tmp->next->index == min)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if (tmp->next->index == min)
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
	int	diff;

	if (pile_is_sorted(*a))
		return ;
	diff = difference(a, get_min2(a, -1));
	if (diff == 1)
		ra(a);
	else if (diff == 2)
	{
		ra(a);
		ra(a);
	}
	else if (diff == 3)
		rra(a);
	if (pile_is_sorted(*a))
		return ;
	pb(a, b);
	sort_for_three(a);
	pa(a, b);
}

void	sort_for_five(t_list **a, t_list **b)
{
	int	diff;

	diff = difference(a, get_min2(a, -1));
	if (diff == 1)
		ra(a);
	else if (diff == 2)
	{
		ra(a);
		ra(a);
	}
	else if (diff == 3)
	{
		rra(a);
		rra(a);
	}
	else if (diff == 4)
		rra(a);
	if (pile_is_sorted(*a))
		return ;
	pb(a, b);
	sort_for_four(a, b);
	pa(a, b);
}

static int	get_min2(t_list **a, int val)
{
	t_list	*tmp;
	int		min;

	tmp = *a;
	min = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((tmp->index < min) && tmp->index != val)
			min = tmp->index;
	}
	return (min);
}

int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
