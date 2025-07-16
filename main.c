#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *stack;

    if (argc < 2)
        return (0);
    stack = build_stack_from_args(argc, argv);
    if (stack == NULL)
        error(stack);
    assign_index(stack);
    push_swap(&stack); 
    free_stack(stack);
    return (0);
}