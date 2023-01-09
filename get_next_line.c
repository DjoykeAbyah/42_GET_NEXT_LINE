/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:19 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/09 12:38:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*finds newline char*/
ssize_t	ft_find_newline(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/* reads the file and puts it in a string
i = where i found /n on which index */
char	*get_next_line(int fd)
{
	char				buffer[BUFFER_SIZE + 1];
	// char				*buffer;
	static char			*temp_string;
	char				*new_string;
	char				*free_string;
	ssize_t				byte_read;
	ssize_t				i;

	i = 0;
	free_string = NULL;
	new_string = NULL;
	temp_string = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_find_newline(temp_string) < 0)
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buffer[byte_read] = '\0';
		if (byte_read == 0)
			return (temp_string);
		if (temp_string == NULL)
			temp_string = ft_strdup(buffer);
		else
		{
			temp_string = ft_strjoin(free_string, buffer);
			free(free_string);
		}
	}
	while (temp_string != NULL && temp_string[i] != '\0')
	{
		int found_nl = ft_find_newline(temp_string);
		if (found_nl == -1)
			{
				free_string = ft_strdup(temp_string);
				free (temp_string);
				temp_string = NULL;
				return (free_string);
			}
		else
		{
			free_string = temp_string;
			new_string = ft_substr(temp_string, 0, ft_find_newline(temp_string) + 1); // stores with \n
			temp_string = ft_substr(free_string, ft_find_newline(temp_string) + 1, ft_strlen(free_string)); // updates temp_string from \n
			// malloc fail check.
			free (free_string);
		}
			if (ft_find_newline(temp_string) != 0)// need to stop when newline is found, else it overwrites new_string with substring
				break ;
		i++;
	}
	return (new_string);
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