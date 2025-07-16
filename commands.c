#include "push_swap.h"

void swap(t_node **stack)
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

void rotate(t_node **stack)
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

    write(1, "ra\n", 3);
}

void reverse_rotate(t_node **stack)
{
    t_node *pre_last;
    t_node *last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    last = *stack;
    while (last->next != NULL)
        last = last->next;

    pre_last = last->prev;
    pre_last->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
    write(1, "rra\n", 4);
}