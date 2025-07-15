#include "push_swap.h"

static void radix_sort(t_node **stack);
static int get_max_bits(t_node *stack);

void push_swap(t_node **stack)
{
    int stack_size;

    stack_size = get_stack_size(*stack);

    if (stack_size < 6)
        sort_small(stack, stack_size);
    else
    {
        radix_sort(stack);
    }
}


static void radix_sort(t_node **stack)
{
    int i;
    int max_bits;

    i = 0;
    max_bits = get_max_bits(*stack);
    while (i < max_bits)
    {





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
        stack = stack->index;
    }
    bits = 0;
    while(max >> bits !=0)
        bits++;
    return (bits);
}