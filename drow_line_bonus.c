/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:16:58 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/14 21:17:49 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
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
	while ((int)(arg[0] - arg[2]) || (int)(arg[1] - arg[3]))
	{
		if (arg[0] < 1000 && arg[0] > 0 && arg[1] < 1000 && arg[1] > 0)
			my_mlx_pixel_put(data, arg[0], arg[1], data->color);
		arg[0] += x_step;
		arg[1] += y_step;
	}
}
