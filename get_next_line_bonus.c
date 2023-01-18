/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 11:35:31 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/18 18:30:18 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_find_newline(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read_line(int fd, char *buffer, char *read_buffer)
{
	int		byte_read;
	char	*free_string;

	while (ft_find_newline(read_buffer) == -1)
	{
		if (buffer == NULL)
			return (buffer);
		byte_read = read (fd, read_buffer, BUFFER_SIZE);
		read_buffer[byte_read] = '\0';
		if (byte_read == 0)
			return (buffer);
		if (byte_read == -1)
		{
			read_buffer[0] = '\0';
			free (buffer);
			return (0);
		}
		free_string = buffer;
		buffer = ft_copy_join(buffer, read_buffer);
		free (free_string);
		if (buffer == NULL)
			return (NULL);
	}
	return (buffer);
}

char	*ft_save(char *str)
{
	char	*new_str;
	int		len;

	new_str = NULL;
	len = ft_find_newline(str);
	if (len == -1)
		return (str);
	new_str = ft_substr(str, 0, len + 1);
	free (str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		read_buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char			*buffer;
	int				i;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = ft_copy_join(buffer, read_buffer[fd]);
	if (buffer == NULL)
		return (NULL);
	buffer = ft_read_line(fd, buffer, read_buffer[fd]);
	if (buffer == NULL)
		return (NULL);
	buffer = ft_save(buffer);
	if (buffer == NULL)
		return (NULL);
	i = ft_find_newline(read_buffer[fd]);
	ft_strlcpy(read_buffer[fd], &read_buffer[fd][i + 1],
		ft_strlen(&read_buffer[fd][i]));
	if (read_buffer[fd][0] == '\0' && buffer[0] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}
