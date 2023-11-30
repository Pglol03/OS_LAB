#!/bin/bash

declare nos[5]=(4 -1 2 66 10)
# Prints the number befor sorting

echo "Original Numbers in array:"
for (( i = 0; i <= 4; i++ ))
    do
      echo ${nos[$i]}
    done

 #
 # Now do the Sorting of numbers  
 #

for (( i = 0; i <= 4 ; i++ ))
do
   for (( j = $i; j <= 4; j++ ))
   do
      if [ ${nos[$i]} -gt ${nos[$j]}  ]; then
       t=${nos[$i]}
       nos[$i]=${nos[$j]}
       nos[$j]=$t
      fi
   done
done

#
# Print the sorted number
# 
echo -e "\nSorted Numbers in Ascending Order:"
for (( i=0; i <= 4; i++ )) 
do
  echo ${nos[$i]}
done

# Static input of Array
arr=(10 8 20 100 12)

echo "Array in original order"
echo ${arr[*]}

# Performing Bubble sort 
for ((i = 0; i<5; i++))
do
    
    for((j = 0; j<5-i-1; j++))
    do
    
        if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
        then
            # swap
            temp=${arr[j]}
            arr[$j]=${arr[$((j+1))]}  
            arr[$((j+1))]=$temp
        fi
    done
done

echo "Array in sorted order :"
echo ${arr[*]}