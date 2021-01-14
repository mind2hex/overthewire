#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<stdlib.h>

// Function prototypes
int system(const char *command);

int main(int argc, const char **argv){
  char *foo;
  
  // Exit with status code -1 if no argument provided
  if (argc == 1) {

    // Print usage
    puts("*** File Printer ***");
    printf("Usage: %s filename\n",argv[0]);
    
    return -1;
  }
  else {
    // Exit with status code 1 if wrong access 
    if (access(argv[1], 4) != 0){
      
      puts("You can't have that file...");
      
      return 1;
    }
    // Formatting order to execute with argument 1
    int8_t buffer[511];
    snprintf(buffer, 511, "/bin/cat %s", argv[1]);

    // Executing formatted command (/bin/cat %s)
    system(buffer);
    
  }
    
  return 0;
}

