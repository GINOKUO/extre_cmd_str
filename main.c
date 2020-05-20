 #include <stdio.h>
  
int main(void)
{
     FILE * fp;
     if ((fp = popen("ls -l", "r")) == NULL)
     {
         printf("open failed!");
         return -1;
    }
     char but[256];
     while (fgets(but, 255, fp) != NULL)
         printf("%s", but);
     if (pclose(fp) == -1)
     {
         printf("close failed!");
         return -2;
     }
     return 0;
}