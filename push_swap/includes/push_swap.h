/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:56:16 by aluzingu          #+#    #+#             */
/*   Updated: 2024/07/08 16:56:18 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				valor;
	int				posicao;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack		*fill_stack(int i, char **argv, int *erro);
void		do_sa(t_stack **stack);
void		do_sb(t_stack **stack);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack);
void		do_rrb(t_stack **stack);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_push_swap(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_put_posicao(t_stack **stack);
void		do_move(t_stack **stack_a, t_stack **stack_b,
				int cost_a, int cost_b);
void		ft_only_thre_in_stack_a(t_stack **stack_a,
				t_stack **stack_b);
void		mini_sort(t_stack **stack);
void		get_target_position(t_stack **a, t_stack **b);
void		get_get_cost(t_stack **stack_a, t_stack **stack_b);
char		**ft_split(char *str);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);
int			is_input_correct(char **argv, int i);
int			get_size_stack(t_stack *stack);
int			get_hingt_index(t_stack *stack);
int			is_digit(char c);
int			ft_is_sorted(t_stack *stack);
t_stack		*get_last(t_stack *stack);
t_stack		*get_before_last(t_stack *stack);

#endif
