# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 11:48:51 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/14 15:15:31 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAME: The name of the final library file to be created.
NAME = libft.a

# SRCS: List of source files to be compiled into object files.
SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c \
        ft_isascii.c ft_isprint.c ft_strlen.c \
        ft_memset.c ft_bzero.c ft_memcpy.c  \
        ft_memmove.c ft_strlcpy.c ft_strlcat.c  \
        ft_toupper.c ft_tolower.c ft_strchr.c \
        ft_strrchr.c ft_strncmp.c ft_memchr.c \
        ft_memcmp.c ft_strnstr.c ft_atoi.c \
        ft_calloc.c ft_strdup.c ft_substr.c \
        ft_strjoin.c ft_strtrim.c ft_split.c \
        ft_itoa.c ft_strmapi.c ft_striteri.c \
        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
        ft_putnbr_fd.c

# OBJS: List of object files generated from the source files.
OBJS =$(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))

# BUILD_PATH: Directory where object files will be stored.
BUILD_PATH = build

# BONUS: List of bonus source files for additional functionality.
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# BONUS_OBJS: List of object files generated from the bonus source files.
BONUS_OBJS = $(addprefix $(BUILD_PATH)/, $(BONUS:.c=.o))

# BONUS_MARK: A marker file to indicate that the bonus has been built.
BONUS_MARK = .bonus

# Compiler and flags
CC = cc                # Compiler to use
CFLAGS = -Wall -Wextra -Werror  # Compilation flags

# Utility commands
TCH = touch            # Command to create an empty file
RM = rm -f             # Command to remove files
RM_DIR = rm -rf        # Command to remove directories
AR = ar rcs            # Command to create a static library
MKDIR_P = mkdir -p     # Command to create a directory


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

# .PHONY: Declares phony targets to avoid conflicts with files of the same name.
.PHONY: all clean fclean re

# all: Default target to build the library.
all: $(NAME)

# $(NAME): Rule to create the library from object files.
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# Rule to compile source files into object files.
$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the build directory if it doesn't exist.
$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)

# bonus: Target to build the library with bonus functionality.
bonus: $(BONUS_MARK)

# $(BONUS_MARK): Rule to build the library with bonus object files.
$(BONUS_MARK): $(OBJS) $(BONUS_OBJS) | $(BUILD_PATH)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@$(TCH) $(BONUS_MARK)

# clean: Removes object files and the bonus marker file.
clean:
	@$(RM_DIR) $(BUILD_PATH)
	@$(RM) $(BONUS_MARK)

# fclean: Removes everything created by the Makefile, including the library.
fclean: clean
	@$(RM) $(NAME)

# re: Cleans and rebuilds everything.
re: fclean all
