/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:26 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/03 19:47:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main3(void)
{
	int		fd;
	char	*line;
	

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
		free (line);
	}
	//free(line);
	close (fd);
	return (0);
}



int main(void)
{
	main3();
	//system("leaks a.out");
}

// int	main2(void)
// {
// 	int		fd;
// 	char 	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		line = ft_get_next_line(fd);
// 		printf("%s", line);
// 		free (line);
// 	}
// 	close (fd);
// 	return (0);
// }

// int	main2(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s\n", ft_get_next_line(fd));
// 	printf("%s\n", ft_get_next_line(fd));
// 	// printf("%s\n", ft_get_next_line(fd));
// 	// printf("%s\n", ft_get_next_line(fd));
// 	// // printf("%s\n", ft_get_next_line(fd));
// 	// // printf("%s\n", ft_get_next_line(fd));
// 	close (fd);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*awsome_line;
// 	int		fd;
// 	int		i;

// 	i = 1;
// 	awsome_line = NULL;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("\neeerrrrrooorrrrr");
// 		return (0);
// 	}
// 	awsome_line = ft_get_next_line(fd);
// 	while (awsome_line)
// 	{
// 		awsome_line = ft_get_next_line(fd);
// 		printf("%s", awsome_line);
// 		free(awsome_line);
// 		i++;
// 	}
// 	free(awsome_line);
// 	close (fd);
// 	return (0);
// }

/* else pathname if not in same dir ./documents/get_next_line/test.txt*/