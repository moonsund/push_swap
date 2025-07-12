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


void assign_index(t_node *stack_a);
t_node *parse_argv(int argc, char **argv);

// utils.c
void ps_error(t_node *stack);
void free_stack(t_node *stack);
void free_array(char **array);
void print_stack(t_node *stack); // TO BE DELETED

// operations.c
void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void rra(t_node **a);
// void rrb(t_node **b);
// void rrr(t_node **a, t_node **b);






#endif