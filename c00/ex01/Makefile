# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 10:18:02 by ktombola          #+#    #+#              #
#    Updated: 2025/09/24 10:18:06 by ktombola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I includes
SRC =  src/Contact.cpp src/main.cpp src/PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re