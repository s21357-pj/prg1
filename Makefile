CC=g++
CFLAGS="-std=c++11"
test: 
	$(CC) $(CFLAGS) rpn_calc.cpp -Wall -Werror -o rpn_calc
