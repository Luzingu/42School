#ifndef ANIMAL
#define ANIMAL
	#include <iostream>

	class Animal
	{
		protected:
			std::string _type;
		public:
			Animal(void);
			Animal(const Animal &src);
			Animal &operator=(const Animal &src);
			virtual	~Animal(void);
			virtual void makeSound(void) const;
			std::string getType(void) const;
	};
#endif