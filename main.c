/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:15:54 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/19 17:25:52 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cross_button(void)
{
	exit (0);
}

void	ft_free_map(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void	first_init(t_fdf *data)
{
	data->zoom = 20;
	data->angle = 0.8;
	data->flag_color = 0;
	data->y_shift = 500;
	data->x_shift = 500;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		exit(0);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	first_init(data);
	drow(data);
	mlx_hook(data->win_ptr, 17, 0, ft_cross_button, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	exit(0);
}
