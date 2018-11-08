#include <stdio.h>
#include <string.h>

#include <crypt.h>
#include <unistd.h>

#define _XOPEN_SOURCE

#define NUM_CHARS 26
#define NUM_ALPHA 52

#define UPPERCASE_A 65
#define LOWERCASE_A 97

static char *seed = "ab";

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./crack [hash]\n");
    return 1;
  }

  const char *hash = argv[1];
  printf("Hash supplied: %s\n", hash);

  char alpha[NUM_ALPHA + 1];
  for (int i = 0; i < NUM_CHARS; ++i) {
    alpha[i] = (i + UPPERCASE_A); // 65 - 90 : A..Z
    alpha[i + NUM_CHARS] = (i + LOWERCASE_A); // 97 - 122 : a..z
  }
  alpha[NUM_ALPHA] = '\0';

  /* Candidate passwords have a fixed length of 4. */
  char candidate[5];
  for (int a = 0; a < NUM_ALPHA; ++a) {
    for (int b = 0; b < NUM_ALPHA; ++b) {
      for (int c = 0; c < NUM_ALPHA; ++c) {
        for (int d = 0; d < NUM_ALPHA; ++d) {
          candidate[0] = alpha[a];
          candidate[1] = alpha[b];
          candidate[2] = alpha[c];
          candidate[3] = alpha[d];
          candidate[4] = '\0';
          if (strcmp(hash, crypt(candidate, seed)) == 0) {
            printf("Password: %s\n", candidate);
            return 0;
          }
        }
      }
    }
  }

  printf("No luck\n");
  return 1;
}

