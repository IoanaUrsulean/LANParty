#include"task1.h"

int main(int argc, char **argv)
{
    char *caleTask = argv[1];
    char *caleDate = argv[2];
    char *caleIesire = argv[3];

    FILE *task_file = fopen(caleTask, "rt");
    if(task_file == NULL){
        printf("ErRoR! Could not open task_file."); 
        exit(1);
    }


    teamNode *head = NULL;
    int *numberOfTeams = (int *)malloc(sizeof(int));
    *numberOfTeams = 0;

    int taskArray[5] = {0};
    for(int i = 0; i < 5; i++)
        fscanf(task_file, "%d", &taskArray[i]);

    if(taskArray[0])
    {
        readList( caleDate, &head, numberOfTeams);
        displayList(caleIesire, head, *numberOfTeams);
    } 

    fclose(task_file);
    return 0;
}