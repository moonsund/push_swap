#include "push_swap.h"

static void sort_3(t_node **stack);
static void sort_5(t_node **stack_a);

void sort_small(t_node **stack)
{
    int stack_size;

    stack_size = get_stack_size(*stack);
    if (stack_size == 2)
    {
        if ((*stack)->value > (*stack)->next->value)
            sa(stack);
    }
    else if (stack_size == 3)
        sort_3(stack);
    else if (stack_size == 4 || stack_size == 5)
        sort_5(stack);
}

static void sort_3(t_node **stack)
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

static void sort_5(t_node **stack_a)
{
    t_node *stack_b;
    int position;
    int stack_size;
    int target_index;
    
    stack_b = NULL;
    target_index = 0;
    stack_size = get_stack_size(*stack_a);
    while (stack_size > 3)
    {
        position = find_position(*stack_a, target_index);
        while ((*stack_a)->index != target_index)
        {
            if (position <= stack_size / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        pb(stack_a, &stack_b);
        stack_size--;
        target_index++;
    }
    sort_3(stack_a);
    while (get_stack_size(stack_b) > 0)
        pa(stack_a, &stack_b);
}
