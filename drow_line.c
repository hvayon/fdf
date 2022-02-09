/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:40 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/09 21:50:19 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)

void	isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
    *y = (*x + *y) * sin(data->angle) - z;
}

void	drow_line(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->matrix[(int)y][(int)x].z;
	z1 = data->matrix[(int)y1][(int)x1].z;
	
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom/5;
	z1 *= data->zoom/5;

	if ((z > 0) || (z1 > 0))
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;

if (data->flag != 1)
{
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
}

	x += data->x_shift;
	y += data->y_shift;
	x1 += data->x_shift;
	y1 += data->y_shift;
	
	x_step = x1 - x;
	y_step = y1 - y;

	max = MAX((float)fabs(x_step), (float)fabs(y_step));
	
	x_step /= max;
	y_step /= max;
	
	
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	drow(fdf *data)
{
	int x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				drow_line(x, y, x + 1, y, data);
			if (y < data->height - 1)
				drow_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
			
}