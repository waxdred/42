# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    timer42.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 23:07:13 by jmilhas           #+#    #+#              #
#    Updated: 2022/06/27 23:41:17 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/sh

timer(){
	echo "run main 42"
	g++ -D CHECK=0 ./test/timer_main_42.cpp -o ./build/timer_0
	g++ -D CHECK=1 ./test/timer_main_42.cpp -o ./build/timer_1
	echo "Std main"
	timer ./build/timer_0
	echo "FT main"
	timer ./build/timer_1
	exit
}

timer
