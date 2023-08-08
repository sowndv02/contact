#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct Contact
{
    int Number;
    char First_Name[30];
    char Last_Name[30];
    char Company[100];
    char Phone_Number[30];
    char Email[30];
    char Working_Address[50];
    char Home_Address[50];
    char Birthday[20];
    
} ct;
ct a[100];
void clearFileContent();
int vt,found = 0;
char n[100];
int NumberChange;
int month;
int Number = 0;
void print_menu();
void add_contact();
void edit_contact();
void delete_contact();
int read_file();
void write_file();
void add_information();
void display_contact();
int Check_Phone_Number(char Phone_Number[]);
int check_birthday(char bd[]);
void search_contact();
int get_date(char bd[]);
int get_month(char bd[]);
void display_month();
void sort_by_date();
void edit_contact();
void list_contact();




int main()
{
    char choice;

    read_file();
	do
	{
		
		print_menu();
		
		scanf("%c%*c", &choice);

		system("cls"); // for windows

		printf("CONTACT KEEPER\n");
		printf("==============\n\n");
		switch(choice)
		{
			case '1':
				add_contact();
				break;
			case '2':
				display_contact();
				printf("Enter STT of the contact you want to edit: ");
				 scanf("%d", &NumberChange);
				edit_contact();
				break;
			case '3':
				delete_contact();
				break;
		    case '4':
		    	search_contact();
		    	break;
		    case '5':
		    	printf("Enter month of birthday of contact you want to display (sort by date): ");
				fflush(stdin); scanf("%d", &month);
				display_month();
		    	break;
		    case '6':
		    	 list_contact();
		    	break;
		    case '7':
		    	display_contact();
		}
		
		if (choice != 'q')
		{
			printf("\n\n---\n");
			printf("Press any key to back to main menu.");
			getchar();
		}
		system("cls");
	}
	while (choice != 'q');
	write_file();
	return 0;
}


void print_menu()
{
	printf("CONTACT KEEPER\n");
	printf("==============\n\n");
	printf("1. Add Contact\n");
	printf("2. Edit Contact\n");
	printf("3. Delete Contact by Name or by Phone Number\n");
	printf("4. Search contact by Name or by Phone Number\n");
	printf("5. List all contacts with birthdays in a given month (sort by date)\n");
	printf("6. List all contacts in the table format (sort by name)\n");
	printf("6. List all contacts in the table\n");
	printf("q. Quit\n\n");
	printf("Enter your choice (1/2/3/4/5/6/7/q): ");
}
int check_edit(char flag[])
{
	if(flag[0]=='-'&&flag[1]=='1')
		return 0;
		
	return 1;	
}

void edit_contact() 
{
	int i ;
	char flag[100];
	for (i = 0; i < Number; i++) {
		if (i + 1 == NumberChange) {
			
		    found = i+1;
		   	printf("Found STT = %d\n", NumberChange);
		   	
		   	printf("Enter -1 to don't change!!\n");
		   	
		   	
			printf("Enter new first name: "); fflush(stdin); gets(flag);
			
			if(check_edit(flag))
							strcpy(a[i].First_Name,flag);
							
	        printf("Enter new last name: "); fflush(stdin); gets(flag);
	        
	        if(check_edit(flag))
				strcpy(a[i].Last_Name,flag);
				
        	printf("Enter new company: "); fflush(stdin); gets(flag);
        	
        	if(check_edit(flag))
				strcpy(a[i].Company,flag);
				
	         while (1) 
			 {
		         printf("Enter new phone number: "); 
		         fflush(stdin);
		         gets(flag);
		         
		         if(check_edit(flag))
				     strcpy(a[i].Phone_Number,flag);
				     
		         if (Check_Phone_Number(a[i].Phone_Number) == 2)
		             printf("Please try again, The phone number you just entered has strange characters\n");
		              
		         if(Check_Phone_Number(a[i].Phone_Number) == 1)
		              printf("Try again, phone number should have 9 or 10 digits\n");
		         
		         if(Check_Phone_Number(a[i].Phone_Number) == 0)
		              break;
             } 
           	printf("Enter new email: "); fflush(stdin); gets(flag);
           	
           	if(check_edit(flag))
				strcpy(a[i].Email,flag);

         	printf("Enter new working address: "); fflush(stdin); gets(flag);
         	
         	if(check_edit(flag))
				strcpy(a[i].Working_Address,flag);

	        printf("Enter new home address: "); fflush(stdin); gets(flag);
	        
	        if(check_edit(flag))
				strcpy(a[i].Home_Address,flag);
				
	        while (1) 
	      	{
		         printf("Enter Birthday(DD/MM/YYYY): "); 
		         fflush(stdin);
		         gets(flag);
		         
		         if(check_edit(flag))
				    strcpy(a[i].Birthday,flag);
				
		         if(check_birthday(a[i].Birthday)==1)
		         break;
	     	} 
		}
	}
	if (found ==  0) {
		printf("Cannot find any contact with Number = %d", NumberChange);
		getch();
	}
}


