#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{   
    while(1)
    {
        char s[256];
        fgets(s, 250 , stdin);
        char ret[100][100];
        char *pret[100];
        int j = 0;
        int cur = 0 ;
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i] == ' ' || s[i] == '\n')
            {   
                pret[j] = ret[j];
                j++;
                cur = 0;
            }
            else
            {
                ret[j][cur++] = s[i];
                ret[j][cur] = '\0';
            }
        }
        pret[j] = NULL;
        int x = fork();
        if(x == 0)
            execvp(pret[0], pret);

    }
    return 0;
}