#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

	#include <iostream>

	class ClapTrap
	{
		protected:
				std::string name;
				int hit_points;
				int energy_points;
				int atack_demage;
		public:
				void attack(const std::string& target);
				void takeDamage(unsigned int amount);
				void beRepaired(unsigned int amount);
				ClapTrap(std::string _name);
				ClapTrap();
				~ClapTrap();
				ClapTrap (const ClapTrap &other);
				ClapTrap &operator=(const ClapTrap &other);
	};
	
#endif