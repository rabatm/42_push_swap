#include "../includes/push_swap.h"

void ft_r(t_swap **p1) 
{    
    t_swap *tmp_swap;
    t_swap *tmp_last;

    if (*p1 == NULL || (*p1)->next == NULL)
        return;

    tmp_last = ft_getlast(*p1);
    tmp_swap = *p1;
    *p1 = (*p1)->next;
    (*p1)->prev = NULL;
    tmp_last->next = tmp_swap;
    tmp_swap->prev = tmp_last;
    tmp_swap->next = NULL;
}