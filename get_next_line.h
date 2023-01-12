/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:23 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/12 16:10:33 by dreijans      ########   odam.nl         */
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
#  define BUFFER_SIZE 100
# endif

char			*get_next_line(int fd);
char			*ft_save(char *str);
ssize_t			ft_find_newline(char *str);
size_t			ft_strlen(const char *s);
char			*ft_copy_join(char *s1, char *s2);
char			*ft_strdup(char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strlcpy(char *dst, const char *src, size_t dstsize);
// ssize_t			ft_find_end(char *str);

#endif
