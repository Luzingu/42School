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

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_before_last(t_stack *stack)
{
	if (!stack || !(stack->next))
		return (NULL);
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_put_posicao(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->posicao = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->valor > tmp->next->valor)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_hingt_index(t_stack *stack)
{
	int		hight;
	t_stack	*tmp;

	tmp = stack;
	hight = -1;
	while (tmp)
	{
		if (hight < tmp->index)
			hight = tmp->index;
		tmp = tmp->next;
	}
	return (hight);
}
