
#include"header.h"
#include"library.h"
void show_record(){
  system("cls");
  FILE *f;
  char ch;

  f = fopen("score.txt", "r");
  while( (ch = getc(f))!= EOF)

  printf("%c",ch);
  getch();
  fclose(f);
}

void update(){
  float score;
   FILE *f;
   char playername[20];
   f=fopen("score.txt","a");
   printf("Write a name to make your score secure : \n");
   gets(playername);
   if (f== NULL)
   {
     printf("File cannot be opened\n");
   }
   fprintf(f,"%s %0.2f\n",playername,score);
   fclose(f);
 }

void quiz(){
      {
        int r,r1,count,neg,i,n;
        float score, score1,score2;
        char choice;

        mainhome:

        printf("\t\t::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\tC PROGRAM QUIZ GAME\n");

        printf("\n\t\t > Press S to start the game");
        printf("\n\t\t > Press v to view all player data");
        printf("\n\t\t > Press M to return to Main screen");


        choice=toupper(getch());
        if (choice=='V')
      {
      show_record();
      goto mainhome;
      }




       else if (choice=='M')
      {
      menu();
    }


       else if(choice=='S')
       {
         system("cls");
        goto home;

        home:
        system("cls");
       count=0;
        neg=0;
        for(i=1;i<=10;i++)
        {
       system("cls");
        r1=i;


        switch(r1)
       {
       case 1:
       printf("What is IOE?\n");
       printf("\n\nA. Institutute Of Engineering\t\tB. Industrial Office of Economics\n\nC. Institutute of Energy\t\tD. International office of electronics\n");

       if (toupper(getch())=='A')
         {
             printf("\n\nCorrect!!!");count++;
             getch();
             break;
      }
       else
              {
                  printf("\n\nWrong!!! The correct answer is A. Institutute Of Engineering ");neg++;
                  getch();
              break;
              }

           case 2:
       printf("\n\n\nWho won the World Cup in 2014?");
       printf("\n\n\nA. Spain\t\tB. France\n\nC. Netherlands\t\tD. Germany");

       if (toupper(getch())=='D')
         {
           printf("\n\nCorrect!!!");count++;
         getch();
         break;
         }
       else
              {
                printf("\n\nWrong!!! The correct answer is D. Germany");neg++;
              getch();
              break;
            }


            case 3:printf("\n\n\nWhat is know as father of computer science?");
            printf("\n\nA. John Sttaford\t\tB. Charles Babbage\n\nC. Alan Turing\t\tD. Adam Gatters");

            if (toupper(getch())=='C')
              {
                printf("\n\nCorrect!!!");count++;
              getch();
              break;
           }
            else
                   {
                     printf("\n\nWrong!!! The correct answer is C. Alan Tuning");neg++;
                   getch();
                   break;
                 }

           case 4:
           printf("\n\n\nWhose equation is this:  E=MC^2?");
           printf("\n\n\nA. Thomas A. Editon\t\tB. Nikola Tesla \nC. Sir Isac Newton\t\tD. Albert Einstein");

           if (toupper(getch())=='D')
             {
               printf("\n\nCorrect!!!");count++;
             getch();
             break;
             }
           else
                  {
                    printf("\n\nWrong!!! The correct answer is D. Albert Einstein");neg++;
                  getch();
                  break;
                }

            case 5:
                printf("\n\n\nWhat is the color do you get when you mix red and white?");
                printf("\n\nA. Red\t\tB. Pink\n\nC. Orange\t\tD. none of the above ");

                if (toupper(getch())=='B')
                  {printf("\n\nCorrect!!!");count++;
                  getch();
                  break;
                  }
                else
                       {printf("\n\nWrong!!! The correct answer is B. Pink");neg++;
                       getch();
                       break;
                     }

            case 6:
            printf("\n\n\nWhat is the national sport in Japan?");
            printf("\n\nA. Cricket\t\tB. Table Tenis\n\nC. Sumo Wrestling\t\tD. Base Ball");

            if (toupper(getch())=='C')
              {
                printf("\n\nCorrect!!!");count++;
              getch();
              break;
              }
            else
                   {
                   printf("\n\nWrong!!! The correct answer is C. Sumo Wrestling");neg++;
                   getch();
                   break;
                   }

             case 7:
             printf("\n\n\nWhich of the campus is known as Central Campus for IOE?");
             printf("\n\n\nA. Thapathali Campus\t\tB. ERC\n\nC. WRC\t\tD. Pulchowk Campus");

               if (toupper(getch())=='D')
                 {
                   printf("\n\nCorrect!!!");count++;
                 getch();
                 break;
                   }
                 else
                      {
                  printf("\n\nWrong!!! The correct answer is D. Pulchowk Campus");neg++;
                      getch();
                      break;
                }
                case 8:
                printf("\n\n\nWhich district of Nepal is known as 76th district?");
                printf("\n\n\nA. Biratnagar\t\tB. Phokhara\n\nC. Chitwan\t\tD. Kathmandu");

                if (toupper(getch())=='C')
                          {
                            printf("\n\nCorrect!!!");count++;
                          getch();
                          break;
                          }
                        else
                               {
                                 printf("\n\nWrong!!! The correct answer is C. Chitwan");neg++;
                               getch();
                               break;
                             }
                  case 9:
                   printf("\n\n\nWhat is the full form of CAN");
                 printf("\n\n\nA. Chief Assistant of Nepal\t\tB. Cricket Association of Nepal\n\nC. Central Association of Nepal\t\tD. Centralized Agriculture of Nepal");

                     if (toupper(getch())=='B')
                               {
                                 printf("\n\nCorrect!!!");count++;
                               getch();
                               break;
                               }
                             else
                                    {
                                      printf("\n\nWrong!!! The correct answer is B. Cricket Association of Nepal");neg++;
                                    getch();
                                    break;
                                  }


           case 10:
           printf("\n\n\nKim Jong-Un is leader of which country?");
           printf("\n\n\nA. South Korea\t\tB. North Korea\n\nC. China\t\tD. Japan");

           if (toupper(getch())=='B')
             {
             printf("\n\nCorrect!!!");
             count++;
             getch();
             break;
             }
             else
            {
            printf("\n\nWrong!!! The correct answer is B. North Korea");neg++;
            getch();
            break;
            goto score;
            }
          }

      }
      score:

      score1=(float)count*1000;
      score2=(float)neg*500;
      score=(score1-score2);
      if(score>0.00 && score<15000)
        {
        printf("\n\n\t\t CONGRATULATION ");
          printf("\n\t\t You won Rs.%.2f",score);

          goto go;
        }


      else
      {
      printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
         printf("\n\t\t Thanks for your participation");
         printf("\n\t\t TRY AGAIN");
         goto go;}

      go:
      puts("\n\n Press Y if you want to play next game");
      puts(" Press any key if you want to go main menu");
      if (toupper(getch())=='Y')
      quiz();

      else
       {
       update(score);
       system("cls");
       goto mainhome;
     }
    }
  }
}

