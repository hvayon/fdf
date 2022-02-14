/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:18:25 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/14 21:54:12 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	*make_arg(float x, float y, float x1, float y1)
{
	float	*arg;

	arg = (float *)malloc(sizeof(float) * 4);
	arg[0] = x;
	arg[1] = y;
	arg[2] = x1;
	arg[3] = y1;
	return (arg);
}

void	drow_loop(int x, int y, t_fdf *data)
{
	float	*arg;

	y = 0;
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
}

void	drow(t_fdf *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_memset((int *)data->addr, 0x000000,
		1000 * 1000 * (data->bits_per_pixel / 8));
	drow_loop(x, y, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
