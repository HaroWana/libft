#include "libft.h" 

static int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{	
		if (n == -2147483648)
		{
			len += 2;
			n /= -10;
		}
		else
		{
			len++;
			n *= -1;
		}
	}
	else if (n == 0)
		len = 1;
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	nbr;

	len = ft_count_digits(n);
	str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nbr = n * -1;
		str[0] = '-';
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}