#include"task1.h"
#include"task2.h"
#include"task4.h"
#include"task5.h"
#include"task3.h"

Queue *createQueue()
{
    //functie pentru crearea cozii
    Queue *q;
    q = ( Queue *)malloc(sizeof(Queue));
    if(q == NULL ) 
        return NULL;
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, teamNode *head)
{
    //functie adaugare element in coada
    while(head != NULL)
    {
        queueNode * newNode = (queueNode *)malloc(sizeof(queueNode));
        newNode->team1 = head->val;
        newNode->team2 = head->next->val;
        newNode->next = NULL;
        if(q->rear == NULL) 
            q->rear = newNode;
        else 
        {
            (q->rear)->next = newNode;
            (q->rear) = newNode;
        }
        if(q->front == NULL ) 
            q->front = q->rear ;
        head = (head->next)->next;
    }
}

int isQueueEmpty(Queue *q)
{
    //functie de verificare coada vida
	return (q->front==NULL);
}

int deQueue(Queue *q, Team *d) 
{  
    //functie pentru eliminarea unui element din coada, retinandu-se valoarea
	queueNode* aux; 
    
	if(isQueueEmpty(q)) 
       return INT_MIN;
	
	aux=q->front; 
	d[0]=aux->team1;
    d[1]=aux->team2;
	q->front=(q->front)->next;
	free(aux); 	
} 

void deleteQueue(Queue *q)
{
    //functie de stergere a cozii
    queueNode *aux ;
    while(!isQueueEmpty(q))
    {
        aux = q->front ;
        q->front = q->front->next ;
        for(int i = 0; i < aux->team1.numberOfPlayers; i++)
        {
            free(aux->team1.playersArray[i].firstName);
            free(aux->team1.playersArray[i].secondName);    
        }
        free((aux->team1.playersArray));
        free((aux->team1.teamName));
        for(int i = 0; i < aux->team2.numberOfPlayers; i++)
        {
            free(aux->team2.playersArray[i].firstName);
            free(aux->team2.playersArray[i].secondName);    
        }
        free((aux->team2.playersArray));
        free((aux->team2.teamName));
        free(aux);
    }
    free(q);
}

int isStackEmpty(teamNode *top)
{
    //functie de verificare stiva vida
	return top == NULL;
}

Team top(teamNode *top)
{
    //functie ce returneaza valoarea primului element din stiva
	if (!isStackEmpty(top)) 
	    return top->val;
} 

void push(teamNode **top, Team v) 
{
    //functie de adaugare element in stiva
	teamNode *newNode = (teamNode *)malloc(sizeof(teamNode));
	newNode->val = v;
	newNode->next = *top;
	*top = newNode;
}

Team pop(teamNode **top) 
{
    //functie de eliminare element in stiva
	if(!isStackEmpty(*top))  
	{
        teamNode *temp = (*top); 		
	    Team aux = temp->val;	
	    *top = (*top)->next;      		
	    free(temp);
	    return aux;
    }
}

