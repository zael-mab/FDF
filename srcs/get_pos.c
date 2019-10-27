/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:09:14 by hseffian          #+#    #+#             */
/*   Updated: 2019/10/27 10:33:29 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	first_line(char **line, t_mlx *mlx)
{
	int i;

	i = -1;
	mlx->first_nbc = 0;
	while (line[++i])
		mlx->first_nbc++;
}

void	count_word(char **line, t_mlx *mlx)
{
	int i;

	i = -1;
	mlx->nbc = 0;
	while (line[++i])
		mlx->nbc++;
}

void	count_line(char *namefile, t_mlx *mlx)
{
	int		fd;
	char	*line;
	char	**t;

	mlx->nbl = 0;
	fd = open(namefile, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (mlx->nbl == 0)
		{
			t = ft_strsplit(line, ' ');
			first_line(t, mlx);
			free_tab((void **)t, mlx->first_nbc + 1);
		}
		mlx->nbl++;
		free(line);
	}
	close(fd);
}

void	compare(t_mlx *mlx)
{
	if (mlx->nbc >= mlx->first_nbc)
		mlx->nbc = mlx->first_nbc;
	else
	{
		ft_putendl("This file is invalid.");
		exit(0);
	}
}

void	get_pos_z(t_mlx *mlx, t_fdf *fdf, char *s)
{
	count_line(s, mlx);
	if (!(mlx->tbl = (int **)malloc(sizeof(int *) * (mlx->nbl))))
		exit(0);
	fdf->fd = open(s, O_RDONLY);
	fdf->i = 0;
	while (get_next_line(fdf->fd, &fdf->line))
	{
		if (!(fdf->splited = ft_strsplit(fdf->line, ' ')))
			suit_free(mlx->tbl);
		check_error(fdf);
		count_word(fdf->splited, mlx);
		compare(mlx);
		if (!(mlx->tbl[fdf->i] = (int *)malloc(sizeof(int) * (mlx->nbc))))
			suit_free(mlx->tbl);
		fdf->j = -1;
		while (++fdf->j < mlx->nbc)
			mlx->tbl[fdf->i][fdf->j] = ft_atoi(fdf->splited[fdf->j]);
		fdf->i++;
		free_tab((void **)fdf->splited, mlx->nbc + 1);
		free(fdf->line);
	}
}
