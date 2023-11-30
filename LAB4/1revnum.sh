function revnum(){
    local number="$1"
    local reversed=""
    
    # Loop through each digit of the number in reverse order
    while [ $number != 0 ]
    do
        digit=$(( number % 10 ))
        reversed="${reversed}${digit}"
        number=$(( number / 10 ))
    done
    
    echo "Reversed number: $reversed"
}

revnum 12345
