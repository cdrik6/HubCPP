#!/bin/bash

# Run tests for ex04
# Usage: ./run_tests.sh

# Colors
red='\033[31m'
green='\033[32m'
reset='\033[0m'

make

echo -e "\n${green}Starting tests...${reset}"


# Test 1
echo -e "\nTest 1"
./sed tests/no_matches.txt match replacement
if [ $? -eq 0 ]; then
	diff_output=$(diff tests/no_matches.txt.result tests/no_matches.txt.replace)
	if [ -z "$diff_output" ]; then
		echo -e "${green}Passed${reset}"
	else
		echo -e "${red}Failed${reset}"
	fi
fi

# Test 2
echo -e "\nTest 2"
./sed tests/one_match_per_line.txt match "word match"
if [ $? -eq 0 ]; then
	diff_output=$(diff tests/one_match_per_line.txt.result tests/one_match_per_line.txt.replace)
	if [ -z "$diff_output" ]; then
		echo -e "${green}Passed${reset}"
	else
		echo -e "${red}Failed${reset}"
	fi
fi

# Test 3
echo -e "\nTest 3"
./sed tests/multiple_matches.txt dance sway
if [ $? -eq 0 ]; then
	diff_output=$(diff tests/multiple_matches.txt.result tests/multiple_matches.txt.replace)
	if [ -z "$diff_output" ]; then
		echo -e "${green}Passed${reset}"
	else
		echo -e "${red}Failed${reset}"
	fi
fi

# Test 4
echo -e "\nTest 4"
./sed tests/numbers.txt 5 Z
if [ $? -eq 0 ]; then
	diff_output=$(diff tests/numbers.txt.result tests/numbers.txt.replace)
	if [ -z "$diff_output" ]; then
		echo -e "${green}Passed${reset}"
	else
		echo -e "${red}Failed${reset}"
	fi
fi

# Test 5
echo -e "\nTest 5"
./sed tests/special_chars.txt "$" "\"*
\""
if [ $? -eq 0 ]; then
	diff_output=$(diff tests/special_chars.txt.result tests/special_chars.txt.replace)
	if [ -z "$diff_output" ]; then
		echo -e "${green}Passed${reset}"
	else
		echo -e "${red}Failed${reset}"
	fi
fi

# Test 6
echo -e "\nTest 6"
./sed tests/toto.txt "
" "aaa"
if [ $? -eq 0 ]; then
	diff_output=$(diff tests/toto.txt.result tests/toto.txt.replace)
	if [ -z "$diff_output" ]; then
		echo -e "${green}Passed${reset}"
	else
		echo -e "${red}Failed${reset}"
	fi
fi

echo -e "\n${green}Tests finished${reset}"