#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char captcha[6];
    char input[20];

    srand(time(NULL));

    for(int i = 0; i < 5; i++)
    {
        captcha[i] = 'A' + rand() % 26;
    }
    captcha[5] = '\0';

    printf("CAPTCHA: %s\n", captcha);

    printf("Enter the CAPTCHA: ");
    scanf("%s", input);

    if(strcmp(captcha, input) == 0)
        printf("Verification successful. You are human.\n");
    else
        printf("Verification failed. Try again.\n");

    return 0;
}
