/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:42:59 by aluzingu          #+#    #+#             */
/*   Updated: 2024/07/08 16:43:01 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stack_min(t_stack *tmp, int *min_v)
{
	t_stack	*stack_min;

	while (tmp)
	{
		if (tmp->index == -1)
		{
			if (*min_v == INT_MIN)
				*min_v = tmp->valor;
			if (tmp->valor <= *min_v)
			{
				*min_v = tmp->valor;
				stack_min = tmp;
			}
		}
		tmp = tmp->next;
	}
	return (stack_min);
}

void	ft_put_index(t_stack *stack, int stack_size)
{
	t_stack	*stack_min;
	int		index;
	int		min_v;

	index = 1;
	while (stack_size > 0)
	{
		min_v = INT_MIN;
		stack_min = ft_stack_min(stack, &min_v);
		if (stack_min)
		{
			stack_min->index = index;
			++index;
		}
		stack_size--;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_do(char **valores, int start)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	int		erro;

	erro = 1;
	stack_a = fill_stack(start, valores, &erro);
	if (erro == 0)
	{
		free(stack_a);
		ft_putstr("Error\n");
		return ;
	}
	stack_b = NULL;
	size = get_size_stack(stack_a);
	ft_put_index(stack_a, size);
	do_push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{	
	char	**valores;
	int		start;

	if (argc < 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	valores = argv;
	start = 1;
	if (argc == 2)
	{
		start = 0;
		valores = ft_split(argv[1]);
	}
	if (!is_input_correct(valores, start))
		ft_putstr("Error\n");
	else
		ft_do(valores, start);
	return (0);
}
