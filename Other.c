
#include"header.h"
#include"library.h"
void menu(){
    int menu1choice;
    system("cls");
    get_date();
    printf("\n\n\n\n\t\t\t\t\t ___________________________\n");
    printf("\t\t\t\t\t|\t:::::MAIN MENU::::: |");
    printf("\n\t\t\t\t\t ___________________________\n");
    Sleep(500);
    printf("\t\t\t\t\t|\t1. QUIZ             |\n");
    Sleep(500);
    printf("\t\t\t\t\t|\t2. SECRET NOTES     |\n");
    Sleep(500);
    printf("\t\t\t\t\t|\t3. TIME TOOLS       |\n");
		Sleep(500);
    printf("\t\t\t\t\t|\t4. VISITORS         |\n");
    Sleep(500);
    printf("\t\t\t\t\t|\t5. BMI CALCULATOR   |\n");
    Sleep(500);
    printf("\t\t\t\t\t|\t6. EXIT             |\n");
    Sleep(500);
    printf("\t\t\t\t\t|\t                    |");
    printf("\n\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t");
    scanf("%d", &menu1choice);


    switch ( menu1choice )
    {
         case 1:
    	{
        clrscr();
        quiz();
        break;
      }

         case 2:
			{
        system("cls");
				printf("SECRET NOTES\n" );
        welcome();

        break;

			}
			case 3:
			{
        timeTool();
      }
				break;

			case 4:{
        clrscr();
        show_visitors();
        break;
			}
      case 6:{
        printf("Are you sure? \n");
        exit_c();
        break;

      }
      case 5:{
        system("cls");
        bmi();
      }


		}
}


void stopwatch(){

  int min, msec, sec;
  printf("\n\n\t\t\t\t\tEnter ^C to stop or exit the stopwatch \n");
  Sleep(5000);
  for(min=0; min<59; min++){
    for(sec=0; sec<59; sec++){
      for(msec=0; msec<100; msec++){
				clrscr();

        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t %d\t\t: %d\t\t: %d\t\t",min,sec,msec);
        printf("\n");
        Sleep(10);

      }
    }
  }

}

void clrscr(){
	system("@cls||clear");
}

void timer(){

  printf("\n\n\t\t\t\t\tEnter ^C to stop or exit the Timer\n");
  Sleep(5000);
  int hour, min, sec,i,j,k=0;
  printf("\n\n\t\t\t\t\tEnter Hours: \n\t\t\t\t\t");
  scanf("%d", &hour );
  printf("\n\t\t\t\t\tEnter Minutes: \n\t\t\t\t\t");
  scanf("%d", &min);

  if(hour>0 && min==0)
  {
  for (i=hour-1; i>=0; i--){
  for(j=59;j>0;j--){
      for(sec=59; sec>=0; sec--){
        clrscr();
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t %d\t\t: %d\t\t: %d\t\t",i,j,sec);
        Sleep(1000);

        }
      }
    }
  }
  else if (hour==0 && min>0)
  {

        for(j=min; j>=0; j--){
          for(sec=5; sec>=0; sec--){
            clrscr();
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t %d\t\t: %d\t\t: %d\t\t",j,sec);
            Sleep(1000);

        }
      }
    }

  else if(hour>0 && min>0)
  {
    for(i=hour; i>=0; i--){
      if(k>0)

      {
        for(j=59; j>0; j--){
          for (sec=59;sec>=0;sec--){
          clrscr();
          printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t %d\t\t: %d\t\t: %d\t\t",i,j,sec);
          Sleep(1000);

        }
      }
    }

      for(j=min; j>=0; j--){
        for (sec=59;sec>=0;sec--)
        {
        clrscr();
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t %d\t\t: %d\t\t: %d\t\t",i,j,sec);
        Sleep(1000);



  }
    }
        k++;

    }

  }

}

