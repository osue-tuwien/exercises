/**
 * @file common.h
 * @author OSUE Team <osue-team@cps.tuwien.ac.at>
 * @date 2017-10-06
 *
 * @brief Common definitions for OSUE exercise 1B `Battleship'.
 */

// guard block:
#ifndef COMMON_H
#define COMMON_H

// default hostname and port:
#define DEFAULT_HOST    "localhost"
#define DEFAULT_PORT    "1280"

// Length of each side of the map:
#define MAP_SIZE        10

// Minimum and maximum length of the ships:
#define MIN_SHIP_LEN    2
#define MAX_SHIP_LEN    4

// Number of ships of each length:
#define SHIP_CNT_LEN2   2   // 2 ships of length 2
#define SHIP_CNT_LEN3   3   // 3 ships of length 3
#define SHIP_CNT_LEN4   1   // 1 ship of length 4

// Maximum number of rounds after which the client loses the game:
#define MAX_ROUNDS      80

// Suggested values to save information about the squares of the map:
#define SQUARE_UNKNOWN  0 // the square has not been targeted yet
#define SQUARE_HIT      1 // a shot at the square hit a ship
#define SQUARE_EMPTY    2 // a shot at the square was a miss (thus it is empty)

#include <stdint.h>

/**
 * @brief Print a map showing the squares where ships have been hit.
 *
 * You might find this function useful for debugging.
 *
 * @param map A 2-dimensional array of unsigned 8-bit integers, where each
 *            element represents a square and its value indicates whether a
 *            shot has already been directed at this square and if a ship was
 *            hit by that shot, according to the values suggested above.
 *
 * Example usage:
 * @code
 *  uint8_t map[MAP_SIZE][MAP_SIZE];
 *  memset(&map, 0, sizeof(map)); // initialize each square as unknown
 *  map[1][5] = SQUARE_EMPTY;   // a shot at B5 did not hit anything
 *  map[2][3] = SQUARE_HIT;     // a shot at C3 hit a ship
 *  print_map(map);
 * @endcode
 */
static inline void print_map(uint8_t map[MAP_SIZE][MAP_SIZE])
{
    int x, y;

    printf("  ");
    for (x = 0; x < MAP_SIZE; x++)
        printf("%c ", 'A' + x);
    printf("\n");

    for (y = 0; y < MAP_SIZE; y++) {
        printf("%c ", '0' + y);
        for (x = 0; x < MAP_SIZE; x++)
            printf("%c ", map[x][y] ? ((map[x][y] == 1) ? 'x' : 'o') : ' ');
        printf("\n");
    }
}

#endif // COMMON_H
