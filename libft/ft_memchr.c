/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:39:04 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/30 18:32:17 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*stmp;
	size_t			i;

	i = 0;
	stmp = (unsigned char *)s;
	while (i < n)
	{
		if (*stmp == (unsigned char)c)
			return ((void *)stmp);
		stmp++;
		i++;
	}
	return (NULL);
}
