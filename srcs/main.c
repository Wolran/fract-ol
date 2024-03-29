
#include "fractol.h"

void	update_fractal_c(t_canvas *canvas)
{
	int				x;
	int				y;
	double			mouse_re;
	double			mouse_im;
	t_complex_info	*c_info;

	c_info = &canvas->comp_info;
	mlx_mouse_get_pos(canvas->mlx, canvas->win, &x, &y);
	mouse_re = (double)x / (WIN_WIDTH / (c_info->max.re - c_info->min.re))
		+ c_info->min.re;
	mouse_im = (double)y / (WIN_HEIGHT / (c_info->max.im - c_info->min.im)) * -1
		+ c_info->max.im;
	c_info->c.re = mouse_re;
	c_info->c.im = mouse_im;
}

int	main_loop(t_canvas *canvas)
{
	canvas->ticks++;
	if (canvas->is_pressed_mouse_left)
		update_fractal_c(canvas);
	if ((canvas->ticks & 8) != 0)
		return (0);
	if (canvas->fractal_type == '0' || canvas->fractal_type == '2')
		plot_mandelbrot_and_burningship(canvas);
	else if (canvas->fractal_type == '1')
		plot_julia(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_canvas	canvas;

	if (argc != 2 || (!(argv[1][0] == '0' || argv[1][0] == '1'
		|| argv[1][0] == '2') || argv[1][1] != '\0'))
	{
		ft_putstr_fd(INVALID_ARG_MSG, STDOUT_FILENO);
		return (1);
	}
	canvas.fractal_type = argv[1][0];
	init_canvas(&canvas);
	mlx_hook(canvas.win, ClientMessage, 1L << 17, exit_canvas, &canvas);
	mlx_hook(canvas.win, KeyPress, KeyPressMask, key_press_hook, &canvas);
	mlx_mouse_hook(canvas.win, mouse_press_hook, &canvas);
	mlx_hook(canvas.win, ButtonRelease, ButtonReleaseMask, mouse_release_hook,
		&canvas);
	mlx_loop_hook(canvas.mlx, &main_loop, &canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
