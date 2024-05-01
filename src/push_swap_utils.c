/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:09:20 by ishouche          #+#    #+#             */
/*   Updated: 2024/05/02 01:42:40 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_in_list(int digit, t_list *a)
{
	while (a)
	{
		if (*(int *)a->content == digit)
			return (true);
		a = a->next;
	}
	return (false);
}

bool	is_number(char *final)
{
	int	i;

	i = -1;
	while (final[++i])
	{
		if (!ft_isdigit(final[i]))
		{
			if ((final[i] == '-' || final[i] == '+')
				&& ft_isdigit(final[i + 1]))
				break ;
			else
				return (false);
		}
	}
	return (true);
}

bool	fit_in_int(char *final)
{
	int	i;
	int	sign;
	int	len;

	sign = 1;
	i = 0;
	if (final[0] == '-')
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
	return (true);
}

void	free_deux_d(char **final)
{
	int	i;

	i = -1;
	if (final)
	{
		while (final[++i])
			free(final[i]);
		free (final);
	}
}

int	pile_len(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
