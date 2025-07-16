#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h> // write
# include <stddef.h> // NULL
#include <limits.h> // INT_MAX

typedef struct s_node
{
    int index;
    int value;
    struct s_node *prev;
    struct s_node *next;
} t_node;

// push_swap
t_node *build_stack_from_args(int argc, char **argv);
void push_swap(t_node **stack);
void sort_small(t_node **a, int stack_size);

// commands.c
void swap(t_node **a);
void push(t_node **a, t_node **b, const char *cmd);
void rotate(t_node **stack);
void reverse_rotate(t_node **stack);

// utils.c
void assign_index(t_node *stack_a);
void error(t_node *stack);
void free_stack(t_node *stack);
void free_array(char **array);
int get_stack_size(t_node *stack);

#endif