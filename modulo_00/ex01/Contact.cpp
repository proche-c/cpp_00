/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {

    std::cout << "Se ha creado un contacto" << std::endl;
    return ;
}

Contact::~Contact( void )	{

    std::cout << "Se ha borrado un contacto" << std::endl;
}

void    Contact::set_contact_info(int amount) {

    bool valid;
    int i;

    while (this->first_name.empty())
    {
        std::cout << "Type the first name:";
        std::getline(std::cin, this->first_name);
    }
    while (this->last_name.empty())
    {
        std::cout << "Type the last name:";
        std::getline(std::cin, this->last_name);
    }
    while (this->nickname.empty())
    {
        std::cout << "Type the nickname:";
        std::getline(std::cin, this->nickname);
    }
    valid = false;
    while (this->phone_number.empty() || valid == false)
    {
        std::cout << std::setw(9);
        std::cout << "Type the phone number:";
        std::getline(std::cin, this->phone_number);
        valid = validate_phone_number(this->phone_number);
    }
    while (this->darkest_secret.empty())
    {
        std::cout << "Type the darkest secret:";
        std::getline(std::cin, this->darkest_secret);
    }
    this->index = amount;
}

bool    Contact::validate_phone_number(std::string str) {

    int     i;
    bool    result;

    result = true;
    i = 0;
    while (i < this->phone_number.length())
    {
        if (isdigit(this->phone_number[i]) == 0)
            result = false;
        i++;
    }
    if (result == false)
        std::cout << "That is not a phone number" << std::endl;
    if (this->phone_number.length() != 9)
    {
        std::cout << "A phone number should have 9 digits" << std::endl;
        result = false;
    }
    return (result);
}

void    Contact::delete_contact_info( void ) {

    this->first_name.clear();
    this->last_name.clear();
    this->nickname.clear();
    this->phone_number.clear();
    this->darkest_secret.clear();
}
