/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:14:39 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/14 20:14:50 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
