/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:23:56 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/25 21:45:22 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_range(long res, int nominate)
{
	if (res >= -2147483648 && res <= 2147483647)
		return ((int)res);
	else if (nominate == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		nominate;
	long	res;

	nominate = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i = i + 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nominate = nominate * -1;
		i = i + 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + nominate * (str[i] - '0');
		i++;
	}
	return (ft_handle_range(res, nominate));
}
