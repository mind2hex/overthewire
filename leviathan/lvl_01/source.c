#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

// Prototypes
int strcmp(const char *s1, const char *s2);

int main(){
  int8_t *s2 = "sex";
  int8_t s1[4];
  
  int8_t v1, v2, v3;

  printf("password: ");
  v1 = getchar();
  v2 = getchar();
  v3 = getchar();

  s1[0] = v1;
  s1[1] = v2;
  s1[2] = v3;
  s1[3] = '\0';

  if (strcmp(s1,s2) == 0){
    system("/bin/sh");
  }
  else{
    puts("Wrong password, Good Bye ...");
  }


  return 0;

}


