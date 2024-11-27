/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_extended.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:35:48 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/05/02 16:35:50 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_half_min(t_list *stack_)
{
	int	min;
	int	size;
	int	i;

	min = find_min2(stack_);
	size = ft_lstsize(stack_);
	i = 0;
	while (stack_)
	{
		if (stack_->index == min)
			break ;
		i++;
		stack_ = stack_->next;
	}
	if (i <= size / 2)
		return (1);
	else
		return (2);
	return (0);
}

int	test_0(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	return (i == (int)ft_strlen(str));
}
