/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:21:11 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/11 18:33:28 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdbool.h>

static size_t	count_args(char const *s)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i] == ' ' && s[i])
		i++;
	while (s[i])
	{
		if (i > 0 && s[i] == ' ' && s[i - 1] != ' ')
		{
			counter++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != ' ')
		counter++;
	return (counter);
}

size_t	arrlen(char **args)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (args[i])
	{
		len += count_args(args[i]);
		i++;
	}
	return (len);
}

static bool	validate_num(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+'))
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static bool	parse_input(t_stack *a, char **args)
{
	int		i;
	int		j;
	int		len;
	char	**current_args;

	len = a->len;
	i = 0;
	while (len > 0)
	{
		current_args = ft_split((const char *)(args[i]), ' ');
		if (!current_args[0])
			return (0);
		j = 0;
		while (current_args[j])
		{
			if (!validate_num(current_args[j]))
				return (0);
			a->arr[i] = ft_atoi(current_args[j]);
			j++;
			i++;
			len--;
		}
	}
	return (1);
}

bool	init_stacks(t_stack *a, t_stack *b, char **args, int len)
{
	int	i;

	a->arr = (int *)ft_calloc((size_t)len, sizeof(int));
	if (!a->arr)
		return (0);
	b->arr = (int *)ft_calloc((size_t)len, sizeof(int));
	if (!b->arr)
	{
		free(a->arr);
		return (0);
	}
	a->len = len;
	b->len = 0;
	a->name = "a";
	b->name = "b";
	i = 0;
	if (!parse_input(a, args))
	{
		free(a->arr);
		free(b->arr);
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	bool	is_valid;

// 	is_valid = validate_num("");
// 	ft_printf("input: %s\nis valid? %d\n");
// }