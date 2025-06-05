/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:46:00 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/04 20:17:43 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	valid_extension(char *filename)
{
	char	*ext;
	int		size;
	int		i;

	i = 0;
	ext = ".cub";
	size = ft_strlen(filename);
	if (size < 5)
		return (false);
	size -= 4;
	while (i < 4)
	{
		if (ext[i] != filename[size + i])
			return (false);
		i++;
	}
	return (true);
}

#ifndef ERR_MSG_H
# define ERR_MSG_H

# define USAGE	"Error\nUsage -> ./cub3d [path/to/map.cub]\n"
# define EXT	"Error\nOnly [.cub] files are expected\n"
# define OPEN	"Error\nThe file failed to open\n"
# define READ	"Error\nThe file failed to read\n"
# define ALLOC	"Error\nAllocation memory\n"

int	open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (fd_putstr(OPEN, 2), exit(1), fd);
	return (fd);
}

char	*get_buff(int fd)
{
	char	*buff;
	char	tmp;
	int		bread;
	size_t	sizeb;

	sizeb = 0;
	buff = NULL;
	while (1)
	{
		bread = read(fd, &tmp, 1);
		if (bread < 1)
			break ;
		buff = ft_realloc(buff, sizeb + 2);
		if (!buff)
			return (fd_putstr(ALLOC, 2), free(buff), close(fd), exit(1), NULL);
		buff[sizeb++] = tmp;
	}
	if (bread == -1)
		return (fd_putstr(READ, 2), free(buff), close(fd), exit(1), NULL);
	if (buff)
		buff[sizeb] = '\0';
	return (buff);
}

int	main(int ac, char **av)
{
	char	*map;

	if (ac != 2)
		return (fd_putstr(USAGE, 2), 0);
	if (!valid_extension(av[1]))
		return (fd_putstr(EXT, 2), EXIT_FAILURE);
	map = get_buff(open_file(av[1]));
	if (is_error(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

#endif
