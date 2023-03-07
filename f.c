#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

int mainpage();

// Student function

/*   */void student_login();
/*           */void new_registration();
/*           */void login_page(FILE*,int);
/*                  */void student_main_login_page();
/*                          */void student_main_login_page();

/*   */void employee_login();
/*           */void warden_login();
/*           */void meal_table();
/*           */void infirmary_login();

int insertt(FILE*);
int display(FILE*);
void display_notice_board();
void edit_notice_board();
void studentinfo_display();

void studentinfo_display()
{    
     
     FILE* fr = fopen("student_info.dat","r");
     printf("\n\n ===========================================================================================================================================================\n\n");    

     if (!fr)
		printf("Can't open file\n");

     else
     {
         int j=0, column ;
         char buffer[1024], choice;;    
         while (fgets(buffer,1024, fr)) 
         {   

             column=0;
			 char* value = strtok(buffer, ",");
             while (value) 
             {
                 if (column == 0) 
                 {
                     printf("\n\n USN : ");
                 }
				
                 if (column == 1) 
                 {
                     printf("\tNAME : ");
                 }

                 if (column == 2) 
                 {
                     printf("\t\t\tE-MAIL ID: ");
                 }
                 if (column == 3) 
                 {
                     printf("\t\tPHONE NO : ");
                 }
                 if (column == 4) 
                 {
                     printf("\t\tROOM NO : ");
                 }

                 printf("%s", value);
                 value = strtok(NULL, ",");
                 column++;
		     }
             printf("\n");			
         }
    }
     printf("\n\n ===========================================================================================================================================================\n\n");    
     fclose(fr);
}


void edit_notice_board()
{
     char ch;
     FILE *fp;
     fp=fopen("notice_board.bin","wb+"); 
     printf(" Enter the new text (press cntrl Z to exit): ");
     printf("\n\n===========================================================================================================================================================\n\n");    

     while((ch = getchar())!=EOF)
     {
         putc(ch,fp);
     }
     fclose(fp);
     printf("\n ===========================================================================================================================================================\n\n");    

     return;
}

void display_notice_board()
{
     FILE* fptr = fopen("notice_board.bin","rb");
     printf("\n\n ===========================================================================================================================================================");
     printf("\n\n                                                                          NOTICE                                                                        \n\n");
     char content[1000];
     if(fptr != NULL)
     {
         while (fgets(content, 1000, fptr))
             printf("%s",content);
         printf("\n\n ===========================================================================================================================================================\n\n");
     }
     else
     {
         printf("\nFile open unsuccessful\n");
     }
     fclose(fptr);
}

int insertt(FILE* fp)
{
   char ch; 
   fseek(fp, -1, SEEK_END);
   
   printf("\n\n Enter the text ( press cntrl Z to exit ) : ");
   printf("\n\n ===========================================================================================================================================================\n\n");

   putc('\n',fp);
   putc('\n',fp);
   while((ch = getchar())!=EOF)
   {
      putc(ch,fp); 
   }
   fclose(fp);
   printf("\n\n ===========================================================================================================================================================");

   return 0;
}



int display(FILE* fptr)
{
     system("cls");
     char content[1000];
     printf("\n\n ===========================================================================================================================================================\n\n\n");

     if(fptr != NULL)
     {
         while (fgets(content, 1000, fptr))
                printf("%s",content);
         printf("\n\n ===========================================================================================================================================================");
     }
     else
     {
         printf("\nFile open unsuccessful\n");
     }
     fclose(fptr);
     for(;;)
     {
        char choice;
        scanf("%c",&choice);
        if(choice=='\n')
            return 0;
     }
}

