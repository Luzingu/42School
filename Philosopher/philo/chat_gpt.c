#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philosopher
{
    int id;
    int meals;
    long long last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_t thread;
    struct s_data *data;
} t_philosopher;

typedef struct s_data
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_count;
    pthread_mutex_t *forks;
    long long start_time;
    int all_alive;
    pthread_mutex_t meal_check;
} t_data;

long long current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_status(t_philosopher *philo, char *status)
{
    long long timestamp = current_time() - philo->data->start_time;
    printf("%lld %d %s\n", timestamp, philo->id, status);
}

void *routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    while (philo->data->all_alive)
    {
        // Philosopher is thinking
        print_status(philo, "is thinking");

        // Pick up forks
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");

        // Philosopher is eating
        pthread_mutex_lock(&philo->data->meal_check);
        philo->last_meal = current_time();
        print_status(philo, "is eating");
        usleep(philo->data->time_to_eat * 1000);
        philo->meals++;
        pthread_mutex_unlock(&philo->data->meal_check);

        // Put down forks
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        // Philosopher is sleeping
        print_status(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);

        // Check if philosopher has eaten enough times
        if (philo->data->must_eat_count != -1 && philo->meals >= philo->data->must_eat_count)
            break;
    }
    return NULL;
}

void *monitor(void *arg)
{
    t_philosopher *philos = (t_philosopher *)arg;
    t_data *data = philos->data;
    int meals_completed;

    while (data->all_alive)
    {
        meals_completed = 1;
        for (int i = 0; i < data->number_of_philosophers; i++)
        {
            pthread_mutex_lock(&data->meal_check);
            if ((current_time() - philos[i].last_meal) > data->time_to_die)
            {
                print_status(&philos[i], "died");
                data->all_alive = 0;
            }
            if (data->must_eat_count != -1 && philos[i].meals < data->must_eat_count)
                meals_completed = 0;
            pthread_mutex_unlock(&data->meal_check);
        }
        if (meals_completed && data->must_eat_count != -1)
        {
            data->all_alive = 0;
        }
        usleep(1000); // Sleep for a short time to avoid busy waiting
    }
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
    {
        printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
        return 1;
    }

    t_data data;
    data.number_of_philosophers = atoi(argv[1]);
    data.time_to_die = atoi(argv[2]);
    data.time_to_eat = atoi(argv[3]);
    data.time_to_sleep = atoi(argv[4]);
    data.must_eat_count = (argc == 6) ? atoi(argv[5]) : -1;
    data.all_alive = 1;
    data.forks = malloc(sizeof(pthread_mutex_t) * data.number_of_philosophers);
    pthread_mutex_init(&data.meal_check, NULL);
    for (int i = 0; i < data.number_of_philosophers; i++)
        pthread_mutex_init(&data.forks[i], NULL);

    t_philosopher *philosophers = malloc(sizeof(t_philosopher) * data.number_of_philosophers);
    data.start_time = current_time();
    for (int i = 0; i < data.number_of_philosophers; i++)
    {
        philosophers[i].id = i + 1;
        philosophers[i].meals = 0;
        philosophers[i].last_meal = data.start_time;
        philosophers[i].left_fork = &data.forks[i];
        philosophers[i].right_fork = &data.forks[(i + 1) % data.number_of_philosophers];
        philosophers[i].data = &data;
        pthread_create(&philosophers[i].thread, NULL, routine, &philosophers[i]);
    }

    // Cria a thread de monitoramento
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor, philosophers);

    // Espera que as threads dos filósofos terminem
    for (int i = 0; i < data.number_of_philosophers; i++)
        pthread_join(philosophers[i].thread, NULL);

    // Espera a thread de monitoramento terminar
    pthread_join(monitor_thread, NULL);

    // Finaliza e limpa recursos
    for (int i = 0; i < data.number_of_philosophers; i++)
        pthread_mutex_destroy(&data.forks[i]);
    pthread_mutex_destroy(&data.meal_check);
    free(data.forks);
    free(philosophers);

    return 0;
}
