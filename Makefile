# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 18:03:15 by mefische          #+#    #+#              #
#    Updated: 2025/08/07 18:03:15 by mefische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE 			= make -s --no-print-directory -C
NAME 			= push_swap

SRC				= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS			= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
HEADERS			= $(INC_PATH)/push_swap.h

SRC_PATH		= src
INC_PATH		= src
LIBS_PATH		= lib
BUILD_PATH		= .build

FILES			= main.c parsing.c parsing_utils.c

LIBFT_URL 		= https://github.com/mfischer-98/Libft_extra.git
LIBFT_PATH		= $(LIBS_PATH)/libft
LIBFT_ARC		= $(LIBFT_PATH)/libft.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
INC				= -I $(INC_PATH)
RM				= rm -rf
AR				= ar rcs
MKDIR_P			= mkdir -p


#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: deps $(BUILD_PATH) $(NAME)	#Compile

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(OBJS)	## Compile
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT_ARC) -o $(NAME)
	@echo " $(MAG)🌸 Compiling $(MAG)$(NAME)$(D)"


deps:		#Download/Update deps
	@if test -d "$(LIBFT_PATH)"; then \
		echo "    $(B)$(D)$(CYN)[Nothing to be done 𖡼.𖤣𖥧𖡼.𖤣𖥧$(D)]"; fi
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "    $(CYN)[libft] folder found 𖡼.𖤣𖥧𖡼.𖤣𖥧"; fi

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo " $(B)$(MAG)🌸 Creating build folder..."

$(LIBFT_ARC):
	@$(MAKE) $(LIBFT_PATH) >/dev/null 2>&1

get_libft:
	@echo "   $(B)Getting Libft$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	@git clone -q $(LIBFT_URL) $(LIBFT_PATH);
	@echo " $(B)$(MAG)🌸 Libft submodule download$(D)..."

clean:				#Remove object files
	@echo "$(CYN)𖡼.𖤣𖥧𖡼.𖤣𖥧 $(B)Cleaning object files$(D)"
	@$(RM) $(BUILD_PATH); 
	@echo "         -Removing $(BUILD_PATH) folder & files"; \

fclean: clean			#Remove executable and .gdbinit
	@echo "$(CYN)𖡼.𖤣𖥧𖡼.𖤣𖥧 $(B)Cleaning executables$(D)"
	@$(RM) $(NAME);
	@echo "         -Removing $(NAME) file"; \

libclean: fclean	#Remove libs
	@echo "$(CYN)𖡼.𖤣𖥧𖡼.𖤣𖥧 $(B)Cleaning libs$(D)"
	@$(RM) $(LIBS_PATH)
	@$(RM) push_swap_visualizer

re: libclean all

.PHONY: all deps clean fclean libclean re tester get_libft visualizer

# Colors
#
B		= $(shell tput bold)
D		= $(shell tput sgr0)
CYN		= $(shell tput setaf 6)
MAG		= $(shell tput setaf 5)