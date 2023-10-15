#!/bin/bash

rm -rf tests
mkdir tests
cd tests

max=16

# $1 - cache size, $2 - number of elements, $3 - max value
function generate_random_test() {
    echo $1 $2

    for n in $( seq 1 $2 )
    do    
        echo $(($RANDOM % $3))
    done
}

for i in $(seq 4 $max)
do
    #echo $i $($i / 2) $j $a $b
    elements_size=$((2**i))
    cache_size=$((elements_size / 16))
    max_value=$(($elements_size / 2))
    generate_random_test $cache_size $elements_size $max_value | tee test_"$elements_size"
done