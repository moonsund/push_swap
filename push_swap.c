#include "push_swap.h"

static void radix_sort(t_node **stack, int stack_size);
static int get_max_bits(t_node *stack);
static int is_sorted(t_node *stack);

void push_swap(t_node **stack)
{
    int stack_size;

    stack_size = get_stack_size(*stack);

    if (is_sorted(*stack))
        return;
    else if (stack_size < 6)
        sort_small(stack, stack_size);
    else
        radix_sort(stack, stack_size);
}

static void radix_sort(t_node **stack_a, int stack_size)
{
    int i;
    int j;
    int max_bits;
    t_node *stack_b;

    stack_b = NULL;
    i = 0;
    max_bits = get_max_bits(*stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j < stack_size)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)
                pb(stack_a, &stack_b);
            else
                ra(stack_a);
            j++;
        }
        while (stack_b)
            pa(stack_a, &stack_b);
        i++;
    }
}

static int get_max_bits(t_node *stack)
{
    int max;
    int bits;

    max = 0;
    while(stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    bits = 0;
    while(max >> bits !=0)
        bits++;
    return (bits);
}

static int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->index > stack->next->index)
            return (0);
        stack = stack->next;
    }
    return (1);
}