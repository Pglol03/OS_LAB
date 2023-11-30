# Function to check file type and permissions
function check_file_type_and_permissions() {
    local filename="$1"

    # Check if the file exists
    if [ ! -e "$filename" ]; then
        echo "Error: File '$filename' does not exist."
        exit 1
    fi

    # Check file type
    if [ -f "$filename" ]; then
        echo "File Type: Regular File"
    elif [ -r "$filename" ]; then
        echo "File Type: Readable File"
    elif [ -w "$filename" ]; then
        echo "File Type: Writeable File"
    elif [ -x "$filename" ]; then
        echo "File Type: Executable File"
    elif [ -d "$filename" ]; then
        echo "File Type: Directory"
    else
        echo "File Type: Other"
    fi

    # Check file permissions
    echo "File Permissions: $(stat -l "$filename")"
}

# Read the file name from the user
echo "Enter the file name: " 
read file_input

# Call the function with the user input file name
check_file_type_and_permissions "$file_input"
