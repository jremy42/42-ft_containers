#!/bin/bash

# ANSI Colors
RED="\033[31;1m"
GREEN="\033[32;1m"
RST="\033[0m"


TEST_NUMBER="0"
VALGRIND="valgrind"

function test_success() {
	echo -e "${GREEN}SUCCESS${RST}"
}

function test_fail() {
	echo -e "${RED}FAIL${RST}"
}



function create_executable ()
{
	NAME=$(echo ".test_file/"$1 | rev | cut -c 5- | rev)
	mkdir -p ${NAME}
	cp $1 srcs/main.cpp
	make
	mv ft_containers $NAME
	make std
	mv std_containers $NAME
}

function execute_test ()
{
	EXEC_DIR=$(echo ".test_file/"$1 | rev | cut -c 5- | rev)
	NAME=$(echo $EXEC_DIR | rev | cut -d '/' -f 1 | rev)
	echo "$TEST_NUMBER TESTING:$NAME"
	./$EXEC_DIR/ft_containers 1> $EXEC_DIR/ft_containers.out 2> $EXEC_DIR/ft_containers.err
	./$EXEC_DIR/std_containers 1> $EXEC_DIR/std_containers.out 2> $EXEC_DIR/std_containers.err
	diff $EXEC_DIR/ft_containers.out $EXEC_DIR/std_containers.out > $EXEC_DIR/diff.out
	if [ $? -eq 0 ]
	then
		test_success
	else
		test_fail
		diff $EXEC_DIR/ft_containers.out $EXEC_DIR/std_containers.out
	fi
	diff $EXEC_DIR/ft_containers.err $EXEC_DIR/std_containers.err > $EXEC_DIR/diff.err
	if [ $? -eq 0 ]
	then
		echo -n ""
	else
		echo "ERRORS:"
		test_fail
		diff $EXEC_DIR/ft_containers.err $EXEC_DIR/std_containers.err
	fi
	TEST_NUMBER=$((TEST_NUMBER + 1))

}


echo "Building executable tests..."

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


echo "Running tests..."
if ! test -z "$1"
then
	TEST_FILES="$1"
else
	TEST_FILES=`ls test/**/*`
fi

for i in $TEST_FILES
do
	execute_test "$i"
done



#rm -rf .test_file