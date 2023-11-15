/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsort3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:53 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 15:19:54 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_first_is_big(t_swap *stark)
{
	if ((stark->num > stark->next->next->num)
		&& (stark->num > stark->next->num))
		return (1);
	return (0);
}

int	ft_last_is_big(t_swap *stark)
{
	if ((stark->next->next->num > stark->num)
		&& (stark->next->next->num > stark->next->num))
		return (1);
	return (0);
}

int	ft_mdl_is_the_small(t_swap *stark)
{
	if ((stark->next->num < stark->num)
		&& (stark->next->num < stark->next->next->num))
		return (1);
	return (0);
}

int	ft_mdl_is_big(t_swap *stark)
{
	if ((stark->next->num > stark->num)
		&& (stark->next->num > stark->next->next->num))
		return (1);
	return (0);
}

int	ft_mdl_is_medium(t_swap *stark)
{
	if (ft_mdl_is_the_small(stark)
		&& ft_mdl_is_big(stark) == 0)
		return (1);
	return (0);
}
