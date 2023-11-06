/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int 	main()
{
	PhoneBook	MyBook;
	bool		run;
	std::string	command;

	run = true;
	while (run)
	{
		std::cout << "Type a command:";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			MyBook.add_contact();
		else if (command.compare("SEARCH") == 0)
			MyBook.search_contact();
		else if (command.compare("EXIT") == 0)
			run = false;
	}
	return (0);
}
