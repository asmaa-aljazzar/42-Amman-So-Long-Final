/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:32:26 by aaljazza          #+#    #+#             */
/*   Updated: 2024/09/28 13:32:35 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

/*
* to allocate a specified amount of memory and then initialize it to zero
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;
	size_t	i;

	c = malloc(nmemb * size);
	if (!c)
	{
		return (NULL);
	}
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)c)[i] = 0;
		i++;
	}
	return (c);
}
