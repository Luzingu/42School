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

void	swap_elem(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->valor;
	stack->valor = stack->next->valor;
	stack->next->valor = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_stack **stack)
{
	swap_elem(*stack);
	ft_putstr("sa\n");
}

void	do_sb(t_stack **stack)
{
	swap_elem(*stack);
	ft_putstr("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_elem(*stack_a);
	swap_elem(*stack_b);
	ft_putstr("ss\n");
}