void visitors(){
    FILE *fptr;
    printf("\n\n");
    printf("\t \t\t  ****************************A B O U T************************** \n");
    printf(" \t   ------------------------------------------------------------------------------------------------------");
    printf("\n \t   |This project is collaborative effort of 3 beginners in programming.                                  |");
    printf("\n \t   |It is developed as a part of the C assignment that we are entitiled to submit at the end of semester.|");
    printf("\n \t   |As the name suggests It incorporates some of the smart features of some smart tools.                 |");
    printf("\n \t   |We believe that the user will like our creation and benefit in some way from this project.           |");
    printf("\n \t   ------------------------------------------------------------------------------------------------------");
    printf("\n\n\n");
    char name[20];
    char surname[30];
    fptr = fopen("visitors.txt", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
      printf("\n\n\n\t                   Enter your name and surname: ");
      scanf("%s %s", name, surname);
      fprintf(fptr, "%s %s\n", name, surname);
      fclose(fptr);
}

void show_visitors(){
  FILE *fptr;
  char ch;
  printf("\t\tWe would like to thank you all of the personals mentined below, who visited or used our Program. \n");

  fptr = fopen("visitors.txt", "r");

  while( (ch = getc(fptr))!= EOF)
  printf("%c",ch);

  // closing the file pointer
  fclose(fptr);
  getch();
  system("cls");
  menu();
}

void exit_c(){
  exit(1);
}

void timeTool(){

  int choice2;
  system("cls");
  printf("\t\t\t\t\t:::::::::::::::::::: Select One to use::::::::::::::::::::: \n\n\t\t\t\t\t1. Stopwatch\n\t\t\t\t\t2. Timer\n\t\t\t\t\t3. Go to main Menu\n\t\t\t\t\t4. Exit\n\t\t\t\t\t" );
  scanf("%d",&choice2);
  switch (choice2) {
    case 1:
    system("cls");stopwatch();
      break;
      case 2: system("cls");timer();
      break;
      case 3:system("cls"); menu();
      break;
      case 4: exit_c();
      break;

    default: {
      printf("something wrong\n");
    }
  }
}

void get_date(){
  SYSTEMTIME str_t;
	GetSystemTime(&str_t);
  printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	printf("%d/%d/%d",
	str_t.wYear,str_t.wMonth,str_t.wDay
	);
}

void bmi(){
  float weight,height,bmi;
  printf("\t\t\t\t\t\tEnter weight in kgs:");
  scanf("%f",&weight);
  printf("\t\t\t\t\t\tEnter Height in meters: ");
  scanf("%f",&height );
  bmi=weight/(height*height);
  printf("\n\n\t\t\t\t\t\tBMI: %f",bmi);
  bmi<18.5?printf("\t\tUnderweight"):
  (bmi<25)?printf("\t\tNormal weight"):
  (bmi<30)?printf("\t\tOverweight"):
  printf("Obesity");
  getch();
  menu();
}

void loading(){
  int i;
  for (i=0; i<=100; i++)
  {
    clrscr();

      get_date();
      printf("\n\n\n\n");
      printf("\n\t\t\t\t\t000000   00    00   000000   00000   000000\n\t\t\t\t\t00       000  000   00  00   00  00    00\n\t\t\t\t\t000000   00 00 00   000000   00000     00\n\t\t\t\t\t    00   00    00   00  00   00  00    00\n\t\t\t\t\t000000   00    00   00  00   00   00   00");
      printf("\n\n\t\t\t\t\t000000   000000   000000   00      000000\n\t\t\t\t\t  00     00  00   00  00   00      00\n\t\t\t\t\t  00     00  00   00  00   00      000000\n\t\t\t\t\t  00     00  00   00  00   00          00\n\t\t\t\t\t  00     000000   000000   00000   000000\n\n\n\n\n");
      printf("\n\t\t\t\t\t\t\tLoading...%d%c ",i,'%' );
      printf("\n\n\n\n\n\t\t\t\t       @ ANJIL|KUNDAN|NIRAJAN  | All right reserved\n\n\t\t\t\t\t\t");
      Sleep(25);
  }

}
