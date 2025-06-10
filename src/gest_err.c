/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:54 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/10 17:01:52 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_valid_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W' || str[i] == 9 || str[i] == 32)
			i++;
		else
			break ;
	}
	if ((size_t)i == ft_strlen(str))
		return (true);
	return (false);
}

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

bool	map_closed(char **arr, int y)
{
	int	i;
	
	i = 0;
	while (arr[y + 1] != NULL)
	{
		while (arr[y][i] == 32)
			i++;
		if (arr[y][i] != '1' || arr[y][ft_strlen(arr[y]) - 1] != '1')
			return (false);
		y++;
		i = 0;
	}
	if (!is_wall(arr[y], ft_strlen(arr[y])))
		return (false);
	return (true);
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
			if (is_wall(&file[first], (last-first)))
				break ;
		}
	}
	return (i);
}

bool	is_double_player(char *str)
{
	int		i;
	int	check;

	i = ret_map_index(str);
	check = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			check++;
		else if (check > 1)
			return (true);
		i++;
	}
	return (false);
}

int	*player_pos(char **arr)
{
	int	*pos;
	int	y;
	int	x;

	y = 0;
	x = 0;
	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	pos[0] = 0;
	pos[1] = 0;
	while (arr[y])
	{
		while (arr[y][x])
		{
			if (arr[y][x] == 'N' || arr[y][x] == 'S' 
					|| arr[y][x] == 'E' || arr[y][x] == 'W') {
				pos[0] = x;
				pos[1] = y;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

bool	is_mult_lines(char *file)
{
	int		i;

	i = ret_map_index(file);
	while (file[i])
	{
		if (file[i] == '\n') 
		{
			i++;
			while (file[i] == 32)
				i++;
			if (file[i] != '\n')
				continue ;
			else
				return (true);
		}
		i++;
	}
	return (false);
}

bool	is_error(char *file)
{
	char	**arr;
	int		y;

	if (is_mult_lines(file))
		return (fd_putstr("Error\nMultiples lines in map\n", 2), true);
	arr = str2arr(file, "\n");
	if (!arr)
		return (true);
	y = ret_map_line(arr);
	if (y < 0)
		return (fd_putstr("Error\nThe map is missing or invalid\n", 2), true);
	if (!valid_id(arr, y))
		return (true);
	if (!map_closed(arr, y))
		return (fd_putstr("Error\nThe map is not closed\n", 2), true);
	return (false);
}
