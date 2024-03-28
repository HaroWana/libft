#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (haystack[i + j] && needle[j]
			&& haystack[i + j] == needle[j] && i + j < n)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}