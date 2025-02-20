/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:01:10 by slargo-b          #+#    #+#             */
/*   Updated: 2025/02/12 11:16:40 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}

char	*ft_laquequiera(char *save, char *buffer)
{
	char	*rest;

	rest = ft_strjoin(save, buffer);
	if (!rest)
		return (NULL);
	free (save);
	return (rest);
}

/* size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	a;
	unsigned int	i;

	a = 0;
	i = 0;
	while (src[a] != '\0')
	{
		a++;
	}
	if (size > 0)
	{
		while (i < (size - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (a);
} */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	str[len1 + len2] = '\0';
	return (str);
}
//  int main ()
// {
// 	char *aqui;
// 	char	*a;
// 	char	*b;

// 	a = "hola";
//  	// b = "como";
// 	// aqui = ft_strjoin(a, b);
// 	printf("%s\n", ft_strchr(a, 'o'));
// }
