#ifndef SO_LONG_H
# define SO_LONG_H

# include "X11/keysym.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_count
{
	int		e;
	int		c;
	int		max_x;
	int		max_y;
}			t_count;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_ori
{
	int		is_over;
	void	*mlx_ptr;
	void	*win;
	int		max_x;
	int		max_y;
	int		count;
	t_point	*point;
	char	**map;
	void	*img_limit;
	void	*img_char;
	void	*img_coin;
	void	*img_floor;
	void	*img_end;
	void	*img_terminate;

}			t_ori;

char		**mapping(int fd);
int			char_map(char c);
int			side_map(char **map);
int			check_map(char **map);
int			count_e(char **map);
int			count_c(char **map);
int			spread(char **map, t_count *count, int x, int y);
int			visit_p(char **map, int x, int y, t_count *count);
int			path_ok(char **map);
t_point		*start_p(char **map);
int			draw_win(t_ori *ori);
void		put_img(t_ori *ori, int x, int y);
int			init_solong(t_ori *ori);
void		dim_lim(t_ori *ori);
int			han_inp(int key, t_ori *ori);
int			move_guts_x(t_ori *ori, int move);
int			close_window(t_ori *ori);
int			move_guts_y(t_ori *ori, int move);
void		printmap(char **str);
int			terminate(t_ori *ori);
int			find_y(char **map, char c);
int			find_x(char **map, char c);
int			count_occur(char **map, char c);
void		free_args(char *str1, char *str2);
int			map_voids(char *str);
int			res_siz(char **map);
void		free_imgs(void *a, void *b, void *c, void *d);
int			v_c(char *str);

#endif