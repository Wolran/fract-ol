#include "fractol.h"

uint32_t	convert_rgb_hex(int r, int g, int b)
{
	uint32_t	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

uint32_t	simple_colorizer(int iter, t_canvas *canvas)
{
	int	r;
	int	g;
	int	b;

	r = (int)((double)iter / canvas->max_iter * 255);
	g = (int)((double)iter / canvas->max_iter * 0);
	b = (int)((double)iter / canvas->max_iter * 0);
	return (convert_rgb_hex(r, g, b));
}
