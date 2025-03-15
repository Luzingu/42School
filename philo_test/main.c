#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_programa
{
    int numb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int times_to_eat;
}   t_programa;


int soma_total = 0;
pthread_mutex_t lock;

void *ft_executor(void *valor)
{
    int i = 0;

    while (i <= 10000)
    {
        pthread_mutex_lock(&lock);
        soma_total++;
        pthread_mutex_unlock(&lock);
        i++;
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_t t1, t2;
    t_programa *programa;
    programa = (t_programa *)malloc(sizeof(t_programa));

    if (argc != 6)
    {
        printf("Error \n");
        return (0);
    }
    programa->numb_philo = atoi(argv[1]);
    programa->time_to_die = atoi(argv[2]);
    programa->time_to_eat = atoi(argv[3]);
    programa->time_to_sleep = atoi(argv[4]);
    programa->times_to_eat = atoi(argv[5]);


    
    //pthread_join(t2, NULL);

    return (0);
}