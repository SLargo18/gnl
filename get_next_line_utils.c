/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:01:10 by slargo-b          #+#    #+#             */
/*   Updated: 2025/02/05 21:35:53 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	*a;
	unsigned int	*b;
	size_t			i;

	i = 0;
	a = (unsigned int *)dest;
	b = (unsigned int *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}

static char	ft_strlen(const char *s)
{
	char	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	ft_strjoin(char const *s1, char const *s2)
{
	int		*str;
	char	len1;
	char	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (int *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
