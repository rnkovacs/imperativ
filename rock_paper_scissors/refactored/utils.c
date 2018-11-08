#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void tolower_str(char *dest, int dest_size, const char *src) {
  if ((int) strlen(src) > (dest_size - 1)) {
    fprintf(stderr, "Error: too long input\n");
    exit(EXIT_FAILURE);
  }
  while (*src) {
    *dest = (char) tolower(*src);
    src++;
    dest++;
  }
  *dest = '\0';
}

choice_t set_user_choice(const char *input) {
  if (strcmp(input, "rock") == 0)
    return ROCK;
  if (strcmp(input, "paper") == 0)
    return PAPER;
  if (strcmp(input, "scissors") == 0)
    return SCISSORS;

  fprintf(stderr, "Error: invalid input\n");
  exit(EXIT_FAILURE);
}

const char *choice_to_str(choice_t machine) {
  switch (machine) {
    default:
      fprintf(stderr, "Error: invalid input\n");
      exit(EXIT_FAILURE);
    case ROCK:
      return "rock";
    case PAPER:
      return "paper";
    case SCISSORS:
      return "scissors";
  }
}

void print_winner(winner_t result) {
  switch (result) {
    default:
      fprintf(stderr, "Error: invalid input\n");
      exit(EXIT_FAILURE);
    case USER:
      printf("User wins!\n");
      return;
    case MACHINE:
      printf("Machine wins!\n");
      return;
    case TIE:
      printf("It's a tie.\n");
      return;
  }
}
