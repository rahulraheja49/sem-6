#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[15];
    int pass = 0;

    printf("Enter the password: ");
    gets(buff);

    if(strcmp(buff, "pass"))
    {
        printf ("Wrong Password\n");
    }
    else
    {
        printf ("Correct Password\n");
        pass = 1;
    }

    if(pass)
    {
       /* Now Give root or admin rights to user*/
        printf ("Root privileges given to the user\n");
    }

    return 0;
}