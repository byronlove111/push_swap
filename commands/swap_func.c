/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:46:55 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/29 15:08:13 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = *stack;
	if (!current || !current->next)
		return ;
	
	next_node = current->next;
	current->next = next_node->next;
	if (next_node->next)
		next_node->next->prev = current;
	next_node->prev = NULL;
	next_node->next = current;
	current->prev = next_node;
	*stack = next_node;
}

void	commands_sa(t_stack_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	commands_sb(t_stack_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	commands_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}