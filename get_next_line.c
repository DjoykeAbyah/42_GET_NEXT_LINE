/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:19 by dreijans      #+#    #+#                 */
/*   Updated: 2022/12/30 21:11:23 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*get the line until /n and end it with a /0
at the address of str[i]
() have to use this because line and str arent equal
+2 for /n and /0*/
char	*get_line(char **str, size_t len)
{
	char		*line;
	char		*pointer_free;
	size_t		i;

	i = 0;
	//printf("%i\n", len);
	line = malloc(sizeof(char) * len + 2);
	if (line == NULL)
		return (NULL);
	while (i <= len)
	{
		line[i] = (*str)[i];
		i++;
	}
	line[i] = '\0';
	pointer_free = *str;
	*str = ft_strdup(&(*str)[i]);
	free (pointer_free);
	return (line);
}

/*finds newline char*/
size_t	ft_find_newline(char *str)
{
	size_t			i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

/* reads the file and puts it in a string
i = where i found /n on which index
i want to know the strlen - /n char*/
char	*ft_readfile(int fd)
{
	static char			buffer[BUFFER_SIZE + 1];
	static char			*new_string;
	char				*temp_buffer;
	size_t				byte_read;
	size_t				i;

	byte_read = 1;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	while (byte_read != 0)
	{
		//puts("HERE");
		byte_read = read (fd, buffer, BUFFER_SIZE);
		//printf("buffer:%s\n", buffer);
		if (new_string == NULL)
			new_string = ft_strdup(buffer);
		else
			new_string = ft_strjoin(new_string, buffer);
		i = ft_find_newline(new_string);
		//printf("%s\n", new_string);
		if (i != 0)
		{
			temp_buffer = get_line(&new_string, i);
			//printf("%s\n", temp_buffer);
			return (temp_buffer);
		}
	}
	return (buffer);
}

// char	*get_next_line(int fd)
// {
	
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