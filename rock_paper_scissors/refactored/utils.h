#ifndef GAME_UTILS_H
#define GAME_UTILS_H

enum choice { ROCK, PAPER, SCISSORS, INVALID };
typedef enum choice choice_t;

enum winner { USER, MACHINE, TIE };
typedef enum winner winner_t;

void         tolower_str(char *dest, int dest_size, const char *src);
choice_t     set_user_choice(const char *input);
const char * choice_to_str(choice_t machine);
void         print_winner(winner_t result);

#endif
