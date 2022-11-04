/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:53:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/04 11:23:20 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "colors.h"
#include "libft.h"

void	cvec_print(t_cvec *vec, bool extra_info)
{
	int		i;
	char	c;

	if (extra_info)
		ft_printf("len: " YEL "%d" RST
			" capacity: " YEL "%d" RST
			" bufsize: " YEL "%d" RST
			"\n", vec->len, vec->capacity, vec->buffer_size);
	i = 0;
	while (i < vec->len)
	{
		c = vec->arr[i];
		if (c == '\0')
			ft_printf("\\0");
		else
			ft_printf("%c", c);
		i++;
	}
	ft_printf("\n");
}

/*
 * The string must be null terminated
 * The \0 character at the end of the string
 * is not appended to the vector if terminate is
 * false
 * */
void	cvec_appendstr(t_cvec *vec, const char *str, bool terminate)
{
	while (*str != '\0')
	{
		cvec_append(vec, *str++);
	}
	if (terminate)
		cvec_append(vec, *str);
}
