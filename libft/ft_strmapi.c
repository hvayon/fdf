/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:25:26 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/25 22:05:28 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	i = -1;
	while (res[++i])
		res[i] = f(i, res[i]);
	return (res);
}
