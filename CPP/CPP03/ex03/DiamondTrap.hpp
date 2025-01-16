#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

	#include "ScavTrap.hpp"
	#include "FragTrap.hpp"

	class DiamondTrap: public ScavTrap, public FragTrap
	{
		private:
			std::string name;
		public:
			DiamondTrap();
			DiamondTrap(const DiamondTrap &copy);
			DiamondTrap(std::string _name);
			virtual ~DiamondTrap();
			DiamondTrap &operator=(const DiamondTrap &src);
			void attack(const std::string &target);
			void whoAmI(void);
	};
#endif