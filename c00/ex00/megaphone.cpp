/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/09/24 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	print_arg(char *args)
{
	while (*args)
	{
		if (std::isalpha(*args))
			std::cout << (char)std::toupper(*args);
		else
			std::cout << *args;
		args++;
	}
}

int	main(int argc, char **argv)
{
	char	**args;

	args = ++argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*args)
		{
			print_arg(*args);
			args++;
		}
		std::cout << std::endl;
	}
	return (0);
}
