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
		if (s[i] == sep)
		{
			sizes[k] = j;
			i++;
			k++;
			j = 0;
		}
		i++;
		j++;
	}
	return (sizes);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int	*word_sizes;
	int	i;
	int	j;
	int	k;

	new = malloc(ft_word_count(s, c) * sizeof(char *));
	word_sizes = ft_word_sizes(s, c);
	i = 0;
	j = 0;
	k = 0;
	new[j] = malloc(word_sizes[j] * sizeof(char) + 1);
	while (s[i])
	{
		if (s[i] == c)
		{
			new[j++][k] = 0;
			i++;
			k = 0;
			new[j] = malloc(word_sizes[j] * sizeof(char) + 1);
		}
		else if (s[i] != c)
			new[j][k++] = s[i++];
	}
	new[j][k] = 0;
	new[++j] = 0;
	return (new);
}
