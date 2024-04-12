/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:22:27 by ismail            #+#    #+#             */
/*   Updated: 2024/04/12 07:09:00 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_list **a)
{
	 t_list	*tmp;

	 tmp = *a;
	(*a)->content = (*a)->next;
	(*a) = (*a)->next;
	(*a)->content = tmp->content;
}

void	pa(t_list **a, t_list **b)
{
	ft_lstadd_front(a, *b);
	free((*b)->content);
}

void	ra(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	free((*a)->content);
	ft_lstadd_back(a, tmp);
}

int	main(void)
{
	t_list	*a;
	int	*i = 0;

	a = NULL;
	while ((long int)i < 5)
	{
		ft_lstadd_front(&a, ft_lstnew((int *)i));
		i++;
	}
	ra(&a);
	while(a->next != NULL)
	{
		printf("%ld", (long int)a->content);
		a = a->next;
	}
}
