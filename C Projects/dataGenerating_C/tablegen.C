#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

char generateRandomChar(int minAscii, int maxAscii) {
    return (char)(minAscii + rand() % (maxAscii - minAscii + 1));
}
int main() {

    int b=0;
    printf("TableGen menu");
    printf("\n-------------\n1. Generate new table\n2. Exit\n\nSelection:");
   
    scanf("%d", &b);
   system("clear");
   char proceed;
do{
    if(b==2){
      
        printf("Goodbye and thanks for using TableGen\n");
         return 0;
    }  
  
        printf("Column Options\n");
        printf("-------------\n");
        printf("1. User ID \t 5.Phone number\n");
        printf("2. First Name \t 6.Email address\n");
        printf("3. Second Name \t 7.SIN\n");
        printf("4. Country \t 8.Password\n");

        printf("Enter column list (comma-separated, no spaces):");

    char str[]="";
    char filename[]="hh";
    int count=0;
    scanf("%s", &str);
    int a[8];

    char * token = strtok(str,",");
while(token!=NULL){
    a[count]=atoi(token);
   count++;
    token = strtok(NULL,",");
}

int c;
printf("\nEnter row count (1 < n < 1M)\n");
scanf("%d",&c);
printf("Enter output file name (no suffix):\n");
scanf("%s", &filename);

printf("summary of properties:\n");
printf("Columns:");
for(int i=0;i<count;i++)
{
    if(i==count-1)
    {
        printf("%d",a[i]);
    }
    else
    {
        printf("%d,",a[i]);
    }
}
printf("\nRow count: %d",c);
strcat(filename,".csv"); 
printf("\nFile name: %s \n",filename);

FILE *filew = fopen("helper.txt", "w");
FILE *fileb = fopen("countries.txt", "r");
FILE *filec = fopen("first_names.txt", "r");
FILE *filed = fopen("last_names.txt", "r");
FILE *filee = fopen("email_suffixes.txt", "r");
char ch;
char arf[1000][40];
int x;
for(int b = 0;b<1000;b++){
    x=0;
    while((ch=fgetc(filec)) !='\n'){
        arf[b][x]=ch;
        x++;
    }
}
char arl[1000][40];
for(int b = 0;b<1000;b++){
    x=0;
    while((ch=fgetc(filed)) !='\n'){
        arl[b][x]=ch;
        x++;
    }
}
char arc[195][50];
for(int b = 0;b<195;b++){
    x=0;
    while((ch=fgetc(fileb)) !='\n'){
        arc[b][x]=ch;
        x++;
    }
}
char are[100][50];
for(int b = 0;b<100;b++){
    x=0;
    while((ch=fgetc(filee)) !='\n'){
        are[b][x]=ch;
        x++;
    }
}
int randfirst=rand() % 1000;
int randlast =rand() % 1000;
int randcountry;
int randnum;
int randnum1;
int row=0;
int nums[]={398, 270, 925, 867, 209, 429, 908, 997,444, 219};

for(int v = 0;v<count;v++){
    if(a[v]==1){
fprintf(filew,"User id, ");
    }
     else if(a[v]==2)
     fprintf(filew,"First Name, ");
      else if(a[v]==3)
      fprintf(filew,"Last Name, ");
       else if(a[v]==4)
       fprintf(filew,"Country, ");
        else if(a[v]==5)
        fprintf(filew,"Phone, ");
         else if(a[v]==6)
          fprintf(filew,"Email, ");
          else if(a[v]==7)
           fprintf(filew,"Sin, ");
            else if(a[v]==8)
             fprintf(filew,"Password"); 
           if(v==count-1){
            fprintf(filew,"\n");
           }
}



while(row<c)
{
for(int i=0;i<count;i++)
{
    if(a[i]==1){
  fprintf(filew,"%d",row+1);
   // printf("%d",row+1);
    }
    else if(a[i]==2)
    {
         randfirst=rand() % 1000;
         fprintf(filew,arf[randfirst]);
        //printf("%s",arf[randfirst]);
    }
    else if(a[i]==3)
    {
        randlast =rand() % 1000;
         fprintf(filew,arl[randlast]);
        //printf("%s",arl[randlast]);
    }
    else if(a[i]==4)
    {
         randcountry=rand() % 195 +1;
          fprintf(filew,arc[randcountry]);
       // printf("%s",arc[randcountry]);
    }
     else if(a[i]==5)
    {
          randnum1=rand() % 9000 + 1000 ;
          randnum =rand() % 10;
          fprintf(filew,"%d-",nums[randnum]);
          fprintf(filew,"%d",randnum1);
        //printf("%d-",nums[randnum]);
       // printf("%d",randnum1);
    }
    else if(a[i]==6)
{
     fprintf(filew,"%c",arf[randfirst][0]);
     fprintf(filew,arl[randlast]);
     fprintf(filew,"%s",are[rand() % 100]);
//printf("%c",arf[randfirst][0]);
//printf("%s.",arl[randlast]);
     //  printf("%s",are[rand() % 100]);
}
else if(a[i]==7)
{
long randomSin=rand() % 900000000 + 100000000;
fprintf(filew,"%ld",randomSin);
//printf("%ld ",randomSin);
}
else if(a[i]==8)
{
    int passwordLength = 6 + rand() % 11;
     char password[17]; // +1 for the null terminator
    for (int i = 0; i < passwordLength; i++) {
        password[i] = generateRandomChar(32, 126);
         if (password[i] == ',') 
            i--;
        }
         password[passwordLength] = '\0';
    fprintf(filew,"%s",password);
   // printf("%s ",password);
    }
if(i<count-1){
    //printf(", ");
    fprintf(filew,", ");
}
}
 //printf("\n");
 fprintf(filew,"\n");
row++;
}

fclose(filew);
FILE *filewreads = fopen("helper.txt", "r");
FILE *finalfile = fopen(filename, "w");
char filearr[row+1][1000];
int som=0;
for(int a1=0;a1<row+1;a1++){
    som=0;
while((ch=fgetc(filewreads))!='\n'){
filearr[a1][som]=ch;
som++;
}
if(a1!=row+1)
filearr[a1][som]='\n';
}
//printf("\n\n\n\n");

int it =0;
int commas=0;
while((filearr[0][it]!='L')){
if((filearr[0][it]==',')){
commas++;
}
it++;
if((filearr[0][it]=='\n')){
    commas=0;
break;
    }
}

char temp[1000][120];
int here1 =0;
int here2 =0;
int numofcommas;
int l2=0;
int m=0;
if(commas!=0){
for(int xo=0;xo<row;xo++){
for(int l=1;l<row;l++){
    numofcommas=0;
    l2=0;
    while(numofcommas!=commas){
    if(filearr[l][l2]==','){
        numofcommas++;
    }
    l2++;
    here1=l2+1;
    }
   // printf("\nthis is the FL%c\n",filearr[l][here1]);
    numofcommas=0;
    l2=0;
while(numofcommas!=commas){
    if(filearr[l+1][l2]==','){
        numofcommas++;
    }
    l2++;
    here2=l2+1;
    }
   // printf("\nthis is the SL%c\n",filearr[l+1][here2]);
    numofcommas=0;
if(filearr[l][here1]>filearr[l+1][here2]){
for(int m=0;m<120;m++){
    temp[l][m] = filearr[l][m];
}
for(int v=0;v<120;v++){
    filearr[l][v] =filearr[l+1][v];
}
for(int v=0;v<120;v++){
    filearr[l+1][v] =temp[l][v];
}
}
}
}
}

for(int t=0;t<c;t++){
    fprintf(finalfile,filearr[t]);
}
fclose(finalfile);
//printf("\n\n\n\n");
printf("\nPress 'c' or 'C' to continue");
char empty;
scanf("%c",&empty);
scanf("%c",&proceed);
}while(( (proceed == 'c') || (proceed == 'C')));
return 0;
}