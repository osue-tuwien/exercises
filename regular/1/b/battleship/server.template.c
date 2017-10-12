/**
 * @file server.c
 * @author OSUE Team <osue-team@cps.tuwien.ac.at>
 * @date 2017-10-06
 *
 * @brief Server for OSUE exercise 1B `Battleship'.
 */

// IO, C standard library, POSIX API, data types:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

// Assertions, errors, signals:
#include <assert.h>
#include <errno.h>
#include <signal.h>

// Time:
#include <time.h>

// Sockets, TCP, ... :
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>

// stuff shared by client and server:
#include "common.h"

// Static variables for things you might want to access from several functions:
static const char *port = DEFAULT_PORT; // the port to bind to

// Static variables for resources that should be freed before exiting:
static struct addrinfo *ai = NULL;      // addrinfo struct
static int sockfd = -1;                 // socket file descriptor
static int connfd = -1;                 // connection file descriptor

/* TODO
 * You might want to add further static variables here, for instance to save
 * the programe name (argv[0]) since you should include it in all messages.
 *
 * You should also have some kind of a list which saves information about your
 * ships. For this purpose you might want to define a struct. Bear in mind that
 * your server must keep record about which ships have been hit (and also where
 * they have been hit) in order to know when a ship was sunk.
 *
 * You might also find it convenient to add a few functions, for instance:
 *  - a function which cleans up all resources and exits the program
 *  - a function which parses the arguments from the command line
 *  - a function which adds a new ship to your list of ships
 *  - a function which checks whether a client's shot hit any of your ships
 */

int main(int argc, char *argv[])
{
    /* TODO
     * Add code to parse the command line arguments, maybe as a separate
     * function.
     */

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int res = getaddrinfo(NULL, port, &hints, &ai);
    /* TODO
     * check for errors
     */

    sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    /* TODO
     * check for errors
     */

    int val = 1;
    res = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof val);
    /* TODO
     * check for errors
     */

    res = bind(sockfd, ai->ai_addr, ai->ai_addrlen);
    /* TODO
     * check for errors
     */

    res = listen(sockfd, 1);
    /* TODO
     * check for errors
     */

    connfd = accept(sockfd, NULL, NULL);
    /* TODO
     * check for errors
     */

    /* TODO
     * Here you might want to add variables to keep track of the game status,
     * for instance the number of rounds that have been played.
     */

    while (...) {
        /* TODO
         * add code to:
         *  - wait for a request from the client
         *  - check for a parity error or invalid coordinates in the request
         *  - check whether a ship was hit and determine the status to return
         *  - send an according response to the client
         */
    }

    /* TODO
     * cleanup
     */
}
