/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:57:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 09:09:03 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "colors.h"
#include <stdlib.h>
#include "libft.h"
#include <stdbool.h>

void	cvec_append(t_cvec *vec, char element)
{
	vec->len++;
	cvec_update(vec);
	vec->arr[vec->len - 1] = element;
}

/*
 * Returns the new updated array. NULL if malloc fails.
 * Reallocates new memory, moves all integers to it.
 * Frees the old char array.
 * */
char	*cvec_update(t_cvec *vec)
{
	char	*new_arr;
	int		i;

	if (vec->len > vec->capacity)
	{
		vec->capacity += vec->buffer_size;
		new_arr = (char *)malloc(sizeof(char) * vec->capacity);
		if (new_arr == NULL)
			return (NULL);
		i = 0;
		while (i < vec->len)
		{
			new_arr[i] = vec->arr[i];
			i++;
		}
		free(vec->arr);
		vec->arr = new_arr;
	}
	return (vec->arr);
}

/* Creates a new vector with a given buffer_size. If the vector's
 * length exceeds the capacity, memory is reallocated by
 * capacity + buffer_size*/
t_cvec	*cvec_new(int buffer_size)
{
	t_cvec	*vec;

	vec = (t_cvec *)malloc(sizeof(t_cvec));
	if (vec == NULL)
		return (NULL);
	vec->len = 0;
	vec->arr = (char *)malloc(sizeof(char) * buffer_size);
	if (vec->arr == NULL)
		return (NULL);
	vec->capacity = buffer_size;
	vec->buffer_size = buffer_size;
	return (vec);
}

/* 
 * Frees the array
 * */
void	cvec_del(t_cvec *vec)
{
	free(vec->arr);
	free(vec);
}

t_cvec	*cvec_dup(t_cvec *vec)
{
	int		i;
	t_cvec	*new_vec;

	new_vec = (t_cvec *)malloc(sizeof(t_cvec));
	if (!new_vec)
		return (NULL);
	new_vec->arr = (char *)malloc(sizeof(char) * vec->capacity);
	if (!new_vec->arr)
		return (NULL);
	new_vec->len = vec->len;
	new_vec->capacity = vec->capacity;
	new_vec->buffer_size = vec->buffer_size;
	i = 0;
	while (i < vec->len)
	{
		new_vec->arr[i] = vec->arr[i];
		i++;
	}
	return (new_vec);
}
