#include "../includes/push_swap.h"

void	prtlst(t_swap *stark)
{
	while (stark)
	{
		printf("%d\n", stark->num);
		stark = stark->next;
	}
}

/*int	main(int argc, char *argv[])
{
	t_head	*t_stark;

	if (argc < 2)
		return (0);
	t_stark = malloc(sizeof(t_head));
	t_stark->head_a = ft_init_stark(argv);
	if ((ft_check_is_sort(t_stark->head_a)) || ft_check_doublons(t_stark->head_a))
	{
		ft_destroy_lst(t_stark->head_a);
		ft_printf("finito pipo\n");
		return (0);
	}
		ft_printf("BEFORE SA\n");
		prtlst(t_stark->head_a);
		ft_printf("AFTER SA\n");
		t_stark->head_a = ft_sa(t_stark->head_a);
		prtlst(t_stark->head_a);
		return (0);
}
*/
