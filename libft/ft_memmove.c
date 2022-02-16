/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:39:09 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/25 21:51:01 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *scr, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*secr;

	dest = (unsigned char *)dst;
	secr = (unsigned char *)scr;
	if (!dst && !scr)
		return (dst);
	i = 0;
	if (dest > secr)
	{
		while (len-- > 0)
			dest[len] = secr[len];
	}
	else
	{
		while (len > i)
		{
			dest[i] = secr[i];
			i++;
		}
	}
	return (dst);
}
