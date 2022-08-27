/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:13:39 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 09:23:59 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../vector.h"

int	main(void)
{
	t_cvec	*vec;

	vec = cvec_new(100);

	cvec_append(vec, 'a');
	cvec_append(vec, 'b');
	cvec_append(vec, '\0');
	cvec_append(vec, 'd');
	cvec_append(vec, 'd');
	cvec_append(vec, 'd');
	cvec_append(vec, '\n');
	cvec_append(vec, 'd');
	cvec_append(vec, 'd');
	cvec_append(vec, 'd');

	cvec_print(vec, true);

	cvec_appendstr(vec, "hello\nworld", true);
	cvec_print(vec, true);
}
