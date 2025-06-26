# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:12:49 by lseabra-          #+#    #+#              #
#    Updated: 2025/06/26 16:30:14 by lseabra-         ###   ########.fr        #
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

SRCS =	swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		input_utils.c \
		sort_three.c \
		calc_moves.c \
		push_swap.c \
		retrieve_numbers.c \
		ft_atol.c
OBJS = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))
BUILD_PATH = build

#LIBFT
SRCS_LIBFT =	ft_bzero.c \
				ft_calloc.c \
				ft_isdigit.c \
				ft_memset.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strlen.c \
				ft_strncmp.c \
				error_utils.c
OBJS_LIBFT = $(addprefix $(BUILD_PATH)/, $(SRCS_LIBFT:.c=.o))
#GET_NEXT_LINE
SRCS_GNL =  get_next_line.c \
			get_next_line_utils.c
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

$(NAME): $(MAIN) $(LIB_NAME)
	$(CC) $(CFLAGS) $(MAIN) $(LIB_NAME) -o $(NAME)

$(LIB_NAME): $(OBJS_LIBFT) $(OBJS)
	$(AR) $(LIB_NAME) $(OBJS_LIBFT) $(OBJS)

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(NAME_BONUS)
	$(RM) .bonus

re: fclean all

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(NAME_BONUS)
	$(TCH) $(BONUS_MARK)

$(NAME_BONUS): $(MAIN_BONUS) $(LIB_NAME) $(OBJS_BONUS) $(OBJS_GNL)
	$(AR) $(LIB_NAME) $(OBJS_BONUS) $(OBJS_GNL)
	$(CC) $(CFLAGS) $(MAIN_BONUS) $(LIB_NAME) -o $(NAME_BONUS)
