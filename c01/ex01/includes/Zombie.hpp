/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/11/10 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;
    
    public:
        Zombie();
        Zombie(const std::string &inputName);
        ~Zombie();

        void setName(const std::string &newName);
        void announce(void);
};

Zombie  *zombieHorde(int N, std::string name);

#endif
