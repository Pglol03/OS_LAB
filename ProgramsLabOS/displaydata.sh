#!/bin/bash

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 [arg1] [arg2] [...]"
    exit 1
fi

# Display the provided arguments
echo "You provided $# arguments:"
for arg in "$@"; do
    echo "- $arg"
done
