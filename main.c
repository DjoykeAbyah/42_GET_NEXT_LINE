/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:26 by dreijans      #+#    #+#                 */
/*   Updated: 2022/12/30 21:21:47 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*wieh;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		wieh = ft_readfile(fd);
		if (wieh == NULL)
			break ;
		printf("%s\n", wieh);
		free (wieh);
	}
	close (fd);
}

/*gaat iets mis in strjoin???? wierd printing*/

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
// 		printf("\nwieeeh error jonge");
// 		return (0);
// 	}
// 	awsome_line = ft_readfile(fd);
// 	while (awsome_line)
// 	{
// 		awsome_line = ft_readfile(fd);
// 		printf("%s", awsome_line);
// 		free(awsome_line);
// 		i++;
// 	}
// 	free(awsome_line);
// 	close (fd);
// 	return (0);
// }

/* else pathname if not in same dir ./documents/get_next_line/test.txt*/