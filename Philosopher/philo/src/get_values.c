#include "../includes/philo.h"

int get_number(t_programa *programa)
{
    int retorno;
    pthread_mutex_lock(&programa->get_value);
    retorno = programa->number;
    pthread_mutex_unlock(&programa->get_value);
    return (retorno);
}

int get_stop(t_programa *programa)
{
    int retorno;
    pthread_mutex_lock(&programa->get_value);
    retorno = programa->stop;
    pthread_mutex_unlock(&programa->get_value);
    return (retorno);
}

int get_time_to_die(t_programa *programa)
{
    int retorno;
    pthread_mutex_lock(&programa->get_value);
    retorno = programa->time_to_die;
    pthread_mutex_unlock(&programa->get_value);
    return (retorno);
}

int get_max_ate(t_programa *programa)
{
    int retorno;
    pthread_mutex_lock(&programa->get_value);
    retorno = programa->max_ate;
    pthread_mutex_unlock(&programa->get_value);
    return (retorno);
}

int get_must_eat_count(t_programa *programa)
{
    int retorno;
    pthread_mutex_lock(&programa->get_value);
    retorno = programa->must_eat_count;
    pthread_mutex_unlock(&programa->get_value);
    return (retorno);
}

int get_time_to_eat(t_programa *programa)
{
    int retorno;
    pthread_mutex_lock(&programa->get_value);
    retorno = programa->time_to_eat;
    pthread_mutex_unlock(&programa->get_value);
    return (retorno);
}