/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:10:31 by julnolle          #+#    #+#             */
/*   Updated: 2021/08/19 12:33:44 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst, void (*print)(int))
{
	if (lst)
	{
		while (lst)
		{
			print(*(int *)(lst->content));
			write(1, " ", 1);
			lst = lst->next;
		}
	}
	else
		ft_putendl("LISTE VIDE");
}

int	sort_stack(t_list *a, t_list *b)
{
	(void)b;
	print_lst(a, ft_putnbr);
	return (0);
}
