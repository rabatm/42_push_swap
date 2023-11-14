#include "../includes/push_swap.h"

void	ft_error_gest(t_head *t_stark)
{
	if (ft_check_doublons(t_stark->head_a) == 1)
	{

		ft_destroy_lst(t_stark->head_a);
		free(t_stark);
		ft_prterror_quit();
	}
	if (ft_check_is_sort(t_stark->head_a) == 1)
	{
		ft_destroy_lst(t_stark->head_a);
		free(t_stark);
		exit (1);
	}
}

void	ft_prterror_quit(void)
{
	ft_printf("Error\n");
	exit (1);
}