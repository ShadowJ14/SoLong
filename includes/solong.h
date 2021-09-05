/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:31:49 by lprates           #+#    #+#             */
/*   Updated: 2021/09/05 19:59:41 by lprates          ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"


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

typedef struct s_sprites
{
	void *background;
	void *wall;
	void *main_char;
}				t_sprites;


typedef struct	s_alldata{
	t_vars		mlxwin;
	t_data		img;
	int			color;
	int			v_size;
	int 		h_size;
	int			vert_move;
	int			hor_move;
	t_sprites	sprites;

}				t_alldata;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(double distance, int color);
int		get_oposite(int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif