/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 11:35:31 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/13 19:58:12 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read_line(int fd, char *buffer, char *temp_buffer)
{
	int		byte_read;
	char	*free_string;

	while (ft_find_newline(temp_buffer) == -1)
	{
		if (buffer == NULL)
			return (buffer);
		byte_read = read (fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[byte_read] = '\0';
		if (byte_read == 0)
			return (buffer);
		if (byte_read == -1)
			return (0);
		free_string = buffer;
		buffer = ft_copy_join(buffer, temp_buffer);
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
	static char		temp_buffer[BUFFER_SIZE + 1];
	char			*buffer;
	int				i;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_copy_join(buffer, temp_buffer);
	if (buffer == NULL)
		return (NULL);
	buffer = ft_read_line(fd, buffer, temp_buffer);
	if (buffer == NULL)
		return (NULL);
	buffer = ft_save(buffer);
	if (buffer == NULL)
		return (NULL);
	i = ft_find_newline(temp_buffer);
	ft_strlcpy(temp_buffer, &temp_buffer[i + 1], ft_strlen(&temp_buffer[i]));
	if (temp_buffer[0] == '\0' && buffer[0] == '\0')
		return (NULL);
	return (buffer);
}

	// printf("------------buffer = %s\n", buffer);
	// printf("------------temp_buffer = %s\n", temp_buffer);
	// printf("------------buffer before = %s\n", buffer);
	// printf("---------");