void student_main_login_page(int i)
{
     system("cls");
     FILE* fs = fopen("student_info.dat","r");
     if (!fs)
		printf("Can't open file\n");

	 else 
     {
         printf("\n\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
         printf("\n                                                                         STUDENT DETAILS                                                               \n");
		 char buffer[1024];
		 int row = 0, column = 0;
         while (fgets(buffer,1024, fs)) 
         {   row++;
			 if (row == i+1)
             {	
			    char* value = strtok(buffer, ",");
                while (value) 
                {
				
                    if (column == 0) 
                    {
                        printf("\n\nUSN         :  ");
                    }

				
                    if (column == 1) 
                    {
                        printf("\n\nName        :  ");
                    }

				
                    if (column == 2) 
                    {
                        printf("\n\nE-mail Id   :  ");
                    }

                    if (column == 3) 
                    {
                        printf("\n\nContact No. :  ");
                    }

                    if (column == 4) 
                    {
                        printf("\n\nRoom No.    :  ");
                    }

                    printf("%s", value);
                    value = strtok(NULL, ",");
                    column++;
			     }			
             }

             else
             {
                continue;
             }
         fclose(fs);
         printf("\n\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");

         int choice;
         for(;;)
         {
            printf("\n\n\n\n\t     1. NOTICE BOARD\t\t2. COMPLAINTS\t\t3. INFIRMARY\t\t4. MEAL DETAILS\t\t5. LOGOUT\t\t6. EXIT\n\n\t     Enter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: display_notice_board();
                        break;
                case 2: FILE* fp=fopen("complaints.bin","rb+");
                        insertt(fp);
                        break;
                case 3: FILE* fa=fopen("infirmary_complaints.bin","rb+");
                        insertt(fa);
                        break;
                case 4: meal_table();
                        break;
                case 5: student_login();
                        break;
                case 6: exit(0);
                default: printf("\nWrong Choice\n");
            }
         }
         printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
         	

	     }
    }
}
struct {

    char usn[15];
    char name[60];
    char mail_id[30];
    char phone[17];
    char room_no[6];
    char gender[7];
    char password[20];
    }add;
void new_registration()
{
     system("CLS");
    int choice; 
    FILE *ptr, *fp;
    ptr=fopen("student_info.dat","r+");
    printf("\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");

    printf("\n Enter the USN number: ");
    scanf("%s",add.usn);
    printf("\n Enter the name: ");
    scanf("%s",add.name);
    printf("\n Enter your email id: ");
    scanf("%s",add.mail_id);
    printf("\n Enter the phone number: ");
    scanf("%s",add.phone);
    printf("\n Enter your room no.: ");
    scanf("%s",add.room_no);
    int r=0;
    for(;;)
    {
        gets(add.gender);
        if( !( (strcmp(add.gender,"g")) && (strcmp(add.gender,"b")) ) )
            break;
        printf("\n Enter your gender (g/b) : ");
    }
        
    printf("\n Please enter your password : ");
    scanf("%s",add.password);
    
    fseek(ptr, -1, SEEK_END);
    fprintf(ptr,"\n%s,%s,%s,%s,%s,%s\n", add.usn, add.name, add.mail_id, add.phone, add.room_no, add.gender);
    
    fclose(ptr);

    fp=fopen("s_user_pass.dat","r+");
    fseek(fp, -1, SEEK_END);
    fprintf(fp,"%s,%s,\n", add.mail_id, add.password,'\n');
    fclose(fp);

    printf("\n\n Student added successfully!\n");
    printf("\n\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");

    char enter;
    printf("\nPress enter to exit");
    for(;;)
    {
        enter=getc(stdin);
        if(enter='\n')
            break;
    }
    getc(stdin);
    system("cls");
    return;
}

void login_page(FILE*fp,int l)
{
     system("cls");
     char  username[20],password[20];
	 if (!fp)
		printf("Can't open file\n");
    
    else
    {
        for(;;)
        {
            printf("\nUSERNAME: ");
            scanf("%s",username);
            printf("\nPASSWORD: ");
            scanf("%s",password);
            char buffer[1024], *value, st, st2 ; int i=0;

		    while (fgets(buffer,1024, fp)) 
            {
                value = strtok(buffer, ",");
                if(!strcmp(value,username))
                {   
                    value = strtok(NULL, ",");
                    if(!strcmp(value,password))
                    {  
                        fclose(fp);
                        switch(l)
                        {
                            case 0: system("cls");
                                    student_main_login_page(i);
                                    break;
                            case 1: system("cls");
                                    warden_login();
                                    break;
                            case 2: system("cls");
                                    for(;;)
                                    {
                                        meal_table();
                                        st=getc(stdin);
                                        if(st=='\n')
                                            break;
                                    }
                                    break;
                            case 3: system("cls");
                                    infirmary_login();
                                    break;
                        }
                    }    
                }
                i++;
	        }
            printf("Press enter to continue");
            getc(stdin);
            fclose(fp); 
            switch(l)
            {
                case 0: system("cls");
                        student_login();
                        break;
                case 1:                       
                case 2:  
                case 3: system("cls");
                        employee_login();
                        break;
                        
            }
        }
    }
}


void student_login()
{
   system("cls");
   int choice;
   for(;;)
   {
        printf("\n\n=======================================================================\n||                                                                   ||\n||                        STUDENT LOGIN                              ||\n||                                                                   ||\n||          1. Login                                                 ||\n||                                                                   ||\n||          2. New Registration                                      ||\n||                                                                   ||\n||          3. Back                                                  ||\n||                                                                   ||\n||          4. Exit                                                  ||\n||                                                                   ||\n=======================================================================\n");
        printf("\nEnter your choices: ");
            scanf("%d",&choice);
            switch(choice)                                                                 
            {
                case 1: FILE* fp = fopen("s_user_pass.dat", "r");
                        int l=0;
                        login_page(fp,l);
                        break;
                case 2: new_registration();
                        break;
                case 3: mainpage();
                        break;
                case 4: exit(0);
                default : system("cls");
                          printf("\nPlease enter valid choice\n");
            }
   }
}

void employee_login()
{  system("cls");
   FILE* fp;
   int choice, l;
   for(;;)
   {
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n||                                                                   ||\n||                           EMPLOYEE LOGIN                          ||\n||                                                                   ||\n||          1. Warden Login                                          ||\n||                                                                   ||\n||          2. Chef Login                                            ||\n||                                                                   ||\n||          3. Infirmary Login                                       ||\n||                                                                   ||\n||          4. Back                                                  ||\n||                                                                   ||\n||          5. Exit                                                  ||\n||                                                                   ||\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choices: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: fp = fopen("warden.dat", "r");
                        l=1;
                        login_page(fp,l);
                        break;
                case 2: fp = fopen("chef.dat", "r");
                        l=2;
                        login_page(fp,l);
                        break;
                case 3: fp = fopen("infirmary.dat", "r");
                        l=3;
                        login_page(fp,l);
                        break;
                case 4: mainpage();
                        break;
                case 5: exit(0);
                default : system("cls");
                          printf("\nPlease enter valid choice\n");
                          
            }
   }
}

