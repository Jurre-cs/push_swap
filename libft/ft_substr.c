/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 16:31:37 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/30 17:39:42 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// typedef struct s_person {
// 	char *name;
// 	int age;
// } t_person;

// typedef int i32;

// t_person p;
// pg->name =  "fsdf";
// p.ae = 53644;

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	if (len > i + start)
		len = i + start;
	if (start > i)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		(len = ft_strlen(s) - start);
	subs = ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start];
		start++;
		i++;
	}
	return (subs);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s", ft_substr("idk what people want from me", 16, 13));
// }