void add_information()
{
        	printf("First_Name: ");
        	fflush(stdin);
        	gets(a[Number].First_Name);
			
        	printf("Last_Name: ");
        	fflush(stdin);
        	gets(a[Number].Last_Name);

        	printf("Company: ");
        	fflush(stdin);
        	gets(a[Number].Company);

        	while (1) {
		         printf("Enter phone number: "); 
		         fflush(stdin);
		         gets(a[Number].Phone_Number);
		         if (Check_Phone_Number(a[Number].Phone_Number) == 2)
		              printf("Please try again, The phone number you just entered has strange characters\n");
		              
		         if(Check_Phone_Number(a[Number].Phone_Number) == 1)
		         printf("Try again, phone number should have 9 or 10 digits\n");
		         
		         if(Check_Phone_Number(a[Number].Phone_Number) == 0)
		         break;
           	} 

        	printf("Email: ");
        	fflush(stdin);
        	gets(a[Number].Email);

        	printf("Working Address: ");
        	fflush(stdin);
        	gets(a[Number].Working_Address);

        	printf("Home Address: ");
        	fflush(stdin);
        	gets(a[Number].Home_Address);

        	//Enter BirthDay DD/MM/YYYY or DD MM YYYY or DD-MM-YYYY
        	while (1) {
		         printf("Enter Birthday(DD/MM/YYYY): "); 
		         fflush(stdin);
		         gets(a[Number].Birthday);
		         if(check_birthday(a[Number].Birthday)==1)
		         break;
		        } 
        	
        	a[Number].Number = Number;
}


void add_contact()
{     
     add_information(); 
     Number++;
}


void search_contact()
{
	int i;
	printf("/nInput last name or phone number:");
	char t[100];
	gets(t);
	printf(" %-5s%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", "STT", "First name", "Last name", "Company name", "Phone number", "Email", "Working address", "Home address", "Birthday");
	for(i = 0; i < Number; i++)
	if(strcmp(t, a[i].Phone_Number) == 0 || strcmp(t, a[i].Last_Name) == 0)
	{
		printf(" %-5d%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", i+1, a[i].First_Name, a[i].Last_Name, a[i].Company, a[i].Phone_Number, a[i].Email, a[i].Working_Address, a[i].Home_Address, a[i].Birthday);
	    
	}
	getch();
}

void delete_contact()
{
	int i,j;
	printf("/nInput last name or phone number:");
	char t[100];
	gets(t);
	int tt;
	for(i = 0; i < Number; i++)
	if(strcmp(t, a[i].Phone_Number) == 0 || strcmp(t, a[i].Last_Name) == 0)
	{
		for(j = i; j <= Number; j++)
		a[j]=a[j+1];
		Number--;
	}
}

void gett(char x[])
{
	int j = 0;
	for(vt ; vt < strlen(n); vt++)
	{
		if(n[vt] == ';'||n[vt] == '\n'){
		vt++;
		return;
		}
		x[j++] = n[vt];
	}
}

int read_file()
{
	FILE *fp;
	fp = fopen("contact.txt", "r");
	int i = 0;
	fflush(stdin);
	Number = 0;
	while(fgets(n,99,fp))
	{
		fflush(stdin);
		vt = 0;
		
		gett(a[Number].First_Name);
		gett(a[Number].Last_Name);
		gett(a[Number].Company);
		gett(a[Number].Phone_Number);
		gett(a[Number].Email);
		gett(a[Number].Working_Address);
		gett(a[Number].Home_Address);
		gett(a[Number].Birthday);
		fflush(stdin);
		Number++;
	}
	printf("Read file successfully!\n\n");
	fclose(fp);
	
}


int Check_Phone_Number(char Phone_Number[])
{
	int i;
	for(i = 0; i<strlen(Phone_Number);i++ )
		if(Phone_Number[i] > '9'|| Phone_Number[i]<'0')
			return 2;
		
	if(strlen(Phone_Number)<9||strlen(Phone_Number)>10)
		    return 1;
	
	return 0;
}

