#include "../includes/push_swap.h"

void	ft_cacul_cost(t_swap *my_swap, int swap_middle)
{
	int		currentcost;

	currentcost = 0;
	while(currentcost < swap_middle)
	{
		my_swap->mycost = currentcost;
		my_swap = my_swap->next;
		currentcost++;	
	}
	while(my_swap)
	{
		my_swap->mycost = currentcost;
		my_swap = my_swap->next;
		currentcost--;
	}
}

void	ft_cacul_b_back(t_head **my_swap)
{
	t_swap	*current_swap;
	t_swap	*tolook_swap;

	current_swap = my_swap;
	while (current_swap)
	{	
		tolook_swap = my_swap;

		while(tolook_swap)
		{
			if ((current_swap->num < tolook_swap->num)
				&& (tolook_swap->num > current_swap->new_post))
					current_swap->new_post = current_swap->num;
			tolook_swap = tolook_swap->next;
		}
		current_swap = current_swap->next;
	}
}