/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:35:29 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/16 11:57:01 by redrouic         ###   ########.fr       */
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
	char	*tmp;
	int		y;

	y = 0;
	while (y < line)
	{
		tab = str2arr(arr[y], " \t");
		if (!is_id(tab[0]))
			return (false);
		if (!tab[1])
			return (fd_putstr("Error\nNo ID content provided\n", 2), false);
		if (!ft_strcmp(tab[0], "F") && !ft_strcmp(tab[0], "C"))
			tmp = get_buff(tab[1]);
		if (tab[0] && tab[1])
			(free(tmp), free(tab[0]), free(tab[1]));
		tab = 0;
		y++;
	}
	return (true);
}

/*
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

static int	is_valid_rgb(const char *str)
{
	int	count;
	int	num;
	int	digit_found;

	count = 0;
	if (!str) 
		return (0);
	while (*str) 
	{
		num = 0;
		digit_found = 0;
		while (*str && (*str >= '0' && *str <= '9')) 
		{
			digit_found = 1;
			num = num * 10 + (*str - '0');
			if (num > 255) 
				return (0);
			str++;
		}
		if (!digit_found) 
			return (0);
		count++;
		if (count == 4) 
		{
			if (*str != '\0') 
				return (0);
			break;
		}
		if (*str != ',') 
			return (0);
		str++;
	}
	return (count == 4);
}
*/
