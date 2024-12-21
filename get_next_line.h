/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:48:39 by ualkan            #+#    #+#             */
/*   Updated: 2024/12/21 12:39:51 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_srcnl(const char *s);
size_t	ft_l(const char *s);
char	*ft_strjoin(char *old_stack, char *buffer);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_c(size_t num, size_t size);

#endif