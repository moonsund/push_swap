#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *stack_a;
    t_node *stack_b;

    stack_b = NULL;
    if (argc < 2)
        return (0);
    stack_a = parse_argv(argc, argv);
    if (stack_a == NULL)
        ps_error(stack_a);
    
    // push_swap(stack_a, stack_b);
    while (stack_a != NULL)
    {
        printf("int: %d\n", stack_a->value);
        stack_a = stack_a->next;
    }
    
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}