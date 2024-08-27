/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_funcion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:56:45 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 11:53:01 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool    has_simulation_stopped(t_programa *programa)
{
    bool ret;

    ret = false;
    pthread_mutex_lock(&programa->stop_lock);
    if (programa->stop == true)
        ret = true;
    pthread_mutex_unlock(&programa->stop_lock);
    return (ret);
}