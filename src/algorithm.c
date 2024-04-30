/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:31:38 by ismail            #+#    #+#             */
/*   Updated: 2024/04/30 23:44:07 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **a, t_list **b)
{
	int		i;
	int		j;
	t_info	inf;

	i = -1;
	inf.size = pile_len(*a);
	inf.max_num = inf.size - 1;
	inf.max_bit = 0;
	while ((inf.max_num >> inf.max_bit) != 0)
		inf.max_bit++;
	while (++i < inf.max_bit)
	{
		j = -1;
		while (++j < inf.size)
		{
			inf.num = (int)(*a)->index;
			if (((inf.num >> i) & 1) == 1)
				ra(a);
			else
				pb(b, a);
		}
		while (pile_len(*b) != 0)
			pa(a, b);
	}
}
