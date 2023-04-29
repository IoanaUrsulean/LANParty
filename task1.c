#include"task1.h"

void readPlayerArray(Player *array, int intValue, FILE *read_file)
{
    char *auxChar1=(char *)malloc(20*sizeof(char));
    char *auxChar2=(char *)malloc(20*sizeof(char));
    int auxInt;
	for(int j=0; intValue; j++)
    {
        auxChar1 = (char *)realloc(auxChar1, 20*sizeof(char));
        auxChar2 = (char *)realloc(auxChar2, 20*sizeof(char));
        fscanf(read_file, "%s%s%d", auxChar1, auxChar2, &auxInt);
        auxChar1 = (char *)realloc(auxChar1, strlen(auxChar1)*sizeof(char));
        auxChar2 = (char *)realloc(auxChar2, strlen(auxChar2)*sizeof(char));
        strcpy(array[j].firstName, auxChar1);
        strcpy(array[j].secondName, auxChar2);
        array[j].points = auxInt;
    }
    free(auxChar1);
    free(auxChar2);
}

void readTeamNode(teamNode **head, int intValue, char *charValue, FILE *read_file)
{
	teamNode* newNode = (teamNode*)malloc(sizeof(teamNode));
	newNode->val.numberOfPlayers = intValue;
    newNode->val.teamName = (char *)malloc(strlen(charValue)*sizeof(char));
    strcpy(newNode->val.teamName, charValue);

    newNode->val.playersArray = (Player *)malloc(intValue*sizeof(Player));
    readPlayerArray(newNode->val.playersArray, intValue, read_file );

	newNode->next = *head;
	*head = newNode;

    
}

void readList(char *caleDate, teamNode **head, int *numberOfTeams)
{
    FILE *read_file = fopen(caleDate, "rt");
    if(read_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn ReAd_FiLe."); 
        exit(1);
    }

    fscanf(read_file, "%d", numberOfTeams);
    int auxInt;
    char *auxChar;

    for(int i=0; i<*numberOfTeams; i++)
    {
        fscanf(read_file, "%d", &auxInt);
        //getchar();
        auxChar = (char *)malloc(100*sizeof(char));
        fgets(auxChar, 100, read_file);
        auxChar = (char *)realloc(auxChar, strlen(auxChar)*sizeof(char));
        readTeamNode(head, auxInt, auxChar, read_file);
    }

    fclose(read_file);
}

void displayList(char *caleIesire, teamNode *head, int numberOfTeams)
{
    FILE *display_file = fopen(caleIesire, "wt");
    if(display_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn ReAd_FiLe."); 
        exit(1);
    }
    for(int i=0; i<numberOfTeams; i++)
    {
        fprintf(display_file, "%s\n", head->val.teamName);
        head = head->next;
    }
}

void deleteList(teamNode **head)
{
    teamNode *headcopy;
    while (* head != NULL )
    {
        headcopy =(*head)->next ;
        for(int i=0; i<(*head)->val.numberOfPlayers; i++)
        {
            free((*head)->val.playersArray[i].firstName);
            free((*head)->val.playersArray[i].secondName);    
        }
        free(((*head)->val.playersArray));
        free(((*head)->val.teamName));
        free(*head);
        *head = headcopy ;
    }
    * head = NULL ;
}


void freeAll(Team teamArray[], int *numberOfTeams)
{ 
   ;
}   

/*
 

    FILE *display_file = fopen(argv[3], "at");
    if(display_file == NULL){
        printf("ErRoR! Could not open display_file."); 
        exit(1);
    }
    fclose(display_file);
*/