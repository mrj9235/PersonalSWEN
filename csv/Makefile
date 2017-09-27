run: csv test
	./csv<food.csv
	./test

csv: csv.c unit_tests.c
	gcc -o csv csv.c unit_tests.c

test: csv.c unit_tests.c
	gcc -o test csv.c unit_tests.c
