/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class	Contact	{

public:

	int			index;

	Contact( void );
	~Contact( void );

	void	set_contact_info(int amount);
	void	delete_contact_info( void );
	void	show_info_contact( void );
	void	display_contact();
	//void	set_new_index( void );

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	bool	validate_phone_number(std::string	str);
	bool	validate_name(std::string	str);

};

#endif
