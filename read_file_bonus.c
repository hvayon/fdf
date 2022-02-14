/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:12:33 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/14 22:03:31 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_height(char *file_name)
{
	int	fd;
	int	height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	get_widht(char *file_name)
{
	int		fd;
	int		widht;
	char	*line;
	char	**arg;
	int		i;

	widht = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	arg = ft_split(line, ' ');
	i = 0;
	while (arg[i] != '\0')
	{
		i++;
		widht++;
	}
	free(line);
	close(fd);
	return (widht);
}

void	fill_matrix(t_matrix *z_line, char *line)
{
	char	**arg;
	char	**el;
	int		i;
	int		j;

	arg = ft_split(line, ' ');
	i = 0;
	while (arg[i])
	{
		el = ft_split(arg[i], ',');
		z_line[i].z = ft_atoi(el[0]);
		if (el[1] != NULL)
			z_line[i].color = convert_color(el[1]);
		else
			z_line[i].color = 0xffffff;
		j = 0;
		while (el[j] != NULL)
			free(el[j++]);
		free(arg[i]);
		free(el[j]);
		free(el);
		i++;
	}
	free(arg);
}

void	make_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	data->matrix = (t_matrix **)malloc(sizeof(t_matrix *) * (data->height));
	if (!data->matrix)
		exit(0);
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = (t_matrix *)malloc(sizeof(t_matrix) * (data->width));
		if (!data->matrix[i])
			exit(0);
		i++;
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_widht(file_name);
	if (data->width == 0 && data->height == 0)
		exit (0);
	make_matrix(data);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->matrix[i] = NULL;
}
// -lmlx -framework OpenGL -framework AppKit