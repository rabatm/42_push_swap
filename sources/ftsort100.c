/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsort100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martincelavie <martincelavie@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:48 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 16:11:59 by martincelav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_update_cost(t_head **t_stark)
{
	ft_find_closest_in_a(t_stark);
	ft_cacul_cost((*t_stark)->head_b, (*t_stark)->head_b_size);
	ft_cacul_cost((*t_stark)->head_a, (*t_stark)->head_a_size);
}

void	ft_gesti_sorty(t_swap *current_cheaper_stark, t_head **t_stark)
{
	if (current_cheaper_stark->top == current_cheaper_stark->new_post->top)
	{
		while (((*t_stark)->head_a != current_cheaper_stark->new_post)
			& ((*t_stark)->head_b != current_cheaper_stark))
		{
			if (current_cheaper_stark->new_post->top)
				ft_rrr(t_stark);
			else
				ft_rr(t_stark);
		}
	}
	while ((*t_stark)->head_a != current_cheaper_stark->new_post)
	{
		if (current_cheaper_stark->new_post->top)
			ft_rra(&(*t_stark)->head_a);
		else
			ft_ra(&(*t_stark)->head_a);
	}
}

t_swap	*ft_get_cheaper(t_swap *stark_a)
{
	int		cheaper;
	int		tmp_cheaper;
	t_swap	*current_stark;
	t_swap	*cheaper_stark;

	current_stark = stark_a;
	cheaper = MAX_INT;
	tmp_cheaper = 0;
	while (current_stark)
	{
		tmp_cheaper = current_stark->mycost + current_stark->new_post->mycost;
		if (tmp_cheaper < cheaper)
		{
			cheaper_stark = current_stark;
			cheaper = tmp_cheaper;
		}
		current_stark = current_stark->next;
	}
	return (cheaper_stark);
}

void	ft_sort_100(t_head **t_stark)
{
	t_swap	*current_cheaper_stark;

	while ((*t_stark)->head_a_size > 3)
		ft_pb(*t_stark);
	ft_sort_3(&(*t_stark)->head_a);
	while ((*t_stark)->head_b)
	{
		ft_update_cost(t_stark);
		current_cheaper_stark = ft_get_cheaper((*t_stark)->head_b);
		ft_gesti_sorty(current_cheaper_stark, t_stark);
		while ((*t_stark)->head_b != current_cheaper_stark)
		{
			if (current_cheaper_stark->top)
				ft_rrb(&(*t_stark)->head_b);
			else
				ft_rb(&(*t_stark)->head_b);
		}
		if (((*t_stark)->head_b == current_cheaper_stark)
			&& ((*t_stark)->head_b->new_post == (*t_stark)->head_a))
			ft_pa(*t_stark);
	}
	while (!ft_check_is_sort((*t_stark)->head_a))
		ft_ra(&(*t_stark)->head_a);
}
