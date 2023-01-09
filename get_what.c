/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_what.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 11:35:31 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/09 12:38:50 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// # include <unistd.h>
// # include <fcntl.h>
// # include <stdlib.h>
// # include <stdio.h>
// # include <stddef.h>


// // int main()
// // {
// // 	char *str;
// // 	char *tmp;
	
// // 	str = malloc(1000);
// // 	tmp = str;
// // 	str = malloc(1000);
// // 	free(tmp);
// // 	tmp = NULL;
// // 	free(tmp);
// // 	return (system("leaks -q a.out"), 0);
// // }

// int main()
// {
// 	int fd;
// 	char *str;

// 	fd = open ("test.txt", O_RDONLY);
// 	read (fd, str, 5);
// 	printf("%s\n", str);
// 	read (fd, str, 2);
// 	printf("%s\n", str);
// 	//overschrijft eerste 2 krijgt nog steeds laastte 3 van vorige read te zien.
// 	//bzero gebruiken?
// }