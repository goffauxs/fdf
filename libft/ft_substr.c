/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:44:59 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/04/21 15:55:45 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		ret = malloc(sizeof(char));
	else if (len < s_len - start)
		ret = malloc(sizeof(char) * (len + 1));
	else
		ret = malloc(sizeof(char) * (s_len - start + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (start < s_len && s[start + i] != '\0' && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
