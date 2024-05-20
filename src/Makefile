CC = gcc
CFLAGS = 
LIBS =  -lcheck
LINUX = -lrt -lpthread -lm 
LFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)

all: clean test gcov_report

s21_string.a:
	$(CC) -c $(CFLAGS) s21_*.c 
	ar rcs s21_string.a s21_*.o 

unit_tests.o:
	$(CC) -I$(brew --prefix check)/include -c $(CFLAGS) unit_tests.c

valgrind: test
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./unit_tests

test: clean s21_string.a unit_tests.o 
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) unit_tests.o s21_string.a -o unit_tests $(LIBS)
else
	$(CC) unit_tests.o s21_string.a -o unit_tests $(LIBS) $(LINUX)
endif
	./unit_tests

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) unit_tests.c s21_*.c -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) unit_tests.c s21_*.c -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o ./report test.info
	open ./report/index.html

rebuild: clean
	make

style:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i ./*.c ./*.h
	clang-format -n ./*.c ./*.h

clean:
	rm -rf unit_tests *.o *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf report
	rm -rf gcov_test
	rm -rf test.out
