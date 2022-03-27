#include "../includes/Contact.hpp"

static  void	ft_menu(void)
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "\tADD" << std::endl;
	std::cout << "\tSEARCH" << std::endl;
	std::cout << "\tEXIT" << std::endl;
	std::cout << std::endl;
}


int	main(void)
{
	int	index;
	Contact	phone[NB_CONTACT];
	std::string	command;

	index = 0;
	while (1)
	{
		ft_menu();
		if (index == NB_CONTACT)
			index = 0;
		getline(std::cin, command, '\n');
		for (int i = 0; i < (int)command.length(); i++)
			command[i] = toupper(command[i]);
		if (command == "ADD")
		{
			ft_add_contact(&phone[index]);
			index++;
		}
		else if (command == "SEARCH")
			ft_search(phone);
		else if (command == "EXIT")
			return(0);
	}
	return (0);
}
