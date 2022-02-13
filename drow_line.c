/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:40 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/13 20:41:30 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	convert_color(char *color_name)
{
	int		num;
	int		i;
	int		j;
	int		len;
	char	*arg;

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
				break ;
			j++;
		}
		num += j * pow(16, len);
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

void	get_zoom(float *arg, t_fdf *data, int *z, int *z1)
{
	arg[0] *= data->zoom;
	arg[1] *= data->zoom;
	arg[2] *= data->zoom;
	arg[3] *= data->zoom;
	*z *= data->zoom / 2;
	*z1 *= data->zoom / 2;
}

void	choose_color(float *arg, t_fdf *data)
{
	if (data->flag_color % 2 != 0)
		data->color = 0xffbf00;
	else
		data->color = data->matrix[(int)arg[1]][(int)arg[0]].color;
	
}

void	choose_isometric(float *arg, t_fdf *data, int *z, int *z1)
{
	if (data->flag != 1)
	{
		isometric(&arg[0], &arg[1], *z, data);
		isometric(&arg[2], &arg[3], *z1, data);
	}
}

void	data_shift(float *arg, t_fdf *data)
{
	arg[0] += data->x_shift;
	arg[1] += data->y_shift;
	arg[2] += data->x_shift;
	arg[3] += data->y_shift;
}

void	drow_line(float *arg, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->matrix[(int)arg[1]][(int)arg[0]].z;
	z1 = data->matrix[(int)arg[3]][(int)arg[2]].z;
	choose_color(arg, data);
	get_zoom(arg, data, &z, &z1);
	choose_isometric(arg, data, &z, &z1);
	data_shift(arg, data);
	
	x_step = arg[2] - arg[0];
	y_step = arg[3] - arg[1];

	max = ft_max((float)fabs(x_step), (float)fabs(y_step));

	x_step /= max;
	y_step /= max;
	
	
	while((int)(arg[0] - arg[2]) || (int)(arg[1] - arg[3]))
	{
		
		if (arg[0] < 1000 && arg[0] > 0 && arg[1] < 1000 && arg[1] > 0)
			my_mlx_pixel_put(data, arg[0], arg[1], data->color);
		arg[0] += x_step;
		arg[1] += y_step;
	}
}

float	*make_arg(float a, float b, float c, float d)
{
	float *arg;

	arg = (float *)malloc(sizeof(float) * 4);
	arg[0] = a;
	arg[1] = b;
	arg[2] = c;
	arg[3] = d;
	return (arg);
}

void	drow(t_fdf *data)
{
	int x;
	int	y;
	float *arg;

	y = 0;
	ft_memset((int *)data->addr, 0x000000,
		1000 * 1000 * (data->bits_per_pixel / 8));
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				arg = make_arg(x, y, x + 1, y);
				drow_line(arg, data);
				free(arg);
			}
			if (y < data->height - 1)
			{
				arg = make_arg(x, y, x, y + 1);
				drow_line(arg, data);
				free(arg);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}