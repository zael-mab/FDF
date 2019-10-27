/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:24:55 by zael-mab          #+#    #+#             */
/*   Updated: 2019/10/27 10:36:20 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "mlx.h"
# include "../srcs/get_next_line/get_next_line.h"
# include <math.h>

typedef struct	s_fdf
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**splited;
}				t_fdf;

typedef struct	s_bonus
{
	int		projection;
	double	zoom;
	double	left;
	double	right;
	double	up;
	double	down;
	double	h;
	int		windowx;
	int		windowy;
	int		color;
	int		color1;
}				t_bonus;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		**tbl;
	int		nbl;
	int		nbc;
	int		first_nbc;
	t_bonus bonus;
}				t_mlx;

typedef	struct	s_draw_line
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xincr;
	int		yincr;
	int		error;
	int		i;
	int		diffx;
	int		diffy;
}				t_draw_line;

typedef	struct	s_coords
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_coords;

typedef	struct	s_draw
{
	int		i_index;
	int		j_index;
	int		f_x;
	int		f_y;
	int		s_x;
	int		s_y;
	int		t_x;
	int		t_y;
	int		adjust[2];
}				t_draw;

void			draw_line(t_mlx *mlx, t_coords coords, int color);
int				keyhooks(int key, t_mlx *mlx);
void			draw(t_mlx *mlx);
void			get_pos_z(t_mlx *mlx, t_fdf *fdf, char *s);
void			free_tab(void **tab, int nb);
void			suit_free(int **tbl);
void			mlx_put_string(t_mlx *mlx);
void			check_error(t_fdf *fdf);

#endif
