#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;
	
	i = 0;
	j= 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 0;
		i++;
		j++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else if (i == j)
		return (NULL);
	return ((char *)&s[i - j]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
			if (haystack[i] != needle[j])
				j = 0;
		}
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int    i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!(new))
		return (NULL);
	while (len > i || s[start] != '\0')
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
