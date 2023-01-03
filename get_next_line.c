/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:19 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/03 19:56:45 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*finds newline char*/
size_t	ft_find_newline(char *str)
{
	size_t			i;

	i = 0;
	if (!str)
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
i = where i found /n on which index */
char	*get_next_line(int fd)
{
	char				buffer[BUFFER_SIZE + 1];
	static char			*temp_string;
	char				*new_string;
	char				*free_string;
	size_t				byte_read;
	size_t				i;
	size_t				len;

	len = 0;
	i = 0;
	byte_read = 1;
	new_string = NULL;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	while (byte_read != 0 && !ft_find_newline(temp_string))
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		if (temp_string == NULL)
		{
			temp_string = ft_strdup(buffer); // or ft_substr?
		}
		else
		{
			free_string = temp_string;
			temp_string = ft_strjoin(free_string, buffer); // dont put it to NULL because joining
			free(free_string);
		}
	}
	while (temp_string[i] != '\0' && temp_string[i] != '\n')
	{
		i++;
		int j = ft_find_newline(temp_string);
		if (j == 0)
			{
				free_string = ft_strdup(temp_string);
				free (temp_string);
				temp_string = NULL;	
				return (free_string);
			}
		free_string = temp_string;
		new_string = ft_substr(temp_string, 0, j + 1); // stores with \n
		temp_string = ft_substr(free_string, j + 1, 6); // updates temp_string from \n
		free (free_string);
		if (j != 0)// need to stop when newline is found, else it overwrites new_string with substring
			break ;
	}
	return (new_string); // null terminated string 
}

	//static int			b = 0;
	//printf("-------------------------------%d----------------------------\n", b++);
	
	// printf("byte read=%zu\n", byte_read);
	// printf("j=%d\n", j);
	// printf("new_string=%s\n", new_string);
	//printf("buffer=%s\n", buffer);
	// printf("temp_string=%s\n", temp_string);

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