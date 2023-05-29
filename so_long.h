/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:22:16 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/25 07:56:21 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

// insert empty line in map
// add 2 or more newlines at eof
// surround collectable with enemies

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "printf/ft_printf.h"

# define IMG_WIDTH 32
# define IMG_HEIGHT 32
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define ESC 65307
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define EEVEEFRONT_PATH "textures/eeveefront.xpm"
# define EEVEEBACK_PATH "textures/eeveeback.xpm"
# define EEVEELEFT_PATH "textures/eeveeleft.xpm"
# define EEVEERIGHT_PATH "textures/eeveeright.xpm"
# define BACKGROUND_PATH "textures/background.xpm"
# define WALL_PATH "textures/wall.xpm"
# define ITEMS_PATH "textures/items.xpm"
# define EXIT_PATH "textures/exit.xpm"
# define ENEMY_PATH "textures/enemy.xpm"

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		items;
	int		valid_exit;
}	t_map;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		collected;
	int		counter;
	t_img	eeveefront;
	t_img	eeveeback;
	t_img	eeveeleft;
	t_img	eeveeright;
	t_img	background;
	t_img	wall;
	t_img	items;
	t_img	exit;
	t_img	enemy;
	t_map	map;
}	t_data;

// so_long
int				ft_render_next_frame(t_data *data);
int				ft_key_hook(int keycode, t_data *data);
void			ft_init(t_data *data);
void			ft_put_background(t_data *data);
int				ft_exit(t_data *data);
void			ft_init_imgs(t_data *data);
t_img			ft_new_img(void *mlx, char *path);
void			ft_window_size(t_data *data, char **argv);
int				ft_line_len(int fd);
int				ft_line_count(int fd);
size_t			ft_strlen(char const *str);
void			ft_create_map(t_data *data);
char			*ft_strjoin(char *s1, char const *s2);
void			ft_put_player(t_data *data);
char			**ft_convert_input(int fd);
void			ft_player_move(t_data *data, char pos, int dir);
void			ft_collect(t_data *data, char pos, int dir);
void			ft_move(t_data *data, char pos, int dir);
void			ft_win(t_data *data);
int				ft_count_char(char *str, char c);
void			ft_check_content(t_data *data);
void			ft_check_borders(t_data *data);
void			ft_map_error(char *str, t_data *data);
char			*ft_get_moves(t_data *data);
void			ft_count_on_screen(t_data *data);
void			ft_freeall(t_data *data);
void			ft_free_map(t_data *data);
void			flood_fill(t_data *data);
int				check_valid_path(t_data *copy, int x, int y);
char			*ft_strdup(const char *src);
// get_next_line
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*get_next_line(int fd);
char			*ft_memcpygnl(char *stash);
char			*readtext(int fd, char *stash);
int				findnewline(char *stash);
char			*ft_strjoingnl(char *stash, char *buf);
int				ft_strlengnl(char *str);
char			*split(char *stash);
char			*ft_strcpy(char *stash, char *buf, char *str);
// ft_split
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
char			**ft_split(char const *s, char c);
// bonus
void			ft_create_map_bonus(t_data *data);
void			ft_move_bonus(t_data *data);

#endif
