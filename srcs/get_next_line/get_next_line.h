/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:53:19 by zael-mab          #+#    #+#             */
/*   Updated: 2019/06/18 02:37:54 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 32
# define CON_ST 4846

int			get_next_line(int fd, char **line);

#endif