void deleteStack(teamNode **top)
{
    //functie de stergere a stivei
	teamNode  *temp;
	while (!isStackEmpty(*top))
    {
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}
void modifyPoints(Team d)
{
    //functie ce modifica punctajul castigatorilor
    for(int i = 0; i < d.numberOfPlayers; i++)
        d.playersArray[i].points++;
}
void displayRounds(FILE *display_file, teamNode *winnerStack, int numberOfTeams, int roundNumber)
{
    //functie de afisare a castigatorilor fiecarei runde
    fprintf(display_file, "\nWINNERS OF ROUND NO:%d\n", roundNumber);
    for(int i = 0; i < numberOfTeams; i++)
    {
        fprintf(display_file,"%-34s-  %.2f\n", winnerStack->val.teamName, winnerStack->val.teamPoints);
        winnerStack = winnerStack->next;
    }
}
void decideWinner(FILE *display_file, Queue **q, teamNode **winnerStack, teamNode **loserStack, Team *d)
{
    //functia ce umple stiva de castigatori si de invinsi dupa caz
    while(!isQueueEmpty(*q))
    {
        deQueue(*q, d);
        fprintf(display_file, "%-33s-%33s\n", d[0].teamName, d[1].teamName);
        if(d[0].teamPoints > d[1].teamPoints)
        {
            modifyPoints(d[0]);
            push(&*winnerStack, d[0]);
            push(&*loserStack, d[1]);
        }
        else
        {
            modifyPoints(d[1]);
            push(&*winnerStack, d[1]);
            push(&*loserStack, d[0]);
        }
    }
}

void tasks4and5(FILE *display_file, int *taskArray, teamNode *winnerStack, BSTNode **BSTroot, AVLNode **AVLroot, int numberOfTeams)
{   
    //functie pentru salvarea datelor necesare taskurilor 4 si 5
    if(taskArray[3])
        if(numberOfTeams == 8)
            *BSTroot = leaderBoard(display_file, winnerStack);
    if(taskArray[4])
        if(numberOfTeams == 8)
            *AVLroot = tree(display_file, winnerStack, numberOfTeams);
}

void printTasks4and5(FILE *display_file, int *taskArray, BSTNode **BSTroot, AVLNode **AVLroot)
{
    //functie pentru afisare si eliberare de memorie taskurile 4 si 5
    if(taskArray[3])
    {
        fprintf(display_file, "\nTOP 8 TEAMS:\n");
        inorder(display_file, *BSTroot);
        deleteBST(&*BSTroot);
    }
    if(taskArray[4])
    {
        fprintf(display_file, "\nTHE LEVEL 2 TEAMS ARE:\n");
        printLevel(display_file, *AVLroot, 3);
        deleteAVL(&*AVLroot);
    }
}
void rounds(FILE *display_file, Queue **q, teamNode **winnerStack, teamNode **loserStack, int *numberOfTeams, Team *d, int roundNumber)
{
    //functie de creare a meciurilor
    decideWinner(display_file, &*q, &*winnerStack, &*loserStack, d);
    (*numberOfTeams) = (*numberOfTeams)/2;
    teamPoints(*winnerStack);
    displayRounds(display_file, *winnerStack, *numberOfTeams, roundNumber);
    deleteStack(&*loserStack);
}
void playGame(char *outputFilePath, teamNode **head, int *numberOfTeams, int *taskArray)
{
    //functia de baza a acestui task
    FILE *display_file = fopen(outputFilePath, "at");
    if(display_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn ReAd_FiLe."); 
        exit(1);
    }
    //se creeaza coada cu meciurile
    Queue *q = createQueue();
    enQueue(q, *head);

    Team *d = (Team *)malloc(2*sizeof(Team));
    if(d == NULL)
    {
        printf("AlLoCaTiOn ErRoR!\n");
        exit(1);
    }
    teamNode *winnerStack = NULL, *loserStack = NULL;

    //se creeaza primul meci separat
    fprintf(display_file, "\n--- ROUND NO:1\n");
    rounds(display_file, &q, &winnerStack, &loserStack, &*numberOfTeams, d, 1);

    int *roundNumber = (int *)malloc(sizeof(int));
    intAllocationTest(roundNumber);
    *roundNumber = 1;
    BSTNode *BSTroot = NULL;
    AVLNode *AVLroot = NULL;
    //se creeaza restul meciurilor
    while(*numberOfTeams > 1)
    {   
        //se salveaza datele necesare taskului 4 si 5 daca este cazul
        tasks4and5(display_file, taskArray, winnerStack, &BSTroot, &AVLroot, *numberOfTeams);

        deleteQueue(q);
        q =  NULL;
        q = createQueue();
        enQueue(q, winnerStack);
        deleteStack(&winnerStack);
        //se creeaza celelalte meciuri
        (*roundNumber)++;
        fprintf(display_file, "\n--- ROUND NO:%d\n", *roundNumber);
        rounds(display_file, &q, &winnerStack, &loserStack, &*numberOfTeams, d, *roundNumber);
    }
    //se sterg coada si cele doua stive cu eliberare de memorie
    deleteQueue(q);
    q =  NULL;
    deleteStack(&winnerStack);
    winnerStack = NULL;
    deleteStack(&loserStack);
    loserStack = NULL;

    //se afiseaza taskurile 4 si 5 daca este cazul
    printTasks4and5(display_file, taskArray, &BSTroot, &AVLroot);
    
    fclose(display_file);
    free(d);
    free(roundNumber);
}