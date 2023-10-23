/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:15:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/23 19:18:59 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FUNCION QUE BUSCA SALTO DE LINEA
//int i para recorrer strings
//char dest para guardar nuestra string de retorno
//mientras buf y buff sea distinto de salto de linea
//incrementamos i para conocer la longitud que hay hasta el salto
//cuando rompa el bucle hacemos un malloc de i + 1
//protegemos el malloc de dest
//reiniciamos i = 0
//SI ft_strchr(buf, \n != 0)
//ret = 1;
//MIENTRAAS haya buff, sea iterable y sea distinto de salto de linea)
//copiamos en dest el contenido de buf
//terminamos dest con caracter nulo
//lo devolvemos


//FUNCION PARA COPIAR LOS QUE SIGUE A SALTO DE LINEA
//declaramos iterador de i
//declaramoos iterador de j
//char dest, para guardar
//incializamos de iterador i a  0
//MIENTRAS  haya buff, sea iterable, y sea distinto de salto de linea
//iteramos i
//hacemos malloc de destino, por la talla de buffer, menos la longitud de i(que equivale a los bytes  que hay hasta el salto de linea) mas 1 para el caracter nulo
//protegemos dest en caso de que malloc falle
//inicializamos j a 0
//mientras haya buffer y sea iterable
//copiamos el contenido de buf en dest
//icrementamos j
//y preincrementamos i para copiar el caracter salto de linea
//colocamos el caracter nulo al final de destino
//devolvermos este


//GET NEXT  LINE
//char buf que vale BUFFER_SIZE + 1
//int ret (retorno), para saber si el read a fallado
//static char *str para guardar nuextro textpo (?)
//char *temp para guardar temporalmente datos

//retonro = buffer_size
//conotrolar fd negtivo, o superior a 1023, si no hay linea, o el buffer es <= 0
//ret se iguala a -1
//si retorno es mayor que 0. se iguala a read
//se protege otra vez que si read es igual a -1, ret sea -1;
//buf[ret] = '\0' para terminar el fichero, puesto que real devuelve la longitud
//
//llamamos a ft_strjoin para unir nuestra str (vacia la primera vez) y buf (donde hemos leido conread la cantidad x de bytes)
//y luego liberamos temp con un free
//IF detectamos un salto de linea paramos, la manera de comprobarlo sera con ft_strchr (str \n)
//hacemos  un break
//
//llamar a una funcion que busque salto de linea (str y de nuestro valor de ret)
//guardar en temp nuestra str
//guardar en nuestra str static todo lo que sigue del salto llamando a funcion.
//liberar de nuevo temp
//si el valor de retorno es igual a 0 o str[0] es igual a 0
//liberar str
//reestablecerla en 0
//devolver el retorno


