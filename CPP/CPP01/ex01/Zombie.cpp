
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    Zombie::name = name;
    std::cout << "Zombie (" << name << ") created" << std::endl;
}

Zombie::Zombie()
{
    
}

Zombie::~Zombie()
{
    std::cout << "Zombie (" << Zombie::name << ") destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << Zombie::name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}