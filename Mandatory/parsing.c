/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:35:31 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/05/02 16:35:34 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_input(char *argv[])
{
	int		i;
	char	*str;
	char	**numbers;

	i = 2;
	str = ft_strdup(argv[1]);
	if (!str[0] || !check_empty_n(str))
		return (free(str), NULL);
	while (argv[i])
	{
		if (!argv[i][0] || !check_empty_n(argv[i]))
			return (free(str), NULL);
		str = ft_strjoin2(str, " ");
		str = ft_strjoin2(str, argv[i]);
		i++;
	}
	numbers = ft_split(str, ' ');
	free(str);
	return (numbers);
}

t_list	*fill_stack(char **numbers)
{
	int		i;
	t_list	*stack_a;
	int		data;

	i = 0;
	stack_a = NULL;
	if (!numbers)
		return (NULL);
	while (numbers[i])
	{
		if (!check_numbers(stack_a, ft_atoi(numbers[i]))
			|| !correct_number(numbers[i]) || (ft_strlen(numbers[i]) > 1
				&& !ft_atoi(numbers[i]) && (ft_strncmp("+0", numbers[i],
						ft_strlen(numbers[i])) && ft_strncmp("-0", numbers[i],
						ft_strlen(numbers[i])) && !test_0(numbers[i]))))
		{
			free2d((void **)numbers);
			ft_lstclear(&stack_a, free);
			return (NULL);
		}
		data = ft_atoi(numbers[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((data)));
		i++;
	}
	return (free2d((void **)numbers), stack_a);
}

int	correct_number(char *number)
{
	int	i;
	int	j;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	j = i;
	while (number[i] && ft_isdigit(number[i]))
		i++;
	if (j == i)
		return (0);
	return (i == (int)ft_strlen(number));
}

int	check_numbers(t_list *stack_a, int to_search)
{
	while (stack_a != NULL)
	{
		if (stack_a->content == to_search)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_empty_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return ((int)ft_strlen(str) != i);
}
