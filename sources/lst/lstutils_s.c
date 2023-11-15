/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:20:37 by mrabat            #+#    #+#             */
/*   Updated: 2023/11/15 15:20:38 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_check_maxmin(char **myarg, int inity)
{
	int			i;
	int			j;
	long long	num;

	i = inity;
	while (myarg[i])
	{
		j = 0;
		while (myarg[i][j])
		{
			if (!ft_isdigit(myarg[i][j]))
				ft_prterror_quit();
		j++;
		}
		num = ft_atoi(myarg[i]);
		if (num >= MAX_INT || num <= MIN_INT)
			ft_prterror_quit();
		i++;
	}
}

t_swap	*ft_getlast(t_swap *my_stark)
{
	t_swap	*tmp_stark;

	tmp_stark = my_stark;
	if (!tmp_stark)
		return (NULL);
	while (tmp_stark->next)
	{
		tmp_stark = tmp_stark->next;
	}
	return (tmp_stark);
}

void	ft_destroy_lst(t_swap *first_start)
{
	t_swap	*current_stark;
	t_swap	*next_stark;

	if (!first_start)
		return ;
	current_stark = first_start;
	while (current_stark)
	{
		next_stark = current_stark->next;
		free(current_stark);
		current_stark = next_stark;
	}
}
