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
	int		min_num;
	int		diff;
	
	closest = head;
	min_num = head->num;
	current = head;
	while (current != NULL)
	{
		diff = abs(current->num - num);
		if ((diff < abs(min_num - num)) && (current->num < num))
		{
			min_num = current->num;
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
	
	current_b = (*t_stark)->head_b;
	while (current_b != NULL)
	{
		current_b->before = 1;
		closest_in_a = ft_find_closest((*t_stark)->head_a, current_b->num);	
		if (closest_in_a->num > current_b->num)
			current_b->before = 0;
		current_b->new_post = closest_in_a;
		current_b = current_b->next;
	}
}
