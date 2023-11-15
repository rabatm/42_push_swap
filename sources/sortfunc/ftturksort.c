/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftturksort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:41 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 15:19:46 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_min	ft_get_min(t_swap *s_stark)
{
	int		i;
	t_swap	*current_stark;
	t_min	mini_stak;

	current_stark = s_stark;
	mini_stak.min = MAX_INT;
	mini_stak.index_min = 0;
	i = 0;
	while (current_stark)
	{
		if (current_stark->num <= mini_stak.min)
		{
			mini_stak.min = current_stark->num;
			mini_stak.index_min = i;
		}
		i ++;
		current_stark = current_stark->next;
	}
	return (mini_stak);
}

t_swap	*ft_move_min(t_swap *f_stark, int top, int min)
{
	while (f_stark->num != min)
	{
		if (top)
		{
			ft_ra(&f_stark);
		}
		else
		{
			ft_rra(&f_stark);
		}
	}
	return (f_stark);
}
