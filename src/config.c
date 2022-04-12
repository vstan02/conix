#include <stdio.h>

extern void read_file(const char* path) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    return NULL;
  }
  
  char* content = NULL;
  fclose(file);
  return content;
}
