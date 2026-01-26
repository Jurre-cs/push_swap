/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 14:58:10 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/23 15:31:40 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*csrc;
	unsigned char		*cdest;
	size_t				i;

	csrc = ((const unsigned char *)src);
	cdest = ((unsigned char *)dest);
	if (!csrc && !cdest)
		return (NULL);
	if (cdest < csrc || cdest >= csrc + n)
		return (ft_memcpy(cdest, csrc, n));
	i = n;
	while (i-- > 0)
		cdest[i] = csrc[i];
	return (cdest);
}

// #include <stdio.h>

// int main(void)
// {
// 	int i = 5;
// 	char c[40] = "whatt";
// 	char s[40] = "whatttttt";
// 	// memmove(s, c + 3, i);
// 	// memcpy(s, c + 3, i);
// 	printf("%s", ft_memmove(c, "con\0sec\0\0te\0tur", 10));
// 	// printf("%s", memmove(s, "con\0sec\0\0te\0tur", 10));
// }