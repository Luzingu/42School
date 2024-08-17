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

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	ft_put_posicao(stack);
	lowest_pos = tmp->posicao;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->posicao;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	ajust_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_size_stack(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	ft_only_thre_in_stack_a(stack_a, stack_b);
	mini_sort(stack_a);
	i = 0;
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
		i++;
	}
	if (!ft_is_sorted(*stack_a))
		ajust_stack(stack_a);
}

void	do_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (ft_is_sorted(*stack_a))
		return ;
	if (size == 2)
		do_sa(stack_a);
	else if (size == 3)
		mini_sort(stack_a);
	else
		sort(stack_a, stack_b);
}
