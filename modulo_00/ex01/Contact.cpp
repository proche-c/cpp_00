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

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact( void ) {

    return ;
}

Contact::~Contact( void )	{

    return ;
}

void    Contact::set_contact_info(int amount) {

    bool valid;
    int i;

    valid = false;
    while (this->_first_name.empty() || valid == false)
    {
        std::cout << "Type the first name:";
        std::getline(std::cin, this->_first_name);
        valid = _validate_name(this->_first_name);
    }
    valid = false;
    while (this->_last_name.empty() || valid == false)
    {
        std::cout << "Type the last name:";
        std::getline(std::cin, this->_last_name);
        valid = _validate_name(this->_first_name);
    }
    valid = false;
    while (this->_nickname.empty() || valid == false)
    {
        std::cout << "Type the nickname:";
        std::getline(std::cin, this->_nickname);
        valid = _validate_name(this->_nickname);
    }
    valid = false;
    while (this->_phone_number.empty() || valid == false)
    {
        std::cout << std::setw(9);
        std::cout << "Type the phone number:";
        std::getline(std::cin, this->_phone_number);
        valid = _validate_phone_number(this->_phone_number);
    }
    valid = false;
    while (this->_darkest_secret.empty() || valid == false)
    {
        std::cout << "Type the darkest secret:";
        std::getline(std::cin, this->_darkest_secret);
        valid = _validate_name(this->_darkest_secret);
    }
    this->index = amount;
}

bool    Contact::_validate_name(std::string   str)    {

    if (str.empty() == true)
        return (false);
    else
        return (true);
}

bool    Contact::_validate_phone_number(std::string str) {

    int     i;
    bool    result;

    result = true;
    i = 0;
    while (i < this->_phone_number.length())
    {
        if (isdigit(this->_phone_number[i]) == 0)
            result = false;
        i++;
    }
    if (result == false)
        std::cout << "That is not a phone number" << std::endl;
    if (this->_phone_number.length() != 9)
    {
        std::cout << "A phone number should have 9 digits" << std::endl;
        result = false;
    }
    return (result);
}

void    Contact::delete_contact_info( void ) {

    this->_first_name.clear();
    this->_last_name.clear();
    this->_nickname.clear();
    this->_phone_number.clear();
    this->_darkest_secret.clear();
}

void    Contact::show_info_contact( void )  {

    std::string first_name_to_show;
    std::string last_name_to_show;
    std::string nickname_to_show;

    std::cout << this->index << "         |";
    if (this->_first_name.length() > 10)
    {
        first_name_to_show = this->_first_name.substr(0, 9);
        std::cout << first_name_to_show << ".|";
    }
    else
    {
        first_name_to_show = this->_first_name.substr(0, this->_first_name.length());
        first_name_to_show.resize(10, ' ');
        std::cout << first_name_to_show << "|";
    }
    if (this->_last_name.length() > 10)
    {
        last_name_to_show = this->_last_name.substr(0, 9);
        std::cout << last_name_to_show << ".|";
    }
    else
    {
        last_name_to_show = this->_last_name.substr(0, this->_last_name.length());
        last_name_to_show.resize(10, ' ');
        std::cout << last_name_to_show << "|";
    }
    if (this->_nickname.length() > 10)
    {
        nickname_to_show = this->_nickname.substr(0, 9);
        std::cout << nickname_to_show << "." << std::endl;
    }
    else
    {
        nickname_to_show = this->_nickname.substr(0, this->_nickname.length());
        nickname_to_show.resize(10, ' ');
        std::cout << nickname_to_show << std::endl;
    }
}

void    Contact::display_contact( void )    {

    std::cout << "First name: " << this->_first_name << std::endl;
    std::cout << "Last name: " << this->_last_name << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}
