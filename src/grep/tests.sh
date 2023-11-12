#!/bin/bash
SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""
FAILED_TESTS=()

grep_command=(
    "./grep"
)
sys_command=(
    "grep"
)

flags=(
    "v"
    "c"
    "l"
    "n"
    "h"
    "o"
)

tests=(
    "s test_files/test1.txt FLAGS"
    "for grep.c grep.h Makefile FLAGS"
    "for grep.c FLAGS"
    "-e for -e ^int grep.c grep.h Makefile FLAGS"
    "-e for -e ^int grep.c FLAGS"
    "-e regex -e ^print grep.c FLAGS -f test_files/test7.txt"
    "-e while -e void grep.c Makefile FLAGS -f test_files/test7.txt"
    "-e Linux test_files/test.txt"
    "-e sample test_files/test8.txt"
    "-n -e lines test_files/test9.txt"
    "-c -e patterns test_files/test10.txt"
)

manual=(
    "-n for test_files/test2.txt test_files/test3.txt"
    "-n for test_files/test2.txt"
    "-n -e ^\} test_files/test2.txt"
    "-ce ^int test_files/test2.txt test_files/test3.txt"
    "-e ^int test_files/test2.txt"
    "-nivh = test_files/test2.txt test_files/test3.txt"
    "-ie INT test_files/test5.txt"
    "-echar test_files/test2.txt test_files/test3.txt"
    "-ne = -e out test_files/test5.txt"
    "-iv int test_files/test5.txt"
    "-in int test_files/test5.txt"
    "-c -l aboba test_files/test2.txt test_files/test5.txt"
    "-v test_files/test2.txt -e ank"
    "-noe ) test_files/test5.txt"
    "-l for test_files/test2.txt test_files/test3.txt"
    "-o -e int test_files/test4.txt"
    "-e = -e out test_files/test5.txt"
    "-e ing -e as -e the -e not -e is test_files/test6.txt"
    "-c -e . test_files/test2.txt -e '.'"
    "-l for no_file.txt test_files/test3.txt"
    "-e int -si no_file.txt grep.c no_file2.txt grep.h"
    "-si grep.c -f no_pattern.txt"
    "-e additional test_files/test8.txt"
    "-c -e test test_files/test9.txt"
    "-i -e LINES test_files/test10.txt"
    # Add more manual tests as needed
)

run_test() {
    param=$(echo "$@" | sed "s/FLAGS/$var/")
    "${grep_command[@]}" $param > "${grep_command[@]}".log
    "${sys_command[@]}" $param > "${sys_command[@]}".log
    DIFF="$(diff -s "${grep_command[@]}".log "${sys_command[@]}".log)"
    let "COUNTER++"
    if [ "$DIFF" == "Files "${grep_command[@]}".log and "${sys_command[@]}".log are identical" ]
    then
        let "SUCCESS++"
        echo "$COUNTER - Success $param"
    else
        let "FAIL++"
        echo "$COUNTER - Fail $param"
        FAILED_TESTS+=("$COUNTER - $param")
    fi
    rm -f "${grep_command[@]}".log "${sys_command[@]}".log
}

echo "^^^^^^^^^^^^^^^^^^^^^^^"
echo "TESTS WITH NORMAL FLAGS"
echo "^^^^^^^^^^^^^^^^^^^^^^^"
printf "\n"
echo "#######################"
echo "MANUAL TESTS"
echo "#######################"
printf "\n"

for i in "${manual[@]}"
do
    var="-"
    run_test "$i"
done

printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "1 PARAMETER"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        run_test "$i"
    done
done
printf "\n"
echo "======================="
echo "2 PARAMETERS"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                run_test "$i"
            done
        fi
    done
done
printf "\n"
echo "======================="
echo "3 PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$var1 -$var2 -$var3"
                    run_test "$i"
                done
            fi
        done
    done
done
printf "\n"
echo "======================="
echo "4 PARAMETERS"
echo "======================="
printf "\n"
for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            for var4 in "${flags[@]}"
            do
                if [ $var1 != $var2 ] && [ $var2 != $var3 ] \
                && [ $var1 != $var3 ] && [ $var1 != $var4 ] \
                && [ $var2 != $var4 ] && [ $var3 != $var4 ]
                then
                    for i in "${tests[@]}"
                    do
                        var="-$var1 -$var2 -$var3 -$var4"
                        run_test "$i"
                    done
                fi
            done
        done
    done
done
printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "DOUBLE PARAMETER"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1$var2"
                run_test "$i"
            done
        fi
    done
done

printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "TRIPLE PARAMETER"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for var2 in "${flags[@]}"
    do
        for var3 in "${flags[@]}"
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$var1$var2$var3"
                    run_test "$i"
                done
            fi
        done
    done
done

printf "\n"
echo "#######################"
echo "FAILED TESTS"
echo "#######################"
printf "\n"

for failed_test in "${FAILED_TESTS[@]}"; do
    echo "$failed_test"
done

printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"

