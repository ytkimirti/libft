/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:59:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 09:11:54 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "colors.h"
#include <stdlib.h>
#include "libft.h"
#include <stdbool.h>

void	ivec_append(t_ivec *vec, int element)
{
	vec->len++;
	ivec_update(vec);
	vec->arr[vec->len - 1] = element;
}

/*
 * Returns the new updated array. NULL if malloc fails.
 * Reallocates new memory, moves all integers to it.
 * Frees the old integer array.
 * */
int	*ivec_update(t_ivec *vec)
{
	int		*new_arr;
	int		i;

	if (vec->len > vec->capacity)
	{
		vec->capacity += vec->buffer_size;
		new_arr = (int *)malloc(sizeof(int) * vec->capacity);
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
t_ivec	*ivec_new(int buffer_size)
{
	t_ivec	*vec;

	vec = (t_ivec *)malloc(sizeof(t_ivec));
	if (vec == NULL)
		return (NULL);
	vec->len = 0;
	vec->arr = (int *)malloc(sizeof(int) * buffer_size);
	if (vec->arr == NULL)
		return (NULL);
	vec->capacity = buffer_size;
	vec->buffer_size = buffer_size;
	return (vec);
}

/* 
 * Frees the array
 * */
void	ivec_del(t_ivec *vec)
{
	free(vec->arr);
	free(vec);
}

t_ivec	*ivec_dup(t_ivec *vec)
{
	int		i;
	t_ivec	*new_vec;

	new_vec = (t_ivec *)malloc(sizeof(t_ivec));
	if (!new_vec)
		return (NULL);
	new_vec->arr = (int *)malloc(sizeof(int) * vec->capacity);
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
