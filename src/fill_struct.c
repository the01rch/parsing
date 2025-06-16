/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:32:50 by kpires            #+#    #+#             */
/*   Updated: 2025/06/16 11:28:04 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_dimensions(t_game *game)
{
	int		y;
	int		x;
	int		max;

	y = 0;
	x = 0;
	max = 0;
	while (game->map.map[y])
	{
		while (game->map.map[y][x])
		{
			x++;
			if (max == 0)
				max = x;
			else if (x > max)
				max = x;
		}
		y++;
	}
	game->map.height = y;
	game->map.width = x;
	printf("height : %d\n, width : %d\n", game->map.height, game->map.width);
	return ;
}
