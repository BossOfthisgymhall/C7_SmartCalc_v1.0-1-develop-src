GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS=-fprofile-arcs -ftest-coverage 
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
FILES= $(wildcard *.c)
OBJ= $(patsubst %.c,%.o,$(wildcard *.c))
OS = $(shell uname -s)
TEST_FILE = $(wildcard tests/*.c)

OS = $(shell uname -s)
ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: clean install dist test dvi run

install: uninstall
	mkdir build
	cd front/CALC && qmake && make && make clean && rm Makefile && cd ../../ && mv front/CALC/CALC.app build

run:
	open ./build/CALC.app
s21_smart_calc.a:
	$(GCC) $(FLAGS) -c back/*.c
	ar rcs s21_smart_calc.a *.o
	ranlib s21_smart_calc.a
	rm -rf *.o

uninstall:
	rm -rf build
dvi:
	open READ.md
dist:
	mkdir smart_calc/
	mkdir smart_calc/src
	cp -R back front tests build Makefile smart_calc/src
	tar cvzf smart_calc.tgz smart_calc/
	rm -rf smart_calc

test: s21_smart_calc.a
ifeq ($(OS), Darwin)
	$(GCC) $(FLAGS)  tests/*.c s21_smart_calc.a -o unit_test -lcheck -lm
else
	$(GCC) $(FLAGS) tests/*.c s21_smart_calc.a -o unit_test -lcheck $(LINUX_FLAGS)
endif
	./unit_test


gcov_report:
ifeq ($(OS), Darwin)
	$(GCC) $(FLAGS) $(GCOV_FLAGS) back/*.c $(TEST_FILE) -o gcov_test -lcheck -lm
else
	$(GCC) $(FLAGS) $(GCOV_FLAGS) back/*.c $(TEST_FILE) -o gcov_test -lcheck $(LINUX_FLAGS)
endif
	./gcov_test

	lcov --capture --directory . --output-file=coverage.info
	genhtml coverage.info --output-directory=res
	$(OPEN_CMD) ./res/index.html
	rm -rf *.gcno
	rm -rf *.gcda

check_style:
	cp ../materials/linters/.clang-format .
	clang-format -n ./back/*.c *.h ./tests/*.c ./tests/*.h ./front/CALC/*.cpp ./front/CALC/*.h

valgrind:
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./unit_test

my_test: clean my_test
	$(GCC) -o my_test back/*.c -lm -g
	./my_test
clean:
	rm -rf ./my_test
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf report