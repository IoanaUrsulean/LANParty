#ifndef task1_h
#define task1_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Player
{
    char *firstName;
    char *secondName;
    int points;
};
typedef struct Player Player;

struct Team
{
    int numberOfPlayers;
    char *teamName;
    Player *playersArray;
    float teamPoints;
};
typedef struct Team Team;

struct teamNode
{
    Team val;
    struct teamNode *next;
};
typedef struct teamNode teamNode;

void intAllocationTest(int *p);
void charAllocationTest(char *p);
void readPlayerArray(Player *array, int intValue, FILE *read_file);
void readTeamNode(teamNode **head, int intValue, char *charValue, FILE *read_file);
void readList(char *inputFilePath, teamNode **head, int *numberOfTeams);
void displayList(char *outputFilePath, teamNode *head, int numberOfTeams);
void freeNodeList(teamNode **head);
void deleteList( teamNode **head);
void freeMemory(teamNode **head, int *numberOfTeams, int *taskArray);
#endif