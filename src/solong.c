#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "solong.h"

static void	change_sprite(char *file1, char *file2, t_alldata *all)
{
	int			xpm_height;
	int			xpm_width;
	static int	count = 0;

	if (count == 0)
	{
		all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, file1, &xpm_height, &xpm_width);
		count = 1;
	}
	else if (count == 1)
	{
		all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, file2, &xpm_height, &xpm_width);
		count = 0;
	}
	return ;
}

int             key_hook(int keycode, t_alldata *all)
{
    printf("Hello, this is key: %i\n", keycode);
	if (keycode == 13)
	{
		all->vert_move -= 32;
		change_sprite("../sprites/sprites/char_up1.xpm", "../sprites/sprites/char_up2.xpm", all);
	}
	if (keycode == 1)
	{
		all->vert_move += 32;
		change_sprite("../sprites/sprites/char_down1.xpm", "../sprites/sprites/char_down2.xpm", all);
	}
	if (keycode == 0)
	{
		all->hor_move -= 32;
		change_sprite("../sprites/sprites/char_left1.xpm", "../sprites/sprites/char_left2.xpm", all);
	}
	if (keycode == 2)
	{
		all->hor_move += 32;
		change_sprite("../sprites/sprites/char_right1.xpm", "../sprites/sprites/char_right2.xpm", all);
	}
	return (0);
}

int	render_next_frame(t_alldata *all)
{
	int i;
	int j;
	int xpm_height;
	int xpm_width;

	i = 0;
	mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->img.img, 0, 0);
	all->sprites.background = mlx_xpm_file_to_image(all->mlxwin.mlx, "../sprites/sprites/background.xpm", &xpm_height, &xpm_width);
	all->sprites.wall = mlx_xpm_file_to_image(all->mlxwin.mlx, "../sprites/sprites/wall_block2.xpm", &xpm_height, &xpm_width);
	while (i < all->v_size)
	{
		j = 0;
		while (j < all->h_size)
		{
			mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.background, j, i);
			mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.main_char, all->hor_move, all->vert_move);
			if (i == 0 || j == 0 || j == all->h_size - xpm_width || i == all->v_size - xpm_height)
				mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->sprites.wall, j, i);
			j += (xpm_width);
		}
		i += (xpm_height);
	}
	//mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, background, 0, 0);
	return (0);
}

int	main(void)
{
	t_alldata *all;
	int xpm_height;
	int xpm_width;

	all = malloc(sizeof(t_alldata));
	all->h_size = 6 * 32;
	all->v_size = 6 * 32;
	all->hor_move = 32 * 4;
	all->vert_move = 32 * 4;

	all->mlxwin.mlx = mlx_init();
	all->mlxwin.win = mlx_new_window(all->mlxwin.mlx, all->h_size, all->v_size, "Hello world!");
    all->img.img = mlx_new_image(all->mlxwin.mlx, all->h_size, all->v_size);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
                                 &all->img.endian);

	all->color = create_trgb(0, 0, 0, 0);
	all->sprites.main_char = mlx_xpm_file_to_image(all->mlxwin.mlx, "../sprites/sprites/char_downstop.xpm", &xpm_height, &xpm_width);

	// loop that keeps rendering the next frame
	mlx_loop_hook(all->mlxwin.mlx, render_next_frame, all);
	// loop that listens to key press events
	mlx_key_hook(all->mlxwin.win, key_hook, all);
	//mlx_put_image_to_window(all->mlxwin.mlx, all->mlxwin.win, all->img.img, 0, 0);
	mlx_loop(all->mlxwin.mlx);
	return (0);
}
