#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

	#include "ClapTrap.hpp"

	class ScavTrap: virtual public ClapTrap
	{
		private:
			bool guarding_gate;
		public:
			ScavTrap(void);
			ScavTrap(std::string _name);
			virtual ~ScavTrap();
			ScavTrap (const ScavTrap &src);
			ScavTrap &operator=(const ScavTrap &src);
			void attack(const std::string& target);
			void guardGate(void);
	};

#endif