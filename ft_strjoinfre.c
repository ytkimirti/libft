/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:07:10 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/27 12:33:09 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strjoinfre(char *s1, char *s2)
{
	size_t	memsize;
	size_t	i;
	char	*new_str;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	memsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(memsize * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < memsize && s1[i] != '\0')
		new_str[i] = s1[i];
	while (i < memsize)
	{
		new_str[i] = s2[i - len_s1];
		i++;
	}
	free(s1);
	free(s2);
	return (new_str);
}
