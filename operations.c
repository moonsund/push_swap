#include "push_swap.h"

void swap(t_node **stack, const char *cmd)
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
    write(1, cmd, 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    // sa(stack_a);
    // sb(stack_b);
}

void push(t_node **origin, t_node **target, const char *cmd)
{
    t_node *top;

    if (!origin || !(*origin))
        return;
    
    top = *origin;

    *origin = (*origin)->next;
    if (*origin)
        (*origin)->prev = NULL;

    top->next = *target;
    if (*target)
        (*target)->prev = top;
    top->prev = NULL;
    *target = top;
    write(1, cmd, 3);
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