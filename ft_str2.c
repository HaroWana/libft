/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:11:00 by jlorber           #+#    #+#             */
/*   Updated: 2022/03/15 17:27:04 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (dst[len] && len < dstsize)
		len++;
	i = len;
	while (src[len - i] && len + 1 < dstsize)
	{
			dst[len] = src[len - i];
			len++;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new;

	len = 0;
	while (s1[len] != '\0')
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new))
		return (NULL);
	new[len] = '\0';
	while (len > 0)
	{
		new[len - 1] = s1[len - 1];
		len--;
	}
	return (new);
}
