/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:44:11 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/26 16:16:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	size;
	void	*ptr;

	size = ft_strlen(s) + 1;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, size);
	return (ptr);
}
