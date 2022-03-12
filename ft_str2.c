#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
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
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = ft_strlen(dst);
	len = ft_strlen(src) + j;
	if (dstsize < 1)
		return (len);
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
		if (j == dstsize - 1)
			break;
	}
	dst[j] = '\0';
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int    len;
	unsigned int    i;

	while (src[len] != '\0')
		len++;
	i = 0;
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		if (i == dstsize - 1)
			break;
	}
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
