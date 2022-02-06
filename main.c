/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:15:54 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/06 20:40:59 by hvayon           ###   ########.fr       */
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
int		deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int main(int argc, char **argv)
{
	fdf *data;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	drow(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
	data->zoom = 20;
	
	ft_free_map(data);
	free(data);
}



// void	ft_free_map(fdf *data)
// {
// 	int i;
// 	int j;
// 	i = 0;
// 	while (i <= data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			free(data->matrix[i][j]);
// 			j++;
// 		}
// 		//free(data->matrix[i]);
// 		i++;
// 	}
// }