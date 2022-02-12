/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:40 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/12 21:56:29 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
    *y = (*x + *y) * sin(data->angle) - z;
}

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	int_max(float a, float b)
// {
// 	int max;
// 	if (fabs(a) > fabs(b))
// 		max = (int)a;
// 	else
// 		max = (int)b;
// 	return(max);
// }

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

int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
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

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom/2;
	z1 *= data->zoom/2;


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

	max = ft_max((float)fabs(x_step), (float)fabs(y_step));

	x_step /= max;
	y_step /= max;
	
	
	while((int)(x - x1) || (int)(y - y1))
	{
		
		if (x < 1000 && x > 0 && y < 1000 && y > 0)
			my_mlx_pixel_put(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	drow(fdf *data)
{
	int x;
	int	y;

	y = 0;
	ft_memset((int *)data->addr, 0x000000,
		1000 * 1000 * (data->bits_per_pixel / 8));
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}