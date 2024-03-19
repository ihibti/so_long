/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:48 by ihibti            #+#    #+#             */
/*   Updated: 2024/02/16 18:22:06 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	y_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[0][i])
		i++;
	return (i);
}

int	free_path(char **map, t_count *ret, t_point *dep)
{
	free_error(map);
	free(ret);
	free(dep);
	return (-1);
}

int	path_ok(char **map)
{
	int		x;
	int		y;
	t_count	*ret;
	t_point	*depart;

	depart = start_p(map);
	if (!depart)
		return (-1);
	x = depart->x;
	y = depart->y;
	ret = malloc(sizeof(t_count));
	ret->c = 0;
	ret->e = 0;
	ret->max_x = ft_strlen(map[0]);
	ret->max_y = y_map(map);
	spread(map, ret, x, y);
	free_error(map);
	map = mapping(open("map.ber", O_RDONLY));
	if (ret->c != count_c(map))
		return (free_path(map, ret, depart));
	if (ret->e != count_e(map))
		return (free_path(map, ret, depart));
	free_path(map, ret, depart);
	return (0);
}

int	visit_p(char **map, int x, int y, t_count *count)
{
	if (map[x][y] == 'v')
		return (-1);
	if (map[x][y] == '1')
		return (1);
	if (map[x][y] == 'E')
	{
		count->e = count->e + 1;
		map[x][y] = 1;
		return (1);
	}
	if (map[x][y] == 'C')
		count->c = count->c + 1;
	map[x][y] = 'v';
	return (0);
}

int	spread(char **map, t_count *count, int x, int y)
{
	if (visit_p(map, x, y, count) != 0)
		return (-1);
	if ((x + 1) <= count->max_x)
		spread(map, count, x + 1, y);
	if ((y + 1) <= count->max_y)
		spread(map, count, x, y + 1);
	if ((x - 1) >= 0)
		spread(map, count, x - 1, y);
	if ((y - 1) >= 0)
		spread(map, count, x, y - 1);
	return (0);
}
