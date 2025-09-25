/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/09/24 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            phoneBook.addContact();
        else if (cmd == "SEARCH")
            phoneBook.searchContacts();
        else if (cmd == "EXIT")
            break ;
    }
    return 0;
}
