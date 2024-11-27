/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:02 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/05/02 16:36:04 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_sort_(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = range_eq(ft_lstsize(*stack_a));
	while ((*stack_a))
	{
		if ((*stack_a)->index <= range && (*stack_a)->index >= i)
		{
			push(stack_a, stack_b, "pb");
			i++;
			range++;
		}
		else if ((*stack_a)->index < i)
		{
			push(stack_a, stack_b, "pb");
			rotate(stack_b, "rb");
			i++;
			range++;
		}
		else
			rotate(stack_a, "ra");
	}
	fill_a(stack_a, stack_b);
}

void	option_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 5)
		_sort_(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			swap(*stack_a, "sa");
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (1)
	{
		if (find_min(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b, "pb");
			sort_four(stack_a, stack_b);
			push(stack_b, stack_a, "pa");
			return ;
		}
		else
		{
			if (find_half_min(*stack_a) == 1)
				rotate(stack_a, "ra");
			else if (find_half_min(*stack_a) == 2)
				reverse_rotate(stack_a, "rra");
		}
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (1)
	{
		if (find_min(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b, "pb");
			sort_three(stack_a);
			push(stack_b, stack_a, "pa");
			return ;
		}
		rotate(stack_a, "ra");
	}
}

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		rotate(stack_a, "ra");
		swap(*stack_a, "sa");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rotate(stack_a, "ra");
		else
			swap(*stack_a, "sa");
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if ((*stack_a)->content < (*stack_a)->next->next->content)
		{
			reverse_rotate(stack_a, "rra");
			swap(*stack_a, "sa");
		}
		else
			reverse_rotate(stack_a, "rra");
	}
}
