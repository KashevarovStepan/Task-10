#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

void delw(char*s,char*s2,int bw, int ew,int*end,int*dot)
{
    int i=0,j=0,k=0,l=0,zero=*end,d=*dot,ok;
    while((int)s[i]!=(int)'\0')
    {
        if((int)s[i]==(int)' '||(int)s[i]==(int)'.')
        {
            ok=0;
            if(i-1-j==ew-bw)
            {
                for(k=j;k<i;k++)if((int)s[k]!=(int)s[k+bw-j])ok=1;
            }
            else ok=1;
            if(ok)
            {
                for(k=j;k<=i;k++)s2[l++]=s[k];
                j=i+1;
            }
            else j=i+1;
        }
        i++;
    }
    zero=l;
    d=l-1;
    s2[zero]='\0';
    s2[d]='.';
    *end=zero;
    *dot=d;
}

void delword(char*s2,char*s3,int*end,int*dot)
{
    int i=0,j=0,k=0,l=0,zero=*end,d=*dot,ok;
    while((int)s2[i]!=(int)'\0')
    {
        if((int)s2[i]==(int)' '||(int)s2[i]==(int)'.')
        {
            ok=1;
            if(i-1-j==0)ok=1;
            else
            {
                for(k=j+1;k<i;k++)if((int)s2[k]==(int)s2[j])ok=0;
            }
            if(ok)
            {
                for(k=j;k<=i;k++)s3[l++]=s2[k];
                j=i+1;
            }
            else j=i+1;
        }
        i++;
    }
    zero=l;
    d=l-1;
    s3[zero]='\0';
    s3[d]='.';
    *end=zero;
    *dot=d;
}

int main()
{
    setlocale(LC_ALL,"Rus");
    printf("Task 10\n");
    char str[256],str2[256],str3[256],*word,*s,*s2,*s3;
    int i=0,j=0,dot=-1,end,bw,ew;
    s=str;
    s2=str2;
    s3=str3;
    printf("Введите строку символов\n");
    gets(str);
    while((int)s[i]==(int)' ')i++;
    while((int)s[i]!=(int)'\0')
    {
        if((int)s[i]!=(int)' ')
        {
            s[j]=s[i];
            if((int)s[j]==(int)'.')dot=j;
            j++;
        }
        else
        {
            if((int)s[j-1]!=(int)' ')
            {
                s[j]=s[i];
                j++;
            }
        }
        i++;
    }
    if((int)s[j-1]==(int)' ')j--;
    s[j]='\0';
    end=j;
    ew=end-1;
    if(dot!=-1)
    {
        if((int)s[dot-1]==(int)' ')
        {
            s[dot-1]='.';
            s[dot]='\0';
            end=dot;
            dot--;
            ew=dot-1;
        }
    }
    printf("\nСтрока без лишних пробелов(1B):\n");
    puts(s);

    printf("\nУдаление последнего слова и подобных из строки(2):\n");
    i=0;j=0;
    i=ew;
    while((int)s[i]!=(int)' ')
    {
        bw=i;
        i--;
    }
    i=0;
    if(dot!=-1)delw(s,s2,bw,ew,&end,&dot);
    else
    {
        dot=end;
        end++;
        s[dot]='.';
        s[end]='\0';
        delw(s,s2,bw,ew,&end,&dot);
        end=dot;
        s2[end]='\0';
        dot=-1;
    }
    puts(s2);

    printf("\nИндивидуальное задание(3)\n");
    printf("Если первая буква слова входит в это слово только один раз:\n");
    if(dot!=-1)delword(s2,s3,&end,&dot);
    else
    {
        dot=end;
        end++;
        s[dot]='.';
        s[end]='\0';
        delword(s2,s3,&end,&dot);
        end=dot;
        s2[end]='\0';
        dot=-1;
    }
    puts(s3);
    return 0;
}
