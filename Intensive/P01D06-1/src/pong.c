#include <stdio.h>

void print_game_field(int l_rocket, int rightR, int ball_x, int ball_y, int l_player_score,
                      int r_player_score);
int move_left_rocket(int key, int current_pos);
int move_right_rocket(int key, int current_pos);
void pong_game(int l_rocket, int r_rocket, int ball_x, int ball_y, int ball_dir_x, int ball_dir_y,
               int l_player_score, int r_player_score);

int main() {
    int l_rocket = 12;
    int r_rocket = 12;
    int ball_x = 40;
    int ball_y = 12;
    int ball_dir_x = 1;
    int ball_dir_y = 1;
    int l_player_score = 0;
    int r_player_score = 0;

    pong_game(l_rocket, r_rocket, ball_x, ball_y, ball_dir_x, ball_dir_y, l_player_score, r_player_score);

    return 0;
}

void print_game_field(int l_rocket, int rightR, int ball_x, int ball_y, int l_player_score,
                      int r_player_score) {
    printf("\033[H\033[J");
    printf("%-25s", "a ↑");
    printf("\033[0;34m");  // change to blue
    printf("Синий Игрок %0*d |", 2, l_player_score);
    printf("\033[0;31m");  // change to red
    printf("| %0*d Красный Игрок", 2, r_player_score);
    printf("\033[0m");  // reset color
    printf("%25s\n", "↑ k");
    printf("%-18sИгра 'Понг' @Team 82 / Пробел - пропуск действия%18s\n", "z ↓", "↓ m");

    for (int h = 0; h < 25; h++) {
        for (int w = 0; w < 80; w++) {
            if ((h == l_rocket || h == l_rocket - 1 || h == l_rocket + 1) && (w == 1)) {
                printf("]");
            } else if ((h == rightR || h == rightR - 1 || h == rightR + 1) && (w == 78)) {
                printf("[");
            } else if (h == ball_y && w == ball_x) {
                printf("o");
            } else if (h == 0 || h == 24) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    if (l_player_score == 21) {
        printf("\033[0;34m");
        printf("%47s\n", "blue player WON!");
    }
    if (r_player_score == 21) {
        printf("\033[0;31m");
        printf("%47s\n", "red player WON!");
    }
}

int move_left_rocket(int key, int current_pos) {
    if (key == 'a' && current_pos > 2) {
        current_pos--;
    } else if (key == 'z' && current_pos < 22) {
        current_pos++;
    }
    return current_pos;
}
int move_right_rocket(int key, int current_pos) {
    if (key == 'k' && current_pos > 2) {
        current_pos--;
    } else if (key == 'm' && current_pos < 22) {
        current_pos++;
    }
    return current_pos;
}

void pong_game(int l_rocket, int r_rocket, int ball_x, int ball_y, int ball_dir_x, int ball_dir_y,
               int l_player_score, int r_player_score) {
    char k;
    while (l_player_score < 21 && r_player_score < 21) {
        scanf("%c", &k);
        if (k == ' ' || k == 'k' || k == 'm' || k == 'a' || k == 'z') {
            if (ball_y == 23) {
                ball_dir_y = -1;
            } else if (ball_y == 1) {
                ball_dir_y = 1;
            }
            if ((ball_x == 77 || ball_x == 2)) {
                if ((ball_y == r_rocket || ball_y == r_rocket - 1 || ball_y == r_rocket + 1)) {
                    ball_dir_x = -1;
                } else if ((ball_y == l_rocket || ball_y == l_rocket - 1 || ball_y == l_rocket + 1)) {
                    ball_dir_x = 1;
                } else if ((ball_y + 1 == r_rocket || ball_y + 1 == r_rocket - 1 ||
                            ball_y + 1 == r_rocket + 1)) {
                    ball_dir_x = -1;
                } else if ((ball_y - 1 == l_rocket || ball_y - 1 == l_rocket - 1 ||
                            ball_y - 1 == l_rocket + 1)) {
                    ball_dir_x = 1;
                }
            }
            if (ball_x == 79 || ball_x == 0) {
                if (ball_x == 79) {
                    printf("\a");
                    l_player_score++;
                } else if (ball_x == 0) {
                    printf("\a");
                    r_player_score++;
                }
                ball_x = 40;
                ball_y = 12;
                ball_dir_x = ball_dir_x * -1;
                ball_dir_y = ball_dir_y * -1;
            }
            ball_x += ball_dir_x;
            ball_y += ball_dir_y;
            l_rocket = move_left_rocket(k, l_rocket);
            r_rocket = move_right_rocket(k, r_rocket);

            print_game_field(l_rocket, r_rocket, ball_x, ball_y, l_player_score, r_player_score);
        }
    }
}
