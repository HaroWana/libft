#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	char		*ptr;

	ptr = b;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char		*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char		*s;
	char		*d;

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
		while (n > i)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dst);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && str1[i] == str2[i] && str1[i] != '\0' 
			&& str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}