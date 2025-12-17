# To-Do List Application

---

## Objective

The main objective of this To-Do List application is to provide a simple, interactive, and efficient tool for managing tasks. It allows users to add, view, mark as completed, edit, and delete tasks in a structured manner while ensuring user-friendly input handling and clear feedback.

This program helps users organize their tasks, track progress, and maintain an up-to-date and manageable task list to improve productivity. With features such as adding, displaying, editing, deleting, and marking tasks as completed, users can efficiently manage their daily responsibilities.

---

## Project Features

The application integrates the following functionalities:

* **Add Tasks**: Create and store new tasks in the to-do list.
* **Display Tasks**: View all tasks along with their current status.
* **Mark Tasks as Done**: Update task status to track completion.
* **Delete Tasks**: Remove unnecessary or completed tasks.
* **Edit Tasks**: Modify existing task descriptions.
* **Exit Program**: Safely close the program after saving tasks.

---

## Header Files

The following header files are used to support input/output operations and string handling:

```c
#include <stdio.h>   // Input and output functions
#include <string.h>  // String manipulation functions
```

---

## Constants Definition

The program defines constants to control task limits and file handling:

```c
#define MAX_TASKS 50
#define MAX_TASK_LENGTH 50
#define FILENAME "tasks.txt"
```

* **MAX_TASKS**: Maximum number of tasks allowed
* **MAX_TASK_LENGTH**: Maximum length of a task description
* **FILENAME**: File used to store tasks persistently

---

## Data Structures

### Task Structure

Each task is represented using a structure with the following fields:

* `description[MAX_TASK_LENGTH]`: Stores the task description
* `status[15]`: Stores the task status ("in progress" or "completed")

```c
typedef struct {
    char description[MAX_TASK_LENGTH];
    char status[15];
} Task;
```

### Global Variables

* `tasks[MAX_TASKS]`: Array to store all tasks
* `taskCount`: Tracks the current number of tasks

---

## Functions Description

### 1. `loadTasks()`

**Purpose:** Load saved tasks from a file.

**Steps:**

* Open `tasks.txt` in read mode
* If the file does not exist, return
* Read task descriptions and statuses using `fscanf`
* Increment `taskCount` until EOF or `MAX_TASKS`
* Close the file

---

### 2. `saveTasks()`

**Purpose:** Save current tasks to a file.

**Steps:**

* Open `tasks.txt` in write mode
* Write each task's description and status to the file
* Close the file

---

### 3. `addTask()`

**Purpose:** Add a new task to the list.

**Steps:**

* Check if `taskCount < MAX_TASKS`
* Prompt the user for a task description
* Store the description and set status to "in progress"
* Increment `taskCount`
* Save tasks to the file
* Display a success message

---

### 4. `displayTasks()`

**Purpose:** Display all tasks and their statuses.

**Steps:**

* If no tasks exist, display an appropriate message
* Otherwise, loop through and print task number, status, and description

---

### 5. `markTaskDone()`

**Purpose:** Mark a task as completed.

**Steps:**

* Display all tasks
* Prompt the user for a task number
* Validate the input
* Update the task status to "completed"
* Save changes and display confirmation

---

### 6. `deleteTask()`

**Purpose:** Delete a task from the list.

**Steps:**

* Display all tasks
* Prompt the user for a task number
* Validate the input
* Shift remaining tasks to fill the gap
* Decrement `taskCount`
* Save changes and display confirmation

---

### 7. `editTask()`

**Purpose:** Edit an existing task description.

**Steps:**

* Display all tasks
* Prompt the user for a task number
* Validate the input
* Accept a new task description
* Update the task and save changes

---

### 8. `main()`

**Purpose:** Control program execution and user interaction.

**Steps:**

* Load tasks at program startup
* Display the main menu:

  * Add Task
  * Display Tasks
  * Mark As Complete
  * Delete Task
  * Edit Task
  * Exit
* Use a switch statement to call the appropriate function
* Continue until the user selects Exit
* Save tasks before terminating the program

---

## Program Demonstration

### Adding a Task

* User selects **Add Task**
* Enters a description
* Task is added with status "in progress"

### Displaying Tasks

* User selects **Display Tasks**
* All tasks with their statuses are shown

### Marking a Task as Complete

* User selects **Mark As Complete**
* Chooses a task number
* Task status changes to "completed"

### Deleting a Task

* User selects **Delete Task**
* Chooses a task number
* Task is removed from the list

### Editing a Task

* User selects **Edit Task**
* Chooses a task number
* Updates the task description

---

## End of Program

The program exits safely after saving all tasks and displaying an exit message.
