/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:09:05 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/05 07:38:05 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

size_t	ft_strlen(const char *str);
void	fd_putstr(const char *str, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t new_size);
char	**str2arr(char *str, const char *sep);
bool	valid_id(char **arr, int line);
bool	is_error(char *file);
