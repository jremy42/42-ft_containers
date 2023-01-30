#!/bin/bash

# ANSI Colors
RED="\033[31;1m"
GREEN="\033[32;1m"
YEL="\033[33;1m"
BLU="\033[34;1m"
RST="\033[0m"
LOAD_BAR=""

TEST_NUMBER="0"
VALGRIND="valgrind  --leak-check=full --track-fds=yes --show-leak-kinds=all --exit-on-first-error=yes --error-exitcode=2 "
PRINT_CONTAINER_TYPE=""

function runing_tests()
{
	
	clear
	echo -e "${BLU}*************************************************${RST}"
	echo -e "${BLU}*              Running tests...                 *${RST}"
	echo -e "${BLU}*************************************************${RST}"

}

function test_success() {
	echo -e "${GREEN}SUCCESS${RST}"
}

function test_fail() {
	echo -e "${RED}FAIL${RST}"
}



function create_executable ()
{
	echo -e "${BLU}$LOAD_BAR${RST}"
	TMP=$(echo $1 | cut -c 5- | rev | cut -c 5- | rev)
	NAME=$(echo ".test_file/"$TMP)
	mkdir -p ${NAME}
	echo "Creating executable test: $NAME"
	cp $1 srcs/main.cpp
	make
	if [ $? -ne 0 ]
	then
		echo "Compilation error"
		exit 1
	fi
	mv ft_containers $NAME
	make fclean
	make std
		if [ $? -ne 0 ]
	then
		echo "Compilation error"
		exit 1
	fi
	mv std_containers $NAME
	make fclean
	clear
	cp -r random_numbers.txt $NAME
	LOAD_BAR+="#"
}

function execute_test ()
{
	TMP=$(echo $1 | cut -c 5- | rev | cut -c 5- | rev)
	EXEC_DIR=$(echo ".test_file"$TMP)
	NAME=$(echo $EXEC_DIR | rev | cut -d '/' -f 1 | rev)
	echo "$TEST_NUMBER TESTING:$NAME"
	./$EXEC_DIR/ft_containers 1> $EXEC_DIR/ft_containers.out 2> $EXEC_DIR/ft_containers.err
	./$EXEC_DIR/std_containers 1> $EXEC_DIR/std_containers.out 2> $EXEC_DIR/std_containers.err
	./compares $NAME $EXEC_DIR/ft_containers.out $EXEC_DIR/std_containers.out
	#./compares "ERRORS" $EXEC_DIR/ft_containers.err $EXEC_DIR/std_containers.err
	TEST_NUMBER=$((TEST_NUMBER + 1))

}

function check_leak()
{
	TMP=$(echo $1 | cut -c 5- | rev | cut -c 5- | rev)
	EXEC_DIR=$(echo ".test_file"$TMP)
	NAME=$(echo $EXEC_DIR | rev | cut -d '/' -f 1 | rev)
	echo "$TEST_NUMBER TESTING:$NAME"
	$VALGRIND ./$EXEC_DIR/ft_containers 1> /dev/null 2>valgrind.err
	if [ $? -ne 0 ]
	then
		echo -e "${RED}LEAKS${RST}"
		cat valgrind.err
		exit 1
	fi
	echo -e "${GREEN}NO LEAKS${RST}"
}

clear
g++ -std=c++98 -o compares test/compare.cpp
g++ -std=c++98 -o random test/random.cpp
./random > random_numbers.txt
echo "Building executable tests..."
clear

if ! test -z "$1"
then
	TEST_FILES="$1"
else
	TEST_FILES=`ls test/**/*`
fi

for i in $TEST_FILES
do
	create_executable "$i"
done

runing_tests
if ! test -z "$1"
then
	TEST_FILES="$1"
else
	TEST_FILES=`ls test/**/*`
fi

for i in $TEST_FILES
do
	TMP=$(echo $i  | cut -c 6- | cut -d '/' -f 1 | tr '[:lower:]' '[:upper:]')
	if [ "$TMP" != "$PRINT_CONTAINER_TYPE" ]
	then
		echo -e "${BLU}####[$TMP]####${RST}"
		PRINT_CONTAINER_TYPE=$TMP
	fi
	execute_test "$i"
done

for i in $TEST_FILES
do
	TMP=$(echo $i  | cut -c 6- | cut -d '/' -f 1 | tr '[:lower:]' '[:upper:]')
	if [ "$TMP" != "$PRINT_CONTAINER_TYPE" ]
	then
		echo -e "${BLU}####[$TMP]####${RST}"
		PRINT_CONTAINER_TYPE=$TMP
	fi
	check_leak "$i"
done

echo -e "${BLU}*************************************************${RST}"
echo -e "${BLU}*              BENCHMARK	                     *${RST}"
echo -e "${BLU}*************************************************${RST}"
cp -r test/time.cpp srcs/main.cpp
make
./ft_containers
make fclean
rm compares
rm random
rm random_numbers.txt
rm -rf .test_file
rm -rf valgrind.err