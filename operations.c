#include "push_swap.h"

void sa(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    
    first = *stack;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *stack = second;
    write(1, "sa\n", 3);
}

void sb(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    
    first = *stack;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *stack = second;
    write(1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_node **stack_a, t_node **stack_b)
{
    t_node *top;

    if (!stack_b || !(*stack_b))
        return;
    
    top = *stack_b;

    *stack_b = (*stack_b)->next;
    if (*stack_b)
        (*stack_b)->prev = NULL;

    top->next = *stack_a;
    if (*stack_a)
        (*stack_a)->prev = top;
    top->prev = NULL;
    *stack_a = top;
    write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
    t_node *top;

    if (!stack_a || !(*stack_a))
        return;
    
    top = *stack_a;

    *stack_a = (*stack_a)->next;
    if (*stack_a)
        (*stack_a)->prev = NULL;

    top->next = *stack_b;
    if (*stack_b)
        (*stack_b)->prev = top;
    top->prev = NULL;
    *stack_b = top;
    write(1, "pb\n", 3);
}

void ra(t_node **stack)
{
    t_node *first;
    t_node *movable;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = *stack;
    movable = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    while(movable->next != NULL)
        movable = movable->next;    
    first->next = NULL;
    first->prev = movable;
    movable->next = first;
    (*stack)->prev = NULL;

    write(1, "ra\n", 3);
}

void rb(t_node **stack)
{
    t_node *first;
    t_node *movable;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = *stack;
    movable = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    while(movable->next != NULL)
        movable = movable->next;    
    first->next = NULL;
    first->prev = movable;
    movable->next = first;
    (*stack)->prev = NULL;
    write(1, "rb\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_node **stack)
{
    t_node *penultimate;
    t_node *movable;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    movable = *stack;
    while(movable->next != NULL)
        movable = movable->next;
    penultimate = movable->prev;
    penultimate->next = NULL;
    movable->prev = NULL;
    movable->next = *stack;
    (*stack)->prev = movable;
    *stack = movable;

    write(1, "rra\n", 4);
}

void rrb(t_node **stack)
{
    t_node *penultimate;
    t_node *movable;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    movable = *stack;
    while(movable->next != NULL)
        movable = movable->next;
    penultimate = movable->prev;
    penultimate->next = NULL;
    movable->prev = NULL;
    movable->next = *stack;
    (*stack)->prev = movable;
    *stack = movable;

    write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}