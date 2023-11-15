/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martincelavie <martincelavie@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:55 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 16:11:46 by martincelav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_swap **stark_a)
{
	if (ft_mdl_is_big((*stark_a)))
		ft_sa(stark_a);
	if ((ft_last_is_big((*stark_a)))
		&& (ft_mdl_is_the_small((*stark_a))))
		ft_sa(stark_a);
	if (ft_first_is_big((*stark_a)))
		ft_ra(stark_a);
	if (ft_mdl_is_medium((*stark_a)))
		ft_sa(stark_a);
}

void	ft_sort_2(t_swap **stark_a)
{
		ft_sa(stark_a);
}

void	ft_sort(t_head **t_stark)
{
	if ((*t_stark)->head_a_size == 2)
		ft_sort_2((&(*t_stark)->head_a));
	else
		ft_sort_100(t_stark);
}