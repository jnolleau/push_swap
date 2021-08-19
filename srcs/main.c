/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:10:31 by julnolle          #+#    #+#             */
/*   Updated: 2021/08/19 12:33:35 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_check_args(char const *str)
{
	char	**values;
	int		i;

	values = NULL;
	values = ft_split_whitespaces(str);
	if (values)
	{
		if (values[0] == NULL)
		{
			free_tab_str(values);
			return (NULL);
		}
		i = 0;
		while (values[i])
		{
			if (!ft_isdigit_str(values[i]))
			{
				free_tab_str(values);
				return (NULL);
			}
			i++;
		}
	}
	return (values);
}

int	check_duplicate(t_list *a, int val)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (*(int *)(tmp->content) == val)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	add_values_to_stack(char **values, t_list **a)
{
	t_list	*new;
	int		*val;
	long	tmp_val;

	while (*values)
	{
		tmp_val = atol(*values++);
		if (tmp_val > (long)INT_MAX ||tmp_val < (long)INT_MIN)
			return (FAILURE);
		if (check_duplicate(*a, (int)tmp_val) == SUCCESS)
		{
			val = (int *)malloc(sizeof(int));
			*val = (int)tmp_val;
			new = ft_lstnew(val);
			ft_lstadd_back(a, new);
		}
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

int	init_data(char const **av, t_list **a)
{
	char	**values;

	while (*av)
	{
		values = ft_check_args(*av);
		if (values)
		{
			if (add_values_to_stack(values, a) == FAILURE)
			{
				free_tab_str(values);
				return (FAILURE);
			}
			free_tab_str(values);
		}
		else
			return (FAILURE);
		av++;
	}
	return (SUCCESS);
}

int	main(int ac, char const **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (init_data(++av, &a) == SUCCESS)
		{
			sort_stack(a, b);
		}
		else
			ft_putendl("Error");
	}
	else
	{
		ft_putendl("Error");
	}
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
