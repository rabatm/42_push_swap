#include "../includes/push_swap.h"

void	prtlst_basic(t_swap *stark)
{
	while (stark)
	{
		printf("%d\n", stark->num);
		stark = stark->next;
	}
}

void	prtlst(t_swap *stark)
{
	while (stark)
	{
		printf("num : %d cost : %d dest : %d costtotal : %d\n", stark->num,
			stark->mycost, stark->new_post->num,
			(stark->new_post->mycost + stark->mycost));
		stark = stark->next;
	}
}

void	prtlst_a(t_swap *stark)
{
	while (stark)
	{
		printf("num : %d mycost : %d\n", stark->num, stark->mycost);
		stark = stark->next;
	}
}

t_head	*get_args_to_init(char *argv[], int argc, t_head *t_stark)
{
	char	**my_argv;
	int		i;

	i = 1;
	if (argc == 2)
	{
		my_argv = ft_split(argv[1], ' ');
		i = 0;
	}
	else
		my_argv = argv;
	ft_check_maxmin(my_argv, i);
	t_stark = ft_init_stark(my_argv, t_stark, i);
	return (t_stark);
}

int	main(int argc, char *argv[])
{
	t_head	*t_stark;

	if (argc < 2)
		exit (0);
	t_stark = malloc(sizeof(t_head));
	if (t_stark == NULL)
		ft_prterror_quit();
	t_stark = get_args_to_init(argv, argc, t_stark);
	ft_error_gest(t_stark);
	ft_sort(&t_stark);
	ft_destroy_lst(t_stark->head_a);
	ft_destroy_lst(t_stark->head_b);
	free(t_stark);
	return (0);
}
