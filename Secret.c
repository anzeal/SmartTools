
#include"header.h"
#include"library.h"
void welcome(){

  char choice1[5];
  printf("\t\t\tSECRET NOTES\n");
  printf("\n\n");
  printf("User Login");
  printf("\n\n");
  printf("A.Sign In:\n");
  printf("B.Sign Up:\n");
  printf("C.Return to Main screen\n");
  printf("D.Exit\n");
  printf("\nEnter the index of your access type(A/B/C/D) : ");
  gets(choice1);
  decision(choice1[0]);
}

//decision() function definition
void decision(char choice){
  switch(toupper(choice)){
    case 'A':
    signIn();//signIn() function declaration
    break;
    case 'B':
    system("cls");
    signUp(); //signUp() function declaration
    break;
    case 'C':
    menu();
    break;
    case 'D':
    exit(1);
    break;
    default:
    system("cls");
    welcome(); //Welcome() function decaration to prompt to the welcome screen
    }
  }//singUp() function definition

void signUp(){

  char Uname[30],password[30];
  FILE *fptr;
  printf("Username :");
  scanf("%s",Uname);//Username input
  printf("Password:");
  scanf("%s",password);//Password input
  fptr = fopen("List.txt", "a+");

  fprintf(fptr,"\n%s %s", Uname, password);//Writing the details in a file

   fclose(fptr);
   getch();
   welcome();
 }
 //signIn() function definition

void signIn(){
  list *l1; //structure pointer variable(array) declaration
  char Uname1[30],p1[30]={0},p2[30]={0};
  char c;
  int n=0,i=0,count=0,j;
  printf("Username : ");
  scanf ("%s",Uname1);
  printf("Password : ");

     for (j= 0;(p1[j]=getch())!=13;j++) {
         putch('*');
         p2[j]=p1[j];
     }

  FILE * fp;
  fp=fopen("List.txt","r");
  c=getc(fp);
  while(c!= EOF)
  {
  if(c=='\n') //Total no of lines count
  n=n+1;
  c=getc(fp);
  }
  fclose(fp); //close the file pointer
  l1=(list*) malloc(n*sizeof(list));//Dynamic memory allocation
  fp=fopen("List.txt","r");
  for(i=0;i<n+1;i++)
  {
  fscanf(fp,"%s %s",l1[i].Uname,l1[i].password);
  }
  fclose(fp);

  for(i=0;i<n+1;i++)
  {
  if ((strcmp(Uname1,l1[i].Uname)==0) && (strcmp(p2,l1[i].password)==0))
  count++;
  }
  free(l1);//Delocalize the dynamic memory
   if(count>0)
  {
  printf("\nAccess granted\n"); getch(); system("cls"); Secret();

  }
  else if(count==0)
  {
    printf("\nUsername or password incorrect\n");
    getch();
    system("cls");
    signIn();//Calling the SignIn() function
  }
}
//Home screen of secret notes section
void Secret(){
  int choices5;
  printf(" \t\t\t Secret Notes\t\n");
  printf("\t\t*********************************\t\n");
  printf("1.Create a new note\n");
  printf("2.Display the contents\n");
  printf("3.Edit your note\n");
  printf("4.Delete note\n");
  printf("5.Return to main screen of Secret Notes\n");
  printf("6.Exit\n");
  printf("\n\n\n*Note: Enter Above Mentioned Numbers Only    \nChoice : ");
  scanf("%d",&choices5);
  switch(toupper(choices5))
  {
   case 1 : newFile(); //newFile() function calling
   break;
   case 2 : DisplayNote(); //DisplayNote() function Calling
   break;
   case 3 : system("cls");Edit(); //Edit() function calling
   break;
   case 4 : Delete_File();//Delete_File() function calling
   break;
   case 5 :system("cls") ;welcome();//Return to welcome screen
   break;
   case 6 : exit(1); //Exit the program successfully
   break;
   default:
   printf("Enter a valid choice");//Not a valid choice
  }
}
//Create new fle function
void newFile(){
  char ch,filename1[30],str1[50];int n,i;
  printf("Enter the filename :");
  fflush(stdin);
  gets(filename1);
  printf("Enter number of lines to be written : ");
  scanf("%d",&n);
  FILE *fpt1;
  fpt1=fopen(strcat(filename1,".txt"),"w");
  if(fpt1==NULL)
  {
  printf("File cannot be opened!");
  exit(1);
  }
  printf("Enter the contents of the file\n\n\n");
  for(i=0;i<=n;i++)
  {
    fgets(str1, sizeof str1, stdin);
    fputs(str1, fpt1);
  }
  fclose(fpt1);
  /*-------------- read the file -------------------------------------*/
  system("cls");
    fpt1 = fopen (filename1, "r");
    printf("\n The contents of the file %s is  :\n",filename1);
    ch = fgetc(fpt1);
    while (ch != EOF)
      {
        printf ("%c", ch);
      ch = fgetc(fpt1);
      }
      printf("\n\n");
      fclose (fpt1);
      getch();
      system("cls");
      Secret();


}
//Edit the file function
void Edit(void){

    FILE *fileptr1, *fileptr2;
    char filechar[40];
    char c;
    int delete_line, temp = 0;

    printf("Enter file name: ");
    scanf("%s", filechar);
    fileptr1 = fopen(strcat(filechar,".txt"), "r");
    c = getc(fileptr1);
    //print the contents of file .
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }
    printf(" \n Enter line number to be deleted and replaced : ");
    scanf("%d", &delete_line);
    //take fileptr1 to start point.
    rewind(fileptr1);
    //open duplicate.c in write mode
    fileptr2 = fopen("duplicate.c", "w");
    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == '\n')
        {
            temp++;
        }
        //till the line to be deleted comes,copy the content to other
        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
            while ((c = getc(fileptr1)) != '\n')
            {
            }
            //read and skip the line ask for new text
            printf("Enter new text\n");
            //flush the input stream
            fflush(stdin);
            putc('\n', fileptr2);
            //put '\n' in new file
            while ((c = getchar()) != '\n')
                putc(c, fileptr2);
            //take the data from user and place it in new file
            fputs("\n", fileptr2);
            temp++;
        }
        //continue this till EOF is encountered
        c = getc(fileptr1);
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filechar);
    rename("duplicate.c",filechar);
    fileptr1 = fopen(filechar, "r");
    //reads the character from file
    c = getc(fileptr1);
    //until last character of file is encountered
    while (c != EOF)
    {
        printf("%c", c);
        //all characters are printed
        c = getc(fileptr1);
    }
    fclose(fileptr1);
    getch();
    system("cls");
    Secret();
}

//Delete_File() function definition
void Delete_File(){
  char filename[30];
  bool r;
  printf("Enter the file name : ");
  scanf("%s",filename);
  r=remove(filename);
  if(r==false)
  printf("File removed successfully\n");
  else
  printf("Unable to delete or file does not exist\n");

  getch();
  system("cls");
  Secret();
}

void DisplayNote(){
  FILE *fptr;char ch,fname[30];
  printf("Enter filename : ");
  scanf("%s",fname);
  fptr = fopen(strcat(fname,".txt"),"r");
  if(fptr==NULL)
  {
    printf("Filename error or file cannot be opened");
    DisplayNote();
  }
  system("cls");
  printf("------------------C O N T E N T S------------------\n\n");
  ch=fgetc(fptr);
  while(ch != EOF)
  {
    printf("%c",ch);
    ch = fgetc(fptr);
  }
  printf("\n\n");
  fclose (fptr);
  getch();
  Secret();

}

