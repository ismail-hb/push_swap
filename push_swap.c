/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:14:43 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/09 16:17:00 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_in_list(int	digit, t_list *a)
{
	while(a)
	{
		if (*(int*)a->content == digit)
			return(true);
		a = a->next;
	}
	return (false);
}

bool	is_number(char *final)
{
	int	i;

	i = -1;
	while(final[++i])
		if (!ft_isdigit(final[i]))
			return (false);
	return (true);
}

bool	fit_in_int(char *final)
{
	int	i;
	int	sign;
	int	len;

	sign = 1;
	i = 0;
	if(final[0] == '-')
	{
		sign *= -1;
		i++;
	}
	if (final[0] == '+')
		i++;
	len = ft_strlen(final + i);
	if (len > 10)
		return (false);
	if (len == 10)
	{
		if (sign == 1)
			return (ft_strncmp(final + i, "2147483647", 10) <= 0);
		return (ft_strncmp(final + i, "2147483648", 10) <= 0);
	}
	return(true);
}

void	free2D(char **final)
{
	int	i;

	i = -1;
	if(final)
	{
		while(final[++i])
			free(final[i]);
		free (final);
	}
}
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
		if (*(int*)a->content > tmp)
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
		return (write(2, "Error", 5), 1);
	if (!pile_is_sorted(a))
	{
		if (pile_len(a) == 2)
			sa(&a);
		else if (pile_len(a) <= 5)
			small_sort(&a, &b);
		else
			big_sort(&a, &b);
	}
	ft_lstclear(&a, free);
	return(0);
}
