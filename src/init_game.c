/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:45 by ihibti            #+#    #+#             */
/*   Updated: 2024/03/19 17:42:42 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_solong(t_ori *ori)
{
	int	h;
	int	w;

	w = 64;
	h = 64;
	ori->img_char = mlx_xpm_file_to_image(ori->mlx_ptr, "img/guts_on_grass.xpm",
			&w, &h);
	ori->img_end = mlx_xpm_file_to_image(ori->mlx_ptr, "img/test.xpm", &w, &h);
	ori->img_floor = mlx_xpm_file_to_image(ori->mlx_ptr,
			"img/new_snow_floor.xpm", &w, &h);
	ori->img_limit = mlx_xpm_file_to_image(ori->mlx_ptr,
			"img/new_limit_treee1.xpm", &w, &h);
	ori->img_coin = mlx_xpm_file_to_image(ori->mlx_ptr,
			"img/behellit_on_grass.xpm", &w, &h);
	ori->img_terminate = mlx_xpm_file_to_image(ori->mlx_ptr, "img/end_love.xpm",
			&w, &h);
	if (!ori->img_char || !ori->img_end || !ori->img_floor || !ori->img_limit
		|| !ori->img_coin || !ori->img_terminate)
	{
		free_imgs(ori->img_char, ori->img_end, ori->img_floor, ori->mlx_ptr);
		free_imgs(ori->img_coin, ori->img_terminate, ori->img_limit,
			ori->mlx_ptr);
		return (0);
	}
	return (1);
}

void	dim_lim(t_ori *ori)
{
	int	i;

	i = 0;
	ori->count = 0;
	ori->max_x = ft_strlen(ori->map[0]);
	while (ori->map[i])
		i++;
	ori->max_y = i;
}

void	put_img(t_ori *ori, int x, int y)
{
	if (ori->is_over == 1)
	{
		mlx_put_image_to_window(ori->mlx_ptr, ori->win, ori->img_terminate, x
			* 64, y * 64);
		return ;
	}
	if (ori->map[y][x] == 'P')
		mlx_put_image_to_window(ori->mlx_ptr, ori->win, ori->img_char, x * 64, y
			* 64);
	else if (ori->map[y][x] == 'E')
		mlx_put_image_to_window(ori->mlx_ptr, ori->win, ori->img_end, x * 64, y
			* 64);
	else if (ori->map[y][x] == '1')
		mlx_put_image_to_window(ori->mlx_ptr, ori->win, ori->img_limit, x * 64,
			y * 64);
	else if (ori->map[y][x] == 'C')
		mlx_put_image_to_window(ori->mlx_ptr, ori->win, ori->img_coin, x * 64, y
			* 64);
	else
		mlx_put_image_to_window(ori->mlx_ptr, ori->win, ori->img_floor, x * 64,
			y * 64);
}

int	draw_win(t_ori *ori)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= ori->max_y - 1)
	{
		while (x <= ori->max_x - 1)
		{
			put_img(ori, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	free_args(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
}
