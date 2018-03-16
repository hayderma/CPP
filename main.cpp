#include <iostream>
#include <string.h>
#include <stdio.h>
#include"content.h"
#include <conio.h>
#include <string>
#include <ctype.h>
#include <time.h>

using namespace std;


 void convert_to_small(char *letter)
    {
        if(*letter>=65&& *letter <=90)
        {
            *letter= *letter +32;

        }

    }
char* convert_to_capital (char arr[])
    {
        int i=0;
        while (arr[i]!='\0')
        {
            arr[i]=toupper(arr[i]);
            i++;
        }
        return arr;
    }

void print_function(char course)
    {
        char choice;
        char choices_arr [11];
        float m_grade=0.00;
        int i,counter;
        if (course=='m')
        {
            char name_array[20];
            char last_name[20];
            cout << "YOUR FIRST NAME : ";
            scanf("%s",&name_array);
            cout <<"\nYOUR LASTNAME : ";
            scanf("%s",&last_name);

            convert_to_capital(name_array);
            convert_to_capital(last_name);

            float m_grade=0.00;

            time_t now;
            time(&now);

            char start_time[35];
            strcpy(start_time,ctime(&now));

            for (i=0;i<5;i++)
            {
                printf(" \n\n%d ) %s \n\n",i+1, MATH_Question[i].Question);
                printf(" %s\n\n", MATH_Question[i].a);
                printf(" %s\n\n", MATH_Question[i].b);
                printf(" %s\n\n", MATH_Question[i].c);
                printf(" %s\n\n", MATH_Question[i].d);
                printf(" Type the letter corresponding to the correct answer : ");
                cin >> choice;
                convert_to_small(&choice);
                while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' )
                {
                    cout << "\n\nYour Selection is not valid !\n";
                    printf(" \nType the letter corresponding to the correct answer : ");
                    cin >> choice;
                    convert_to_small(&choice);
                }

                if (choice == MATH_Answer[i].letter_Answer)
                {

                    m_grade++;
                }
                else {m_grade=m_grade;}
                choices_arr[i]=choice;


            }
            counter =(int)m_grade;
            m_grade=(m_grade*100)/ (i);


            FILE *report;
            char filename[50];
            strcat(filename,last_name);
            strcat(filename,"_");
            strcat(filename,name_array);
            strcat(filename,"_SCORE_REPORT");
            strcat(filename,".txt");

            report=fopen(filename,"w");
            if (report==NULL){printf("can't find\n");}

            time(&now);




            fprintf(report, "\n\n\t\t\t\t  ====== AERONAV OFFLINE TESTING SYSTEM & REPORT GENERATOR ======\n\n");
            fprintf(report, "\n\n\   Name     :  %s , %s\n\n   Score    :  %.1f\n\n   Material :  Algebra  ",last_name,name_array,m_grade);
            fprintf(report, "\n\n\   Started  :  %s\n   Finished :  %s\n",start_time, ctime(&now));
            char status[5];

            if (m_grade < 70)
            {
                strcpy(status,"FAIL");
            }
            else if (m_grade >= 70)
            {
                 strcpy(status,"PASS");
            }
            fprintf(report, "\n   Result   :  %s\n\n",status);


            if (counter != i)
            {
                int k;
                fprintf(report, "\n\n\n\n   Missed Answers   :  \n\n");
                for (k=0;k<i ;k++)
                {
                    if ( MATH_Answer[k].letter_Answer != choices_arr[k])
                    {
                        fprintf(report, "    %s\n\n",MATH_Question[k].Question);
                        fprintf(report, "   Correct Answer   :  %s\n",MATH_Answer[k].Answer);
                    }
                }
            }


            fclose(report);

            cout << "\n\n\t*****************************************************\n";
            cout << "\tA TEXT FILE CONTAINING THE EXAM REPORT IS CREATED IN\n\n\t  THE FOLDER WHERE WHERE THIS PROGRAM EXSISTS\n";
            cout << "\n\tIT'S RECOMMENDED THAT YOU PRINT YOUR EXAM REPORT";
            cout << "\n\t*****************************************************\n\n";
        }
    }




