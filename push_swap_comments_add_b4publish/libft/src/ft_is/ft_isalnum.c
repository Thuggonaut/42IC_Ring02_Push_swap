#include "../../inc/libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') 
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}
