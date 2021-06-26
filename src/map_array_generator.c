
#include "solong.h"

int		map_height(char *path)
{
	char	buffer[10000];
	int		fd;
	int		byte_read;
	int		n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 1;
	while ((byte_read = read(fd, buffer, 1)) > 0)
	{
		if (*buffer == '\n')
			n++;
	}
	close(fd);
	return (n);
}

int		map_width(char *path)
{
	char	buffer;
	int		fd;
	int		byte_read;
	int		n;
	int		max;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 0; 
	max = 0;
	while (((byte_read = read(fd, &buffer, 1)) > 0))
	{
		n++;
		if (buffer == '\n')
		{
			if (n > max)
				max = n;
			n = 0;
		}
	}
	close(fd);
	return (max);
}

char	**array_generator(int width, int height)
{
	char	**arr;
	int		i;
	int		j;

	if ((arr = malloc(sizeof(char*) * (height + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		if ((arr[i] = malloc(sizeof(char) * (width + 1))) == NULL)
			return (NULL);
		j = 0;
		while (j < width)
		{
			arr[i][j] = '%';
			j++;
		}
		arr[i][j] = 0;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	fill_map(char **map, char *path, int i, int j)
{
	char	c;
	int		fd;
	int		byte_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	byte_read = read(fd, &c, 1);
	while (byte_read > 0)
	{
		if (c != '\n')
			map[j][i++] = c;			
		else if (c == '\n')
		{
			map[j++][i] = 0;
			i = 0;
		}
		byte_read = read(fd, &c, 1);
	}
	map[j][i] = 0;
	map[++j] = 0;
	close(fd);
}
