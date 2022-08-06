
#include "vector.h"
#include <stdlib.h>
#include "libft.h"


void pvec_append(t_pvec *vec, void *element)
{
	vec->len++;
	pvec_update(vec);
	vec->arr[vec->len - 1] = element;
}

/*
 * Returns the new updated array. NULL if malloc fails.
 * Reallocates new memory, moves all pointers to it.
 * Frees the old pointer array.
 * */
void **pvec_update(t_pvec *vec)
{
	void	**new_arr;
	int		i;

	if (vec->len > vec->capacity)
	{
		vec->capacity += vec->buffer_size;
		new_arr = (void **)malloc(sizeof(void *) * vec->capacity);
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
t_pvec *pvec_new(int buffer_size)
{
	t_pvec	*vec;

	vec = (t_pvec *)malloc(sizeof(t_pvec));
	if (vec == NULL)
		return (NULL);
	vec->len = 0;
	vec->arr = (void **)malloc(sizeof(void *) * buffer_size);
	if (vec->arr == NULL)
		return (NULL);
	vec->capacity = buffer_size;
	vec->buffer_size = buffer_size;
	return (vec);
}

/* 
 * Deletes every element in the array by using the del function.
 * */
void	pvec_del(t_pvec *vec, void (*del)(void *))
{
	int	i;

	i = 0;
	while (i < vec->len)
	{
		del(vec->arr[i]);
		i++;
	}
	free(vec->arr);
	free(vec);
}

// int	main(void)
// {
// 	t_pvec *vec;
//
// 	vec = pvec_new(2);
// 	pvec_append(vec, (void *)ft_strdup("Ocak"));
// 	pvec_append(vec, (void *)ft_strdup("Subat"));
// 	pvec_append(vec, (void *)ft_strdup("Mart"));
// 	pvec_append(vec, (void *)ft_strdup("Nisan"));
// 	pvec_append(vec, (void *)ft_strdup("Mayis"));
// 	pvec_append(vec, (void *)ft_strdup("Haziran"));
//
// 	for (int i = 0; i < vec->len; i++)
// 	{
// 		ft_printf("i: %d str: %s\n", i, (char *)vec->arr[i]);
// 	}
// }
//
























