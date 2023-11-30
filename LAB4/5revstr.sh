# Function to reverse a string
function reverse_string() {
    local input_string="$1"
    local reversed_string=""

    # Loop through each character in the string in reverse order
    for (( i = ${#input_string} - 1; i >= 0; i-- )); do
        reversed_string="${reversed_string}${input_string:$i:1}"
    done

    echo "$reversed_string"
}

# Read the string from the user
echo "Enter a string: " 
read input_string

# Call the function with the user input string
reversed_result=$(reverse_string "$input_string")

echo "Reversed string: $reversed_result"
