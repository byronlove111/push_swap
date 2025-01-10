/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:26:33 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/30 22:38:08 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	commands_ra(t_stack_node **stack_a)
{
	t_stack_node *first;
	t_stack_node *last;

	if (!*stack_a || !(*stack_a)->next)
		return;
	first = *stack_a;
	last = stack_find_last(stack_a);
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	last->prev = *stack_a;
	ft_printf("ra\n");
}

void	commands_rb(t_stack_node **stack_b)
{
	t_stack_node *first;
	t_stack_node *last;

	if (!*stack_b || !(*stack_b)->next)
		return;
	first = *stack_b;
	last = stack_find_last(stack_b);
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	last->prev = *stack_b;
	ft_printf("rb\n");
}

void	commands_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	commands_ra(stack_a);
	commands_rb(stack_b);
	ft_printf("rr\n");
}