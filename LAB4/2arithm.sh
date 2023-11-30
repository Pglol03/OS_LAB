# Function to perform arithmetic operations
function perform_arithmetic() {
    operator="$1"
    num1=""
    num2=""
    result=""

    case "$operator" in
        "+")
            echo "Number 1 :"
            read num1 
            echo "Number 2 :"
            read num2 
            result=$((num1 + num2))
            ;;
        "-")
            echo "Number 1 :"
            read num1 
            echo "Number 2 :"
            read num2 
            result=$((num1 - num2))
            ;;
        "*")
            echo "Number 1 :"
            read num1 
            echo "Number 2 :"
            read num2 
            result=$((num1 * num2))
            ;;
        "/")
            echo "Number 1 :"
            read num1 
            echo "Number 2 :"
            read num2 
            # Check for division by zero
            if [ "$num2" -eq 0 ]; then
                echo "Error: Division by zero is not allowed."
                exit 1
            fi
            result=$((num1 / num2))
            ;;
        "%")
            echo "Number 1 :"
            read num1 
            echo "Number 2 :"
            read num2 
            # Check for modulo by zero
            if [ "$num2" -eq 0 ]; then
                echo "Error: Modulo by zero is not allowed."
                exit 1
            fi
            result=$((num1 % num2))
            ;;
        *)
            result = "Error: Invalid operator '$operation'."
            exit 1
            ;;
    esac

    echo "Result: $result"
}

# Read operator and numbers from the user
echo "Enter the arithmetic operator (+, -, *, /, %): " 
read operator

# Call the function with user inputs
perform_arithmetic "$operator" 
