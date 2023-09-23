#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s, len);
	return (dst);
}
