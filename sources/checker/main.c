#include "../../includes/push_swap.h"

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
	char	*line;

	if (argc < 2)
		exit (0);
	t_stark = malloc(sizeof(t_head));
	if (t_stark == NULL)
		ft_prterror_quit();
	t_stark = get_args_to_init(argv, argc, t_stark);
	ft_error_gest(t_stark);
	
	line = get_next_line(0, 0);
	while(line)
	{
		printf("ln %s", line);
		free(line);
		line = get_next_line(0, 0);
	}
	ft_destroy_lst(t_stark->head_a);
	ft_destroy_lst(t_stark->head_b);
	free(t_stark);
	return (0);
}
