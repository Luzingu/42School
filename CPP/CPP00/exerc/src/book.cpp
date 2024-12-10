#include "../header/header.hpp"
#include "contact.cpp"

class PhoneBook
{
	public:
		Contact contacts[8];
	private:
		int index;
	public:
		PhoneBook(void)
		{
			this->index = 0;
			std::string line;
			int stop = 0;

			while (!stop)
			{
				std::cout << "Enter the comand (ADD, SEARCH, EXIT)" << std::endl;
				std::getline(std::cin, line);
				if (std::cin.eof())
					break;

				if (line == "ADD")
				{
					if(this->index == 8)
						this->ft_last_contact();
					contacts[this->index].fill_contact();
					this->index++;
				}
				else if(line == "SEARCH")
				{
					int i; 
					i = 0;
					std::cout << std::setw(11);
					std::cout << "Index |";
					std::cout << std::setw(11);
					std::cout << "First Name |";
					std::cout << std::setw(11);
					std::cout << "Last Name |";
					std::cout << std::setw(11);
					std::cout << "Nick Name";
					std::cout << std::endl;
					while (i < this->index)
					{
						contacts[i].print_contact(i);
						std::cout << std::endl;
						i++;
					}

					if(this->index > 0)
					{
						std::cout << "Search contact by Index: ";
						std::cin >> i;
						if(i >= this->index || i < 0)
							std::cout << "Index Nof Found" << std::endl;
						else
							contacts[i].print_contact_detail();
					}
				}
				else if(line == "EXIT")
					break;
				else
					std::cout << "Invalid Comand." << std::endl;
			}
		}
	private:
		void	ft_last_contact()
		{
			int i;

			i = 0;
			while (i < (this->index - 1))
			{
				contacts[i] = contacts[i + 1];
			}
			this->index = 7;
		}	

};