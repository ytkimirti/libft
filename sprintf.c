/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:10:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/27 14:00:45 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*str_arg(char c, va_list ap)
{
	if (c == 's')
		return (ft_strdup(va_arg(ap, char *)));
	if (c == 'd')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == '%')
		return (ft_strdup("%"));
	return (ft_strdup(""));
}

char	*get_until_char(char *str, const char *key, int *i)
{
	char	*p;
	char	*tmp;
	int		len;

	p = ft_strchr(key + *i, '%');
	if (!p)
	{
		len = ft_strlen(key + *i);
		tmp = ft_strdup(key + *i);
	}
	else
	{
		len = p - (key + *i);
		tmp = ft_substr(key, *i, len);
	}
	*i += len;
	return (ft_strjoinfre(str, tmp));
}

char	*ft_sprintf(const char *key, ...)
{
	va_list	ap;
	int		i;
	char	*str;

	va_start(ap, key);
	i = 0;
	str = ft_strdup("");
	while (key[i])
	{
		if (key[i] == '%')
		{
			if (key[i + 1] != 0)
				str = ft_strjoinfre(str, str_arg(key[i + 1], ap));
			i += 2;
			continue ;
		}
		str = get_until_char(str, key, &i);
	}
	va_end(ap);
	return (str);
}

/*#include <unistd.h>*/

/*int	main(void)*/
/*{*/
	/*free(ft_sprintf("abc%defg", 15));*/
	/*free(ft_sprintf("%s%s%%%s:%d","myage", "other", "last", 15));*/
	/*free(ft_sprintf("%s:%d","myage", 15));*/
	/*free(ft_sprintf("%s:%d","myage", 15));*/
	/*free(ft_sprintf("%s:%d","myage", 15));*/
	/*free(ft_sprintf("%s:%d","myage", 15));*/
	/*char *a = malloc(5);*/
	/*ft_strlcpy(a, "hello", 5);*/
	/*a = NULL;*/
	/*pause();*/
/*}*/
