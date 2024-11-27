/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:35:38 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/05/02 18:20:40 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Atribui índices a cada elemento da lista (stack_).*/
void	indexing(t_list *stack_)
{
	t_list	*tmp;
	t_list	*head;

	head = stack_;
	while (stack_)
	{
		stack_->index = 0;
		tmp = head;
		while (tmp)
		{
			if (stack_->content > tmp->content)
				stack_->index++;
			tmp = tmp->next;
		}
		stack_ = stack_->next;
	}
}
/*maior indice presente da lista*/
int	get_max(t_list *stack_)
{
	int	max;

	max = 0;
	while (stack_)
	{
		if (stack_->index > max)
			max = stack_->index;
		stack_ = stack_->next;
	}
	return (max);
}

/*Check if is is sorted in ascending order*/
int	is_sorted(t_list *stack_)
{
	int	temp;

	temp = stack_->content;
	while (stack_)
	{
		if (temp > stack_->content)
			return (0);
		temp = stack_->content;
		stack_ = stack_->next;
	}
	return (1);
}

/*Check if n is the smallest value in the list*/
int	find_min(t_list *stack_, int n)
{
	int	min;

	min = stack_->content;
	while (stack_)
	{
		if (min > stack_->content)
			min = stack_->content;
		stack_ = stack_->next;
	}
	return (min == n);
}

/*Find the smallest value in the list*/
int	find_min2(t_list *stack_)
{
	int	min;

	min = stack_->index;
	while (stack_)
	{
		if (min > stack_->index)
			min = stack_->index;
		stack_ = stack_->next;
	}
	return (min);
}
