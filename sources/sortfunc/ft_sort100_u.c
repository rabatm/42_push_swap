/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:21:47 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 15:21:48 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_swap	*ft_get_min_item(t_swap *s_stark)
{
	t_swap	*current_stark;
	t_swap	*current_min;

	current_stark = s_stark;
	current_min = current_stark;
	while (current_stark)
	{
		if (current_stark->num < current_min->num)
			current_min = current_stark;
		current_stark = current_stark->next;
	}
	return (current_min);
}
