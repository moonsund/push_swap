#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
#include <limits.h> // INT_MAX

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

char *ft_strchr(const char *s, int c);
char **ft_split(const char *s, char c);
int	ft_atoi(const char *str);
void ft_lstadd_back(t_node **lst, t_node *new);
t_node *ft_lstnew(void *content);





#endif