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

static uint32_t	ft_lin_col(uint32_t ca, uint32_t cb, double fac)
{
	uint32_t	col;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	r = ((ca & 0xFF0000) >> 16) * fac;
	g = ((ca & 0xFF00) >> 8) * fac;
	b = ((ca & 0xFF)) * fac;
	r += ((cb & 0xFF0000) >> 16) * (1 - fac);
	g += ((cb & 0xFF00) >> 8) * (1 - fac);
	b += ((cb & 0xFF)) * (1 - fac);
	col = convert_rgb_hex(r, g, b);
	return (col);
}

uint32_t	simple_colorizer(int iter, t_canvas *canvas)
{
	uint32_t	col;
	double		fac;

	fac = (double)iter / canvas->max_iter;
	fac = fac * 4;
	if (fac > 1)
		fac = 1;
	col = ft_lin_col(canvas->colors[canvas->sel_col],
			canvas->colors[canvas->sel_col + 1], fac);
	return (col);
}
