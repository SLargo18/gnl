/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:28:50 by slargo-b          #+#    #+#             */
/*   Updated: 2025/02/05 21:31:26 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	new_line(char *str)
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
}

static char	*get_line(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save [i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	while (save[i] && save[i] != '\n')
	{
		line [j] = save [i];
		i++;
		j++;
	}
	if (save[i] == '\n')
		line [i++] = '\n';
	line [i] = '\0';
	return (line);
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
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_save = malloc(ft_strlen(save) - i + 1);
	if (!new_save)
		return (NULL);
	i++;
	while (save[i])
		new_save[j++] = save [i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;
	int			read_a;

	read_a = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!new_line(save) && (read_a = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_a] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free (buffer);
	line = get_line(save);
	save = update(save);
	return (line);
}

int		main()
{
	char	*str;
	int		fd;
	
	fd = open("text.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free (str);
	}
	free (str);
	close(fd):
}
