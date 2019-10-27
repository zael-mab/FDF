/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:32:43 by zael-mab          #+#    #+#             */
/*   Updated: 2019/10/27 10:32:45 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

void		isometre(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void		cond1(t_draw *draw, t_mlx *mlx, t_coords coords)
{
	if ((draw->j_index + 1) < mlx->first_nbc)
	{
		draw->s_x = 20 * (draw->j_index + 1);
		draw->s_y = 20 * draw->i_index;
		if (mlx->bonus.projection == 1)
			isometre(&draw->s_x, &draw->s_y
				, mlx->tbl[draw->i_index][draw->j_index + 1] * mlx->bonus.h);
		coords.x1 = (draw->f_x * mlx->bonus.zoom)
			+ mlx->bonus.right + mlx->bonus.left + draw->adjust[0];
		coords.y1 = (draw->f_y * mlx->bonus.zoom)
			+ mlx->bonus.up + mlx->bonus.down + draw->adjust[1];
		coords.x2 = (draw->s_x * mlx->bonus.zoom)
			+ mlx->bonus.right + mlx->bonus.left + draw->adjust[0];
		coords.y2 = (draw->s_y * mlx->bonus.zoom)
			+ mlx->bonus.up + mlx->bonus.down + draw->adjust[1];
		if (mlx->tbl[draw->i_index][draw->j_index]
				|| mlx->tbl[draw->i_index][draw->j_index + 1])
			draw_line(mlx, coords, 0x0000FF + 0x001100 * mlx->bonus.color);
		else
			draw_line(mlx, coords, 0xFF0000 + 0x001100 * mlx->bonus.color1);
	}
}

void		cond2(t_draw *draw, t_mlx *mlx, t_coords coords)
{
	if ((draw->i_index + 1) < mlx->nbl)
	{
		draw->t_x = 20 * draw->j_index;
		draw->t_y = 20 * (draw->i_index + 1);
		if (mlx->bonus.projection == 1)
			isometre(&draw->t_x, &draw->t_y
				, mlx->tbl[draw->i_index + 1][draw->j_index] * mlx->bonus.h);
		coords.x1 = (draw->f_x * mlx->bonus.zoom)
			+ mlx->bonus.right + mlx->bonus.left + draw->adjust[0];
		coords.y1 = (draw->f_y * mlx->bonus.zoom)
			+ mlx->bonus.up + mlx->bonus.down + draw->adjust[1];
		coords.x2 = (draw->t_x * mlx->bonus.zoom)
			+ mlx->bonus.right + mlx->bonus.left + draw->adjust[0];
		coords.y2 = (draw->t_y * mlx->bonus.zoom)
			+ mlx->bonus.up + mlx->bonus.down + draw->adjust[1];
		if (mlx->tbl[draw->i_index][draw->j_index]
				|| mlx->tbl[draw->i_index + 1][draw->j_index])
			draw_line(mlx, coords, 0x0000FF + 0x001100 * mlx->bonus.color);
		else
			draw_line(mlx, coords, 0xFF0000 + 0x001100 * mlx->bonus.color1);
	}
}

void		loop(t_mlx *mlx, t_draw draw, t_coords coords)
{
	draw.f_x = 20 * draw.j_index;
	draw.f_y = 20 * draw.i_index;
	if (mlx->bonus.projection == 1)
		isometre(&draw.f_x, &draw.f_y
				, mlx->tbl[draw.i_index][draw.j_index] * mlx->bonus.h);
	cond1(&draw, mlx, coords);
	cond2(&draw, mlx, coords);
}

void		draw(t_mlx *mlx)
{
	t_draw		draw;
	t_coords	coords;

	coords.x1 = 0;
	coords.x2 = 0;
	coords.y1 = 0;
	coords.y2 = 0;
	if (mlx->first_nbc <= 200)
	{
		draw.adjust[0] = mlx->first_nbc * 7;
		draw.adjust[1] = mlx->nbl * 3;
	}
	else
	{
		draw.adjust[0] = 650;
		draw.adjust[1] = 325;
	}
	draw.i_index = -1;
	while (++draw.i_index < mlx->nbl)
	{
		draw.j_index = -1;
		while (++draw.j_index < mlx->first_nbc)
			loop(mlx, draw, coords);
	}
	mlx_put_string(mlx);
}
