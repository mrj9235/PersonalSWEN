# Makefile for julius
julius: julius.o main.o
	gcc -g -o julius main.o julius.o

julius.o: julius.c
	gcc -g -c julius.c

main.o: julius.h main.c
	gcc -g -c main.c

run_test: julius.o julius_tests.o
	gcc -g -o run_test julius_tests.o julius.o

julius_tests.o: julius.o julius_tests.c
	gcc -g -c julius_tests.c

test: run_test
	./run_test

test_full: julius
	./julius < plain.txt > output.txt
	diff -cB cipher.txt output.txt

clean:
	rm -f *.o julius run_test
