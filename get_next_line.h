/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:23 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/13 23:37:59 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char			*get_next_line(int fd);
ssize_t			ft_find_newline(char *str);
char			*ft_read_line(int fd, char *buffer, char *temp_buffer);
char			*ft_save(char *str);
size_t			ft_strlen(const char *s);
char			*ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_copy_join(char *s1, char *s2);

#endif