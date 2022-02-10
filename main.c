/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:15:54 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/10 22:48:02 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(fdf *data)
{
	int i;
	int j;
	i = 0;
	while (i <= data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

int		deal_key(int key, fdf *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (key == 124) //
		data->x_shift += 5; // translate
	else if (key == 125)
		data->y_shift += 5;
	else if (key == 123)
		data->x_shift -= 5;
	else if (key == 126)
		data->y_shift -= 5;
	else if (key == 24) // zoom
		data->zoom += 5;
	else if (key == 27)
		data->zoom -= 5;
	else if (key == 35) // size/front
		data->flag = 1;
	else if (key == 31)
		data->flag = 0;
	else if (key == 15)
		data->angle += 0.1;
	else if (key == 17)
		data->angle -= 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drow(data);
	return (0);
}



int main(int argc, char **argv)
{
	fdf *data;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->angle = 0.8;
	
	data->y_shift = 500;
	data->x_shift = 500;

	drow(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	//printf("%d", convert_color("0x802020"));
	// int i = 0;
	// int j = 0;
	// while (i < data->height)
	// {
	// 	j = 0;
	// 	while (j < data->width)
	// 	{
	// 			printf("%10d ", data->matrix[i][j].color);
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	// ft_free_map(data);
	// free(data);
}
