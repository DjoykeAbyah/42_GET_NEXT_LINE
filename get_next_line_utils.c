/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:14 by dreijans      #+#    #+#                 */
/*   Updated: 2022/12/23 21:04:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	ft_find_newline(char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

/* reads the file and puts it in a string*/
char	*ft_readfile(int fd)
{
	char		*muffin;
	size_t		i;

	i = 0;
	muffin = malloc(sizeof(char) * BUFFER_SIZE);
	if (muffin == NULL)
		return (NULL);
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	while (i == 0)
	{
		read (fd, muffin, BUFFER_SIZE);
		i = ft_find_newline(muffin);
	}
	return (muffin);
	//where do i save the beginning?
	/*free in other function?*/
}

/*
Function name: 		get_next_line

Prototype: 			char *get_next_line(int fd);

Turn in files : 	get_next_line.c, get_next_line_utils.c,
					get_next_line.h

Parameters: fd: 	The file descriptor to read from

Return value: 		Read line: correct behavior
					NULL: there is nothing else to read, or an error
					occurred
				
External functs: 	read, malloc, free

Description: 		Write a function that returns a line read from a
					file descriptor
*/