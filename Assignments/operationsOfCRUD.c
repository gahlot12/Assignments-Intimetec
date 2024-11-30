#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

struct User
{
    int userID;
    char name[MAX_LEN];
    int age;
};

void createFile(char *fileName)
{
    FILE *file = fopen(fileName, "a");
    if (!file)
    {
        printf("Error creating file.\n");
        return;
    }
    fclose(file);
}

void addUser(char *fileName)
{
    struct User newUser;
    FILE *file = fopen(fileName, "r+");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter unique user ID: ");
    scanf("%d", &newUser.userID);

    struct User tempUser;
    while (fscanf(file, "%d,%99[^,],%d\n", &tempUser.userID, tempUser.name, &tempUser.age) == 3)
    {
        if (tempUser.userID == newUser.userID)
        {
            printf("Error: User ID already exists.\n");
            fclose(file);
            return;
        }
    }
    getchar();
    printf("Enter name: ");
    scanf("%[^\n]s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);

    fprintf(file, "%d,%s,%d\n", newUser.userID, newUser.name, newUser.age);
    fclose(file);
    printf("User added successfully!\n");
}

void displayUsers(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (!file)
    {
        printf("No users found!\n");
        return;
    }

    struct User user;
    printf("Users:\n");
    while (fscanf(file, "%d,%99[^,],%d\n", &user.userID, user.name, &user.age) == 3)
    {
        printf("User ID: %d, Name: %s, Age: %d\n", user.userID, user.name, user.age);
    }

    fclose(file);
}

void updateUser(const char *fileName)
{
    int id, flag = 0;
    struct User user;
    FILE *file = fopen(fileName, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp)
    {
        printf("Error opening file.\n");
        if (file)
            fclose(file);
        if (temp)
            fclose(temp);
        return;
    }

    printf("Enter user ID to update: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userID, user.name, &user.age) == 3)
    {
        if (user.userID == id)
        {
            flag = 1;
            getchar();
            printf("Enter new name: ");
            scanf("%[^\n]s", user.name);
            printf("Enter new age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d,%s,%d\n", user.userID, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (flag)
    {
        remove(fileName);
        rename("temp.txt", fileName);
        printf("User updated successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("User ID not found.\n");
    }
}

void removeUser(const char *fileName)
{
    int id, flag = 0;
    struct User user;
    FILE *file = fopen(fileName, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp)
    {
        printf("Error opening file.\n");
        if (file)
            fclose(file);
        if (temp)
            fclose(temp);
        return;
    }

    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userID, user.name, &user.age) == 3)
    {
        if (user.userID == id)
        {
            flag = 1;
        }
        else
        {
            fprintf(temp, "%d,%s,%d\n", user.userID, user.name, user.age);
        }
    }

    fclose(file);
    fclose(temp);

    if (flag)
    {
        remove(fileName);
        rename("temp.txt", fileName);
        printf("User deleted successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("User ID not found.\n");
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    char *fileName = "users.txt";
    createFile(fileName);

    while (1)
    {
        printf("\n1. Add User \n2. Display Users \n3. Update User\n4. Delete User\n5. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addUser(fileName);
            break;
        case 2:
            displayUsers(fileName);
            break;
        case 3:
            updateUser(fileName);
            break;
        case 4:
            removeUser(fileName);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}