# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    timer42.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 23:07:13 by jmilhas           #+#    #+#              #
#    Updated: 2022/07/24 23:42:56 by jmilhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/sh
clear
seed="100"

echo "run main 42"
g++ -D CHECK=0 ./srcs/main.cpp -I ./includes -o ./build/timer_0
g++ -D CHECK=1 ./srcs/main.cpp -I ./includes -o ./build/timer_1
echo "Std main"
time ./build/timer_0 ${seed}
./build/timer_0 ${seed} > std
echo "FT main"
time ./build/timer_1 ${seed}
./build/timer_1 ${seed} > ft

echo "\n\ndiff std => ft"
ret=$(diff std ft)
if [ -z "$ret" ]
then
	echo "diff OK!"
else
	echo "diff Error \n $ret"
fi

rm std ft
 echo "run: make ctest \nfor full test fonction"
