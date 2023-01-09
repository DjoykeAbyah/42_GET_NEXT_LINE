/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:23 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/09 16:46:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
ssize_t		ft_find_newline(char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