void warden_login()
{
    int choice; char choice2;
    for(;;)
    {
        printf("\n\n1. Display Student Information\n2. Meal Table\n3. Complaints\n4. Notice Board\n5. Logout\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:system("cls");
                   studentinfo_display();
                   break;
            case 2: system("cls");
                    meal_table();
                    break;
            case 3: FILE* fptr = fopen("complaints.bin","rb");
                    display(fptr);
                    break;
            case 4: system("cls");
                    display_notice_board();
                    printf("\n\n");
                    edit_notice_board();
                    break;
            case 5: return;
            default: system("cls");
                     printf("\nWrong choice\n");
        }
    }
}

void meal_table()
{    
     
     FILE* fr = fopen("meal_table.dat","r");
     printf("\n\n\n ===========================================================================================================================================================\n\n");

     if (!fr)
     {
		printf(" Can't open file\n");
        printf("\n\n ===========================================================================================================================================================\n\n");    
     }

     else
     {
         int j=0, column ;
         char buffer[1024], choice;;    
         while (fgets(buffer,1024, fr)) 
         {   
             j++;
             switch(j)
             {
                 case 1: printf("\n\n MONDAY\n");
                         break;
                 case 2: printf("\n\n TUESDAY\n");
                         break;
                 case 3: printf("\n\n WEDNESDAY\n");
                         break;
                 case 4: printf("\n\n FRIDAY\n");
                         break;
                 case 5: printf("\n\n SATURDAY\n");
                         break;
                 case 6: printf("\n\n SUNDAY\n");
                         break;
                 default: printf("\n\n ===========================================================================================================================================================\n\n");    
                          return;
             }

             column=0;
			 char* value = strtok(buffer, ";");
             while (value) 
             {
                 if (column == 0) 
                 {
                     printf("\n\n Breakfast : ");
                 }
				
                 if (column == 1) 
                 {
                     printf("\n\n Lunch : ");
                 }

                 if (column == 2) 
                 {
                     printf("\n\n Dinner : ");
                 }

                 printf("%s", value);
                 value = strtok(NULL, ";");
                 column++;
		     }
             printf("\n");			
         }
    }
     fclose(fr);
}

void infirmary_login()
{
    FILE* fptr = fopen("infirmary_complaints.bin","rb");
    display(fptr);
}





// MAIN PAGE
int mainpage()
{
    system("cls");
    int choice_main ;
    for(;;)
    {
        printf("\n\n***********************************************************************************\n***********************************************************************************\n****                                                                           ****\n****                            HOSTEL MANAGMENT SYSTEM                        ****\n****                                                                           ****\n****        1. Student Login                                                   ****\n****                                                                           ****\n****        2. Employee Login                                                  ****\n****                                                                           ****\n****        3. Exit                                                            ****\n****                                                                           ****\n***********************************************************************************\n***********************************************************************************\n");
        printf("\nEnter your choices: ");
        scanf("%d",&choice_main);
        switch(choice_main)
        {
            case 1: student_login();
                    break;
            case 2: employee_login();
                    break;
            case 3: exit(0);
            default : system("cls");
                      printf("\nPlease enter valid choice\n");
        }
        
    } return 0;

}



// MAIN PROGRAM
int main()
{   mainpage();    }