#include"task1.h"
#include"task2.h"
#include"task3.h"

Queue * createQueue()
{
    Queue *q;
    q=( Queue *) malloc ( sizeof ( Queue ));
    if (q== NULL ) 
        return NULL ;
    q->front = q->rear = NULL ;
    return q;
}

void enQueue(Queue *q, teamNode *head)
{
    while(head != NULL)
    {
        queueNode * newNode =( queueNode *) malloc ( sizeof ( queueNode ));
        newNode->team1 = head->val;
        newNode->team2 = head->next->val;
        newNode->next = NULL ;
        if (q->rear == NULL ) 
            q->rear = newNode ;
        else {
            (q->rear ) ->next = newNode ;
            (q->rear ) = newNode ;
        }
        if (q->front == NULL ) 
            q->front = q->rear ;
        head = (head->next)->next;
    }
}

int isQueueEmpty(Queue *q)
{
	return (q->front==NULL);
}

int deQueue(Queue*q, Team *d) 
{  
	queueNode* aux; 
    
	if (isQueueEmpty(q)) 
       return INT_MIN;
	
	aux=q->front; 
	d[0]=aux->team1;
    d[1]=aux->team2;
	q->front=(q->front)->next;
	free(aux); 	
} 

void deleteQueue ( Queue *q)
{
    queueNode *aux ;
    while (! isQueueEmpty (q)){
    aux =q->front ;
    q->front =q->front->next ;
    // printf (”%d” ,aux ->val );
    free ( aux );
    }
    free (q);
}

int isStackEmpty(teamNode*top)
{
	return top==NULL;
}

Team top(teamNode *top)
{
	if (isStackEmpty(top)) 
        return;
	return top->val;
} 

void push(teamNode**top, Team v) 
{
	teamNode* newNode=(teamNode*)malloc(sizeof(teamNode));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

Team pop(teamNode**top) 
{
	if (isStackEmpty(*top)) return;
	teamNode *temp=(*top); 		
	Team aux=temp->val;	
	*top=(*top)->next;      		
	free(temp);
	return aux;
}

void deleteStack(teamNode**top)
{
	teamNode  *temp;
	while (!isStackEmpty(*top))
    {
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}
void modifyPoints(Team d)
{
    for(int i=0; i<d.numberOfPlayers; i++)
        d.playersArray[i].points++;
}
void displayRounds(FILE *display_file, teamNode *winnerStack, int numberOfTeams, int roundNumber)
{
    fprintf(display_file, "\nWINNERS OF ROUND NO:%d\n", roundNumber);
    for(int i=0; i<numberOfTeams; i++)
    {
        fprintf(display_file,"%-32s- %.2f\n", winnerStack->val.teamName, winnerStack->val.teamPoints);
        winnerStack = winnerStack->next;
    }

}
void rounds(char *outputFilePath, teamNode **head, int *numberOfTeams)
{
    FILE *display_file = fopen(outputFilePath, "at");
    if(display_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn ReAd_FiLe."); 
        exit(1);
    }

    Queue *q = createQueue();
    enQueue(q, *head);
    fprintf(display_file, "\n--- ROUND NO:1\n");
    
    Team *d = (Team *)malloc(2*sizeof(Team));
    teamNode *winnerStack = NULL, *loserStack = NULL;
    while(!isQueueEmpty(q))
    {
        deQueue(q, d);
        fprintf(display_file, "%-32s-%32s\n", d[0].teamName, d[1].teamName);
        if(d[0].teamPoints>d[1].teamPoints)
        {
            modifyPoints(d[0]);
            push(&winnerStack, d[0]);
            push(&loserStack, d[1]);
        }
        else
        {
            modifyPoints(d[1]);
            push(&winnerStack, d[1]);
            push(&loserStack, d[0]);
        }
    }
    (*numberOfTeams) = (*numberOfTeams)/2;
    //deleteList(&*head);
    teamPoints(winnerStack, *numberOfTeams);
    displayRounds(display_file, winnerStack, *numberOfTeams, 1);
    deleteStack(&loserStack);
    int roundNumber = 1;
    while(*numberOfTeams > 1)
    {   
        roundNumber++;
        fprintf(display_file, "\n--- ROUND NO:%d\n", roundNumber);
        deleteQueue(q);
        q =  NULL;
        q = createQueue();
        
        enQueue(q, winnerStack);
        deleteStack(&winnerStack);

         while(!isQueueEmpty(q))
        {
            deQueue(q, d);
            fprintf(display_file, "%-32s-%32s\n", d[0].teamName, d[1].teamName);
            if(d[0].teamPoints>d[1].teamPoints)
            {
                modifyPoints(d[0]);
                push(&winnerStack, d[0]);
                push(&loserStack, d[1]);
            }
            else
            {
                modifyPoints(d[1]);
                push(&winnerStack, d[1]);
                push(&loserStack, d[0]);
            }
        }
        (*numberOfTeams) = (*numberOfTeams)/2;
        teamPoints(winnerStack, *numberOfTeams);
        displayRounds(display_file, winnerStack, *numberOfTeams, roundNumber);
        
        deleteStack(&loserStack);
    }
    
    
    fclose(display_file);
}