#include "push_swap.h"

void assign_index(t_node *stack)
{
    t_node *compare;
    t_node *current;
    int index;

    compare = stack;
    while(compare)
    {
        current = stack;
        index = 0;
        while(current)
        {
            if (compare->value > current->value)
                index++;
            current = current->next;
        }
        compare->index = index;
        compare = compare->next;
    }
}

void	error(t_node *stack)
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

int get_stack_size(t_node *stack)
{
    int i;
    t_node *current;

    i = 0;
    current = stack;
    while (current != NULL)
    {
        current = current->next;
        i++;
    }
    return (i);
}