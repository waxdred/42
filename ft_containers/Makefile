# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 22:49:51 by jmilhas           #+#    #+#              #
#    Updated: 2022/07/24 23:51:15 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = ./build/cmake_install.cmake
execute = containers

FILES := $(shell ls | grep compile_commands)

ifeq ($(FILES), compile_commands.json)
	RULES = cd ./build && make
else
	RULES = mkdir build 2>/dev/null && cd ./build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. \
		&& make && mv ./compile_commands.json ..
endif


all:
	$(RULES)
	echo "run: make 42test\n\tfor compare test main 42 with ft et std\n"
	echo "run: make ctest\n\tfor full fonction test libs"

clean:
	@rm -rf ./build 2>/dev/null
	@rm ./compile_commands.json 2>/dev/null

fclean: clean

ctest:
	clear
	@echo "Run Test"
	cd ./build && ctest

log:
	cat ./build/Testing/Temporary/LastTest.log 2>/dev/null

42Test:
	sh script/timer42.sh

.PHONY: all clean fclean re san
.SILENT :
