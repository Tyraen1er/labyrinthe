# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eferrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 22:43:33 by eferrand          #+#    #+#              #
#    Updated: 2017/10/01 05:09:38 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# our executable name
NAME			:=	labyrinthe

# base dirs
SRC_DIR			:=	./srcs
INC_DIR			:=	./includes
LIB_DIR			:=	./libs
OBJ_DIR			:=	./objs

# files to compile
FILE_LIST		:=	main_init.cpp		\
					pars.cpp

OBJ_FILES		:= $(addprefix $(OBJ_DIR)/,$(FILE_LIST:.cpp=.o))

# libraries
#LIB_FT			:=	$(LIB_DIR)/libft
#LIB_FT_INC		:=	-I $(LIB_FT)/includes/
#LIB_FT_LINK		:=	-L $(LIB_FT) -l ft

LIB_SDL_LINK	:=	-l SDL2

# our project
INCLUDES		:=	-I$(INC_DIR) #$(LIB_FT_INC) 
LINK			:=	$(LIB_SDL_LINK) -fsanitize=address -O0 #$(LIB_FT_LINK) 

# compiler and flags
CC				:=	g++
CFLAGS			:= -Wall -Wextra -Werror -fsanitize=address -O0

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

# linking rule: executable NAME needs OBJ_FILES to link
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LINK) -o $(NAME)

# compiler rule: each .o file in OBJ_DIR needs a .c file in SRC_DIR
# $< -- input file (.c)
# $@ -- output file (.o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

relibs:
	#@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all
