/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 13:52:47 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/27 14:29:52 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
		return (0);
	while (n > 0)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
// 	int i = 5;
// 	char c[40] = "what?";
// 	char s[40] = ";ja;fkjzbvlbiawe";
// 	ft_memcpy(s, c, i);
// 	printf("%s", s);
// }