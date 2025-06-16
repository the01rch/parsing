/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:54 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/16 11:46:24 by redrouic         ###   ########.fr       */
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

bool	is_double_player(char *str)
{
	int		i;
	int		check;

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
