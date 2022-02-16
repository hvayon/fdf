/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:14:35 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/14 22:08:36 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *scr, size_t n)
{
	unsigned char	*str;
	unsigned char	*rst;

	str = (unsigned char *)dst;
	rst = (unsigned char *)scr;
	if (!scr && !dst)
		return (dst);
	while (n--)
		*str++ = *rst++;
	return (dst);
}
