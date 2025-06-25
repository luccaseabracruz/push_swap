/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:21:11 by lseabra-          #+#    #+#             */
/*   Updated: 2025/06/25 16:51:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

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

static bool	validate_num(char *str_num, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	if ((str_num[i] == '-' || str_num[i] == '+'))
		i++;
	if (!str_num[i])
		return (0);
	while (str_num[i])
	{
		if (!ft_isdigit(str_num[i]))
			return (0);
		i++;
	}
	num = (long)ft_atol(str_num);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	i = 0;
	while (i < a->len)
	{
		if (num == a->arr[i])
			return (0);
		i++;
	}
	return (1);
}

static bool	parse_input(t_stack *a, char **args)
{
	int		i;
	int		j;
	char	**current_args;

	i = 0;
	while (i < a->len)
	{
		current_args = ft_split((const char *)(args[i]), ' ');
		if (!current_args[0])
			return (0);
		j = 0;
		while (current_args[j])
		{
			if (!validate_num(current_args[j], a))
				return (0);
			a->arr[i] = ft_atol(current_args[j]);
			j++;
			i++;
		}
	}
	return (1);
}

bool	init_stacks(t_stack *a, t_stack *b, char **args, int len)
{
	a->arr = (long *)ft_calloc((size_t)len, sizeof(long));
	if (!a->arr)
		return (0);
	b->arr = (long *)ft_calloc((size_t)len, sizeof(long));
	if (!b->arr)
	{
		free(a->arr);
		return (0);
	}
	a->len = len;
	b->len = 0;
	a->name = "a";
	b->name = "b";
	if (!parse_input(a, args))
	{
		free(a->arr);
		free(b->arr);
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	return (1);
}
