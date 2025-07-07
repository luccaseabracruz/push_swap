/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:21:11 by lseabra-          #+#    #+#             */
/*   Updated: 2025/07/07 20:56:46 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
//delete
#include <stdio.h>

static size_t	count_args(char const *s)
{
	size_t	counter;
	size_t	i;

	if (!s[0])
		return (1);
	counter = 0;
	i = 0;
	while (s[i] == ' ' && s[i])
		i++;
	while (s[i])
	{
		if (i > 0 && s[i] == ' ' && s[i - 1] != ' ')
			counter++;
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
	num = ft_atol(str_num);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	i = 0;
	while (i < a->len)
	{
		if ((int)num == a->arr[i])
			return (0);
		i++;
	}
	return (1);
}

static bool	parse_input(t_stack *a, char **args, int len)
{
	int		arg_i;
	int		arr_i;
	int		current_args_i;
	char	**current_args;

	arr_i = 0;
	arg_i = 0;
	while (arr_i < len)
	{
		current_args = ft_split((const char *)(args[arg_i]), ' ');
		if (!current_args[0])
			return (free_strarr(current_args, 0));
		current_args_i = -1;
		while (current_args[++current_args_i])
		{
			if (!validate_num(current_args[current_args_i], a))
				return (free_strarr(current_args, 0));
			a->arr[arr_i] = (int)ft_atol(current_args[current_args_i]);
			a->len++;
			arr_i++;
		}
		arg_i++;
		free_strarr(current_args, 0);
	}
	return (1);
}

bool	init_stacks(t_stack *a, t_stack *b, char **args, int len)
{
	a->arr = (int *)ft_calloc((size_t)len, sizeof(int));
	if (!a->arr)
		return (0);
	b->arr = (int *)ft_calloc((size_t)len, sizeof(int));
	if (!b->arr)
		return (free_return(a->arr, 0));
	a->len = 0;
	b->len = 0;
	if (!parse_input(a, args, len))
	{
		print_error(NULL);
		free(a->arr);
		return (free_return(b->arr, 0));
	}
	return (1);
}
