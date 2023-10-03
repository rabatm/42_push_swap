#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
}



void ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}