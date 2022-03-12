/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:06:57 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/19 17:27:33 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
	return (0);
}
