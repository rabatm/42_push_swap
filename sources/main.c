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
	t_swap	*stark_a;
	t_swap	*stark_b;

	stark_a = NULL;
	stark_b = NULL;
	(void)argv;
	(void)stark_a;
	(void)stark_b;
	if (argc < 2)
		return (0);
	stark_a = ft_init_stark(argv);
	if ((ft_check_is_sort(stark_a)) || ft_check_doublons(stark_a))
	{
		ft_destroy_lst(stark_a);
		ft_printf("finito pipo");
		return (0);
	}
		ft_printf("NO trie CANARD");
		prtlst(stark_a);
		return (0);
	
}
