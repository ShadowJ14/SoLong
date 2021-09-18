/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:31:49 by lprates           #+#    #+#             */
/*   Updated: 2021/09/18 15:18:57 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line.h"
# include "mlx.h"
# define WALL "./sprites/wall_block2.xpm"
# define BACKGROUND "./sprites/background.xpm"
# define CHAR_UP1 "./sprites/char_up1.xpm"
# define CHAR_UP2 "./sprites/char_up2.xpm"
# define CHAR_DOWN1 "./sprites/char_down1.xpm"
# define CHAR_DOWN2 "./sprites/char_down2.xpm"
# define CHAR_LEFT1 "./sprites/char_left1.xpm"
# define CHAR_LEFT2 "./sprites/char_left2.xpm"
# define CHAR_RIGHT1 "./sprites/char_right1.xpm"
# define CHAR_RIGHT2 "./sprites/char_right2.xpm"
# define CHAR_START "./sprites/char_downstop.xpm"
# define END_SPRITE "./sprites/portal.xpm"
# define COLLECT "./sprites/ice-cream.xpm"
# define ELEMENTS "1CEP"
# define END_MESSAGE "Congraturation! This story is Happy End! Thank You.\n"
# define W 13
# define S 1
# define A 0
# define D 2
# define MLX_PTR all->mlxwin.mlx
# define WIN_PTR all->mlxwin.win
# define PUT_IMG_TO_WIN mlx_put_image_to_window
# define XPM_TO_IMG mlx_xpm_file_to_image

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_sprites
{
	void	*ground;
	void	*wall;
	void	*guy;
	void	*collect;
	void	*end_portal;
}				t_sprites;

typedef struct	s_element
{
	char	type;
	int		posx;
	int		posy;
}				t_element;

typedef struct	s_alldata{
	t_vars		mlxwin;
	t_data		img;
	int			color;
	int			v_size;
	int 		h_size;
	int			guy_y;
	int			guy_x;
	t_sprites	sprites;
	char		**map;
	t_element	*element;
	int			collectibles;
	char		*mov;
	int			end;
}				t_alldata;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(double distance, int color);
int		get_oposite(int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		check_filename_ext(const char *filename, const char *ext);

// solong
void	change_sprite(char *file1, char *file2, t_alldata *all);

// error hadling
void	error_handler(int error);

// aux
int		parse_map(t_alldata *all, int fd);

// init
void	ft_handle_args(t_alldata *all, int argc, char *argv);
void	ft_init(t_alldata *all);
void	ft_repeat_init(t_alldata *all);

// map
void	put_elements(t_alldata *all, int x, int y);

// elements
int	char_colision(t_alldata *all, int count);
void	free_elements(t_alldata *all);

// collision
int	char_colision(t_alldata *all, int count);

// sprites
void	change_sprite(char *file1, char *file2, t_alldata *all);
void	hor_char_sprite(char *file1, char *file2, int mov, t_alldata *all);
void	vert_char_sprite(char *file1, char *file2, int mov, t_alldata *all);

#endif