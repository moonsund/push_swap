#include "push_swap.h"

void	ps_error(t_node *stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void free_stack(t_node *stack)
{
    t_node *tmp;

    while (stack != NULL)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

void free_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}