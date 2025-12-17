#include <stdio.h>
#include <string.h>

#define MAX_TASKS 50
#define MAX_TASK_LENGTH 50
#define FILENAME "tasks1.txt" 

typedef struct {
    char description[MAX_TASK_LENGTH];
    char status[15];
} task;

task tasks[MAX_TASKS];
int taskCount = 0;


void loadTasks() {
	
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return; 
    }
while (fscanf(file, "%49[^\n]%*c %14[^\n]%*c \n", tasks[taskCount].description, tasks[taskCount].status) != EOF) {
	taskCount++;
    if (taskCount >= MAX_TASKS) {
        break;
    
}
}	
    fclose(file);
}


void saveTasks() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Unable to save tasks.\n");
        return;
    }
    
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s\n%s\n", tasks[i].description, tasks[i].status);
    }
    fclose(file);
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter the task description: ");
    fflush(stdin);
    fgets(tasks[taskCount].description, MAX_TASK_LENGTH, stdin);
    
    strcpy(tasks[taskCount].status, "in-progress");
    taskCount++;
    saveTasks();
    printf("Task added successfully!\n");
}

void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\n\t\t\tTo-Do List\n\n");
    printf("\t%s\t\t%10s\t%20s\n\n", "S.no", "Status", "Tasks");
    for (int i = 0; i < taskCount; i++) {
        printf("\t%d\t\t%15s\t%20s\n", i + 1, tasks[i].status, tasks[i].description);
    }
    printf("\n\n");
}

void markTaskDone() {
    int taskNum;
    displayTasks();
    if (taskCount == 0) return;
    printf("Enter the task number to mark as complete: ");
    scanf("%d", &taskNum);
    if (taskNum > 0 && taskNum <= taskCount) {
        strcpy(tasks[taskNum - 1].status, "completed");
        saveTasks();
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task number.\n");
    }
}

void deleteTask() {
    int taskNum;
    displayTasks();
    if (taskCount == 0) return;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNum);
    if (taskNum > 0 && taskNum <= taskCount) {
        for (int i = taskNum - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        saveTasks();
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task number.\n");
    }
}

void editTask() {
    int taskNum;
    displayTasks();
    if (taskCount == 0) return;
    printf("Enter the task number to edit: ");
    scanf("%d", &taskNum);
    if (taskNum > 0 && taskNum <= taskCount) {
        printf("Enter the new description for task %d: ", taskNum);
        fflush(stdin);
        fgets(tasks[taskNum - 1].description, MAX_TASK_LENGTH, stdin);
        saveTasks();
        printf("Task updated successfully!\n");
    } else {
        printf("Invalid task number.\n");
    }
}

int main() {
    char choice;

    loadTasks();  

    do {
        printf("\n\t\t To-Do List Menu \n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark As Complete\n");
        printf("4. Delete Task\n");
        printf("5. Edit Task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        choice = getchar();
        switch (choice) {
            case '1':
                addTask();
                break;
            case '2':
                displayTasks();
                break;
            case '3':
                markTaskDone();
                break;
            case '4':
                deleteTask();
                break;
            case '5':
                editTask();
                break;
            case '6':
                saveTasks();  // Save tasks before exiting
                printf("\tExiting To-Do list!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '6');

    return 0;
}
