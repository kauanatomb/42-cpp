/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/09/24 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : count(0), nextIndex(0) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact()
{
    Contact newContact;
    if (newContact.setContact())
    {
        contacts[nextIndex] = newContact;
        nextIndex = (nextIndex + 1) % 8;
        if (count < 8)
            count++;
    }
}

void PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty!" << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for(int i = 0; i < count; i++)
        contacts[i].displayShort(i);
    
    std::cout << "Enter index of contact: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.size() != 1 || !isdigit(input[0]))
    {
        std::cout << "Invalid index!" << std::endl;
        return ;
    }
    int index = input[0] - '0';
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index!" << std::endl;
        return ;
    }
    contacts[index].displayFull();
}
