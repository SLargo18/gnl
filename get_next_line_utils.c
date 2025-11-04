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

int	has_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
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

char	*ft_strjoin_gnl(char *save, char *buffer)
{
	char	*rest;

	rest = ft_strjoin(save, buffer);
	if (!rest)
		return (NULL);
	free (save);
	return (rest);
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
