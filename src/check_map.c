/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:51 by ihibti            #+#    #+#             */
/*   Updated: 2024/03/19 13:15:24 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**mapping(int fd)
{
	char	*map;
	char	*temp;
	char	*str;
	int		flag;
	char	**ret;

	map = malloc(1);
	map[0] = 0;
	flag = 0;
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	temp = map;
	while (flag == 0)
	{
		map = ft_strjoin(map, str);
		free_args(temp, str);
		temp = map;
		str = get_next_line(fd);
		if (str == NULL)
			flag = 1;
	}
	ret = ft_split(map, '\n');
	free_args(map, str);
	return (ret);
}

int	check_map(char **map)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	if (!map)
		return (-1);
	i = ft_strlen(map[0]);
	while (map[j])
	{
		k = 0;
		while (map[j][k])
		{
			if (char_map(map[j][k]) == 0)
				return (free_error(map), -1);
			k++;
		}
		if (k != i)
			return (free_error(map), -1);
		j++;
	}
	if (side_map(map) == -1 || path_ok(map) == -1)
		return (-1);
	return (0);
}

int	char_map(char c)
{
	if (c == '1')
		return (1);
	if (c == 'P')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'C')
		return (1);
	return (0);
}

int	side_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j++] != '1')
			return (-1);
	}
	while (map[i])
	{
		if (map[i][0] != '1')
			return (-1);
		if (map[i][ft_strlen(map[0]) - 1] != '1')
			return (-1);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j++] != '1')
			return (-1);
	}
	return (0);
}
