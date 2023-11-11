/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:44:25 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/26 14:18:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (--size && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (len);
}
