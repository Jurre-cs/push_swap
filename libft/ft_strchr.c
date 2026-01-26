/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/08 12:33:36 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/27 13:40:13 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	if (c < 0)
		return (NULL);
	while (s1[i] != (char)c)
	{
		if (s1[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s1[i]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "idkhatto\0type";
// 	printf("%s", ft_strchr(s, '\0'));
// }
