#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*s;
	char			*d;

	if (!dst && !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > i)
			d[n] = s[n];
	}
	return (dst);
}