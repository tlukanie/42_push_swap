/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:20:14 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/03 17:19:32 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strjoin_content_buf(char *s1, char *s2)
{
	char			*content;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = 0;
	}
	content = (char *)malloc((str_length(s1) + str_length(s2))
			* sizeof(char) + 1);
	if (!content)
		return (NULL);
	while (s1[i])
	{
		content[i] = s1[i];
		i++;
	}
	while (s2[j])
		content[i++] = s2[j++];
	content[i] = '\0';
	free(s1);
	return (content);
}

char	*strchr_locate_nl(const char *str, int nl)
{
	if (!str)
		return (NULL);
	while (*str && *str != nl)
		str++;
	if (nl == *str)
		return ((char *)str);
	else
		return (NULL);
}
