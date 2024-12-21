/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:47:48 by ualkan            #+#    #+#             */
/*   Updated: 2024/12/21 12:40:55 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_srcnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_l(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *old_stack, char *buffer)
{
	char	*new_stack;
	size_t	i;
	size_t	j;

	new_stack = (char *)ft_c(ft_l(old_stack) + ft_l(buffer) + 1, sizeof(char));
	if (!new_stack)
	{
		free(old_stack);
		return (NULL);
	}
	i = 0;
	while (old_stack[i])
	{
		new_stack[i] = old_stack[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_stack[i + j] = buffer[j];
		j++;
	}
	new_stack[i + j] = '\0';
	free(old_stack);
	return (new_stack);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start >= ft_l(s))
	{
		sub = (char *)ft_c(1, sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_l(s + start) < len)
		len = ft_l(s + start);
	sub = (char *)ft_c(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_c(size_t num, size_t size)
{
	size_t	i;
	char	*p;
	void	*arr;

	arr = malloc(num * size);
	if (!arr)
		return (NULL);
	i = 0;
	p = (char *)arr;
	while (i < num * size)
	{
		p[i] = 0;
		i++;
	}
	return (arr);
}
