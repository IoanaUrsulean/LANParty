#include"task1.h"
void intAllocationTest(int *p)
{
    //functie pentru testare alocare pentru integer
    if(p == NULL)
    {
        printf("AlLoCaTiOn ErRoR!\n");
        exit(1);
    }
}
void charAllocationTest(char *p)
{
    //functie pentru testare alocare pentru caracter
    if(p == NULL)
    {
        printf("AlLoCaTiOn ErRoR!\n");
        exit(1);
    }
}
void readPlayerArray(Player *array, int intValue, FILE *read_file)
{
    //functia pentru citirea datelor despre jucatorii unei echipe
    char charBuff1[50], charBuff2[50];
    int intBuff;
	for(int j = 0; j < intValue; j++)
    {
        fscanf(read_file, "%s%s%d", charBuff1, charBuff2, &intBuff);
        charBuff1[strlen(charBuff1)] = '\0';
        charBuff2[strlen(charBuff2)] = '\0';
        array[j].firstName = (char *)malloc(strlen(charBuff1)*sizeof(char));
        charAllocationTest(array[j].firstName);
        array[j].secondName = (char *)malloc(strlen(charBuff2)*sizeof(char));
        charAllocationTest(array[j].secondName);
        strcpy(array[j].firstName, charBuff1);
        strcpy(array[j].secondName, charBuff2);
        array[j].points = intBuff;
    }
}

void readTeamNode(teamNode **head, int intValue, char *charValue, FILE *read_file)
{
    //functie de inserare in lista a informatiei stocate in buffere
	teamNode *newNode = (teamNode*)malloc(sizeof(teamNode));
    if(newNode == NULL)
    {
        printf("AlLoCaTiOn ErRoR!\n");
        exit(1);
    }
	newNode->val.numberOfPlayers = intValue;
    newNode->val.teamName = (char *)malloc(strlen(charValue)*sizeof(char));
    charAllocationTest(newNode->val.teamName);
    strcpy(newNode->val.teamName, charValue);
    newNode->val.playersArray = (Player *)malloc(intValue*sizeof(Player));
    if(newNode->val.playersArray == NULL)
    {
        printf("AlLoCaTiOn ErRoR!\n");
        exit(1);
    }
    
    //se trateaza separat vectorul cu jucatori
    readPlayerArray(newNode->val.playersArray, intValue, read_file );
	
    //insesarea se face la inceputul listei
    newNode->next = *head;
	*head = newNode;
}

void readList(char *caleDate, teamNode **head, int *numberOfTeams)
{
    //functia de baza pentru acest task
    FILE *read_file = fopen(caleDate, "rt");
    if(read_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn ReAd_FiLe."); 
        exit(1);
    }

    fscanf(read_file, "%d", numberOfTeams);
    int intBuff;
    char charBuff[100];
    for(int i = 0; i < (*numberOfTeams); i++)
    {
        fscanf(read_file, "%d", &intBuff);
        fgetc(read_file);
        fgets(charBuff, 100, read_file);
        charBuff[strlen(charBuff)-2] = '\0';
        if(charBuff[strlen(charBuff)-1] == ' ')
            charBuff[strlen(charBuff)-1] = '\0';
        
        //se citesc intai informatiile despre fiecare echipa ion buffere si apoi se insereaza in lista
        readTeamNode(&*head, intBuff, charBuff, read_file);
    }
    
    fclose(read_file);
}

void displayList(char *outputFilePath, teamNode *head, int numberOfTeams)
{
    //functia de afisare a echipelor din lista
    FILE *display_file = fopen(outputFilePath, "wt");
    if(display_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn ReAd_FiLe."); 
        exit(1);
    }

    while(head!=NULL)
    {
        fprintf(display_file, "%s\n", head->val.teamName);
        head = head->next;
    }
    fclose(display_file);
}

void freeNodeList(teamNode **head)
{
   //functie ce elibereaza un singur nod din lista si informatia continuta de acesta
    for(int i = 0; i < (*head)->val.numberOfPlayers; i++)
    {
        free((*head)->val.playersArray[i].firstName);
        free((*head)->val.playersArray[i].secondName);    
    }
    free(((*head)->val.playersArray));
    free(((*head)->val.teamName));
    free(*head);     
}

void deleteList(teamNode **head)
{
    //functia de stergere a listei cu echipe
    teamNode *headcopy;
    while (* head != NULL )
    {
        headcopy = (*head)->next ;
        freeNodeList(&*head);
        *head = headcopy ;
    }
    *head = NULL ;
}

void freeMemory(teamNode **head, int *numberOfTeams, int *taskArray)
{
    //functie pentru eliberarea memoriei alocate in main
    deleteList(&*head);
    free(numberOfTeams);
    numberOfTeams = NULL;
    free(taskArray);
    taskArray = NULL;
}   