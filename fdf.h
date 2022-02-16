/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:15 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/16 19:37:32 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_matrix
{
	int	color;
	int	z;
}		t_matrix;

typedef struct s_fdf
{
	int			height;
	int			width;
	t_matrix	**matrix;
	int			zoom;
	int			color;
	int			flag_color;
	int			x_shift;
	int			y_shift;
	int			flag;
	float		angle;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_fdf;

void	read_file(char *file_name, t_fdf *data);
char	*get_next_line(int fd);
void	drow_line(float *arg, t_fdf *data);
void	drow(t_fdf *data);
int		convert_color(char *color_name);
void	swap_color(t_fdf *data);
int		deal_key(int key, t_fdf *data);
int		ft_max(float a, float b);
void	get_zoom(float *arg, t_fdf *data, int *z, int *z1);
void	choose_color(float *arg, t_fdf *data);
void	choose_isometric(float *arg, t_fdf *data, int *z, int *z1);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	isometric(float *x, float *y, int z, t_fdf *data);

#endif