#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 10

enum choice { ROCK, PAPER, SCISSORS, INVALID };
typedef enum choice choice_t;

enum winner { USER, MACHINE, TIE };
typedef enum winner winner_t;

void         tolower_str(char *dest, int dest_size, const char *src);
choice_t     set_user_choice(const char *input);
const char * choice_to_str(choice_t machine);
void         print_winner(winner_t result);

int main(int argc, char *argv[]) {
  printf("Rock-paper-scissors game\n\n");

  if (argc != 2) {
    fprintf(stderr, "Usage: %s [rock/paper/scissors]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char input[BUFSIZE];
  tolower_str(input, BUFSIZE, argv[1]);

  choice_t user = set_user_choice(input);

  assert( user >= 0 && user <= 2 );
  printf("User's choice: %s.\n", input);

  srand(time(NULL));
  choice_t machine = rand() % 3;

  assert( machine >= 0 && machine <= 2 );
  printf("Machine's choice: %s.\n", choice_to_str(machine));
  
                /* user:  ROCK     PAPER    SCISSORS  */ /* machine: */
  int control[3][3] = { { TIE,     USER,    MACHINE },   /* ROCK     */
                        { MACHINE, TIE,     USER },      /* PAPER    */
                        { USER,    MACHINE, TIE } };     /* SCISSORS */

  winner_t result = control[machine][user];
  print_winner(result);

  return EXIT_SUCCESS;
}

void tolower_str(char *dest, int dest_size, const char *src) {
  if ((int) strlen(src) > (dest_size - 1)) {
    fprintf(stderr,
            "Error: input should be shorter than %d chars\n", dest_size);
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
