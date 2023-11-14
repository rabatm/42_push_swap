#include "../includes/push_swap.h"

void	ft_check_maxmin(char **myarg)
{
	int			i;
	long long	num;

	i = 1;
	while (myarg[i])
	{
		num = ft_atoi(myarg[i]);
		if (num >= MAX_INT || num <= MIN_INT)
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	ft_error_gest(t_head *t_stark)
{
	if (ft_check_doublons(t_stark->head_a) == 1)
	{
		ft_printf("Error\n");
		ft_destroy_lst(t_stark->head_a);
		free(t_stark);
		exit (1);
	}
	if (ft_check_is_sort(t_stark->head_a) == 1)
	{
		ft_destroy_lst(t_stark->head_a);
		free(t_stark);
		exit (1);
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
