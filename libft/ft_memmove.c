/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 09:49:36 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/06 16:24:05 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if ((!dest && !src) || (dest == src))
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	if (p_src < p_dest)
	{
		while (n-- > 0)
			p_dest[n] = p_src[n];
	}
	else
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
