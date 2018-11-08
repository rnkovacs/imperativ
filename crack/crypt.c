#include <crypt.h>
#include <stdio.h>
#include <unistd.h>

#define _XOPEN_SOURCE

int main(int argc, char *argv[]) {
  printf("%s\n", crypt(argv[1], "ab"));
}
