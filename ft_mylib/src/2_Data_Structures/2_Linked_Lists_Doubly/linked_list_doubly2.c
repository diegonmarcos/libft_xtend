/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_doubly2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:08:36 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/03 17:15:05 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

/*
Find the minimum value node in a circular linked list 
	(excluding a given index)
*/
t_list_dls	*find_min_node(t_list_dls *stack)
{
	t_list_dls	*min_node;
	t_list_dls	*current;
	int		swicth_flag;

	min_node = NULL;
	current = stack;
	swicth_flag = 1;
	if (!stack)
		return (NULL);
	while (swicth_flag || current != stack)
	{
		if (min_node == NULL || current->value < min_node->value)
		{
			min_node = current;
		}
		current = current->next;
		swicth_flag = 0;
	}
	return (min_node);
}

void	ft_print_ls_doubly(t_list_dls *stack)
{
	t_list_dls	*current;
	int			swicth_flag;

	current = stack;
	swicth_flag = 1;
	if (!stack)
		return ;
	while (swicth_flag || current != stack)
	{
		ft_putstr_fd("Value: ", 1);
		ft_putnbr_fd(current->value, 1);
		ft_putstr_fd("\n", 1);
		current = current->next;
		swicth_flag = 0;
	}
}
