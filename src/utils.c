/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:06:29 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/16 11:32:24 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(char *str, int size)
{
	int	x;
	int	i;

	x = size - 1;
	i = 0;
	while (str[x] == 32)
		x--;
	while (str[i] == 32)
		i++;
	while (str[i] && i < x)
	{
		if (str[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

size_t	ret_map_line(char **arr)
{
	int	ret;
	int	y;

	y = 0;
	ret = -1;
	while (arr[y])
	{
		if (check_valid_line(arr[y])
			&& ret == -1 && is_wall(arr[y], ft_strlen(arr[y])))
			ret = y;
		if (ret != -1)
		{
			if (!check_valid_line(arr[y]))
				return (-1);
		}
		y++;
	}
	return (ret);
}

size_t	ret_map_index(char *file)
{
	int		i;
	int		first;
	int		last;

	i = 0;
	first = 0;
	last = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			i++;
			first = i;
			while (file[i] != '\n')
				i++;
			last = i - 1;
			if (is_wall(&file[first], (last - first)))
				break ;
		}
	}
	return (i);
}
/*
bool	is_surrounded(char **map)
{
	int		y;
	int		x;
	bool	inside;

	x = 0;
	y = 0;
	inside = false;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
				inside = true;
			if (inside && map[y][x] == 32)
			{
				if ((map[y - 1][x] == '1' || map[y - 1][x] == 32)
						&& (map[y + 1][x] == '1' || map[y + 1][x] == 32))
					return (true);
				else
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
*/
