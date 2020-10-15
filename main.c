#include <stdio.h>
#include <string.h>

typedef struct list{

char name[100];
double income;
int day;
int month;
int year;
char department[100];
int time;

}list;

int main(int argc, char *argv[]) {
FILE *ent;
int t;
ent = fopen(argv[1], "r+");

fscanf(ent, "%d\n", &t);
list a[t];

for(int i =0; i<t; i++){
  
  fgets(a[i].name, 100, ent);
  fscanf(ent, "%lf", &a[i].income);
  fscanf(ent, "%d/%d/%d\n", &a[i].day, &a[i].month, &a[i].year);
  fgets(a[i].department, 100, ent);

  a[i].time = a[i].day + (a[i].month * 30) +  (a[i].year *30 *365);
  
}
char nameaux[100] = {'\n'}, depaux[100] = {'\n'};
double incaux;
int daux, maux, yaux;

if(strcmp(argv[2],"1")==0){
  strcat(a[t-1].department, "\n");
  for(int i=0;i<t;i++){
        for(int j=i+1;j<t;j++){
            if(strcmp(a[j].name, a[i].name)<0){
                
                strcpy(nameaux, a[i].name);
                strcpy(depaux, a[i].department);
                incaux = a[i].income;
                daux = a[i].day;
                maux = a[i].month;
                yaux = a[i].year;

                strcpy(a[i].name, a[j].name);
                strcpy(a[i].department, a[j].department);
                a[i].income = a[j].income;
                a[i].day = a[j].day;
                a[i].month = a[j].month;
                a[i].year = a[j].year;
                
                strcpy(a[j].name, nameaux);
                strcpy(a[j].department, depaux);
                a[j].income = incaux;
                a[j].day = daux;
                a[j].month = maux;
                a[j].year = yaux;


            }
        }
 }

 FILE *arq;
 arq = fopen(argv[3], "w");

 for(int i=0; i<t; i++){
   fprintf(arq, "%s", a[i].name);
   fprintf(arq, "%.2f\n", a[i].income);
   if(a[i].day >= 10)
   fprintf(arq, "%d/", a[i].day);
   else
   fprintf(arq, "0%d/", a[i].day);
   if(a[i].month >=10)
   fprintf(arq, "%d/", a[i].month);
   else
   fprintf(arq, "0%d/", a[i].month);
   fprintf(arq, "%d\n", a[i].year);
   if(i != t-1)
   fprintf(arq, "%s", a[i].department);
   else{
     int p = strlen(a[i].department) - 1;
     a[i].department[p] = '\0';
   fprintf(arq, "%s", a[i].department);
   }
 }

fclose(arq);
}
if(strcmp(argv[2],"2")==0){
  char nameaux[100] = {'\n'}, depaux[100] = {'\n'};
  double incaux;
  int daux, maux, yaux;
  strcat(a[t-1].department, "\n");
  strcat(argv[3], "\n");
  for(int i = 0; i<t; i++){
    for(int j = i+1; j<t; j++){
      if(strcmp(a[j].name, a[i].name)<0){
                
                strcpy(nameaux, a[i].name);
                strcpy(depaux, a[i].department);
                incaux = a[i].income;
                daux = a[i].day;
                maux = a[i].month;
                yaux = a[i].year;

                strcpy(a[i].name, a[j].name);
                strcpy(a[i].department, a[j].department);
                a[i].income = a[j].income;
                a[i].day = a[j].day;
                a[i].month = a[j].month;
                a[i].year = a[j].year;
                
                strcpy(a[j].name, nameaux);
                strcpy(a[j].department, depaux);
                a[j].income = incaux;
                a[j].day = daux;
                a[j].month = maux;
                a[j].year = yaux;

    }
}
}

for(int i = 0; i<t; i++){
   if(strcmp(argv[3], a[i].department)==0){
   printf("%s", a[i].name);
   printf("%.2f\n", a[i].income);
   if(a[i].day >= 10)
   printf("%d/", a[i].day);
   else
   printf("0%d/", a[i].day);
   if(a[i].month >= 10)
   printf("%d/", a[i].month);
   else
   printf("0%d/", a[i].month);
   printf("%d\n", a[i].year);
   printf("%s", a[i].department);
   }
}
}
if(strcmp(argv[2],"3")==0){
  int older = a[0].time, num = 0;
  for(int i = 1; i<t; i++){
  if(a[i].time < older){
  older = a[i].time;
  num = i;
  }
  }
  printf("%s", a[num].name);
  printf("%.2lf\n", a[num].income);
  if(a[num].day>=10)
  printf("%d/", a[num].day);
  else
  printf("0%d/", a[num].day);
  if(a[num].month>=10)
  printf("%d/", a[num].month);
  else
  printf("0%d/", a[num].month);
  printf("%d\n", a[num].year);

  puts(a[num].department);

}
if(strcmp(argv[2],"4")==0){
      int num = 0, older = 0;
    strcat(argv[3], "\n");
  for(int i = 0; i<t; i++){
    if(strcmp(argv[3],a[i].department)==0){
      if(older == 0){
      older = a[i].time;
      num = i;
      }
    else if(a[i].time < older){
      older = a[i].time;
      num = i;
    }
  }
  }
  printf("%s", a[num].name);
  printf("%.2lf\n", a[num].income);
  if(a[num].day>=10)
  printf("%d/", a[num].day);
  else
  printf("%0d/", a[num].day);
  if(a[num].month>=10)
  printf("%d/", a[num].month);
  else
  printf("0%d/", a[num].month);
  printf("%d\n", a[num].year);
  puts(a[num].department);
  

}
if(strcmp(argv[2],"5")==0){
  double media = 0;
  for(int i = 0; i<t; i++){
    media = media + a[i].income;
  }
  media = media/t;
  printf("%.2lf", media);

}
if(strcmp(argv[2],"6")==0){
  double media = 0;
  int j=0;
  strcat(argv[3], "\n");
  for(int i = 0; i<t; i++){
    if(strcmp(argv[3], a[i].department)==0){
      media = media + a[i].income;
      j++;
      }
  }
  media = media/j;
  printf("%.2lf", media);

}

fclose(ent);

  return 0;
}