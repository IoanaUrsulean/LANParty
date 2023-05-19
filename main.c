#include"task1.h"
#include"task2.h"
#include"task3.h"

int main(int argc, char **argv)
{
    char *taskFilePath = argv[1];
    char *inputFilePath = argv[2];
    char *outputFilePath = argv[3];

    FILE *task_file = fopen(taskFilePath, "rt");
    if(task_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn TaSk_FiLe."); 
        exit(1);
    }

    teamNode *head = NULL;
    int *numberOfTeams = (int *)malloc(sizeof(int));
    intAllocationTest(numberOfTeams);
    *numberOfTeams = 0;
    int *taskArray = (int *)malloc(5*sizeof(int));
    intAllocationTest(taskArray);
    for(int i = 0; i < 5; i++)
        fscanf(task_file, "%d", &taskArray[i]);
    
    if(taskArray[0])
    {
        readList(inputFilePath, &head, numberOfTeams);
        displayList(outputFilePath, head, *numberOfTeams);
    } 
    
    if(taskArray[1])
    {
        teamPoints(head);
        deleteTeams(&head, numberOfTeams);
        displayList(outputFilePath, head, *numberOfTeams);
    } 
    if(taskArray[2])
        playGame(outputFilePath, &head, numberOfTeams, taskArray);

    //eliberare memorie
    freeMemory(&head, numberOfTeams, taskArray);
    fclose(task_file);
    return 0;
}