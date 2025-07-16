#include "push_swap.h"

static void append_new_node(t_node **stack, int value);
static int is_valid_int(const char *str);
static int has_duplicate(t_node *stack, int number);
static t_node *build_stack(char **arguments);

t_node *build_stack_from_args(int argc, char **argv)
{
    char	**arguments;
    int needs_free;
    t_node *stack;

    needs_free = 0;
    if (argc == 2)
    {
        arguments = ft_split(argv[1], ' ');
        needs_free = 1;
    }
    else 
        arguments = argv + 1;
    stack = build_stack(arguments);
    if (needs_free)
        free_array(arguments);
    return (stack);
}

static t_node *build_stack(char **arguments)
{
    int value;
    size_t i;
    t_node *stack;

    stack = NULL;
    i = 0;
    while (arguments[i])
    {
        if (!is_valid_int(arguments[i]))
            error(stack); 
        value = atoi(arguments[i]);
        if (has_duplicate(stack, value))
            error(stack);
        append_new_node(&stack, value);
        i++;
    }
    return (stack); 
}

static void append_new_node(t_node **stack, int value)
{
    t_node *new;
    t_node *last;

    new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return;
    new->index = -1;
    new->value = value;
    new->prev = NULL;
    new->next = NULL;
    if (!stack)
        return;
    if (*stack == NULL)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
    new->prev = last;
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

static int has_duplicate(t_node *stack, int number)
{
    while (stack != NULL)
        {
            if (stack->value == number)
                return (1);
            stack = stack->next;
        }
    return (0);
}