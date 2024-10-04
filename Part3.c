#include<stdio.h>
int p=0;
char z[100];
int main()
{
    int a,q=0;
    FILE* str,*j,*put;
    str=fopen("D:\\vscodePro\\test2\\CS-EASY-02-2.txt","r");
    j=fopen("D:\\vscodePro\\test2\\Josephus.out","r");
    put=fopen("D:\\vscodePro\\test2\\code.txt","w");
    while(fscanf(j,"%d",&a)!=EOF)
    {
        q++;
        if(q%2==1)
        for(int x=1;x<=a;x++)
            fscanf(str,"%c",&z[p++]);
        else
        for(int x=1;x<=a;x++)
            fprintf(put,"%c",z[--p]);
    }
    fclose(str);
    fclose(j);
    fclose(put);
    return 0;
}