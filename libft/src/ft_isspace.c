
#include "libft.h"

int	ft_isspace(char	c)
{
	if (c == '\n' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}
