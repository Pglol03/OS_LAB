#include <stdio.h>
#include <stdlib.h>

int main() {
    // Replace "filename.txt" with the actual file you want to open
    const char *filename = "test.txt";

    char command[100];

    // Determine the command based on the operating system
    #ifdef _WIN32
        sprintf(command, "start %s", filename); // Windows command
    #elif __APPLE__
        sprintf(command, "open %s", filename); // macOS command
    #else
        sprintf(command, "xdg-open %s", filename); // Linux command
    #endif

    // Execute the command using the system call
    int result = system(command);

    if (result == -1) {  
        return 1;
    }

    return 0;
}
