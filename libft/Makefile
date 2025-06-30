# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 13:17:47 by lseabra-          #+#    #+#              #
#    Updated: 2025/06/30 13:25:04 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAME: The name of the final library file to be created.
NAME = libft.a

# SRCS: List of source files to be compiled into object files.
SRCS =	ft_bzero.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strlen.c \
		ft_strncmp.c

# OBJS: List of object files generated from the source files.
OBJS =$(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))

#GET_NEXT_LINE
SRCS_GNL =	get_next_line.c \
			get_next_line_utils.c
OBJS_GNL = $(addprefix $(BUILD_PATH)/, $(SRCS_GNL:.c=.o))

# BUILD_PATH: Directory where object files will be stored.
BUILD_PATH = build

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
$(NAME): $(OBJS) $(OBJS_GNL)
	@$(AR) $(NAME) $(OBJS) $(OBJS_GNL)

# Rule to compile source files into object files.
$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the build directory if it doesn't exist.
$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)

# clean: Removes object files and the bonus marker file.
clean:
	@$(RM_DIR) $(BUILD_PATH)

# fclean: Removes everything created by the Makefile, including the library.
fclean: clean
	@$(RM) $(NAME)

# re: Cleans and rebuilds everything.
re: fclean all