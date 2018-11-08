#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

#define BUFSIZE 10

int main(int argc, char *argv[]) {
  printf("Rock-paper-scissors game\n\n");

  if (argc != 2) {
    fprintf(stderr, "Usage: %s [ROCK/PAPER/SCISSORS]\n", argv[0]);
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

                /* user:  ROCK     PAPER    SCISSORS */  /*  machine: */
  int control[3][3] = { { TIE,     USER,    MACHINE },   /*  ROCK     */
                        { MACHINE, TIE,     USER },      /*  PAPER    */
                        { USER,    MACHINE, TIE } };     /*  SCISSORS */

  winner_t result = control[machine][user];
  print_winner(result);

  return EXIT_SUCCESS;
}
