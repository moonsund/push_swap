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

int get_stack_size(t_node *lst)
{
    int i;
    t_node *current;

    i = 0;
    current = lst;
    while (current != NULL)
    {
        current = current->next;
        i++;
    }
    return (i);
}

int find_position(t_node *stack, int target_index)
{
    int i;
    t_node *current;

    i = 1;
    current = stack;
    while (current->index != target_index)
    {
        current = current->next;
        i++;
    }
    return (i);
}

void print_stack(t_node *stack)
{
    t_node *tmp;

    tmp = stack;
    while (tmp != NULL)
    {
        printf("ndx: %d, int: %d\n", tmp->index, tmp->value);
        tmp = tmp->next;
    }
}