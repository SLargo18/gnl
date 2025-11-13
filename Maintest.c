#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	*str;
	int		fd;
	int i = 1;

	fd = open("prueba.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("<%d> %s", i++, str);
		free (str);
	}	
	free (str);
	close(fd);
	return 0;
}