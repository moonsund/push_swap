#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *stack;

    if (argc < 2)
        return (0);
    stack = parse_argv(argc, argv);
    if (stack == NULL)
        ps_error(stack);
    assign_index(stack);
    


    print_stack(stack);

    sort_small(&stack);

    print_stack(stack);

    // push_swap(&stack_a);
    
    free_stack(stack);
    return (0);
}