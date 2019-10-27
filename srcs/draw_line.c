/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:32:56 by zael-mab          #+#    #+#             */
/*   Updated: 2019/10/27 10:32:59 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			first_cond(t_mlx *mlx, int color, t_draw_line dl)
{
	if (dl.dx > dl.dy)
	{
		dl.i = 0;
		dl.error = dl.dx / 2;
		while (dl.i < dl.dx)
		{
			dl.x += dl.xincr;
			dl.error += dl.dy;
			if (dl.error > dl.dx)
			{
				dl.error -= dl.dx;
				dl.y += dl.yincr;
			}
			mlx_pixel_put(mlx->ptr, mlx->win, dl.x, dl.y, color);
			(dl.i)++;
		}
	}
}

void			second_cond(t_mlx *mlx, int color,
		t_draw_line dl)
{
	if (dl.dx < dl.dy)
	{
		dl.i = 0;
		dl.error = dl.dy / 2;
		while (dl.i < dl.dy)
		{
			dl.y += dl.yincr;
			dl.error += dl.dx;
			if (dl.error > dl.dy)
			{
				dl.error -= dl.dy;
				dl.x += dl.xincr;
			}
			mlx_pixel_put(mlx->ptr, mlx->win, dl.x, dl.y, color);
			(dl.i)++;
		}
	}
}

void			draw_line(t_mlx *mlx, t_coords coords, int color)
{
	t_draw_line		dl;

	dl.dx = abs(coords.x2 - coords.x1);
	dl.dy = abs(coords.y2 - coords.y1);
	if (coords.x1 < coords.x2)
		dl.xincr = 1;
	else
		dl.xincr = -1;
	if (coords.y1 < coords.y2)
		dl.yincr = 1;
	else
		dl.yincr = -1;
	dl.x = coords.x1;
	dl.y = coords.y1;
	first_cond(mlx, color, dl);
	second_cond(mlx, color, dl);
}
