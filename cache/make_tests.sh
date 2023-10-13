#!/bin/bash

mkdir -p test_results

function test() {
    echo -n $(echo $1 | cut -d "_" -f 2)," " | tee -a test_results/test_results_lfu.csv
    cat $1 | bin/cache_lfu                   | tee -a test_results/test_results_lfu.csv
    echo -n $(echo $1 | cut -d "_" -f 2)," " | tee -a test_results/test_results_lru.csv
    cat $1 | bin/cache_lru                   | tee -a test_results/test_results_lru.csv
    echo -n $(echo $1 | cut -d "_" -f 2)," " | tee -a test_results/test_results_ideal.csv
    cat $1 | bin/cache_ideal                 | tee -a test_results/test_results_ideal.csv
}

rm test_results/test_results*

for f in tests/*; do
    test $f
done

sort -k1 -n -t, test_results/test_results_lfu.csv   | tee test_results/test_results_lfu_sorted.csv
sort -k1 -n -t, test_results/test_results_lru.csv   | tee test_results/test_results_lru_sorted.csv
sort -k1 -n -t, test_results/test_results_ideal.csv | tee test_results/test_results_ideal_sorted.csv