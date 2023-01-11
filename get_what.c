/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_what.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 11:35:31 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/11 16:09:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	static char		temp_buffer[BUFFER_SIZE + 1];
	char			*buffer;
	ssize_t 		byte_read;
	int				i;

	buffer = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_copy_join(buffer, temp_buffer);
	while (ft_find_newline(temp_buffer) == -1)
	{
		byte_read = read (fd, temp_buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (temp_buffer);
		buffer = ft_copy_join(buffer, temp_buffer);
	}
	buffer = ft_save(&buffer[i]);
	i = ft_find_newline(temp_buffer);
	ft_strlcpy(temp_buffer, &temp_buffer[i + 1], 2);
	return (buffer);
}

char	*ft_save(char *str)
{
	char	*new_str;
	int		len;

	new_str = NULL;
	len = ft_find_newline(str);
	if (ft_find_newline(str))
		new_str = ft_substr(str, 0, len + 1);
	return (new_str);
}

// char	*read_line(int fd, str);
// {
// 	ssize_t	byte_read;
	
// 	byte_read = read (fd, temp_buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 			return (temp_buffer);
// 		buffer = ft_copy_join(buffer, temp_buffer);
// }
