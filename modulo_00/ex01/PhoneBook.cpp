/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	this->amount = 0;
	this->older_contact = 0;
	std::cout << "********WELCOME TO YOUR PHONE BOOK!********" << std::endl;
	std::cout << "Type ADD to insert a contact" << std::endl;
	std::cout << "Type SEARCH to display the info of a contact" << std::endl;
	std::cout << "Type EXIT to close the program" << std::endl;
	std::cout << "*******************************************" << std::endl;
}

PhoneBook::~PhoneBook( void )	{

	//std::cout << "hasta la vista, baby" << std::endl;
	return ;
}

void	PhoneBook::add_contact( void )	{

	int	i;
	
	//std::cout << "voy a añadir un contacto" << std::endl;
	if (this->amount < 8)
	{
		this->amount++;
		this->contacts[this->amount - 1].set_contact_info(this->amount);
	}
	else
	{
		this->contacts[older_contact].delete_contact_info();
		this->contacts[older_contact].set_contact_info(9);
		i = 0;
		while ( i < 8)
		{
			this->contacts[i].index--;
			i++;
		}
		if (older_contact < 7)
			older_contact++;
		else
			older_contact = 0;
	}
}

void	PhoneBook::search_contact()	{

	int	i;
	int	index_to_show;
	int	to_show;
	std::string	buff;
	bool	validate;

	//std::cout << "voy a buscar un contacto" << std::endl;
	this->show_header();
	i = older_contact;
	while (i < 8 && i < this->amount)
	{
		this->contacts[i].show_info_contact();
		i++;
	}
	i = 0;
	while (i < older_contact)
	{
		this->contacts[i].show_info_contact();
		i++;
	}
	std::cout << "Type index: ";
	std::getline(std::cin, buff);
	index_to_show = buff[0] - 48;
	if (index_to_show < 1 || index_to_show > this->amount)
		std::cout << "Invalid index" << std::endl;
	else
	{
		to_show = this->find_contact_to_show(index_to_show);
		this->contacts[to_show].display_contact();
	}
}

int		PhoneBook::find_contact_to_show(int index_to_show)	{

	int	i;

	i = 0;
	while (i < this->amount)
	{
		if (this->contacts[i].index == index_to_show)
			break ;
		i++;
	}
	return (i);
}

void	PhoneBook::show_header()	{

	std::cout << "Index     |First name|Last name |Nickname  " << std::endl;
}
