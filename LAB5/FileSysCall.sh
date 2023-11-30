# Function to open a file
function openFile(){
    local dir="$1"
    #   Load the file data into the var
    local filedata=""

    #   Open the file
    open "$dir" 

    #   Print file contents
    #echo filedata

    #   Close file
    close "$dir" 

#     # Check file is closed
#     if [ -1 -eq "${filedata}" ]; then
#         echo "Error Closing File"
#     else
#         echo "File Closed"
#     fi
}

# Function to open a file and write to it
function writeFile(){
    local dir="$1"
    local newdata="$2"
    #local newdatalen = ${#newdata}
    
    # #   Load the file data into the var
    # local filedata = ""

    # #   Open the file
    # filedata = open "${dir}" O_RDWR 

    #   Print file contents
    echo "$newdata" >> "$dir"
    echo "Content written to $dir"
    # echo "Existing file data"
    # echo filedata

    # newdata = write filedata newdata newdatalen 

    # # Check if new data is written
    # if [ -1 "${newdata}" ]; then
    #     echo "Error writing to file File"
    # fi
    
    #   Print file contents
    echo "New file data"
    newdata = read filedata 
    echo filedata

    #   Close file
    close "${dir}" 

    # # Check file is closed
    # if [ -1 "${filedata}" ]; then
    #     echo "Error Closing File"
    # else
    #     echo "File Closed"
    # fi
}

# Read the file name from the user
echo "Enter the file name: " 
read file_input

# Call the function with the user input file name
openFile "$file_input"

echo "Enter the file name: " 
read file_input
echo "Enter new data: " 
read file_data

writeFile "$file_input" "$file_data"