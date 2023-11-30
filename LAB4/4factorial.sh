# Function to calculate factorial
function factorial() {
    local num=$1
    local result=1

    for (( i = 1; i <= num; i++ ))
    do
        result=$((result * i))
    done

    echo $result
}

# Read the number from the user
echo "Enter a number: " 
read input_number

# Call the factorial function with the user input number
factorial_result=$(factorial "$input_number")

echo "Factorial of $input_number is $factorial_result"
