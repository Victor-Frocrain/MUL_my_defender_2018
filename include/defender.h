/*
** EPITECH PROJECT, 2019
** defender
** File description:
** defender
*/

#include "my.h"

#ifndef DEFENDER_H_
#define DEFENDER_H_
#define WIDTH 1920
#define HEIGHT 1080
#define NB_MAP 2
#define MENUS 14
#define BACK 7
#define CHARA 30
#define NB_TEX 2
#define SPEED 4
#define OBS 4
#define UNIT 4
#define MUSIC 1
#define TEXT 9
#define MAX_LIFE 100
#define TOWER_LIFE 400
#define PLAYER_LIFE 500
#define DAMAGE 3
#define TEXT1 "name = Michou\nprize = 50\nType = Heavy\nshoot\nDamages = 5\neach seconds"
#define TEXT2 "name = sniper\nprize = 100\nType = long\nshoot\nDamages = 10\neach seconds"
#define TEXT3 "name = archer\nprize = 150\nType = High\nshoot\nDamages = 15\neach seconds"
#define TEXT4 "name = Kyle\nprize = 200\nType = Strong\nshoot\nDamages = 20\neach seconds"

typedef struct entity_t {
    sfTexture *tex;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    char *file;
} entity;

typedef struct strings_t {
    sfText *text;
    sfVector2f pos;
    sfFont *font;
    char *file;
    char *str;
} strings;

typedef struct obstacle_t {
    sfTexture *tex;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    int life;
    float damage;
    sfClock *fight;
    bool pop;
    bool attack;
    sfMusic *clink;
    char *file;
} obstacle;

typedef struct music_s {
    sfMusic *game;
    sfMusic *fight;
    sfMusic *clic;
} music;

typedef struct times_s {
    sfClock *game;
    sfClock *coin;
    sfClock *enemies;
    sfClock *tower;
    sfClock *howtoplay;
} times;

typedef struct sequence_s {
    bool main;
    bool end;
    bool pause;
    bool game;
    bool howtoplay;
    bool synopsis;
} sequence;

typedef struct graph_s {
    sfRenderWindow *window;
    entity *map[NB_MAP];
    entity *menus[MENUS];
    entity *back[BACK];
    obstacle *characters[CHARA];
    obstacle *obs[OBS][UNIT];
    strings *text[TEXT];
    music *musica;
    times *clock;
    sequence *scene;
    char *land;
    bool init_land;
    bool exit;
    int fd;
    bool clicked;
    bool escape;
    int life;
    int tower;
    int score;
    int coin;
    int music;
} graph;

void draw_how_to_play(graph *s);
void init_text(graph *s);
void how_to_play(graph *s);
int my_defender(int ac, char **av);
graph *init_graph(graph *s);
bool init_window(graph *s);
void draw_elem(graph *s);
void draw_main(graph *s);
void init_textures(graph *s);
void init_sprites(graph *s);
void init_rectangles(graph *s);
void destroy_ressources(graph *s);
void destroy_sprites(graph *s);
void destroy_textures(graph *s);
void manage_mouse(graph *s);
void check_mouse_button(graph *s);
bool init_tabs(graph *s);
void anim_enemies(graph *s);
void place_obstacles(graph *s);
void init_files_obstacles(graph *s);
void init_textures_obstacles(graph *s);
void init_sprites_obstacles(graph *s);
void destroy_sprites_obstacles(graph *s);
void destroy_textures_obstacles(graph *s);
void destroy_files_obstacles(graph *s);
void init_rectangles_obstacles(graph *s);
void display_in_order(graph *s);
void disp_towers_order(graph *s, int y);
void detect_height(graph *s, obstacle *obs, int j, int y);
void init_scales4(graph *s);
void disp_enemies_order(graph *s, int y);
void display_in_order(graph *s);
void towers_attack(graph *s);
void init_music(graph *s);
void choose_anim_tower(graph *s, int i, int j);
void check_if_pause(graph *s);
void check_click(int scene, graph *s);
void init_scales1(graph *s);
void init_scales5(graph *s);
void synopsis(graph *s);
void enemies_attack(graph *s, int i, int j);
void check_click_tower(int scene, graph *s);
void check_click_end(int scene, graph *s);
void draw_pause(graph *s);
void init_buttons_files1(graph *s);
char *convert_int_str(int nb);
void time_draw_coin(graph *s);
void draw_coin(graph *s);
void draw_score(graph *s);
void display_life(graph *s);
void draw_info(graph *s);
void position_info_buttons(graph *s, int i);
void text_info_buttons(graph *s, int i);
void draw_text1(graph *s);
void draw_text2(graph *s);
void draw_text3(graph *s);
void draw_text4(graph *s);
void draw_text_info(graph *s, int i);
void display_tower_life(graph *s);
void reset_all(graph *s);
void init_player_life(graph *s);
void display_player_life(graph *s);
bool manage_prize(graph *s, int i);
void manage_end(graph *s);
void init_scales6(graph *s);
void draw_buttons_end(graph *s);
char *write_new_best(graph *s, char *buff);
void read_best(graph *s);
void display_score(graph *s);
void display_land(graph *s);

#endif
