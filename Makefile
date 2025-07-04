# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:12:49 by lseabra-          #+#    #+#              #
#    Updated: 2025/07/04 14:56:21 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
NO_COLOR = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MKDIR = mkdir -p
RM = rm -f
RMDIR = rm -rf
TCH = touch
CP = cp
MV = mv

NAME = push_swap
MAIN = main.c
LIB_NAME = $(NAME).a

SRCS =			calc_moves.c \
				error_utils.c \
				ft_atol.c \
				input_utils.c \
				push_swap.c \
				push.c \
				retrieve_numbers.c \
				reverse_rotate.c \
				rotate.c \
				sort_three.c \
				swap.c \
				lis_utils.c
OBJS = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))
BUILD_PATH = build

#LIBFT
LIBFT_PATH = libft
LIBFT_LIB_NAME = libft.a

#BONUS
BONUS_NAME = checker
BONUS_MAIN = main_bonus.c
BONUS_MARK = .bonus
BONUS_SRCS =	checker_bonus.c \
				error_utils.c \
				ft_atol.c \
				input_utils.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c
BONUS_OBJS = $(addprefix $(BUILD_PATH)/, $(BONUS_SRCS:.c=.o))
BONUS_LIB_NAME = $(BONUS_NAME).a


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MAIN) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(MAIN) $(LIB_NAME) -o $(NAME)
	@echo "$(GREEN)[Program Compiled: $(NAME)]"

$(LIB_NAME): $(LIBFT_PATH)/$(LIBFT_LIB_NAME) $(OBJS)
	@$(CP) $(LIBFT_PATH)/$(LIBFT_LIB_NAME) ./$(LIB_NAME)
	@$(AR) $(LIB_NAME) $(OBJS)
	@echo "$(BLUE)[Static Library created: $(LIB_NAME)]"

$(LIBFT_PATH)/$(LIBFT_LIB_NAME):
	@make -C $(LIBFT_PATH) 
	@echo "$(BLUE)[Static Library created: $(LIBFT_LIB_NAME)]"

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR) $(BUILD_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RMDIR) $(BUILD_PATH)
	@echo "$(GREEN)[Clean]"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(LIB_NAME)
	@$(RM) $(BONUS_NAME)
	@$(RM) $(BONUS_LIB_NAME)
	@$(RM) $(BONUS_MARK)
	@echo "$(GREEN)[Full Clean]"

re: fclean all

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_NAME)
	@$(TCH) $(BONUS_MARK)

$(BONUS_NAME): $(BONUS_MAIN) $(BONUS_LIB_NAME)
	@$(CC) $(CFLAGS) $(BONUS_MAIN) $(BONUS_LIB_NAME) -o $(BONUS_NAME)
	@echo "$(GREEN)[Program Compiled: $(BONUS_NAME)]"

$(BONUS_LIB_NAME): $(LIBFT_PATH)/$(LIBFT_LIB_NAME) $(BONUS_OBJS)
	@$(CP) $(LIBFT_PATH)/$(LIBFT_LIB_NAME) ./$(BONUS_LIB_NAME)
	@$(AR) $(BONUS_LIB_NAME) $(BONUS_OBJS)
	@echo "$(BLUE)[Static Library created: $(BONUS_LIB_NAME)]"
