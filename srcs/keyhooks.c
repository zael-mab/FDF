/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 04:45:57 by hseffian          #+#    #+#             */
/*   Updated: 2019/10/27 04:51:50 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_put_string(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xFF0000, "Menu");
	mlx_string_put(mlx->ptr, mlx->win, 10, 27, 0xFF00, "Projection : space");
	mlx_string_put(mlx->ptr, mlx->win, 10, 44, 0xFF00, "Zoom : Z,X");
	mlx_string_put(mlx->ptr, mlx->win, 10, 61, 0xFF00, "Height : G,H");
	mlx_string_put(mlx->ptr, mlx->win, 10, 78, 0xFF00, "Color : C,V");
}

void	move(int key, t_mlx *mlx)
{
	if (key == 124)
		mlx->bonus.right += 100;
	else if (key == 123)
		mlx->bonus.left -= 100;
	else if (key == 125)
		mlx->bonus.up += 100;
	else if (key == 126)
		mlx->bonus.down -= 100;
	else if (key == 4)
		mlx->bonus.h += 2;
	else if (key == 5)
		mlx->bonus.h -= 2;
}

int		keyhooks(int key, t_mlx *mlx)
{
	move(key, mlx);
	if (key == 53)
	{
		free_tab((void **)mlx->tbl, mlx->nbl);
		exit(0);
	}
	else if (key == 7)
		mlx->bonus.zoom += 0.1;
	else if (key == 6 && mlx->bonus.zoom > 0)
		mlx->bonus.zoom -= 0.1;
	else if (key == 49 && mlx->bonus.projection == 1)
		mlx->bonus.projection = 0;
	else if (key == 49)
		mlx->bonus.projection = 1;
	else if (key == 8)
		mlx->bonus.color += 0xFF;
	else if (key == 9)
		mlx->bonus.color1 += 0xFF;
	mlx_clear_window(mlx->ptr, mlx->win);
	draw(mlx);
	return (0);
}
