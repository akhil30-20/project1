#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER 4096
int main(int argc, char *argv[]) {
  char buff[BUFFER];
  int fd, br;
  char *file;
  file = NULL;
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-") != 0) {
      file = argv[i];
      fd = open(file, O_RDONLY);
      if (fd == -1) {
        warnx(" %s: No such file or directory", file);
      }
      while ((br = read(fd, buff, BUFFER)) > 0) {
        write(STDOUT_FILENO, buff, br);
      }
    }
  }
  close(fd);
  exit(1);
  return EXIT_SUCCESS;
}
