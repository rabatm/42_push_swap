#include "../includes/push_swap.h"

void	prtlst(t_swap *stark)
{
	while (stark)
	{
		printf("%d\n", stark->num);
		stark = stark->next;
	}
}

int	main(int argc, char *argv[])
{
	t_head	*t_stark;

	if (argc < 2)
		return (0);
	t_stark = malloc(sizeof(t_head));
	t_stark = ft_init_stark(argv, t_stark);
	if ((ft_check_is_sort(t_stark->head_a)) || ft_check_doublons(t_stark->head_a))
	{
		ft_destroy_lst(t_stark->head_a);
		ft_printf("finito pi po\n");
		return (0);
	}
		//prtlst(t_stark->head_a);
		ft_sort(&t_stark);
		//prtlst(t_stark->head_a);
		return (0);
}