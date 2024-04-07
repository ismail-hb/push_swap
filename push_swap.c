/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:14:43 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/07 03:11:09 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(ft_printf("Error"), 1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_a(&a, argv + 1);
	if (!pile_is_sorted(a))
	{
		if (pile_len(a) == 2)
			sa(&a);
		else if (pile_len(a) <= 5)
			small_sort(&a, &b);
		else
			big_sort(&a, &b);
	}
	free_pile(&a);
	return(0);
}