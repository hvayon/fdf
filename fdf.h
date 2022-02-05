/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:15 by hvayon            #+#    #+#             */
/*   Updated: 2022/02/05 18:31:25 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "libft/libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
	int height;
	int wight;
	int **z_mitrix; // двумерный массив

	int color;
}				t_list;

#endif