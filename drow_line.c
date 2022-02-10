/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:40 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/10 22:49:04 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)

void	isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
    *y = (*x + *y) * sin(data->angle) - z;
}

int		convert_color(char *color_name)
{
	int num;
	int i;
	int j;
	int len;
	char *arg;
	
	num = 0;
	len = ft_strlen(color_name) - 3;
	arg = "0123456789abcdef";
	i = 2;
	while (color_name[i] != '\0')
	{
		j = 0;
		while (arg[j] != '\0')
		{
			if (color_name[i] == arg[j] || color_name[i] == arg[j + 32])
				break;
			j++;	
		}
		num +=  j * pow(16, len);
		len--; 
		i++;
	}
	return (num);
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
	data->color = data->matrix[(int)y][(int)x].color;
	//printf("%d\n", data->color);
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom/2;
	z1 *= data->zoom/2;
	// printf("%d\n", data->matrix[(int)y][(int)x].z);
//	data->color = data->matrix[(int)y][(int)x].color;
//	data->color = convert_color(&data->color[2]);
	// if ((z > 0) || (z1 > 0))
	// 	data->color = 0xe80c0c;
	// else
	// 	data->color = 0xffffff;

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
		//printf("%d", data->color);
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