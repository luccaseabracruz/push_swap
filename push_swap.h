#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	char	*name;
	int		*arr;
	int		len;
}			t_stack;

void	push(t_stack *from, t_stack *to);
void	swap(int *stack);
int		init_stacks(t_stack *a, t_stack *b, char **arr, int len);

#endif