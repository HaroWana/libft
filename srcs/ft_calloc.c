#include "../libft.h" 

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*new;

	new = (void *)malloc(nmemb * size);
	if (!(new))
		return (NULL);
	ft_bzero(new, nmemb * size);
	return (new);
}