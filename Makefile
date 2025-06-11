# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:12:49 by lseabra-          #+#    #+#              #
#    Updated: 2025/06/11 18:47:40 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MKDIR = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = push_swap.a
SRCS = swap.c push.c rotate.c reverse_rotate.c input_utils.c
OBJS = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))
BUILD_PATH = build
FT_PRINTF_PATH = ft_printf
FT_PRINTF_NAME = libftprintf.a

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT_PRINTF_PATH) all
	cp $(FT_PRINTF_PATH)/$(FT_PRINTF_NAME) .
	mv $(FT_PRINTF_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all