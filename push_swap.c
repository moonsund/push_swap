#include <stdio.h>
#include "push_swap.h"


void	ps_error(t_node *stacks)
{
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

int is_valid_int(const char *s)
{
    
}

int has_dublicate(t_node *stack, int number)
{
    while (!stack)
        {
            if (stack->value == number)
                return (1);
            stack = stack->next;
        }
    return (0);
}

void parce_validate(int argc, char **argv)
{
    char	**input_array;
    size_t i;
    int tmp;
    t_node *stack_a;
    t_node *new_node;

    stack_a = NULL;
    if (argc == 2)
        input_array = ft_split(argv[1], ' '); // free split array
    else 
        input_array = argv + 1;
    i = 0;
    while (input_array[i])
    { 
        if (!is_valid_int(input_array[i]))
            return;
        tmp = atoi(input_array[i]);
        if (has_dublicate(stack_a, tmp))
            ps_error(stack_a);
        new_node = ft_lstnew(tmp);
        ft_lstadd_back(stack_a, new_node);
    }
}


void push_swap(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    parce_validate(argc, argv);

}


int main(int argc, char **argv)
{
    push_swap(argc, argv);
    return (1);
}