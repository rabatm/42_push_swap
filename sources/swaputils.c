#include "../includes/push_swap.h"

int	ft_check_doublons(t_swap *first_stark)
{
	t_swap	*look_stark;
	t_swap	*in_stark;

	look_stark = first_stark;
	in_stark = first_stark;
	while (look_stark)
	{
		in_stark = look_stark->next;
		while (in_stark)
		{
			if (look_stark->num == in_stark->num)
				return (1);
			in_stark = in_stark->next;
		}
		look_stark = look_stark->next;
	}
	return (0);
}

int	ft_check_is_sort(t_swap *first_stark)
{
	while (first_stark->next)
	{
		if (first_stark->num > first_stark->next->num)
			return (0);
		first_stark = first_stark->next;
	}
	return (1);
}
