#include "../includes/push_swap.h"

void	ft_cacul_cost(t_swap *my_swap, int swap_middle)
{
	int		currentcost;

	currentcost = 0;
	while(currentcost < swap_middle)
	{
		my_swap->mycost = currentcost;
		my_swap->top = 0;
		my_swap = my_swap->next;
		currentcost++;
	}
	while(my_swap)
	{
		my_swap->mycost = currentcost;
		my_swap->top = 1;
		my_swap = my_swap->next;
		currentcost--;
	}
}

t_swap *ft_find_closest(t_swap *head, int num)
{
	t_swap *closest;
	t_swap *current;

	closest = NULL;
	current = head;
	while (current != NULL)
	{
		if (num < current->num)
		{
			if (!closest)
				closest = current;
			else if (closest->num > current->num)
				closest = current;
		}		
		current = current->next;	
	}
	return closest;
}

void ft_find_closest_in_a(t_head **t_stark)
{
	t_swap *current_b;
	t_swap *closest_in_a;
	int		testsmall;
	int		testtaill;
	
	current_b = (*t_stark)->head_b;
	while (current_b != NULL)
	{
		closest_in_a = NULL;
		current_b->position = 'M';
		testtaill = ft_im_bigest(current_b->num, (*t_stark)->head_a);
		testsmall = ft_im_smallest(current_b->num, (*t_stark)->head_a);
		if (testtaill == 1)
			current_b->position = 'T';
		if (testsmall == 1)
			current_b->position = 'B';
		if (testsmall == 1 || testtaill == 1)
			closest_in_a = ft_get_min_item((*t_stark)->head_a);
		else
			closest_in_a = ft_find_closest((*t_stark)->head_a, current_b->num);	
		current_b->new_post = closest_in_a;
		current_b = current_b->next;

	}
}
