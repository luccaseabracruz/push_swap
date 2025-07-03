# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 17:06:04 by lseabra-          #+#    #+#              #
#    Updated: 2025/07/03 14:20:06 by lseabra-         ###   ########.fr        #
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

PROGRAM = ../push_swap
CHECKER = ../checker_linux

TEST_ORDERED = test_ordered.sh
TEST_5_RANDOM = test_5_random.sh
TEST_100_RANDOM = test_100_random.sh
TEST_500_RANDOM = test_500_random.sh

FAILS_FILE = fails.txt

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(PROGRAM) $(CHEKER)

$(PROGRAM):
	make -C ../

$(CHECKER):
	make -C ../ bonus

test: all $(PROGRAM)
	@echo "$(YELLOW)\n\n\n[ORDERED NUMBERS TESTS ( < 1)]"
	@./$(TEST_ORDERED)
	@echo "$(YELLOW)\n\n\n[5 RANDOM NUMBERS TESTS ( < 12 operations)]"
	@./$(TEST_5_RANDOM)
	@echo "$(YELLOW)\n\n\n[100 RANDOM NUMBERS TESTS ( < 700 operations)]"
	@./$(TEST_100_RANDOM)
	@echo "$(YELLOW)\n\n\n[500 RANDOM NUMBERS TESTS ( < 5500 operations)]"
	@./$(TEST_500_RANDOM)

clean:
	rm $(FAILS_FILE)	
