/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:21:23 by abbouras          #+#    #+#             */
/*   Updated: 2025/01/07 22:55:54 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void get_index(t_stack_node **stack)
{
    t_stack_node *current;
    t_stack_node *compare;
    int index;

    current = *stack;
    while (current)
    {
        index = 0;
        compare = *stack;
        while (compare)
        {
            if (current->index > compare->index)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

int get_max_bits(t_stack_node **stack)
{
    t_stack_node *node;
    int max;
    int max_bits;

    node = *stack;
    max = node->index;
    max_bits = 0;
    while (node)
    {
        if (node->index > max)
            max = node->index;
        node = node->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void stack_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    size = stack_size(*stack_a);
    get_index(stack_a);
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*stack_a)->index >> i) & 1) == 1)
                commands_ra(stack_a);
            else
                commands_pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            commands_pa(stack_a, stack_b);
        i++;
    }
}