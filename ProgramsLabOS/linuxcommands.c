#!/bin/bash

# Basic Linux Commands
echo "=== Basic Linux Commands ==="

# Display current directory
echo "Current Directory:"
pwd

# List files and directories
echo -e "\nList Files and Directories:"
ls

# Display system information
echo -e "\nSystem Information:"
uname -a

# Advanced Linux Commands
echo -e "\n=== Advanced Linux Commands ==="

# Disk usage
echo -e "\nDisk Usage:"
df -h

# Network information
echo -e "\nNetwork Information:"
ifconfig

# Running processes
echo -e "\nRunning Processes:"
ps aux

# Search for a file
echo -e "\nSearch for a File (e.g., *.txt):"
find . -name "*.txt"

# Compress files
echo -e "\nCompress Files (tar):"
tar -czf archive.tar.gz file1.txt file2.txt

# Decompress files
echo -e "\nDecompress Files (tar):"
tar -xzf archive.tar.gz

# Text manipulation (replace 'old' with 'new' in file.txt)
echo -e "\nText Manipulation (sed):"
echo "This is an old text." > file.txt
sed -i 's/old/new/g' file.txt
cat file.txt

# User Information
echo -e "\nUser Information:"
who

# System uptime
echo -e "\nSystem Uptime:"
uptime

# Memory usage
echo -e "\nMemory Usage:"
free -m

# Display kernel messages
echo -e "\nKernel Messages:"
dmesg | tail

# Exit script
exit 0
