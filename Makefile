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

MAKE			= make -s --no-print-directory -C
NAME			= push_swap

SRC				= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS			= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
HEADERS			= $(INC_PATH)/push_swap.h

SRC_PATH		= src
INC_PATH		= src
BUILD_PATH		= .build

FILES			= main.c parsing.c parsing_utils.c list_utils.c sort_small.c radix_sort.c commands/push.c commands/rotate.c commands/rev_rotate.c commands/swap.c

LIBFT_PATH		= libft/libft.a
LIBFT_ARC		= $(LIBFT_PATH)

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


deps:		#Check
	@if test -f "$(LIBFT_PATH)"; then \
		echo "    $(B)$(D)$(CYN)[Nothing to be done 𖡼.𖤣𖥧𖡼.𖤣𖥧$(D)]"; fi

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo " $(B)$(MAG)🌸 Creating build folder..."

$(LIBFT_ARC):
	@make -C libft

clean:				#Remove object files
	@echo "$(CYN)𖡼.𖤣𖥧𖡼.𖤣𖥧 $(B)Cleaning object files$(D)"
	@$(RM) $(BUILD_PATH);
	@make -C libft clean
	@echo "         -Removing $(BUILD_PATH) folder & files"; \

fclean: clean		#Remove executables
	@echo "$(CYN)𖡼.𖤣𖥧𖡼.𖤣𖥧 $(B)Cleaning executables$(D)"
	@$(RM) $(NAME);
	@make -C libft fclean
	@echo "         -Removing $(NAME) file"; \

re: fclean all

.PHONY: all deps clean fclean libclean re tester get_libft visualizer

# Colors
B		= $(shell tput bold)
D		= $(shell tput sgr0)
CYN		= $(shell tput setaf 6)
MAG		= $(shell tput setaf 5)