#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    printf("hashed input: %s\n", argv[1]);

    //salt, first two characters of argv[1]
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';
    // printf("Salt: %s\n", salt);

    //string of alphabet
    char alp[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char arr[6];
    int j = 1;

    for (int c = 0; c <= strlen(alp); c++)
    {
        arr[4] = alp[c];

        for (int b = 0; b <= strlen(alp); b++)
        {
            arr[3] = alp[b];

            for (int a = 0; a <= strlen(alp); a++)
            {
                arr[2] = alp[a];

                for (int y = 0; y <= strlen(alp); y++)
                {
                    arr[1] = alp[y];

                    for (int x = 0; x <= strlen(alp); x++)
                    {
                        arr[0] = alp[x];
                        arr[j] = '\0';
                        //printf("%s\n", arr);
                        if (strcmp(argv[1], crypt(arr, salt)) == 0)
                        {
                            printf("%s\n", arr);
                            return 0 ;
                        }
                    }
                    if (j < 5)
                    {
                        j++;
                    }
                }
            }
        }
    }
}
