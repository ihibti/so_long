/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:36 by ihibti            #+#    #+#             */
/*   Updated: 2024/03/19 13:48:55 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_e(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	count_c(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

t_point	*start_p(char **map)
{
	t_point	*ret;
	int		c_e;
	int		c_p;

	c_e = count_occur(map, 'E');
	c_p = count_occur(map, 'P');
	ret = malloc(sizeof(t_point));
	if (!ret)
		return (NULL);
	ret->y = find_x(map, 'P');
	ret->x = find_y(map, 'P');
	if (c_e == 1 && c_p == 1)
		return (ret);
	free(ret);
	free_error(map);
	return (NULL);
}

int	count_occur(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

int	find_y(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}
