/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:33:07 by zael-mab          #+#    #+#             */
/*   Updated: 2019/10/27 01:22:09 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

void		check_error(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (fdf->splited[++i])
	{
		if (ft_atoi(fdf->splited[i]) == 0)
		{
			j = -1;
			while (fdf->splited[i][++j])
				if (!(ft_isdigit(fdf->splited[i][j])) &&
						fdf->splited[i][j] != '-')
				{
					ft_putstr_fd("error no numbers\n", 2);
					exit(1);
				}
		}
	}
}
