
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    Zombie *zombieHorde;
    zombieHorde = new Zombie[N]; 
    i = 0;
    while (i < N)
    {
        zombieHorde[i] = Zombie(name);
        i++;
    }
    return (zombieHorde);
}