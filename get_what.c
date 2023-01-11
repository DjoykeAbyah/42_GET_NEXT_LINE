/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_what.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 11:35:31 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/11 18:37:27 by dreijans      ########   odam.nl         */
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

char	*ft_read_line(int fd, char *buffer, char *temp_buffer)
{
	int	byte_read;

	byte_read = read (fd, temp_buffer, BUFFER_SIZE);
	if (byte_read == 0)
		return (buffer);
	if (byte_read == -1)
		return (0);
	buffer = ft_copy_join(buffer, temp_buffer);
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

//can alsnog buffer = malloc 1 doen hehehehe
char	*get_next_line(int fd)
{
	static char		temp_buffer[BUFFER_SIZE + 1];
	char			*buffer;
	int				i;

	buffer = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_copy_join(buffer, temp_buffer);
	while (ft_find_newline(temp_buffer) == -1)
		buffer = ft_read_line(fd, buffer, &temp_buffer[i]);
	buffer = ft_save(&buffer[i]);
	i = ft_find_newline(temp_buffer);
	ft_strlcpy(temp_buffer, &temp_buffer[i + 1], ft_strlen(&temp_buffer[i]));
	return (buffer);
}


