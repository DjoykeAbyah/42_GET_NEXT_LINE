/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:14 by dreijans      #+#    #+#                 */
/*   Updated: 2022/12/30 17:34:12 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*copy and concatenate strings */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*concatenates two strings*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (dst_len + src_len);
}

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
constant is just for reading but i want to edit s1
needs to be freed because each time malloc used string get's new pointer when altered*/
char	*ft_strjoin(char *s1, char const *s2)
{
	char		*new_str;
	size_t		len;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = (char *)malloc(sizeof (char) * len);
	if (new_str != '\0')
	{
		ft_strlcpy(new_str, s1, (ft_strlen(s1) + 1));
		ft_strlcat(new_str, s2, len);
		free (s1);
		return (new_str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*s2;

	len = ft_strlen(s1)+1;
	s2 = malloc(len * sizeof (char));
	if (s2 == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s2, (void *)s1, len);
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;
	size_t	i;

	i = 0;
	ptrd = (char *)dst;
	ptrs = (char *)src;
	if (ptrd == '\0' && ptrs == '\0')
	{
		return (NULL);
	}
	while (i < n)
	{
		*ptrd = *ptrs;
		ptrd++;
		ptrs++;
		i++;
	}
	return (dst);
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