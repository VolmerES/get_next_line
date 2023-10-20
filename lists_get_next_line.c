/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:03 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/20 16:24:42 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "getnextline.hi"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE "10"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_free_node(t_list **node, t_list *new_node, char *buf)
{
	t_list *tmp;

	if (!node)
		return;
	while (node)
	{
		tmp = (*node)->next;
		free((*node)->content);
		free(*node);
		*node = tmp;
	}
	*node = NULL;
//	if (new_node->content[0])
//		*node = new_node;
	//ielse
	//{
		free(buf);
		free(new_node);
//	}
}
void 	ft_join_node(t_list **node)
{
	int i;
	int j;
	char *buf;
	t_list new_node;
	t_list last_node;

	buf = malloc(&BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!new_node || !buf)
		return;
	last_node = ft_find_last_node(*node);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	new_node->content = buf;
	new_node->next = NULL;
	ft_free_node(node, new_node, buf);
}
void	ft_cpy_str(t_list *node, char *str)
{
	//i para iterar mi string
	//j para iterar el conetent de mi nodo
	int	i;
	int j;

	//protego si nodo esta vacio devuelvo NULL
	if (!node)
		return (NULL);
	k = 0;
	//mientras haya nodo
	while (node)
	{
		i = 0;
		//mientras el conetenido del nodo sea iterable
		while (node->content[i])
		{
			//si en la posicion i del nodo encuentras salto de linea
			//copia el salto de linea y añade un null al final
			if (node->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
			}
			//mientras no lo encuentre el content de mi nodo se copia a la string
			str[k++] = node->content[i++]
		}
		//cuando el contenido de mi nodo ya no es iterable hago que apunte a next
		node = node->next;
	}
	//termino mi string con un caracter nulo
	str[k] = '\0';

}
int	ft_len_to_newline(t_list *node)
{
	//iterador para iterar a traves de la string de la lista
	//otro iterador que me va servir para conocer la len de la lista
	int i;
	int len;

	//si el nodo pasdo es nulo sale
	if (node == NULL)
		return (0);
	//mientras la lista sea distinta de NULL)
	while (node)
	{
		i = 0;
		//mientras el contenido de a lista sea iterable
		while (node->content[i])
		{
			//comprueba si el contenido el salto de linea:w
			if (node->content[i] == '\n')
			{
				//incremento una vez len si encuentra el salto de linea antes de salir del programa
				++len;
				return (len);
			}
			//itero primer el content de mi nodo
			//incremento len para conocer la longitud hasta mi nueva linea
			++i;
			++len;
		}
		//hago que mi nodo apunte a su next
		node = node->next; 
	}
	//devuelvo la longitud de la nueva linea
	return (len)
}
//guarda la linea restante despues de un salto de linea
char	*ft_get_next_line(t_list *node)
{
	//variable para contar cuantos char hay hasta salto de linea
	//char para guardar el contenido de la linea siguiente al salto de linea
	int		str_len;
	char	*next_line;

	//doy el valor de la cantidad de bytes que hay hasta la nueva linea
	str_len = ft_len_to_newline(node)
	//reservo memoria para guardar la siguiente linea
	next_line = malloc(str_len + 1);
	//protego el malloc
	if (next_line == NULL)
		return (NULL);
	//llamo a funcion para copiar la string resultando al buf
	ft_cpy_str(node, next_line);
	//devuelvo la linea resultante
	return (next_line)
}
//encuentra el ultimo nodo, crea un nuevo nodo, le da el valor a content, y lo añade al final de la lista;
void	ft_add_lastback(t_list **node, char *buf)
{
	//declaro nuevo nodo para asginarle espacion con malloc
	//declaro ultimo nodo para buscarlo con funcion ft_last_node
	t_list	*new_node;
	t_list	*last_node;
	
	//establezco el valor de last_node al ultimo nodo de la lista
	last_node = ft_find_last_node(*node);
	//asigno un espacio para nodo a new_node
	new_node = malloc(sizeof(t_list));
	//protego el malloc
	if (new_node ==  NULL)
		return;
	//si el ultimo nodo es equivalente a null (que deberia) creo un nuevo nodo para asginarle un espacio 
	if (last_node == NULL)
		*node = new_node;
	//en caso contrario simplemente lo añado
	else
		last_node->next = new_node
	//al contenido del nuevo nodo le copio buf
	//a next del nuevo nodo que esta al final de mi lista le establezco NULL
	new_node->content = buf;
	new_node->next = NULL;
}

//crea un nuevo nodo con el contenido del texto especificado por BUFFER_SIZE
//y llama a añadirlo al final de la lista de nodos.
void	ft_create_node(t_list **node, fd)
{
	//buf para almacenar los datos leidos
	//declaro un int para contar los bytes leidos y comprobar que no da -1
	char	*buf;
	int		byte_read;
	//si no encuentra un salto de linea devolvera false, en caso contrario true
	while (!ft_found_newline(*node));
	{
		//guardo espacio para almacenar los datos leídos
		buf = malloc(BUFFER_SIZE + 1);
		//protego el malloc
		if (buf == NULL)
			return;
		//almaceno la can de bytes leidos
		//fd = archivo en el que los leo, buf = almaceno los datos leidos, BUFFER_SIZE = cantidad de chars a leer
		byte_read = read(fd, buf, BUFFER_SIZE);
		//Si no copia nada, libero buf.
		if	(!byte_read)
		{
			free(buf);
			return;
		}
		//añado el caracter nulo al final de los bytes almacenados.
		buf[byte_read] = '\0';
		//adjunto al final de mi lista enlazada lo almacenado en buf
		ft_add_lastback(node, buf);
	}

}
char	*get_next_line(int fd)
{
	t_list	*nodo;
	char 	*next_node,

	list = NULL;
	//comprobar que fd no da error, buffersize no es menor que 0
	if (BUFFER_SIZE = 0 || fd < 0)
		return (NULL);
	//llamo a funcion para crear un nuevo nodo
	ft_create_node(&node, fd);
	//llama a la funcion que me dara la siguiente linea a leer
	next_node = ft_get_next_line(node);
	ft_join_node(&nodo);
	return (next_node);
	
}

int	main()
{
	fd = open("lore.txt", O_RDONLY);
	get_next_line(fd)	
}
