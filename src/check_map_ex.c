/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:18:15 by ihibti            #+#    #+#             */
/*   Updated: 2024/03/19 17:43:12 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_end_file(char *str, int i)
{
	while ((str[i] == '\n') && str[i])
		i++;
	if (!str[i])
		return (0);
	return (-1);
}

int	map_voids(char *str)
{
	int	i;
	int	j;
	int	norme;

	i = 0;
	j = 0;
	norme = -1;
	while (str[i] == '\n' && str[i])
		i++;
	while (str[i])
	{
		while (str[i] != '\n' && str[i])
		{
			i++;
			j++;
		}
		if ((norme > -1) && (j != norme))
			return (-1);
		norme = j;
		if (is_end_file(str, i) == 0)
			return (0);
		j = 0;
		i++;
	}
	return (0);
}

int	res_siz(char **map)
{
	int	x;
	int	y;

	x = ft_strlen(map[0]);
	y = 0;
	while (map[y])
		y++;
	if ((y * 64) > 1000)
		return (free_error(map), -1);
	if ((x * 64) > 1850)
		return (free_error(map), -1);
	return (0);
}

void	free_imgs(void *a, void *b, void *c, void *d)
{
	if (a)
		mlx_destroy_image(d, a);
	if (b)
		mlx_destroy_image(d, b);
	if (c)
		mlx_destroy_image(d, c);
}
