#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start))
		new = (char *)malloc(sizeof(*s) * (ft_strlen(s + start) + 1));
	else
		new = (char *)malloc(sizeof(*s) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}
