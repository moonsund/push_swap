#include "push_swap.h"

static void ps_lstadd_back(t_node **lst, t_node *new);
static t_node *ps_lstnew(int index, int value);
static int is_valid_int(const char *str);
static int has_dublicate(t_node *stack, int number);

t_node *parse_argv(int argc, char **argv)
{
    char	**input_array;
    size_t i;
    int tmp;
    t_node *stack_a;
    int should_free;

    should_free = 0;
    stack_a = NULL;
    if (argc == 2)
    {
        input_array = ft_split(argv[1], ' ');
        should_free = 1;
    }
    else 
        input_array = argv + 1;
    i = 0;
    while (input_array[i])
    {
        if (!is_valid_int(input_array[i]))
            ps_error(stack_a); 
        tmp = atoi(input_array[i]);
        if (has_dublicate(stack_a, tmp))
            ps_error(stack_a);
        ps_lstadd_back(&stack_a, ps_lstnew(i, tmp));
        i++;
    }
    if (should_free)
        free_array(input_array);
    return (stack_a);
}

static void ps_lstadd_back(t_node **lst, t_node *new)
{
    t_node *last_node;
    
    if (!lst || !new)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    last_node = *lst;
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = new;
    new->prev = last_node;
}

static t_node *ps_lstnew(int index, int value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->index = index;   
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

static int is_valid_int(const char *str)
{
	int		sign;
	long		value;
    int digit_seen;

	sign = 1;
	value = 0;
    digit_seen = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
        digit_seen = 1;
		value = value * 10 + (*str - '0');
        if ((sign == 1 && value > INT_MAX) ||
            (sign == -1 && value > (long long)INT_MAX + 1))
            return (0);
		str++;
	}
    if (!digit_seen && *str != '\0')
        return (0);
	return (1);
}

static int has_dublicate(t_node *stack, int number)
{
    while (stack != NULL)
        {
            if (stack->value == number)
                return (1);
            stack = stack->next;
        }
    return (0);
}