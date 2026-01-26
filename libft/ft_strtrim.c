/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/21 13:20:43 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/30 17:48:53 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!s1)
		return (NULL);
	if (s1[i] == '\0')
		return (ft_calloc(1, sizeof(char)));
	j = ft_strlen(s1) - 1;
	if (!set)
		return ((char *)s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]) && j > i)
		j--;
	if (!s1)
		return (NULL);
	return (ft_substr(s1, i, j - i + 1));
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s", ft_strtrim("abcdbababb", ""));
// }