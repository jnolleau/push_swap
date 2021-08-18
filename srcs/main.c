/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:10:31 by julnolle          #+#    #+#             */
/*   Updated: 2021/08/18 16:20:26 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char const **av)
{
	if (!av)
		return (FALSE);
	while (*av)
	{
		if (!ft_isdigit_str(*av) || *av[0] == '\0')
			return (FALSE);
		av++;
	}
	return (TRUE);
}

int	main(int ac, char const **av)
{
	if (ac > 1)
	{
		if (ft_check_args(++av) == TRUE)
		{
			print_tab_str(av);
		}
		else
			write(1, "Error", ft_strlen("Error"));
	}
	else
	{
		write(1, "Error", ft_strlen("Error"));
	}
	write(1, "\n", 1);
	return (0);
}
