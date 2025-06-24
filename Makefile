# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:12:49 by lseabra-          #+#    #+#              #
#    Updated: 2025/06/24 18:28:15 by lseabra-         ###   ########.fr        #
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
TCH = touch

MAIN = main.c
NAME = push_swap
LIB_NAME = $(NAME).a

SRCS =  swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		input_utils.c \
		sort_three.c \
		calc_moves.c \
		push_swap.c \
		retrieve_numbers.c
OBJS = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))
BUILD_PATH = build
FT_PRINTF_PATH = ft_printf
FT_PRINTF_NAME = libftprintf.a

#LIBFT
LIBFT_SRCS =  
LIBFT_OBJS = $(addprefix $(BUILD_PATH)/, $(LIBFT_SRCS:.c=.o))
#GET_NEXT_LINE
SRCS_GNL =  get_next_line_bonus.c \
			get_next_line_utils_bonus.c
OBJS_GNL = $(addprefix $(BUILD_PATH)/, $(SRCS_GNL:.c=.o))
#BONUS
NAME_BONUS = checker
MAIN_BONUS = main_bonus.c
BONUS_MARK = .bonus
SRCS_BONUS = checker.c
OBJS_BONUS = $(addprefix $(BUILD_PATH)/, $(SRCS_BONUS:.c=.o))


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIB_NAME)
	$(CC) $(CFLAGS) $(MAIN) $(LIB_NAME) -o $(NAME)

$(LIB_NAME): $(OBJS) $(LIBFT_OBJS)
	make -C $(FT_PRINTF_PATH) all
	cp $(FT_PRINTF_PATH)/$(FT_PRINTF_NAME) .
	mv $(FT_PRINTF_NAME) $(LIB_NAME)
	$(AR) $(LIB_NAME) $(OBJS)

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(NAME_BONUS)
	$(RM) .bonus
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(NAME_BONUS)
	$(TCH) $(BONUS_MARK)

$(NAME_BONUS): $(LIB_NAME) $(OBJS_BONUS) $(OBJS_GNL)
	$(AR) $(LIB_NAME) $(OBJS_BONUS) $(OBJS_GNL)
	$(CC) $(CFLAGS) $(MAIN_BONUS) $(LIB_NAME) -o $(NAME_BONUS) -g
