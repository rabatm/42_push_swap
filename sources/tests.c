#include <stdio.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

// Function to create a new node with given value
t_swap	*new_node(int value)
{
    t_swap	*new;

    new = (t_swap *)malloc(sizeof(t_swap));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

// Function to add a new node at the beginning of the list
void	push(t_swap **head, int value)
{
    t_swap	*new;

    new = new_node(value);
    if (!new)
        return ;
    new->next = *head;
    if (*head)
        (*head)->prev = new;
    *head = new;
}

// Function to print the list
void	print_list(t_swap *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

// Test function for ft_pb
void	test_ft_pb(void)
{
    t_head	t_stark;
    t_swap	*stark_a;
    t_swap	*stark_b;

    // Test case 1: empty stack
    stark_a = NULL;
    stark_b = NULL;
    t_stark.head_a = stark_a;
    t_stark.head_b = stark_b;
    ft_pb(&t_stark);
    printf("Test case 1: ");
    if (t_stark.head_a == NULL && t_stark.head_b == NULL)
        printf("OK\n");
    else
        printf("FAIL\n");

    // Test case 2: stack with one element
    stark_a = new_node(42);
    stark_b = NULL;
    t_stark.head_a = stark_a;
    t_stark.head_b = stark_b;
    ft_pb(&t_stark);
    printf("Test case 2: ");
    if (t_stark.head_a == NULL && t_stark.head_b->value == 42 && t_stark.head_b->next == NULL && t_stark.head_b->prev == NULL)
        printf("OK\n");
    else
        printf("FAIL\n");

    // Test case 3: stack with two elements
    stark_a = NULL;
    push(&stark_a, 42);
    push(&stark_a, 24);
    stark_b = NULL;
    t_stark.head_a = stark_a;
    t_stark.head_b = stark_b;
    ft_pb(&t_stark);
    printf("Test case 3: ");
    if (t_stark.head_a->value == 24 && t_stark.head_a->next == NULL && t_stark.head_a->prev == NULL && t_stark.head_b->value == 42 && t_stark.head_b->next == NULL && t_stark.head_b->prev == NULL)
        printf("OK\n");
    else
        printf("FAIL\n");

    // Test case 4: stack with three elements
    stark_a = NULL;
    push(&stark_a, 42);
    push(&stark_a, 24);
    push(&stark_a, 12);
    stark_b = NULL;
    t_stark.head_a = stark_a;
    t_stark.head_b = stark_b;
    ft_pb(&t_stark);
    printf("Test case 4: ");
    if (t_stark.head_a->value == 24 && t_stark.head_a->next->value == 12 && t_stark.head_a->next->next == NULL && t_stark.head_a->prev == NULL && t_stark.head_a->next->prev == t_stark.head_a && t_stark.head_b->value == 42 && t_stark.head_b->next == NULL && t_stark.head_b->prev == NULL)
        printf("OK\n");
    else
        printf("FAIL\n");
}

int	main(void)
{
    test_ft_pb();
    return (0);
}