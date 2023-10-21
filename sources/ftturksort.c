#include "../includes/push_swap.h"

void ft_turk_sort(t_head t_stark)
{
(void)t_stark;

}

void ft_get_min(t_swap *s_stark)
{
	long	min;
	int		index;
	int		i;
	t_swap	*current_stark;

	current_stark = s_stark;
	min =	MAX_INT;
	index = 0;
	i = 0;
	while	(current_stark)
	{
		if (current_stark->num <= min)
		{
			min = current_stark->num;
			index = i;
		}
		i++;
		current_stark=current_stark->next;
	}
	printf("MIN : %ld index : %d \n", min, index);
}