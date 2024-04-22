/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:31:38 by ismail            #+#    #+#             */
/*   Updated: 2024/04/22 22:48:58 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	num;
	int	size;
	int	max_num;
	int	max_bit;

	i = -1;
	size = pile_len(*a);
	max_num = size - 1;
	max_bit = 0;
	while ((max_num >> max_bit) != 0)
		max_bit++;
	while (++i < max_bit)
	{
		j = -1;
		while (++j < size)
		{
			num = (int)(*a)->index;
			if (((num >> i) & 1) == 1)
				ra(a);
			else
				pb(b, a);
		}
		while(pile_len(*b) != 0)
			pa(a, b);
	}
}
