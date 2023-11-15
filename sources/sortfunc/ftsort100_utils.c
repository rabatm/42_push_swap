/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsort100_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:51 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 15:19:52 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_im_smallest(int myval, t_swap *my_stark)
{
	int		f_small;
	t_swap	*current_stark;

	current_stark = my_stark;
	f_small = 1;
	while (current_stark)
	{
		if (current_stark->num < myval)
			f_small = 0;
		current_stark = current_stark->next;
	}
	return (f_small);
}

int	ft_im_bigest(int myval, t_swap *my_stark)
{
	int		f_big;
	t_swap	*current_stark;

	current_stark = my_stark;
	f_big = 1;
	while (current_stark)
	{
		if (current_stark->num > myval)
			f_big = 0;
		current_stark = current_stark->next;
	}
	return (f_big);
}

int	ft_sqrt(int x)
{
	int	y;

	y = x;
	while (y * y > x)
		y = (y + x / y) / 2;
	return (y);
}
