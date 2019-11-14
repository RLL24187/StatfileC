#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// There is a function called stat. It is used to get information about a file. Write a program that uses stat to display the following information about a file:
// file size
// mode (permissions)
// time of last access (displayed in the following format: Fri Oct 28 09:03:01 2016
// Note
// You may hardcode the file that your program uses, make sure the program works when I download and run it.
// If only there were some file that you know I will have and where it is... hmm...
// Once you have that, try the following:
// Modify the size so it is printed out in human readable form (that is using B, KB, MB, GB).
// You may want to look into the sprintf function to help.
// Attempt to print out the permissions in ls -l form, ignoring the early bits that include the file type information
// Permissions are of type mode_t, which is an integer type.
// The permissions section of the mode is stored in the last 9 bits of the mode_t data type.

void convertpermissions(char * c){ //mode_t
  // char s[100]; //storage
  int i;
  printf("-");
  for (i = 3; i < 6; i++){
    if (*(c + i) == '0'){
      // s = strcat(s, "---");
      printf("---");
    }
    else if (*(c + i) == '1'){
      // s = strcat(s, "--x");
      printf("--x");
    }
    else if (*(c + i) == '2'){
      // s = strcat(s, "-w-");
      printf("-w-");
    }
    else if (*(c + i) == '3'){
      // s = strcat(s, "-wx");
      printf("-wx");
    }
    else if (*(c + i) == '4'){
      // s = strcat(s, "r--");
      printf("r--");
    }
    else if (*(c + i) == '5'){
      // s = strcat(s, "r-x");
      printf("r-x");
    }
    else if (*(c + i) == '6'){
      // s = strcat(s, "rw-");
      printf("rw-");
    }
    else{ //file permissions is 7
      // s = strcat(s, "rwx");
      printf("rwx");
    }
    // return s;
  }
    printf("\n");
//   sprintf ( string, “%d %c %f”, value, c, flt ) ;
//
// where,
// string – buffer to  put the data in.
// value – int variable, c – char variable and flt – float variable. There are for example only. You can use any specifiers.
}

int main(){
  struct stat buffer;
  stat("./statfile.c", &buffer);
  int bytesize = buffer.st_size;
  printf("Printing file size in bytes: %d\n", bytesize);
  printf("Printing file size in KB: %lf\n", bytesize / 1024.000);
  printf("Printing file size in MB: %lf\n", bytesize / 1024.000 / 1024.000);
  printf("Printing file size in GB: %lf\n", bytesize / 1024.000 / 1024.000 / 1024.000);
  printf("Printing file permissions: %o\n", buffer.st_mode);
  printf("Printing time: %s", ctime(&buffer.st_mtime));
  char s[100];
  sprintf(s, "%o", buffer.st_mode);
  // printf("Printing permissions in ls -l form: %s\n", convertpermissions(s));
  printf("Printing permissions in ls -l form: \n");
  convertpermissions(s);
  return 0;
}
