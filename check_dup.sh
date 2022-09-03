#!/bin/bash

# Check for the duplicates in the tree
# Arguments : start stop step = 100, 130, 10; Example: Start from 100 random ints. Make steps with 10.
# Stop at 130. As a result four trees of random ints: 100, 110, 120, 130.

rm -f temp.txt
rm -f size_dup.txt
sh comp.sh

echo "Len Dup" >> size_dup.txt

for i in $(seq $1 $2 $3)
do
	python3 gen_rand.py $i >> temp.txt
	ARG=$(cat temp.txt)
	./bi_tree_bin $ARG >> size_dup.txt
	rm -f temp.txt
done
