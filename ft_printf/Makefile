# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:01:08 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/28 19:16:28 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MKDIR_P = mkdir -p
RM = rm -f
RM_DIR = rm -rf
NAME = libftprintf.a
LIBFT_NAME = libft.a

SRC_PATH = .
BUILD_PATH = build
LIBFT_PATH = libft/
LIBFT_ARCH = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = $(addprefix $(SRC_PATH)/, ft_printf.c ft_print_c.c ft_print_s.c \
		ft_print_p.c ft_print_d.c ft_print_u.c ft_print_hex.c \
		ft_putchar_count.c ft_putstr_count.c ft_uintlen_base.c ft_putnbr_count.c ft_putunbr_count.c)
OBJS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_ARCH) $(BUILD_PATH) $(OBJS)
	make -C $(LIBFT_PATH) bonus
	cp $(LIBFT_PATH)/$(LIBFT_NAME) .
	mv $(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)

$(LIBFT_ARCH):
	$(MAKE) -C $(LIBFT_PATH) bonus

clean:
	$(RM_DIR) $(BUILD_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all