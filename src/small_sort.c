/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:07:27 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/29 16:35:50 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_sort(t_list **a, t_list **b)
{  
    if (pile_len(a) == 3)
        sort_for_three(a, b);
    else if (pile_len(a) == 4)
        sort_for_four(a, b);
    else if (pile_len(a) == 5)
        sort_for_five(a, b);
}

void    sort_for_three(t_list **a, t_list **b)
{
    
}
