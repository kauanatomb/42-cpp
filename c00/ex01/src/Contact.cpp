/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/09/24 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

bool Contact::setContact()
{
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, firstName);
    if (firstName.empty()) return false;

    std::cout << "Last name: ";
    std::getline(std::cin, lastName);
    if (lastName.empty()) return false;

    std::cout << "Nick name: ";
    std::getline(std::cin, nickName);
    if (nickName.empty()) return false;

    std::cout << "Phone number: ";
    std::getline(std::cin, phoneNumber);
    if (phoneNumber.empty()) return false;

    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestSecret);
    if (darkestSecret.empty()) return false;

    return true;
}

void Contact::displayShort(int index) const
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << formatField(firstName) << "|"
              << std::setw(10) << formatField(lastName) << "|"
              << std::setw(10) << formatField(nickName) << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string Contact::formatField(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}
