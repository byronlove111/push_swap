/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:42 by abbouras          #+#    #+#             */
/*   Updated: 2025/01/07 22:56:25 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void	error_exit(void);
void	error_reset(t_stack_node **stack);
int		error_check_dup(t_stack_node **stack, int value);
int		error_check_syntax(char *str);
long	ft_atol(char *str);
int		ft_isspace(char c);
void	stack_init(t_stack_node **stack_a, char **av, int start_index);
void	stack_add_node(t_stack_node **stack, int val);
t_stack_node		*stack_find_last(t_stack_node **stack);
void	stack_free(t_stack_node **stack);
void	stack_print(t_stack_node **stack);
int		stack_is_sorted(t_stack_node **stack);
void	commands_sa(t_stack_node **stack);
void	commands_sb(t_stack_node **stack);
void	commands_ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	commands_pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	commands_pb(t_stack_node **stack_a, t_stack_node **stack_b);
void	commands_ra(t_stack_node **stack_a);
void	commands_rb(t_stack_node **stack_b);
void	commands_rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	commands_rra(t_stack_node **stack_a);
void	commands_rrb(t_stack_node **stack_b);
void	commands_rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void		stack_index(t_stack_node **stack_a);
void		stack_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void	get_index(t_stack_node **stack);
int	get_max_bits(t_stack_node **stack);
int	stack_size(t_stack_node *stack);

#endif