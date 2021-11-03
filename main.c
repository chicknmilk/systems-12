#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

  DIR * d;
  d = opendir("./");
  struct dirent *entry;
  entry = readdir(d);
  int total_size = 0;


  // implement functionality of ls
  while (entry != NULL) {
    struct stat st;
    stat(entry->d_name, &st);
    
    char * file_name = entry->d_name;
    int file_size = st.st_size;
    total_size += file_size;

    if (opendir(file_name) != NULL) {
      printf("(directory) %s, %d bytes\n", file_name, file_size);
    }
    else {
      printf("(file) %s, %d bytes\n", file_name, file_size);
    }

    entry = readdir(d);
  }

  printf("total directory size: %d", total_size);

  closedir(d);

  return 0;
}