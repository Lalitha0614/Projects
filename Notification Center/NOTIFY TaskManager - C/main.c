// including all the header files and tasks.h
#include <stdio.h>
#include <string.h>
#include "tasks.h"

//defining the macro constants used in this program
#define MAX_TASKS 100
#define BASE_YEAR 1900

//Task structure
struct Task task[MAX_TASKS];
int task_counter = 0;

//---------------------------------------------------------------------------------------------------------------------------------------
//_________________________________________Functions to check valid input cases__________________________________________________________
int valid_year(int year) {
  if (year > 0) {
    return 1;
  } else {
    return 0;
  }
}

int valid_month(int month) {
  if (month >= 1 && month <= 12) {
    return 1;
  } else {
    return 0;
  }
}

int valid_day(int day) {
  if (day >= 1 && day <= 31) {
    return 1;
  } else {
    return 0;
  }
}
//______________________________________________________________________________________________________________________________________

//Function to check leap year********************
int leap_year(int year) {
  if (valid_year(year)) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      return 1;
    } else {
      return 0;
    }
  } else {
    printf("Please enter a valid year\n\n");
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------
//__________________________________________________TASK FUNCTIONS_____________________________________________________________________

//Function to create task*********************
void create_task() {
  if (task_counter >= MAX_TASKS) {
    printf("Task limit reached.\n\n");
    return;
  }

  char task_name[100];
  printf("Enter the task name: ");
  getchar(); // Consume the newline character left by the previous scanf
  fgets(task_name, sizeof(task_name), stdin);
  task_name[strcspn(task_name, "\n")] = '\0'; // Remove the trailing newline

  int category;
  printf("Enter the category (1: work, 2: important, 3: general): ");
  scanf("%d", &category);

  // Format the taskname as "year-month-day"
  sprintf(task[task_counter].taskname, "%d-%02d-%02d %s", 0, 0, 0, task_name);
  task[task_counter].category = category;
  task_counter++;
  printf("Task created successfully.\n\n");
  save_tasks();
}


//Funtion to List task*********************
void list_tasks() {
  if (task_counter == 0) {
    printf("No tasks available.\n\n");
    return;
  }

  printf("Tasks:\n");
  for (int i = 0; i < task_counter; i++) {
    const char *category;
    switch (task[i].category) {
    case 1:
      category = "work";
      break;
    case 2:
      category = "important";
      break;
    case 3:
      category = "general";
      break;
    default:
      category = "unknown";
      break;
    }
    printf("%d. Category: %s, Task: %s\n", i + 1, category, task[i].taskname);
  }
}

//Funtion to edit task*********************
void edit_task() {
  if (task_counter == 0) {
    printf("No tasks available to edit.\n\n");
    return;
  }

  int task_index;
  printf("Enter the index of the task to edit: ");
  scanf("%d", &task_index);

  if (task_index < 1 || task_index > task_counter) {
    printf("Invalid task index.\n\n");
    return;
  }

  printf("Enter the new task name: ");
  scanf("%s", task[task_index - 1].taskname);
  printf("Task edited successfully.\n\n");
  save_tasks();
}

//Funtion to delete task*********************
void delete_task() {
  if (task_counter == 0) {
    printf("No tasks available to delete.\n\n");
    return;
  }

  int task_index;
  printf("Enter the index of the task to delete: ");
  scanf("%d", &task_index);

  if (task_index < 1 || task_index > task_counter) {
    printf("Invalid task index.\n\n");
    return;
  }

  for (int i = task_index - 1; i < task_counter - 1; i++) {
    strcpy(task[i].taskname, task[i + 1].taskname);
    task[i].category = task[i + 1].category;
  }

  task_counter--;
  printf("Task deleted successfully.\n\n");
  save_tasks();
}

//Function to create a task corresponding to a date****************
void create_task_for_date(int year,int month,int day){
  if (task_counter >= MAX_TASKS) {
    printf("Task limit reached.\n\n");
    return;
  }
    if (!valid_year(year) || !valid_month(month) || !valid_day(day)) {
    printf("Please enter valid date inputs.\n\n");
    return;
  }

  char task_name[100];
  printf("Enter the task name: ");
  getchar(); // Consume the newline character left by the previous scanf
  fgets(task_name, sizeof(task_name), stdin);
  task_name[strcspn(task_name, "\n")] = '\0'; // Remove the trailing newline

  int category;
  printf("Enter the category (1: work, 2: important, 3: general): ");
  scanf("%d", &category);

  // Format the taskname as "year-month-day"
  sprintf(task[task_counter].taskname, "%d-%02d-%02d %s", year, month, day, task_name);
  task[task_counter].category = category;
  task_counter++;
  printf("Task created successfully.\n\n");
  save_tasks();

  // Print the calendar after creating the task
  print_calendar(year, month);
}


//Funtion to display task for a date*********************
void display_tasks_for_date(int year, int month, int day) {
  printf("Tasks for %d-%02d-%02d:\n", year, month, day);
  int found = 0;

  for (int i = 0; i < task_counter; i++) {
    // Extract the date information from the taskname
    int task_year, task_month, task_day;
    sscanf(task[i].taskname, "%d-%d-%d", &task_year, &task_month, &task_day);

    if (task_year == year && task_month == month && task_day == day) {
      found = 1;
      const char *category;
      switch (task[i].category) {
      case 1:
        category = "work";
        break;
      case 2:
        category = "important";
        break;
      case 3:
        category = "general";
        break;
      default:
        category = "unknown";
        break;
      }
      printf("Task: %s, Category: %s\n", task[i].taskname, category);
    }
  }

  if (!found) {
    printf("No tasks found for the given date.\n\n");
  }
}

//Funtion to Save task in the file tasks.txt*********************
void save_tasks() {
  FILE *fp;
  fp = fopen("tasks.txt", "w");

  if (fp == NULL) {
    printf("Error opening file for writing.\n\n");
    return;
  }

  fprintf(fp, "%d\n", task_counter);

  for (int i = 0; i < task_counter; i++) {
    fprintf(fp, "%s %d\n", task[i].taskname, task[i].category);
  }

  fclose(fp);
}

//function to read tasks from the file tasks.txt*************************
void load_tasks() {
  FILE *fp;
  fp = fopen("tasks.txt", "r");

  if (fp == NULL) {
    return;
  }

  fscanf(fp, "%d\n", &task_counter);

  for (int i = 0; i < task_counter; i++) {
    fscanf(fp, "%s %d\n", task[i].taskname, &task[i].category);
  }

  fclose(fp);
}
//------------------------------------------------------------------------------------------------------------------------------------
//_________________________________________Function to print the calender______________________________________________________________
void print_calendar(int year, int month) {
  int days_in_month[] = {
      31, 28 + leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int weekday;
  int day_counter = 1;
  int days_in_current_month = days_in_month[month - 1];

  printf("Calendar for %d-%02d:\n", year, month);
  printf("Sun Mon Tue Wed Thu Fri Sat\n");

  // Determine the weekday of the first day in the given month
  weekday = (day_counter + BASE_YEAR + (BASE_YEAR / 4) - (BASE_YEAR / 100) +
             (BASE_YEAR / 400)) %
            7;

  // Print leading spaces
  for (int i = 0; i < weekday; i++) {
    printf("    ");
  }

  // Print the days of the month
  while (day_counter <= days_in_current_month) {
    printf("%3d ", day_counter);
    weekday = (weekday + 1) % 7;
    if (weekday == 0) {
      printf("\n");
    }
    day_counter++;
  }

  printf("\n");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//--------------------------------------------------------------------------------------------------------------------------------------
//_______________________________________________________MAIN FUNCTION__________________________________________________________________
#include <stdio.h>
#include <string.h>
#include "tasks.h"

int main() {
  load_tasks();// to read the tasks saved in the file
//Options ------------
  int choice, year, month;
  do {
    printf("What would you like to view now? (Enter your choice)\n\n");
    printf("1. Calendar\n");
    printf("2. Check if a year is a leap year or not\n");
    printf("3. Tasks\n");
    printf("4. Exit Notification center\n\n");
    printf("Enter your choice: ");
    
            if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n\n");
            clear_input_buffer(); // Clear the input buffer
            continue;
            }
            
    switch (choice) {
    case 1:
    //Printing Calender-----------------
      printf("\n");
      printf("Option 1 selected\n\n");
      printf("Please enter the year(xxxx): ");
      scanf("%d", &year);
      printf("Please enter the month(1-12): ");
      scanf("%d", &month);
      if (valid_year(year) && valid_month(month)) {
        print_calendar(year, month);
      } else {
        printf("Please check the year and month entered and enter valid inputs\n\n");
      }
      break;
    case 2:
    //Checking if a year is leap year or not-----
      printf("\n");
      printf("Option 2 selected\n\n");
      printf("Please enter the year(xxxx): ");
      scanf("%d", &year);
      if (leap_year(year) == 1) {
        printf("%d is a leap year.\n", year);
      } else {
        printf("%d is not a leap year.\n", year);
      }
      break;
   
    case 3:
// Working with tasks
      printf("\n");
      printf("Option 3 selected\n\n");
  int tasks_choice;
  //options in tasks
  do {
    printf("What would you like to do?\n\n");
    printf("1. List Tasks\n");
    printf("2. Create a task\n");
    printf("3. Create a task for a particular date\n");
    printf("4. Display tasks corresponding to a date\n");
    printf("5. Edit an existing task\n");
    printf("6. Delete a task\n");
    printf("7. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &tasks_choice);

    switch (tasks_choice) {
    case 1:
      // listing the available tasks
      printf("\n");
      list_tasks();
      break;
    case 2:
      // creating a new task
      printf("\n");
      create_task();
      break;
    case 3:
      // creating a task to a particular date
      printf("\n");
      printf("Option 3 selected\n\n");
      int year, month, day;
      printf("Please enter the year(xxxx): ");
      scanf("%d", &year);
      printf("Please enter the month(1-12): ");
      scanf("%d", &month);
      printf("Please enter the day(1-31): ");
      scanf("%d", &day);
      create_task_for_date(year, month, day);
      break;
    case 4:
      // displaying tasks corresponding to a date
      printf("\n");
      printf("Option 4 selected\n\n");
      printf("Please enter the year(xxxx): ");
      scanf("%d", &year);
      printf("Please enter the month(1-12): ");
      scanf("%d", &month);
      printf("Please enter the day(1-7): ");
      scanf("%d", &day);
      if (valid_year(year) && valid_month(month) && valid_day(day)) {
        display_tasks_for_date(year, month, day);
      } else {
        printf("Please enter valid inputs\n\n");
      }
      break;
      case 5:
      // editing an existing task
      printf("\n");
      edit_task();
      break;
     case 6:
      // deleting a task
      printf("\n");
      delete_task();
      break;
     case 7:
      // exiting task manager
      printf("\n");
      printf("Exiting task manager...\n\n");
      break;
     default:
      printf("\n");
      printf("Invalid choice. Please try again.\n\n");
      clear_input_buffer(); // Clear the input buffer
      break;
     }
     } while (tasks_choice != 7);
    break;
  
// ... Rest of the code ...
 case 4:
    //exiting notify
      printf("Exiting Notification center...\n\n");
      break;
    default:
    printf("\n");
    printf("Invalid choice. Please try again.\n\n");
    clear_input_buffer(); // Clear the input buffer
    break;
    }
  } while (choice != 4);

//Saving the tasks in tasks.txt file for future accessing------
  save_tasks();
  return 0;
}


