/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:56 by aluzingu          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:58 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mini_sort(t_stack **stack)
{
	int	high_index;

	high_index = get_hingt_index(*stack);
	if (ft_is_sorted(*stack))
		return ;
	if ((*stack)->index == high_index)
		do_ra(stack);
	else if ((*stack)->next->index == high_index)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

void	ft_only_thre_in_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = get_size_stack(*stack_a);
	pushed = 0;
	while ((size - pushed) > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->posicao;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->posicao;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	ft_put_posicao(a);
	ft_put_posicao(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

void	get_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;

	size_a = get_size_stack(*stack_a);
	size_b = get_size_stack(*stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
		{
			tmp->cost_a = (size_a - tmp->target_pos) * -1;
		}
		tmp->cost_b = tmp->posicao;
		if (tmp->posicao > size_b / 2)
			tmp->cost_b = (size_b - tmp->posicao) * -1;
		tmp = tmp->next;
	}
}
