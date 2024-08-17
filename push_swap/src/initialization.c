/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:30:38 by aluzingu          #+#    #+#             */
/*   Updated: 2024/07/09 15:30:40 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack(int v)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->valor = v;
	new_stack->posicao = -1;
	new_stack->index = -1;
	new_stack->cost_a = 0;
	new_stack->cost_b = 0;
	new_stack->target_pos = -1;
	new_stack->next = NULL;
	return (new_stack);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

t_stack	*fill_stack(int i, char **argv, int *erro)
{
	t_stack			*stack;
	long int		number;

	stack = NULL;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			*erro = 0;
			return (stack);
		}
		ft_lstadd_back(&stack, new_stack(number));
		i++;
	}
	return (stack);
}
