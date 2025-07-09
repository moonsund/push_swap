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
    int value;
    struct s_node *next;
} t_node;


t_node *parse_argv(int argc, char **argv);
void ps_error(t_node *stack);
void free_stack(t_node *stack);
void free_array(char **array);




#endif