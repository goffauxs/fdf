/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:52:42 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/04/21 12:31:54 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] != '\0' && i <= len)
	{
		if (big[i] == little[0] && !ft_memcmp(&big[i], little, little_len))
		{
			if (i <= len - little_len)
				return ((char *)&big[i]);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
