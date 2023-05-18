#include"task1.h"
#include"task2.h"

void teamPoints(teamNode *head)
{
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
    int n = 1;
    while(2*n <= numberOfTeams)
        n = 2*n;
    return n;
}

int floatEqual(float a, float b)
{
    return fabs(a-b) < 0.0000001;
}

void deleteTeamNode(teamNode **head , float v)
{
    if(*head == NULL ) 
        return;
    teamNode *headcopy = *head ;
    if(floatEqual(headcopy->val.teamPoints, v))
    {
        *head = (*head)->next ;
        freeNodeList(&headcopy); 
        return ; 
    }
    teamNode *prev = *head ; 
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
    int *max = (int *)malloc(sizeof(int));
    intAllocationTest(max); 
    *max = maxNumberOfTeams(*numberOfTeams);
    float lowestScore;
    while(*numberOfTeams != *max)
    {
        lowestScore = findLowestScore(*head);
        deleteTeamNode(&*head, lowestScore);
        (*numberOfTeams)--;
    }
    free(max);
}








/*
BSTnode *newNode(float data) {
	BSTnode *node = (BSTnode*)malloc(sizeof(BSTnode));
	node->val = data;
	node->left = node->right = NULL;
	return node;
}

BSTnode *insert(BSTnode* node, float key) {
	if (node == NULL) return newNode(key);
	if (key < node->val)
		node->left  = insert(node->left, key);
	else if (key > node->val)
		node->right = insert(node->right, key);
	return node;
}

void createPointsBST(BSTnode *root)
{
    
    while (* head != NULL )
    {
        root = insert(root, head->val.teamPoints);
        head = head->next;
    }
}
*/