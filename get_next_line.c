/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:14:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/02/10 20:31:57 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* static int	new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
} */

static char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save [i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save [i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save [i];
		i++;
	}
	line [i] = '\0';
	return (line);
}

static char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	int		read_a;

	read_a = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_a > 0)
	{
		read_a = read(fd, buffer, BUFFER_SIZE);
		if (read_a < 0)
			return (free(save), free(buffer), NULL);
		buffer[read_a] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
			return (free(buffer), NULL);
		if (ft_strchr(save, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (save);
}

static char	*update_save(char *save)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save [i] != '\n')
		i++;
	if (!save)
		return (free(save), NULL);
	new_save = malloc(ft_strlen(save) - i - 2);
	if (!new_save)
		return (NULL);
	i++;
	while (save[i])
	{
		new_save[j] = save [i];
		i++;
		j++;
	}
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = malloc (1);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	printf("%s\n", line);
	save = update_save(save);
	return (line);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	/*str = get_next_line(fd); 
	printf("%s", str); 
	 str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str); */
	while ((str = get_next_line(fd)) != NULL)
 	{
 		printf("%s", str);
 		free (str);
 	}
	close(fd);
}
