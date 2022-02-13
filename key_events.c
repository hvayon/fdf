/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:36:01 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/13 20:37:19 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_translate(int key, t_fdf *data)
{
	if (key == 124)
		data->x_shift += 5;
	else if (key == 125)
		data->y_shift += 5;
	else if (key == 123)
		data->x_shift -= 5;
	else if (key == 126)
		data->y_shift -= 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
}

void	key_zoom(int key, t_fdf *data)
{
	if (key == 24)
		data->zoom += 5;
	else if (key == 27)
		data->zoom -= 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
}

void	key_projection(int key, t_fdf *data)
{
	if (key == 35)
		data->flag = 1;
	else if (key == 31)
		data->flag = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
}

void	key_rotation(int key, t_fdf *data)
{
	if (key == 15)
		data->angle += 0.1;
	else if (key == 17)
		data->angle -= 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
}

void	key_color(int key, t_fdf *data)
{
	if (key == 16)
		data->flag_color++;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
}
