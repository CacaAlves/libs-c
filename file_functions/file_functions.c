#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_functions.h"

char *file_functions_get_dir_linux()
{
    char *strDir = (char *)malloc(sizeof(char) * 100);

    FILE *ptr = fopen("get_dir_linux.txt", "w"); /* Creates or cleans the file */
    fclose(ptr);

    system("pwd > get_dir_linux.txt"); /* Saves the dirname in the file */

    ptr = fopen("get_dir_linux.txt", "r");

    fscanf(ptr, "%s", strDir);

    return strDir;
}

void file_functions_create_folder_linux(const char *folderName)
{
    if (folderName != NULL)
    {
        int length = strlen(folderName);
        char *command = (char *)malloc(sizeof(char) * (7 + length));
        command[0] = 'm';
        command[1] = 'k';
        command[2] = 'd';
        command[3] = 'i';
        command[4] = 'r';
        command[5] = ' ';
        command[6] = '\0';

        strcat(command, folderName);

        system(command);
    }
}

void file_functions_create_file_linux(char *path)
{
    int length = strlen(path);

    char *command = (char *)malloc(sizeof(char) * (7 + length));

    command[0] = 't';
    command[1] = 'o';
    command[2] = 'u';
    command[3] = 'c';
    command[4] = 'h';
    command[5] = ' ';

    strcat(command, path);

    system(command);
}

void file_functions_delete_file_linux(char *path)
{
    int length = strlen(path);
    char *command = (char *)malloc(sizeof(char) * (4 + length));

    command[0] = 'r';
    command[1] = 'm';
    command[2] = ' ';
    command[3] = '\0';

    strcat(command, path);

    system(command);
}

void file_functions_delete_folder_linux(char *path)
{
    int length = strlen(path);
    char *command = (char *)malloc(sizeof(char) * (7 + length));

    command[0] = 'r';
    command[1] = 'm';
    command[2] = ' ';
    command[3] = '-';
    command[4] = 'r';
    command[5] = ' ';
    command[6] = '\0';

    strcat(command, path);

    system(command);
}
