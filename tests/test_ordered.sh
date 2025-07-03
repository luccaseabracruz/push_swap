#!/bin/bash
RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

sequences=(
	"0 1"
	"0 1 2"
	"0 1 2 3"
	"0 1 2 3 4"
	"0 1 2 3 4 5"
	"0 1 2 3 4 5 6"
	"0 1 2 3 4 5 6 7"
	"0 1 2 3 4 5 6 7 8"
	"0 1 2 3 4 5 6 7 8 9"
	"0 1 2 5 6 8"
	"0 2 4 6 8"
	"1 3 5 7 9"
	"0 1 2 4 5 6 7 8"
	"0 1 2 4 5 6 7 8 9"
)

for arg in "${sequences[@]}"; do
	ordered=$(../push_swap $arg | ../checker_linux $arg)
	if [ "$ordered" == "OK" ]; then
		echo -e "${GREEN}OK${RESET}"
	else
		echo -e "${RED}KO${RESET}"
	fi
	count=$(../push_swap $arg | wc -l)
	if [ "$count" -ge 1 ]; then
		echo "$arg"
		echo -e "${RED}${count}${RESET}"
	else
		echo -e "${GREEN}${count}${RESET}"
	fi
done
