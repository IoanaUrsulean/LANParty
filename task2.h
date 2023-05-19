#ifndef task2_h
#define task2_h
#include"task1.h"
#include<math.h>

void teamPoints(teamNode *head);
int maxNumberOfTeams(int numberOfTeams);
int floatEqual(float a, float b);
void deleteTeamNode(teamNode **head , float v);
float findLowestScore(teamNode *head);
void deleteTeams(teamNode **head, int *numberOfTeams);
#endif