#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	neg;

	neg = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
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