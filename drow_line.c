/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:40 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/06 20:40:17 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)

void	drow_line(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	
	x_step = x1 - x;
	y_step = y1 - y;

	max = MAX((float)fabs(x_step), (float)fabs(y_step));
	
	x_step /= max;
	y_step /= max;
	
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
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
			drow_line(x, y, x + 1, y, data);
			drow_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
			
}