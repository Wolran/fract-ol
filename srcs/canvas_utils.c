
#include "fractol.h"

static void	init_colors(t_canvas *canvas)
{
	canvas->colors[0] = 0xffcc00;
	canvas->colors[1] = 0xb30000;
	canvas->colors[2] = 0x00ccff;
	canvas->colors[3] = 0x0000b3;
	canvas->colors[4] = 0xffccff;
	canvas->colors[5] = 0xb300b3;
	canvas->colors[6] = 0x660066;
	canvas->colors[7] = 0x003300;
	canvas->sel_col = 0;
	canvas->ticks = 0;
}

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->win = mlx_new_window(canvas->mlx, WIN_WIDTH, WIN_HEIGHT,
			CANVAS_TITLE);
	if (canvas->win == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->img.img = mlx_new_image(canvas->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!canvas->img.img)
		exit_canvas(EXIT_FAILURE);
	canvas->img.addr = mlx_get_data_addr(
			canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.line_length,
			&canvas->img.endian);
	canvas->comp_info.max.re = 2;
	canvas->comp_info.max.im = 2;
	canvas->comp_info.min.re = -2;
	canvas->comp_info.min.im = -2;
	canvas->comp_info.c.re = 0.4;
	canvas->comp_info.c.im = -0.325;
	canvas->is_pressed_mouse_left = false;
	canvas->max_iter = MAX_ITER;
	init_colors(canvas);
}
