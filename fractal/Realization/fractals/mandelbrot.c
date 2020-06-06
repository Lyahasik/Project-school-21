/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:06:10 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/06 18:47:53 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		pixel_mandelbrot(t_fractal *fractal, float x, float y, char win)
{
	float	cx;
	float	cy;
	float	temp;
	int		i;

	win = 0;
	i = -1;
	cx = (x / fractal->block_w - fractal->sx) * fractal->size - fractal->dx;
	cy = (fractal->sy - y / fractal->block_h) * fractal->size + fractal->dy;
	x = 0;
	y = 0;
	while ((temp = x * x + y * y) <= 4 && ++i < fractal->it)
	{
		temp = x * x - y * y + cx;
		y = 2 * x * y + cy;
		x = temp;
	}
	if (temp > 4)
		return (color(fractal, (i < 1) ? 1 : i));
	return (0x99FF99);
}

void	out_mandelbrot(t_system *mlx, t_fractal *fractal)
{
	int	x;
	int	y;

	clear_window(mlx);
	ft_bzero(mlx->re_img, sizeof(int) * (F_W * F_H));
	y = -1;
	while (++y < F_H)
	{
		x = -1;
		{
			while (++x < F_W)
				mlx->re_img[y * F_W + x] = pixel_mandelbrot(fractal, x, y, 'F');
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, M_H + 1);
}

void	create_mandelbrot(t_fractal *fractal, int width, int height)
{
	fractal->block_w = width / 3;
	fractal->block_h = height / 2;
	fractal->size = 1;
	fractal->sx = 2;
	fractal->sy = 1;
	fractal->dx = 0;
	fractal->dy = 0;
	fractal->it = 30;
	fractal->psych = 0;
	fractal->color.rgba = 0x00FFFF;
}
