/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:54 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/05 09:06:18 by redrouic         ###   ########.fr       */
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

bool	is_wall(char *str)
{
	int	x;
	int	i;

	x = ft_strlen(str) - 1;
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
		if (check_valid_line(arr[y]) && ret == -1 && is_wall(arr[y]))
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
	if (!is_wall(arr[y]))
		return (false);
	return (true);
}

static int is_valid_rgb(const char *str)
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

/*
void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])	
	{
		printf("arr[%d]: %s\n", i, arr[i]);
		i++;
	}
}
*/

bool	is_error(char *file)
{
	char	**arr;
	int		y;

	arr = str2arr(file, "\n");
	if (!arr)
		return (true);
	y = ret_map_line(arr);
	if (y < 0)
		return (fd_putstr("Error\nThe map is missing or invalid\n", 2), true);
//	print_arr(arr);
	if (!valid_id(arr, y))
		return (true);
	if (!map_closed(arr, y))
		return (fd_putstr("Error\nThe map is not closed\n", 2), true);
	return (false);
}
