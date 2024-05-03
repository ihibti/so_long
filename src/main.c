/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:38 by ihibti            #+#    #+#             */
/*   Updated: 2024/04/26 12:08:46 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_av(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac != 2)
		return (-1);
	i = ft_strlen(av[1]);
	if (i < 5)
		return (-1);
	i = i - 4;
	if (ft_strncmp(av[1] + i, ".ber", 4) != 0)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (close(fd), -1);
	close(fd);
	return (0);
}

int	start_mlx(t_ori *ori)
{
	ori->mlx_ptr = mlx_init();
	if (ori->mlx_ptr == NULL)
		return (0);
	ori->win = mlx_new_window(ori->mlx_ptr, (ori->max_x * 64), (ori->max_y
				* 64), "so_long");
	if (ori->win == NULL)
	{
		free(ori->mlx_ptr);
		return (0);
	}
	if (init_solong(ori) == 0)
	{
		mlx_destroy_window(ori->mlx_ptr, ori->win);
		mlx_destroy_display(ori->mlx_ptr);
		free(ori->mlx_ptr);
		return (0);
	}
	mlx_loop_hook(ori->mlx_ptr, draw_win, ori);
	mlx_key_hook(ori->win, han_inp, ori);
	mlx_hook(ori->win, 17, 1, terminate, ori);
	return (1);
}

int	main(int ac, char **av)
{
	char	**map;
	t_ori	ori;

	if (check_av(ac, av) == -1)
		return (ft_printf("Error\n"), 0);
	map = mapping(open(av[1], O_RDONLY));
	if (!map)
		return (ft_printf("Error\n"), free_error(map), 0);
	if (check_map(map) == -1)
		return (printf("Error\n"), 0);
	ori.map = mapping(open(av[1], O_RDONLY));
	ori.is_over = 0;
	dim_lim(&ori);
	if (start_mlx(&ori) == 0)
	{
		free_error(ori.map);
		ft_putstr_fd("Failed to initialize mlx", 2);
		return (1);
	}
	mlx_loop(ori.mlx_ptr);
	return (0);
}

int	close_window(t_ori *ori)
{
	mlx_destroy_display(ori->mlx_ptr);
	return (1);
}

int	find_x(char **map, char c)
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
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}
