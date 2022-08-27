/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivector_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:53:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 08:56:51 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "colors.h"
#include "libft.h"

void	ivec_print(t_ivec *vec, bool extra_info)
{
	int	i;

	if (extra_info)
		ft_printf("len: " YEL "%d" RST
			" capacity: " YEL "%d" RST
			" bufsize: " YEL "%d" RST
			"\n", vec->len, vec->capacity, vec->buffer_size);
	ft_printf("[");
	i = 0;
	while (i < vec->len)
	{
		if (i == vec->len - 1)
			ft_printf("%d", vec->arr[i]);
		else
			ft_printf("%d, ", vec->arr[i]);
		i++;
	}
	ft_printf("]\n");
}
