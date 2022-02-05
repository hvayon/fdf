/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:58 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/05 18:42:55 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	int	fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return(height);
}

int		get_wight(char *file_name)
{
	int fd;
	int wight;
	char *line;
	char **arg;
	int i;

	wight = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	arg = ft_split(line, ' ');
	while(arg[i] != '\0')
	{
		i++;
		wight++;
	}
	close(fd);
	return(wight);
}

void	read_file(char *file_name, t_list *data)
{
	data->height = get_height(file_name);
	data->wight = get_wight(file_name);
}