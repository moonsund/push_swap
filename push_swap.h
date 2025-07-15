#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
#include <stdio.h> // printf TO BE DELETED
#include <limits.h> // INT_MAX

typedef struct s_node
{
    int index;
    int value;
    struct s_node *prev;
    struct s_node *next;
} t_node;

// push_swap
t_node *parse_argv(int argc, char **argv);
void push_swap(t_node **stack);
void sort_small(t_node **a, int stack_size);

// operations.c
void swap(t_node **a, const char *cmd);
void ss(t_node **a, t_node **b);
void push(t_node **a, t_node **b, const char *cmd);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

// utils.c
void assign_index(t_node *stack_a);
void ps_error(t_node *stack);
void free_stack(t_node *stack);
void free_array(char **array);
int get_stack_size(t_node *stack);
void print_stack(t_node *stack); // TO BE DELETED




#endif