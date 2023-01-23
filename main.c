/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:26 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/23 16:56:11 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free (line);
// 	}
// 	free (line);
// 	close (fd);
// 	system("leaks a.out");
// 	return (0);
// }

// int	main(void)
// {
// 	int		fd;
// 	int		fd1;
// 	int		fd2;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	line = "\0";
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			free(line);
// 	}
// 	line = "\0";
// 	while (line)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		if (line == NULL)
// 			free(line);
// 	}
// 	line = "\0";
// 	while (line)
// 	{
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		if (line == NULL)
// 			free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }

// int	main()
// {
// 	int	fd = open("get_next_line.c", O_RDONLY);
// 	int	fd1 = open("get_next_line_utils.c", O_RDONLY);
// 	char	*line;
// 	char	*line1;

// 	while(1)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 			printf("%s", line);
// 		line1 = get_next_line(fd1);
// 		if (line1 != NULL)
// 			printf("%s", line1);
// 		if (line == NULL && line1 == NULL)
// 			break;
// 		if (line == NULL || line1 == NULL)
// 		{
// 			if (get_next_line(30) == NULL)
// 				return (printf("goed zo"));
// 		}
// 		free (line1);
// 		free (line);
// 	}
// 	system("leaks a.out");

// int	main(void)
// {
// 	main3();
// 	system("leaks a.out");
// }
