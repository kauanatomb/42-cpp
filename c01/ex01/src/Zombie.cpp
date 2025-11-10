/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/09/24 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(const std::string &inputName)
{
    name = inputName;
}
Zombie::~Zombie(void) {
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(const std::string &newName) {name = newName;}
