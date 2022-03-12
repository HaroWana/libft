#include "libft.h" 

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	char		*new;

	i = 0;
	new = malloc(nmemb * size);
	if (!(new))
		return (NULL);
	while (i < nmemb)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}

int	ft_atoi(const char *nptr)
{
	int	i;
        int	nb;
        int	neg;

	neg = 1;
	i = 0;
	nb = 0;
	while (nptr[i] <= 32)
		i++;
	if (nptr[i] == 45)
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
	}
	return (nb * neg);
}

int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	char	*str;

	if (n == -2147483648)
		return ("-2147483648\0");
	len = ft_count_digits(n);
	if(!(str = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	if (n == 0)
		return ("0\0");
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len + 1] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

void	*ft_memset(void *b, int c, size_t n);

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
