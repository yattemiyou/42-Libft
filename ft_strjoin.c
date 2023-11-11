/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:39:51 by anonymous         #+#    #+#             */
/*   Updated: 2023/11/11 12:07:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	void	*buffer;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buffer = ft_calloc(size, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, s1, size);
	ft_strlcat(buffer, s2, size);
	return (buffer);
}
