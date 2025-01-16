#ifndef ANIMAL
#define ANIMAL
	#include <iostream>

	class Animal
	{
		protected:
			std::string _type;
			Animal(void);
		public:
			Animal(const Animal &src);
			Animal &operator=(const Animal &src);
			virtual	~Animal(void);
			virtual void makeSound(void) const = 0;
			std::string getType(void) const;
	};
#endif