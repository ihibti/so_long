/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:30 by ihibti            #+#    #+#             */
/*   Updated: 2024/03/14 09:47:39 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ye
#include "../so_long.h"

int	terminate(t_ori *ori)
{
	mlx_destroy_image(ori->mlx_ptr, ori->img_char);
	mlx_destroy_image(ori->mlx_ptr, ori->img_coin);
	mlx_destroy_image(ori->mlx_ptr, ori->img_end);
	mlx_destroy_image(ori->mlx_ptr, ori->img_floor);
	mlx_destroy_image(ori->mlx_ptr, ori->img_limit);
	mlx_destroy_image(ori->mlx_ptr, ori->img_terminate);
	mlx_destroy_window(ori->mlx_ptr, ori->win);
	mlx_destroy_display(ori->mlx_ptr);
	free_error(ori->map);
	free(ori->mlx_ptr);
	if (ori->is_over == 1)
		ft_printf("score final %d GG !\n", ori->count);
	exit(0);
	return (0);
}

int	han_inp(int key, t_ori *ori)
{
	int	h;

	h = 64;
	if (key == 65307)
		terminate(ori);
	if (key == 'a')
		move_guts_x(ori, -1);
	if (key == 'd')
		move_guts_x(ori, 1);
	if (key == 'w')
		move_guts_y(ori, -1);
	if (key == 's')
		move_guts_y(ori, 1);
	if (count_c(ori->map) == 0)
	{
		mlx_destroy_image(ori->mlx_ptr, ori->img_end);
		ori->img_end = mlx_xpm_file_to_image(ori->mlx_ptr,
				"img/casca_on_grass.xpm", &h, &h);
	}
	return (0);
}

void	printmap(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	move_guts_x(t_ori *ori, int move)
{
	int	x;
	int	y;

	x = find_x(ori->map, 'P');
	y = find_y(ori->map, 'P');
	if (ori->is_over == 1)
		return (0);
	if (ori->map[y][x + move] == '1')
		return (0);
	if (ori->map[y][x + move] == 'E')
	{
		if (count_c(ori->map) == 0)
			ori->is_over = 1;
		return (0);
	}
	ori->count += 1;
	ft_printf("%d\n", ori->count);
	ori->map[y][x + move] = 'P';
	ori->map[y][x] = '0';
	return (0);
}

int	move_guts_y(t_ori *ori, int move)
{
	int	x;
	int	y;

	x = find_x(ori->map, 'P');
	y = find_y(ori->map, 'P');
	if (ori->is_over == 1)
		return (0);
	if (ori->map[y + move][x] == '1')
		return (0);
	if (ori->map[y + move][x] == 'E')
	{
		if (count_c(ori->map) == 0)
			ori->is_over = 1;
		return (0);
	}
	ori->count = ori->count + 1;
	ori->map[y + move][x] = 'P';
	ori->map[y][x] = '0';
	ft_printf("%d\n", ori->count);
	return (0);
}
