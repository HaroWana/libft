/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:11:35 by jlorber           #+#    #+#             */
/*   Updated: 2022/03/15 13:36:56 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_char_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	end = 0;
	while (s1[start] && ft_is_char_in_set(s1[start], set))
		start++;
	while (s1[end] != '\0')
		end++;
	while (end > start && ft_is_char_in_set(s1[end - 1], set))
		end--;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	while (start < end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	l = 0;
	while (s[l])
		l++;
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < l)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
