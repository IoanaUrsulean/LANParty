#include"task1.h"
#include"task2.h"
void teamPoints(teamNode *head, int numberOfTeams)
{
    for(int i=0; i<numberOfTeams; i++)
    {
        head->val.teamPoints = 0;
        for(int j=0; j<head->val.numberOfPlayers;j++)
            head->val.teamPoints = head->val.playersArray[j].points;
        head->val.teamPoints = head->val.teamPoints/head->val.numberOfPlayers;
        head = head->next;
    }
}

int maxNumberOfTeams(int numberOfTeams)
{
    int n=1;
    while(2*n < numberOfTeams)
        n = 2*n;
    return n;
}

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


void deleteTeamNode(teamNode **head , float v)
{
    if (* head == NULL ) return;
        teamNode *headcopy = *head ;
    if ( headcopy->val.teamPoints == v)
    {
        *head = (*head)->next ;
        free(headcopy); // sterge primul element
        return ; 
    }
    // 2. Elementul de sters are o pozitie oarecare
    teamNode * prev =* head ; // predecesorul elementului cautat
    while ( headcopy != NULL )
    {
        if( headcopy->val ==v){
           prev = headcopy ;
            headcopy = headcopy->next ;
        }
        else 
        {
            prev->next = headcopy->next ;
            free ( headcopy ); // sterge elementul
            return ; 
        }
    }
}

void deleteTeams(teamNode **root)
{
    if(*root)
}