/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luzl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:51:23 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/24 12:11:45 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_lita
{
    int valor;
}   t_lita;


void *ft_modificador(void *arg)
{
    t_lita  *lst;
    int i;

    lst = (t_lita *)arg;
    i = 1;
    while (i <= 10)
    {
        lst->valor++;
        i++;
    }
    usleep(100);
    return (NULL);
}

int  main()
{
    t_lita lista;
    pthread_t   thread[3];
    
    lista.valor = 0;

    pthread_create(&thread[0], NULL, ft_modificador, &lista);
    pthread_create(&thread[2], NULL, ft_modificador, &lista);
    pthread_create(&thread[1], NULL, ft_modificador, &lista);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);

    printf("Valor: %d \n", lista.valor);
    return (0);
}

/*//ft_modificador(&lista, 10);
    //ft_modificador(&lista, 15);*/