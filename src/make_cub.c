/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:25:53 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/10 14:10:46 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	find_big_line(char **arr)
{
	int		max_index;
	size_t	max_length;
	int		i;
	size_t	length;

	i = 1;
	max_index = 0;
	max_length = ft_strlen(arr[0]);
	length = ft_strlen(arr[i]);
	while (arr[i] != NULL) 
	{
		if (length > max_length)
		{
			max_length = length;
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	count_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	sep2wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32)
			str[i] = '1';
		i++;
	}
}

char	**make_cub(char **arr, int index, int size)
{
	char	**new_arr;
	int		i;

	i = 0;
	new_arr = malloc(sizeof(char *) * size + 1);
	if (!new_arr)
		return (NULL);
	while (i < size)
	{
		new_arr[i] = malloc(sizeof(char) * index + 1);
		if (!new_arr[i])
			return (NULL);
		/*
		ft_memset(new_arr[i]);
		ft_strcpy(new_arr[i], arr[i]);
		*/
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

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
				if ((map[y-1][x] == '1' || map[y-1][x] == 32) 
						&& (map[y+1][x] == '1' || map[y+1][x] == 32))
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
