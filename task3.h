#ifndef task3_h
#define task3_h
#include"task1.h"
#include"task2.h"
#include"task4.h"
#include"task5.h"
#include<limits.h>

struct queueNode
{
    Team team1;
    Team team2;
    struct queueNode *next;
};
typedef struct queueNode queueNode;

struct Q{
    queueNode *front , *rear ;
};
typedef struct Q Queue ;

Queue * createQueue();
void enQueue(Queue *q, teamNode *head);
int isQueueEmpty(Queue *q);
int deQueue(Queue*q, Team *d) ;
void deleteQueue ( Queue *q);
int isStackEmpty(teamNode *top);
Team top(teamNode *top);
void push(teamNode **top, Team v) ;
Team pop(teamNode **top) ;
void deleteStack(teamNode **top);
void decideWinner(FILE *display_file, Queue **q, teamNode **winnerStack, teamNode **loserStack, Team *d);
void tasks4and5(FILE *display_file, int *taskArray, teamNode *winnerStack, BSTNode **BSTroot, AVLNode **AVLroot, int numberOfTeams);
void printTasks4and5(FILE *display_file, int *taskArray, BSTNode **BSTroot, AVLNode **AVLroot);
void rounds(FILE *display_file, Queue **q, teamNode **winnerStack, teamNode **loserStack, int *numberOfTeams, Team *d, int roundNumber);
void playGame(char *outputFilePath, teamNode **head, int *numberOfTeams, int *taskArray);
#endif