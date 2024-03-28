#include "libft.h"

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