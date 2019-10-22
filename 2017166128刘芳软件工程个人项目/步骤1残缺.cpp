#include <stdio.h>
#include <string.h>
 
struct words
{
    char word[20];
    int count;
};
 
main()
{
    struct words word[200] = {0},stmp={0};
    int i=0,j=0,k=0,flag =0;
    char c,tmp[20]={0};
    FILE *fp = NULL;
    fp =fopen("filetest.txt","r");
    while (  (c= fgetc(fp)) !=EOF  )
    {       
        if (c!=',' && c!='.' && c!='?' && c!=' ' && c!='\n')
        {
            tmp[j++] =(c>='A'&&c<='Z')?c+32:c; 
        }else
        {
            tmp[j] ='\0';
            j=0;
            flag = 0;
            for (k=0;k<i;k++)
            {
                if ( strcmp(tmp,word[k].word)==0 )
                {
                    word[k].count++;
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                strcpy(word[i].word,tmp);
                word[i].count++;
                i++;
            }
        }
    }
    fclose(fp);
    for (j=0;j<i;j++)
    {
        for (k=0;k<i-j-1;k++)
        {
            if (word[k].count>word[k+1].count)
            {
                stmp = word[k];
                word[k] = word[k+1];
                word[k+1] = stmp;
            }
        }
    }
    for (k=0;k<i;k++)
    {
        printf("%s£º%d \t",word[k].word,word[k].count);
    }
}

