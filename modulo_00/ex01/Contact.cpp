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

    //std::cout << "Se ha creado un contacto" << std::endl;
    return ;
}

Contact::~Contact( void )	{

    //std::cout << "Se ha borrado un contacto" << std::endl;
}

void    Contact::set_contact_info(int amount) {

    bool valid;
    int i;

    valid = false;
    while (this->first_name.empty() || valid == false)
    {
        std::cout << "Type the first name:";
        std::getline(std::cin, this->first_name);
        valid = validate_name(this->first_name);
    }
    valid = false;
    while (this->last_name.empty() || valid == false)
    {
        std::cout << "Type the last name:";
        std::getline(std::cin, this->last_name);
        valid = validate_name(this->first_name);
    }
    valid = false;
    while (this->nickname.empty() || valid == false)
    {
        std::cout << "Type the nickname:";
        std::getline(std::cin, this->nickname);
        valid = validate_name(this->first_name);
    }
    valid = false;
    while (this->phone_number.empty() || valid == false)
    {
        std::cout << std::setw(9);
        std::cout << "Type the phone number:";
        std::getline(std::cin, this->phone_number);
        valid = validate_phone_number(this->phone_number);
    }
    valid = false;
    while (this->darkest_secret.empty() || valid == false)
    {
        std::cout << "Type the darkest secret:";
        std::getline(std::cin, this->darkest_secret);
        valid = validate_phone_number(this->phone_number);
    }
    this->index = amount;
}

bool    Contact::validate_name(std::string   str)    {

    if (str.empty() == true)
        return (false);
    else
        return (true);
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

void    Contact::show_info_contact( void )  {

    std::string first_name_to_show;
    std::string last_name_to_show;
    std::string nickname_to_show;

    std::cout << this->index << "         |";
    if (this->first_name.length() > 10)
    {
        first_name_to_show = this->first_name.substr(0, 9);
        std::cout << first_name_to_show << ".|";
    }
    else
    {
        first_name_to_show = this->first_name.substr(0, this->first_name.length());
        first_name_to_show.resize(10, ' ');
        std::cout << first_name_to_show << "|";
    }
    if (this->last_name.length() > 10)
    {
        last_name_to_show = this->last_name.substr(0, 9);
        std::cout << last_name_to_show << ".|";
    }
    else
    {
        last_name_to_show = this->last_name.substr(0, this->last_name.length());
        last_name_to_show.resize(10, ' ');
        std::cout << last_name_to_show << "|";
    }
    if (this->nickname.length() > 10)
    {
        nickname_to_show = this->nickname.substr(0, 9);
        std::cout << nickname_to_show << "." << std::endl;
    }
    else
    {
        nickname_to_show = this->nickname.substr(0, this->nickname.length());
        nickname_to_show.resize(10, ' ');
        std::cout << nickname_to_show << std::endl;
    }
}

void    Contact::display_contact( void )    {

    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}
