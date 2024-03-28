#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = b;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (b);
}