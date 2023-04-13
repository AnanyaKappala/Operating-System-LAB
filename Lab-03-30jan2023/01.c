/* write c program to stimulate following linux commands
1. cat 
2. cp
3. grep */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp1, *fp2;
    char ch, file1[20], file2[20], str[80];
    int i, count = 0;

    printf("  1. cat \t 2. cp \t 3. grep \t 4. exit \t Enter your choice: ");
    scanf("%d", &i);
    
    switch(i)
    {
        case 1:printf("Enter the name of file: ");
            scanf("%s", file1);
            fp1 = fopen(file1, "r");
            if(fp1 == NULL)
            {
                printf("Cannot open file %s \n", file1);
                exit(0);
            }
             ch = fgetc(fp1);
            while(ch != EOF)
            {
                printf("%c", ch);
                ch = fgetc(fp1);
            }
            fclose(fp1);
            break; 
        case 2:
            printf("Enter the name of file to be copied: ");
            scanf("%s", file1);
            printf("Enter the name of new file: ");
            scanf("%s", file2);
            fp1 = fopen(file1, "r");
            fp2 = fopen(file2, "w");
            if(fp1 == NULL)
            {
                printf("Cannot open file %s \n", file1);
                exit(0);
            }
            if(fp2 == NULL)
            {
                printf("Cannot open file %s \n", file2);
                exit(0);
            }
            ch = fgetc(fp1);
            while(ch != EOF)
            {
                fputc(ch, fp2);
            ch = fgetc(fp1);
            }
            printf("File copied successfully. \n");
            fclose(fp1);
            fclose(fp2);
            break;
        case 3:
            printf("Enter the name of file: ");
            scanf("%s", file1);
            printf("Enter the string to be searched: ");
            scanf("%s", str);
            fp1 = fopen(file1, "r");
            if(fp1 == NULL)
            {
                printf("Cannot open file %s \n", file1);
                exit(0);
            }
            ch = fgetc(fp1);
            while(ch != EOF)
            {
                if(ch == str[0])
                {
                    fseek(fp1, -1, SEEK_CUR);
                    fgets(str, 80, fp1);
                    printf("%s", str);
                    count++;
                }
                ch = fgetc(fp1);
            }
            if(count == 0)
                printf("String not found. \n");
            else
                printf("Total %d occurence(s) found. \n", count);
            fclose(fp1);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. \n");
    }
    return 0;
}