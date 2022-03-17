/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:10:40 by jlorber           #+#    #+#             */
/*   Updated: 2022/03/15 16:50:51 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == sep)
			j++;
		i++;
	}
	j++;
	return (j);
}

static int	*ft_word_sizes(char const *s, char sep)
{
	int	*sizes;
	int	i;
	int	j;
	int	k;

	sizes = (int *)malloc(sizeof(int) * ft_word_count(s, sep) + 1);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == sep)
		{
			sizes[k] = j + sizeof(sep);
			k++;
			j = 0;
			i++;
		}
		i++;
		j++;
	}
	return (sizes);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		*word_sizes;
	int		i;
	int		j;
	int		k;

	new = malloc(ft_word_count(s, c) * sizeof(char *) + 1);
	word_sizes = ft_word_sizes(s, c);
	i = 0;
	j = 0;
	while (s[i])
	{
		new[j] = malloc(word_sizes[j] * sizeof(char) + 1);
		k = 0;
		while (s[i] != c)
			new[j][k++] = s[i++];
		if (s[i++] == c)
			new[j++][k] = 0;
	}
	new[++j] = 0;
	return (new);
}
