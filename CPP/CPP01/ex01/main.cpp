
#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    int  i;
    zombie = zombieHorde(5, "Zombie");

    i = 0;
    while (i < 5)
    {
        zombie[0].announce();
        i++;
    }
    delete[] zombie;
    return (0);
}