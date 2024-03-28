#include "../libft.h"

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
