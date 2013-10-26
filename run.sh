#! /usr/bin/env bash

total=0
count=4

if [ $# -ge 1 ];
then
	count=$1
fi

for i in `seq 1 $count`; do
	result=`./a.out`
	total=$(($total + $result))
	echo $result
done;

echo '===='
echo $(($total / $count))
