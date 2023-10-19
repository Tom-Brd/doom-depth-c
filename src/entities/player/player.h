#ifndef PLAYER
#define PLAYER

#include "../armor/armor.h"
#include "../inventory/inventory.h"
#include "../spell/spell.h"
#include "../stats/stats.h"
#include "../weapon/weapon.h"
#include "../../utils/array.h"
#include "../../storage/database/database.h"
#include "../entities.h"
#include <sqlite3.h>
#include "../monster/monster.h"
#include <stdlib.h>
#include <string.h>

typedef struct player_t {
    int id;
    char *name;
    unsigned int hp;
    unsigned int hp_max;
    unsigned int mana;
    unsigned int mana_max;
    unsigned int xp;
    unsigned int level;
    unsigned int base_attack;
    unsigned int base_defense;
    unsigned int gold;
    unsigned short action_points;
    spell_t *offensive_spell;
    spell_t *defensive_spell;
    spell_t *healing_spell;
    armor_t *chosen_armor;
    weapon_t *chosen_weapon;
    inventory_t *inventory;
    stats_t *stats;
    unsigned int (*attack)(struct player_t * player, monster_t * target);
    void (*give_exp)(struct player_t * player, unsigned int amount);
    void (*heal)(struct player_t * player, unsigned int amount);
} player_t;

player_t *create_player(char *name);

/**
 * @brief Creates a player from the database.
 *
 * This function creates a player from the database.
 *
 * @param stmt A pointer to the SQLite3 statement.
 * @param spells A pointer to the array of spells.
 *
 * @return A pointer to the player created from the database.
 * @sideeffects May modify the SQLite database by inserting new data.
 * @dependencies Depends on the SQLite3 library.
 * @errors May return SQLITE_ERROR or other error codes if the query execution fails.
 */
void *create_player_from_db(sqlite3_stmt *stmt);

/**
 * @brief Saves the player's data to the database.
 *
 * This function saves the player's data to the database.
 *
 * @param db A pointer to the SQLite3 database connection.
 * @param player A pointer to the player whose data is to be saved.
 *
 * @return SQLITE_OK if the player's data is successfully saved. Otherwise, it returns an error code.
 * @sideeffects May modify the SQLite database by inserting new data.
 * @dependencies Depends on the SQLite3 library.
 * @errors May return SQLITE_ERROR or other error codes if the query execution fails.
 */
int save_player(sqlite3 *db, player_t *player);

void give_exp(player_t * player, unsigned int amount);

#endif
