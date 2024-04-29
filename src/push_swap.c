/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:14:43 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/29 16:27:12 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parse_arg(char *str, t_list **a)
{
	char	**final;
	int		i;
	int		*digit;
	t_list	*new;

	final = ft_split(str, ' ');
	if (!final || !final[0])
		return (free2D(final), false);
	i = -1;
	while (final[++i])
	{
		if (!is_number(final[i]) || !fit_in_int(final[i]))
			return (free2D(final), ft_lstclear(a, free), false);
		digit = malloc(sizeof(int));
		if (!digit)
			return (free2D(final), ft_lstclear(a, free), false);
		*digit = ft_atoi(final[i]);
		new = ft_lstnew(digit);
		if(is_in_list(*digit, *a))
			return(free2D(final), ft_lstclear(a, free), false);
		ft_lstadd_back(a, new);
	}
	return (free2D(final), true);
}

bool	parse(int argc, char **argv, t_list **a)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (!parse_arg(argv[i], a))
			return(false);
	return (true);
}

bool	pile_is_sorted(t_list *a)
{
	int	tmp;

	if (!a)
		return(false);
	tmp = *(int*)a->content;
	a = a->next;
	while(a)
	{
		if (*(int*)a->content < tmp)
			return(false);
		tmp = *(int*)a->content;
		a = a->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return(1);
	if (!parse(argc, argv, &a))
		return (write(2, "Error\n", 6), 1);
	if (!pile_is_sorted(a))
	{
		if (pile_len(a) == 2)
			sa(&a);
		else if (pile_len(a) <= 5)
			small_sort(&a, &b);
		else
		{
			put_index(&a);
			big_sort(&a, &b);
		}
	}
	while (a)
	{
		printf("a : %i\n", *(int*)a->content);
		a = a->next;
	}
	ft_lstclear(&a, free);
	return(0);
}
