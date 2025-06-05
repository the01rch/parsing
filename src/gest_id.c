/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:35:29 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/05 07:35:47 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_id(char *str)
{
	if (!ft_strcmp(str, "NO") && !ft_strcmp(str, "SO")
		&& !ft_strcmp(str, "WE") && !ft_strcmp(str, "EA")
		&& !ft_strcmp(str, "F") && !ft_strcmp(str, "C"))
		return (fd_putstr("Error\nInvalid Identifier\n", 2), false);
	return (true);
}

bool	valid_id(char **arr, int line)
{
	char	**tab;
	int		y;

	y = 0;
	while (y < line)
	{
		tab = str2arr(arr[y], " \t");
		if (!is_id(tab[0]))
			return (false);
		if (!tab[1])
			return (fd_putstr("Error\nNo ID content provided\n", 2), false);
		if (tab[0] && tab[1])
			(free(tab[0]), free(tab[1]));
		tab = 0;
		y++;
	}
	return (true);
}

int	count_sep(char *tab)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	while (tab[i])
	{
		if (tab[i] == ',')
			sep++;
		i++;
	}
	return (sep);
}
