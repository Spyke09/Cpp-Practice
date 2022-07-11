main: main.o print_hello.o
	g++ main.o print_hello.o -o main

main.o: main.cpp
	g++ main.cpp -O2 -c

print_hello.o: print_hello.cpp
	g++ print_hello.cpp -O2 -c