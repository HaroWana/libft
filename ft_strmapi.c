#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	l = 0;
	while (s[l])
		l++;
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < l)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
