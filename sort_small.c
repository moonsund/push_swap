#include "push_swap.h"

static void sort_3(t_node **stack);
static void sort_5(t_node **stack_a, int stack_size);
static int find_position(t_node *stack, int target_index);

void sort_small(t_node **stack, int stack_size)
{
    if (stack_size == 2)
    {
        if ((*stack)->value > (*stack)->next->value)
            swap(stack, "sa\n");
    }
    else if (stack_size <= 3)
        sort_3(stack);
    else if (stack_size <= 5)
        sort_5(stack, stack_size);
}

static void sort_3(t_node **stack)
{
    int x = (*stack)->index;
    int y = (*stack)->next->index;
    int z = (*stack)->next->next->index;

    if (x < y && y < z)
        return;
    else if (x > y && y < z && x < z)
        swap(stack, "sa\n");
    else if (x > y && y < z && x > z)
        ra(stack);
    else if (x < y && y > z && x > z)
        rra(stack);
    else if (x > y && y > z)
    {
        swap(stack, "sa\n");
        rra(stack);
    }
    else if (x < y && y > z && x < z)
    {
        swap(stack, "sa\n");
        ra(stack);
    }
}

static void sort_5(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    int position;
    int target_index;
    
    stack_b = NULL;
    target_index = 0;
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
        push(stack_a, &stack_b, "pb\n");
        stack_size--;
        target_index++;
    }
    sort_3(stack_a);
    while (stack_b)
        push(&stack_b, stack_a, "pa\n");
}

static int find_position(t_node *stack, int target_index)
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