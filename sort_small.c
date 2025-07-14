#include "push_swap.h"

void sort_small(t_node **stack)
{
    if (ps_lstsize(*stack) == 2)
    {
        if ((*stack)->value > (*stack)->next->value)
            sa(stack);
    }

    if (ps_lstsize(*stack) == 3)
    {
        sort_3(stack);
    }

    if (ps_lstsize(*stack) == 4 || ps_lstsize(*stack) == 5)
    {
        sort_5(stack);
    }

}

void sort_3(t_node **stack)
{
    int x = (*stack)->index;
    int y = (*stack)->next->index;
    int z = (*stack)->next->next->index;

    if (x < y && y < z)
        return;
    else if (x > y && y < z && x < z)
        sa(stack);
    else if (x > y && y < z && x > z)
        ra(stack);
    else if (x < y && y > z && x > z)
        rra(stack);
    else if (x > y && y > z)
    {
        sa(stack);
        rra(stack);
    }
    else if (x < y && y > z && x < z)
    {
        sa(stack);
        ra(stack);
    }
}


void sort_5(t_node **stack)
{
    t_node *stack_b;
    int position;
    int stack_size; 
    
    stack_b = NULL;
    stack_size = ps_lstsize(*stack);
    while (stack_size > 3)
    {
        while ((*stack)->index != 0)
        {
            position = find_pos(*stack);
            if (position <= 3)
                ra(stack);
            else
                rra(stack);
            assign_index(*stack);
        }
        pb(stack, &stack_b);
        assign_index(*stack);
        stack_size = ps_lstsize(*stack);
    
    }
    sort_3(stack);
    while (ps_lstsize(stack_b) > 0)
        pa(stack, &stack_b);
}
