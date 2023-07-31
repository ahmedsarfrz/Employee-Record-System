#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
COORD coord={0,0};// Declare a 2D coordinate variable named 'coordinate' with initial position (0, 0).
void gotoxy(int x,int y)
{
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
FILE *f1,*f2;
char another,choice;
struct emp{
char name[40];
int age;
float bs;
};
struct emp e;
char empname[40];
long int resize;
int count = 0;
int sarfaraaz;
 int i,flag,p,xy=16;
char id[30],password[30],ch;
char pid[30]= "COMPANY", ppass[20]="saffu";
do{
system("cls");
printf("\n\n\n\n\n\t\t**********************************************************\n");
 printf("\t\t**********************************************************");
 printf("\n\t\t*************::::::[EMPLOYE RECORD SYSTEM]:::::***********");
 printf("\n\t\t**********************************************************");
 printf("\n\t\t**********************************************************\n");
 printf("\n\n\n");
 printf("\t\tENTER YOUR USER ID : ");
 gets(id);
 printf("\t\tENTER YOUR PASSWORD : ");
 i=0;
 while(1)
 {
 ch=getch();
 if(ch==13)
 {
 password[i]='\0';
 break;
 }
 else if(ch==8)
 {
 if(i>0)
 {
 i--;
 printf("\b \b");
 }
 }
 else if(ch==9||ch==32)
 {
 continue;
 }
 else
 {
 password[i]=ch;
 i++;
 printf("*");
 }
 }
 if(strcmp(id,pid)==0)
 {
 if(strcmp(password,ppass)==0)
 {
 printf("\n\n\n\t\t**** YOU HAVE LOGGED IN SUCCESSFULL ****\n\n");
 Sleep(2000);;
 system("cls");
 printf("\n\n\n");
 printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
printf("\t\t***********************************************************");
 printf("\n\t\t#################::::::[ WELCOME ]:::::###################");
 printf("\n\t\t*********************************************************");
 printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
 printf("\n\n\n\n\n\n");
 printf("\n\n\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE");
 getch();
 break;
 }
 else
 {
 printf("\t\tWRONG PASSWORD\n\n");
 printf("PLEASE TRY AGAIN \n");
 getch();
 count ++;
 }
 }
 else
 {
 printf("\t\tWRONG USER ID \n\n");
 printf(" PLEASE TRY AGAIN \n");
 getch();
 count ++;
 }
 gotoxy(30,10);
}
while(count<=2);
if(count>2){
printf("\n\n\t\tYOU HAD ENTERED WRONG ID AND PASSWORD MORE THAN 3 TIMES");
printf("\n\t\tYOU CROSSED THE LIMIT\n\n");
getch();
exit(1);
}
f1=fopen("EMP.dat","rb+");
if(f1==NULL)
{
f1=fopen("EMP.dat","wb+");
if(f1==NULL)
{
printf("\t\tCan not open file\n");
exit(1);
}
}
resize=sizeof(e);
while(1)
{
system("cls");
printf("\n\n\t\t##########################################################\n");
 printf("\t\t##########################################################");
 printf("\n\t\t###########::::::[EMPLOYE RECORD SYSTEM]:::::#############");
 printf("\n\t\t##########################################################");
 printf("\n\t\t##########################################################\n");
 printf("\n\n\n");
gotoxy(30,10);
printf("1.Add Record ");
gotoxy(30,12);printf("2.List Record ");
gotoxy(30,14);
printf("3.Modify Record ");
gotoxy(30,16);
printf("4.Delete Record ");
gotoxy(30,18);
printf("5.Exit ");
gotoxy(30,20);
printf("Your Choice : ");
fflush(stdin);
choice = getche();
switch(choice)
{
case '1':
system("cls");
printf("\n\n");
 printf("\n\t\t###########::::::[ ADD EMPLOYEE RECORD ]:::::#############");
 printf("\n\n");
fseek(f1,0,SEEK_END);
another = 'y';
while(another=='y')
{
printf("\nEnter name : ");
fflush(stdin);
scanf("%s",e.name);
printf("\nEnter age : ");
scanf("%d",&e.age);
printf("\nEnter basic salary : ");
scanf("%f",&e.bs);
fwrite(&e,resize,1,f1);
printf("\nAdd another record (y/n) : ");
fflush(stdin);
another = getche();
}
break;
case '2':
system("cls");
rewind(f1);
 printf("\n\n");
 printf("\n\t\t##########::::::[ THE EMPLOYEE DATA ]:::::################");
 printf("\n\n\n");
p=1;
printf("\n\n\n");printf("\t\t\t");
printf("_________________________________________\n");
printf("\t\t\t");
printf("|| ||\n");
printf("\t\t\t");
printf("|| \tNAME , AGE , BASIC SALARY\t||\n");
printf("\t\t\t");
printf("||______________________________________||\n");
printf("\t\t\t");
printf("|| ||");
while(fread(&e,resize,1,f1)==1)
{
printf("\n");
Sleep(500);;
printf("\t\t\t");
printf("||");
printf(" (%d)\t%s , %d , %.2f",p,e.name,e.age,e.bs);
gotoxy(64,xy++);
printf("||");
p++;
Sleep(500);;
}
printf("\n");
printf("\t\t\t");
printf("|| ||\n");
printf("\t\t\t");
printf("||______________________________________||\n");
printf("\n\n\n\n\nPRESS ANY KEY TO CONTINUE");
getch();
break;
case '3':
system("cls");
printf("\n\n\n");
 printf("\n\t\t##########::::::[ MODIFY EMPLOYEE RECORD ]:::::###########");
 printf("\n\n\n");
another = 'y';
while(another=='y')
{
printf("\n");
 printf("\nEnter the employee name to modify : ");
 scanf("%s",empname);
 flag=0;
 rewind(f1);
 while(fread(&e,resize,1,f1)==1)
 {
 if(strcmp(e.name,empname)==0)
 {
 printf("\nEnter name : ");
 scanf("%s",e.name);
 printf("\nEnter age : ");
 scanf("%d",&e.age);
 printf("\nEnter basic salary : ");
 scanf("%f",&e.bs);
 fseek(f1,-resize,SEEK_CUR);
 fwrite(&e,resize,1,f1);
 flag=1;
 break;
 }
 }
 if(flag==1)
 {
 printf("\n\t EMPLOYEE NAME : %s DATA HAS BEEN MODIFIED\n",empname);
 }
 else{
 printf("\n\t EMPLOYEE NAME : %s DATA NOT FOUND\n",empname);
 printf("\nModify another record (y/n) : ");
 fflush(f1);
 another = getche();}
}
break;
case '4':
system("cls");
printf("\n\n\n");
 printf("\n\t\t###########::::::[ DELETE EMPLOYEE RECORD ]:::::##########");
 printf("\n\n\n");
another = 'y';
flag=0;
while(another=='y')
{
flag=0;
printf("\n");
printf("\nEnter the employee name to delete : ");
scanf("%s",empname);
f2=fopen("Temp.dat","wb");
rewind(f1);
while(fread(&e,resize,1,f1)==1)
{
if(strcmp(e.name,empname) !=0)
{
fwrite(&e,resize,1,f2);
}
else
{
flag=1;
printf("DELECTED EMPLOYE DETAILS \n");
printf("Name : %s\n",e.name);
printf("Age : %d\n",e.age);
printf("Salary : %f\n",e.bs);
Sleep(1000);;
}
}
fclose(f1);
fclose(f2);
remove("EMP.dat");
rename("Temp.dat","EMP.dat");
if(flag==1)
printf("\n\t EMPLOYEE NAME : %s DATA DELETED\n",empname);
else
printf("\n\t EMPLOYEE NAME : %s DATA NOT FOUND\n",empname);
f1=fopen("EMP.dat","rb+");
printf("\nDelete another record (y/n) : ");
fflush(f1);
another = getche();
}
break;
case '5':
printf("\n\n");
printf("\t\t\t*** THANK YOU *** ");
getch();
fclose(f1);
exit(0);
}
}
return 0;
}
