#ifndef VECTOR_H

# define VECTOR_H

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

#endif
