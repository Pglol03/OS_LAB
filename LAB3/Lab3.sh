function arithmetic_operations(){
a=$1
b=$2
expr $a + $b
expr $a - $b
expr $a / $b
expr $a % $b
expr $a \* $b
}

arithmetic_operations 5 10
