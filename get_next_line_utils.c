/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:14 by dreijans      #+#    #+#                 */
/*   Updated: 2022/12/23 20:11:47 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* reads the file and puts it in a string*/
char	*ft_readfile(int fd)
{
	char	*muffin;
	size_t	i;
	
	i = 0;
	muffin = malloc(sizeof(char *) * BUFFER_SIZE);
	if (muffin == NULL)
		return (NULL);
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	read (fd, muffin, BUFFER_SIZE);
	while (muffin != '\0')
	{
		if (muffin[i] == '\n')
			return (muffin[i]);
		else
		continue reading until you find \n
	}
	// while (muffin != '\0')
	// {
	// 	ft_search_endline(muffin);
	// }
	return (muffin);
	/*free in other function?*/
}

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

/*search for the \n*/
// char	*ft_search_endline(const char *s)
// {
// 	while (*s != '\0')
// 	{
// 		if (*s == '\n')
// 			return (s);
// 		s++;
// 	}
// 	return (NULL);
// }

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