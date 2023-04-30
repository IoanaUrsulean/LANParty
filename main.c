#include"task1.h"

int main(int argc, char **argv)
{
    char *taskFilePath = argv[1];
    char *caleDate = argv[2];
    char *caleIesire = argv[3];

    FILE *task_file = fopen(taskFilePath, "rt");
    if(task_file == NULL){
        printf("ErRoR! CoUlD nOt OpEn TaSk_FiLe."); 
        exit(1);
    }

    teamNode *head = NULL;
    int *numberOfTeams = (int *)malloc(sizeof(int));
    *numberOfTeams = 0;

    int *taskArray = (int *)malloc(5*sizeof(int));
    for(int i = 0; i < 5; i++)
        fscanf(task_file, "%d", &taskArray[i]);

    if(taskArray[0])
    {
        readList(caleDate, &head, numberOfTeams);
        displayList(caleIesire, head, *numberOfTeams);
    } 
    free(taskArray);
    fclose(task_file);
    return 0;
}