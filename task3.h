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
int isStackEmpty(teamNode*top);
Team top(teamNode *top);
void push(teamNode**top, Team v) ;
Team pop(teamNode**top) ;
void deleteStack(teamNode**top);
void rounds(char *outputFilePath, teamNode **head, int *numberOfTeams);