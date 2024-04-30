/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:16:54 by ismail            #+#    #+#             */
/*   Updated: 2024/04/30 23:13:03 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_min(t_list **a)
{
	t_list	*head;
	t_list	*min;
	int		is_min;

	min = NULL;
	is_min = 0;
	head = *a;
	if (head)
	{
		while (head)
		{
			if (head->index == -1)
			{
				if (is_min == 0 || *(int*)head->content < *(int*)min->content)
				{
					min = head;
					is_min = 1;
				}
			}
			head = head->next;
		}
	}
	return (min);
}

void	put_index(t_list **a)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_min(a);
	while (head)
	{
		head->index = index++;
		head = get_min(a);
	}
}

int	difference(t_list **stack, int index)
{
	t_list	*tmp;
	int		diff;

	diff = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		diff++;
		tmp = tmp->next;
	}
	return (diff);
}
