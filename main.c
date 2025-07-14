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
    assign_index(stack_a);
    
    // sa(&stack_a);

    print_stack(stack_a);
    // print_stack(stack_b);

    sort_small(&stack_a);
    // rb(&stack_a);
    // rb(&stack_a);

    print_stack(stack_a);
    // print_stack(stack_b);

    // push_swap(&stack_a, &stack_b);
    
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}