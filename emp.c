#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

COORD coord = {0, 0};

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Employee {
    char name[40];
    int age;
    float basicSalary;
};

  void login(char *userId, char *password) {
    char correctUserId[] = "KGN Technologies";
    char correctPassword[] = "saffu";

    int attempts = 0;
    do {
        system("cls");
        printf("\n\n\n\n\n\t\t#########################\n");
        printf("\t\t#########################");
        printf("\n\t\t### [EMPLOYEE LOGIN] ###");
        printf("\n\t\t#########################");
        printf("\n\t\t#########################\n");
        printf("\n\n\n");
        printf("\t\tENTER YOUR USER ID : ");
        fgets(userId, 30, stdin);

        // Remove newline character from userId
        userId[strcspn(userId, "\n")] = '\0';

        printf("\t\tENTER YOUR PASSWORD : ");
        int i = 0;
        while (1) {
            char ch = getch();
            if (ch == 13) {
                password[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) {
                i--;
                printf("\b \b");
            } else if (ch != 9 && ch != 32) {
                password[i] = ch;
                i++;
                printf("*");
            }
        }

        if (strcmp(userId, correctUserId) == 0 && strcmp(password, correctPassword) == 0) {
            printf("\n\n\n\t\t!!!LOGGED IN SUCCESSFULLY!!!\n\n");
            Sleep(2000);
            system("cls");
            break;
        } else {
            printf("\n\t\tWRONG USER ID OR PASSWORD!!\n");
            attempts++;
            printf("\t\tATTEMPTS LEFT: %d\n", 3 - attempts);
            getch();
        }
    } while (attempts < 3);

    if (attempts >= 3) {
        printf("\n\n\t\tTOO MANY FAILED ATTEMPTS. EXITING...\n");
        getch();
        exit(1);
    }
}


void addRecord(FILE *file) {
    fseek(file, 0, SEEK_END);
    char another = 'y';
    while (another == 'y') {
        struct Employee e;
        printf("\nEnter name: ");
        fgets(e.name, 40, stdin);
        printf("Enter age: ");
        scanf("%d", &e.age);
        printf("Enter basic salary: ");
        scanf("%f", &e.basicSalary);

        fwrite(&e, sizeof(e), 1, file);

        printf("\nAdd another record (y/n): ");
        fflush(stdin);
        another = getchar();
    }
}

void listRecords(FILE *file) {
    system("cls");
    rewind(file);
    printf("\n\n\n");
    printf("\t\t##############################\n");
    printf("\t\t### [ THE EMPLOYEE DATA ] ###");
    printf("\n\t\t##############################");
    printf("\n\n\n");

    int count = 1;
    struct Employee e;
    while (fread(&e, sizeof(e), 1, file) == 1) {
        printf("(%d)\t%s, %d, %.2f\n", count, e.name, e.age, e.basicSalary);
        count++;
        Sleep(500);
    }

    printf("\n\nPRESS ANY KEY TO CONTINUE...");
    getch();
}

void modifyRecord(FILE *file) {
    char empName[40];
    printf("\nEnter the employee name to modify: ");
    fgets(empName, 40, stdin);

    struct Employee e;
    int found = 0;
    rewind(file);
    while (fread(&e, sizeof(e), 1, file) == 1) {
        if (strcmp(e.name, empName) == 0) {
            printf("\nEnter new name: ");
            fgets(e.name, 40, stdin);
            printf("Enter new age: ");
            scanf("%d", &e.age);
            printf("Enter new basic salary: ");
            scanf("%f", &e.basicSalary);

            fseek(file, -sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, file);

            found = 1;
            printf("\nTHE EMPLOYEE NAME: %s DATA HAS BEEN MODIFIED\n", empName);
            break;
        }
    }

    if (!found)
        printf("\nTHE EMPLOYEE NAME: %s DATA NOT FOUND\n", empName);
}

void deleteRecord(FILE *file) {
    char empName[40];
    printf("\nEnter the employee name to delete: ");
    fgets(empName, 40, stdin);

    FILE *tempFile = fopen("Temp.dat", "wb");
    struct Employee e;
    int found = 0;

    rewind(file);
    while (fread(&e, sizeof(e), 1, file) == 1) {
        if (strcmp(e.name, empName) != 0) {
            fwrite(&e, sizeof(e), 1, tempFile);
        } else {
            found = 1;
            printf("DELETED EMPLOYEE DETAILS\nName: %s\nAge: %d\nSalary: %.2f\n", e.name, e.age, e.basicSalary);
            Sleep(1000);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("EMP.dat");
    rename("Temp.dat", "EMP.dat");

    if (found)
        printf("\nTHE EMPLOYEE NAME: %s DATA DELETED\n", empName);
    else
        printf("\nTHE EMPLOYEE NAME: %s DATA NOT FOUND\n", empName);

    file = fopen("EMP.dat", "rb+");
}

int main() {
    FILE *file = fopen("EMP.dat", "rb+");
    if (file == NULL) {
        file = fopen("EMP.dat", "wb+");
        if (file == NULL) {
            printf("\t\tCan not open file\n");
            exit(1);
        }
    }

    char userId[30], password[30];
    login(userId, password);

    while (1) {
        system("cls");
        printf("\n\n\t\t##############################\n");
        printf("\t\t### [EMPLOYEE MANAGEMENT] ###");
        printf("\n\t\t##############################");
        printf("\n\n\n");
        printf("1. Add Record\n");
        printf("2. List Records\n");
        printf("3. Modify Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("\nYour Choice: ");

        fflush(stdin);
        char choice = getche();

        switch (choice) {
            case '1':
                addRecord(file);
                break;
            case '2':
                listRecords(file);
                break;
            case '3':
                modifyRecord(file);
                break;
            case '4':
                deleteRecord(file);
                break;
            case '5':
                printf("\n\n\t\t!!!!!!! THANK YOU !!!!!\n");
                fclose(file);
                getch();
                exit(0);
        }
    }

    return 0;
}
