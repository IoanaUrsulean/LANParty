#include"task1.h"
#include"task2.h"

void teamPoints(teamNode *head)
{
    //functie ce calculeaza punctajul aferent fiecarei echipe 
    while(head != NULL)
    {
        head->val.teamPoints = 0;
        for(int j = 0; j < head->val.numberOfPlayers; j++)
            head->val.teamPoints = head->val.teamPoints + head->val.playersArray[j].points;
        head->val.teamPoints = head->val.teamPoints/head->val.numberOfPlayers;
        head = head->next;
    }
}
/*
void displayTeamPoints(teamNode *head, int numberOfTeams)
{
    //functie ajutatoare de afisare punctaj
    for(int i = 0; i < numberOfTeams; i++)
    {
        printf("%f %s\n",head->val.teamPoints, head->val.teamName);
        getchar();
        head = head->next;
    }
}
*/
int maxNumberOfTeams(int numberOfTeams)
{
    //functie pentru aflare numarului maxim de echipe permis
    int n = 1;
    while(2*n <= numberOfTeams)
        n = 2*n;
    return n;
}

int floatEqual(float a, float b)
{
    //functie pentru compararea a doua numere intregi
    return fabs(a-b) < 0.0000001;
}

void deleteTeamNode(teamNode **head , float v)
{
    //functie pentru stergerea unei echipe dupa punctaj
    if(*head == NULL ) 
        return;
    teamNode *headcopy = *head ;
    //se trateaza separat compararea intre variabile de tip float
    if(floatEqual(headcopy->val.teamPoints, v))
    {
        *head = (*head)->next ;
        freeNodeList(&headcopy); 
        return ; 
    }
    teamNode *prev = *head ;

    //se parcurge de fiecare data lista
    while(headcopy != NULL) 
    {
        if(floatEqual(headcopy->val.teamPoints, v)){
            prev->next = headcopy->next ;
            freeNodeList(&headcopy ); 
            return ; 
        }
        else 
        {
            prev = headcopy ;
            headcopy = headcopy->next ;
        }
    }
}

float findLowestScore(teamNode *head)
{
    //functie pentru localizarea echipei cu cel mai mic scor
    float min = head->val.teamPoints;
    head = head->next;
    while ( head != NULL )
    {
        if(head->val.teamPoints < min)
            min = head->val.teamPoints;
        head = head->next;
    }
    return min;
}

void deleteTeams(teamNode **head, int *numberOfTeams)
{
    //functia de baza pentru acest task
    int *max = (int *)malloc(sizeof(int));
    intAllocationTest(max); 

    //se calculeaza numarul maxim permis de echipe
    *max = maxNumberOfTeams(*numberOfTeams);
    float lowestScore;

    //pana la atingerea numarului maxim de echipe se cauta si se elimina echipa cu cel mai mic scor
    while(*numberOfTeams != *max)
    {
        lowestScore = findLowestScore(*head);
        deleteTeamNode(&*head, lowestScore);
        (*numberOfTeams)--;
    }
    free(max);
}