void display_contact() 
{
	int i;
	printf(" %-5s%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", "STT", "First name", "Last name", "Company name", "Phone number", "Email", "Working address", "Home address", "Birthday");
	for (i = 0; i < Number; i++) {
		printf(" %-5d%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", i+1, a[i].First_Name, a[i].Last_Name, a[i].Company, a[i].Phone_Number, a[i].Email, a[i].Working_Address, a[i].Home_Address, a[i].Birthday);
	}
	printf("\n");
}
void clearFileContent() {
    FILE *fp;
	fp = fopen("contact.txt", "w+");
    fclose(fp);
}
void write_file()
{
	clearFileContent();
	FILE *fp;
	fp = fopen("contact.txt", "a");
	int i;
	for (i = 0; i < Number; i++) {
		fprintf(fp, "%s;%s;%s;%s;%s;%s;%s;%s;\n",
				 a[i].First_Name, a[i].Last_Name, a[i].Company, a[i].Phone_Number, 
				a[i].Email, a[i].Working_Address, a[i].Home_Address, a[i].Birthday);
	}
	printf("Write file successfully!\n\n");
	fclose(fp);
}
int checkk(char x)
{
	if(x < '0' || x > '9') return 1;
	return 0;
}

//dd/mm/yyyy
int check_birthday(char bd[20])
{
	if(strlen(bd) != 10) return 0;
	bd[2] = '/';
	bd[5] = '/';
	if(checkk(bd[0]) || checkk(bd[1]) || checkk(bd[3]) || checkk(bd[4]) || checkk(bd[6]) || checkk(bd[7]) || checkk(bd[8]) || checkk(bd[9])) return 0;
	int day = (bd[0] - '0')*10 + bd[1] - '0';
	int month = (bd[3] - '0')*10 + bd[4] - '0';
	int year = (bd[6] - '0')*1000 + (bd[7] - '0')*100 + (bd[8] - '0')*10 + bd[9] - '0';
	if(month < 1 || month > 12) return 0;
	if(year < 1 || year > 9999) return 0;
	switch(month) {
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day < 1 ||day > 31)return 0;
            break;
        case 2: 
        if(((year%4 == 0 && year % 100 != 0)|| year % 400 == 0) && day > 29) return 0;
        else if(day > 28)return 0;
            break;
        case 4: 
        case 6: 
        case 9:
        case 11: 
            if(day < 1 ||day > 30)return 0;
            break;
    }
    return 1;
}


int get_date(char bd[])
{
	int day = (bd[0] - '0')*10 + bd[1] - '0';
	return day;
}

int get_month(char bd[])
{
		int month = (bd[3] - '0')*10 + bd[4] - '0';
		return month;
}

void display_month() 
{
	sort_by_date();
	int i, found = 0;
	
	for (i = 0; i < Number; i++) {
	
		if (get_month(a[i].Birthday) == month) 
		{
			found = 1;
			if (found == 1) {
				printf(" %-5s%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", "STT", "First name", "Last name", "Company name", "Phone number", "Email", "Working address", "Home address", "Birthday");
			}
			printf("%-20d\n", get_date(a[i].Birthday));
		}
	}
	if (found == 0) printf("Cannot find any contact have month in birthday = %d", month);
	printf("\n");
	getch();
}

void list_contact()
{
	int i, j;
	ct q;
	char swap[30];
	for(i = 0; i < Number; i ++)
	 {
	    for(j = i + 1; j < Number; j ++)
	    {
         	if(strcmp( a[i].Last_Name, a[j].Last_Name) > 0)
         	{
				q = a[i];
				a[i] = a[j];
				a[j] = q;
			 }
			 if(strcmp( a[i].Last_Name, a[j].Last_Name) == 0 && strcmp( a[i].First_Name, a[j].First_Name) > 0){
			 	q = a[i];
				a[i] = a[j];
				a[j] = q;
			 }
         	
         }
     }
	printf(" %-5s%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", "STT", "First name", "Last name", "Company name", "Phone number", "Email", "Working address", "Home address", "Birthday");
	for (i = 0; i < Number; i++) {
		printf(" %-5d%-20s%-20s%-20s%-20s%-30s%-20s%-20s%-20s\n", i+1, a[i].First_Name, a[i].Last_Name, a[i].Company, a[i].Phone_Number, a[i].Email, a[i].Working_Address, a[i].Home_Address, a[i].Birthday);
	}
	
	printf("\n");
	getch();
     
}



void sort_by_date() 
{
	int i, j;
	for (i = 0; i < Number - 1; i++) {
		for (j = i + 1; j < Number; j++) {
			if (get_date(a[i].Birthday) > get_date(a[j].Birthday)) {
				ct temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}	
}
