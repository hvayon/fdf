/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:15 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/06 20:40:42 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "libft/libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include <stdio.h> // delete

typedef struct
{
	int height;
	int width;
	int **matrix; // двумерный массив
	int zoom;

	int color;

	void *mlx_ptr;
	void *win_ptr;
}			fdf;

int		read_file(char *file_name, fdf *data);
char	*get_next_line(int fd);
void	drow_line(float x, float y, float x1, float y1, fdf *data);
void	drow(fdf *data);


#endif