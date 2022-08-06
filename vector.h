#ifndef VECTOR_H

# define VECTOR_H

// Pointer vector

typedef struct
{
	void	**arr;
	int		len;
	int		capacity;
	int		buffer_size;
	void (*del)(void *);
} t_pvec;

void		**pvec_update(t_pvec *vec);
void		pvec_append(t_pvec *vec, void *element);
t_pvec	*pvec_new(int buffer_size);
void	pvec_del(t_pvec *vec, void (*del)(void *));

// Int vector

typedef struct
{
	int	*arr;
	int		len;
	int		capacity;
	int		buffer_size;
} t_ivec;

int			*ivec_update(t_ivec *vec);
void		ivec_append(t_ivec *vec, int element);
t_ivec	*ivec_new(int buffer_size);
void		ivec_del(t_ivec *vec);

#endif