int main()
{

    cout << "\n\n\n\t\t        ====== W E L C O M E ======\n\n";
    cout << "\n\n\t\t====== AERONAV OFFLINE TESTING SYSTEM ======\n\n";
    cout << "\n\n       DISCLAIMER : This program is built by A Student,\n\n\ \tQ's and A's attributed to reliable Online sources  \n\n\n";




    strcpy(MATH_Question[0].Question, "\n\nHow many x intercepts does the graph of the function f(x) = (x^3) + 4 have?");
    strcpy(MATH_Answer[0].Answer,"1");
    MATH_Answer[0].letter_Answer = 'b';
    strcpy(MATH_Question[0].a,"[A] 0");
    strcpy(MATH_Question[0].b,"[B] 1");
    strcpy(MATH_Question[0].c,"[C] 2");
    strcpy(MATH_Question[0].d,"[D] 3");

    strcpy(MATH_Question[1].Question, "\n\nHow many points of intersection do the graphs of the functions\n\n  f(x) = (x^2) and g(x) = (2^x) have?");
    strcpy(MATH_Answer[1].Answer,"2");
    MATH_Answer[1].letter_Answer = 'b';
    strcpy(MATH_Question[1].a,"[A] 1");
    strcpy(MATH_Question[1].b,"[B] 2");
    strcpy(MATH_Question[1].c,"[C] 3");
    strcpy(MATH_Question[1].d,"[D] 4");

    strcpy(MATH_Question[2].Question, "\n\nThe range of the function f(x) = (-x^2) + 2x - 5 is given by the interval");
    strcpy(MATH_Answer[2].Answer,"( - infinity , -4 ]");
    MATH_Answer[2].letter_Answer = 'c';
    strcpy(MATH_Question[2].a,"[A] (0 , Infinity )");
    strcpy(MATH_Question[2].b,"[B] ( - Infinity , 4 ]");
    strcpy(MATH_Question[2].c,"[C] ( - infinity , -4 ]");
    strcpy(MATH_Question[2].d,"[D] ( - infinity , -5 ]");

    strcpy(MATH_Question[3].Question, "\n\nWhich of these functions does not have an inverse?");
    strcpy(MATH_Answer[3].Answer,"f(x) = |x - 5|");
    MATH_Answer[3].letter_Answer = 'a';
    strcpy(MATH_Question[3].a,"[A]  f(x) = |x - 5|");
    strcpy(MATH_Question[3].b,"[B] h(x) = 2x - 9");
    strcpy(MATH_Question[3].c,"[C] k(x) = ln(- x + 4)");
    strcpy(MATH_Question[3].d,"[D]  j(x) = x^(1/3)");

    strcpy(MATH_Question[4].Question, "\n\nThe solution set of the inequality (x + 5)^4 (x + 3) >= 0 is given by interval ");
    strcpy(MATH_Answer[4].Answer,"{-5} U [ -3 , Infinity )");
    MATH_Answer[4].letter_Answer = 'b';
    strcpy(MATH_Question[4].a,"[A]  [ -3 , Infinity )");
    strcpy(MATH_Question[4].b,"[B] {-5} U [ -3 , Infinity )");
    strcpy(MATH_Question[4].c,"[C] ( - Infinity , Infinity )");
    strcpy(MATH_Question[4].d,"[D]   ( -3 , Infinity )");








    int j=200;
    while (j!=0)
    {

        cout << "\n\n\t\t    ======= MAIN MENU ======\n\n";



        cout << "\n\t\t    [ 1 ] Take An Algebra Test\n\n";
        cout << "\t\t    [ 0 ] Exit AERONAV Testing System\n\n";
        cout << "\t\t\tMAKE A SELECTION :=> ";

        cin >> j;

        if (j==0)
        {
            cout << "\n\n\n\n\n\t\t\t     THANK YOU"<<endl;
        }
        else if (j==1)
        {
            print_function('m');
        }
        else if (j < 0 || j > 2)
        {
            cout << "\nInvalid Selection !"<<endl;
        }



    }

    cout << "\n\nHit Any Key to Close Window ";
    getch();

    return 0;
}
