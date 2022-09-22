#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void start();
void addname();
void search_record();
void calculate();
void addrecord();
void searchrecord();
void calculatesalary();
void ext();
struct student {
   char name[25];
	int roll_no,class;
	char n;
	
}stud;

struct teacher{
	char name[25];
	int id[20];
}teach;

int main(){
	int c;
	char A;
	char B;
	char x;
	start();
	return 0;
}
void start(){
	char x;
    int c,d;
	char A;
	char B;
	printf("\n\n\t\t\t welcome to the school billing system\n\n\n");
	printf("\t\t\t choice account type:\n");

	printf("\t\t\t A: Student\n");
	printf("\t\t\t B: Teacher\n");
	printf("\t\t\t C: Exit\n");
	scanf("\t%s",&x);
    system("cls");
	
	switch(x){
		case 'A':
		case 'a':
			printf("\n\n\t\t 1: Add student record\n");
			printf("\n\t\t 2: Student record\n");
			printf("\n\t\t 3: calculate fee\n");
			printf("\t\t 4: Exit\n");
			scanf("%d",&c);
			system("cls");
			
			switch(c){
				case 1:
					addname();	
					break;
					
				case 2:
			        search_record();
					break;
					
			    case 3:
			    	calculate();
					break;
				case 4:
					ext();
					break;
				default:
					{
						printf("\n\t\t\tInvalid entry\n");
						 printf("\n\t\t\tTo Account Type\n\n\t");
                         system("pause");
                         system("cls");
                         start();
					}
			  }	
			  
			case 'B':
				case 'b':
				printf("\n\n\t\t\t 1: Add Teacher record\n");
				printf("\t\t\t 2: Teacher record\n");
				printf("\t\t\t 3: calculate salary\n");
				printf("\t\t\t 4: Exit\n");
				scanf("%d",&d);
				system("cls");
				switch(d){
					
				case 1:
					addrecord();	
					break;
					
				case 2:
			        searchrecord();
					break;
					
			    case 3:
			    	calculatesalary();
					break;
					
				case 4:
					ext();
					break;
				default:
					{
						printf("\n\t\t\tInvalid entry\n");
						 printf("\n\t\t\tTo Account Type\n\n\t");
                         system("pause");
                         system("cls");
                         start();
					}
				}
			
			case 'C':
				case 'c':
				ext();
				break;
			default:
				{
					printf("\n\t\t\tInvalid entry\n");
					 printf("\n\t\t\tTo Account Type\n\n\t");
                     system("pause");
                     system("cls");
                    start();
				}
	}


}
 void addname(){
	char cal;
	struct student stud;
    FILE *fp;
    
    	printf("\n\n\t\t\t Add record\n");
    	fp=fopen("student_stud","a");
	printf("\n\t\t Enter the name: ");
	scanf("%s",&stud.name);
	printf("\t\t Enter the class: ");
	scanf("%d",&stud.class);
	printf("\t\t Enter the i'd number: ");
	scanf("%d",&stud.roll_no);
	if(fp==0){
		fprintf(stderr,"\n\t\t\tThere is no any record first of all add record\n");
	}
	else{
		printf("\n\t\t\t record stored successfuly\n");
	}
	fwrite(&stud,sizeof(struct student),1,fp);
	fclose(fp);
	
		printf("\n\t\t\tpress a to repeat again or press b for main menu: ");
		scanf("%s",&cal);
        system("cls");
        
       if(cal=='a'||cal=='A')
       addname();
	
      if(cal=='b'||cal=='B')
       start();
	
	
}


  void search_record(){
	
	FILE *fp;
	char cal;
	struct student stud;
	fp=fopen("student_stud","r");
	printf("\t\t\t student records\n");
	
	if(fp==NULL){
		fprintf(stderr,"\n\t\t\tThere is no any record\n");
	}else{
		printf("\t\t records\n");
		
	}
	while(fread(&stud,sizeof(struct student),1,fp)){
		printf("\t\t\t student name:%s\n",stud.name);
		printf("\t\t\t class       :%i\n",stud.class);
		printf("\t\t\t roll no     :%i\n",stud.roll_no);
		
	}
	fclose(fp);
	printf("\t\t\t press b for main menu: ");
scanf("%s",&cal);
system("cls");
  if(cal=='b'||cal=='B')
  start();
}


  void calculate(){
	FILE *fp;
	char name[20],cal;
	int rollno,clas,mm,tfee,pay,tdue;
	
	fp=fopen("student_stud","r");
	printf("\t\t\tCalculate fee\n");
	printf("\t\t\t Enter the name: ");
	scanf("%s",&name);
	printf("\t\t\t Enter the i'd: ");
	scanf("%d",&rollno);
	printf("\t\t\t Enter the class: ");
	scanf("%d",&clas);
	while(fread(&stud,sizeof(stud),1,fp)==1)
	{
	
	if(clas==stud.class&&rollno==stud.roll_no)
	{
		printf("\t\t\t Enter the month till which fee have to paid: ");
		scanf("%d",&mm);
		tfee=mm*2000;
		printf("\t\t\t your total fee is : %d\n",tfee);
		printf("\t\t\t Payment amount is : ");
		scanf("%d",&pay);
		tdue=tfee-pay;
		printf("\t\t\t your remaning due is : %d\n",tdue);
	}
	/*else{
		printf("\t\t\tThere is no any record\n");
	}*/
}
       
		printf("\t\t\tpress a to repeat again or press b for main menu: ");
    scanf("%s",&cal);
    system("cls");
     if(cal=='a'||cal=='A')
     calculate();
     if(cal=='b'||cal=='B')
     start();
     	
}
      
   
  void addrecord(){
	char cal;
	FILE *ft;
	 do{
    	printf("\n\n\t\t\t Add record\n");
    	ft=fopen("teacher_teach","a");
	printf("\n\t\t\tEnter the name: ");
	scanf("%s",&teach.name);
	
	printf("\t\t\t Enter the teacher i'd number: ");
	scanf("%d",&teach.id);
	//printf("Your record is recorded in the system.");
	if(ft==0){
		fprintf(stderr,"\n\t\t\tThere is no any record\n");
	}else{
		printf("\t\t\trecord stored successfuly\n");
	}
	fwrite(&teach,sizeof(struct teacher),1,ft);
	fclose(ft);
	
	printf("\t\t\tpress a to repeat again or press b for main menu: ");
scanf("%s",&cal);
system("cls");
if(cal=='a'||cal=='A')
  addrecord();
  if(cal=='b'||cal=='B')
  start();
	

}while(cal=='A'||cal=='a');
}

  void searchrecord(){
	FILE *ft;
	char cal;
	ft=fopen("teacher_teach","r");
	
	if(ft==NULL){
		fprintf(stderr,"\n\t\t\tThere is no any record\n");
	}else{
		printf("\t\t\t Teacher records\n");
		
	}
	while(fread(&teach,sizeof(struct teacher),1,ft)){
		printf("\n\t\t\tteacher name:%s\n",teach.name);
		printf("\t\t\tteacher id     :%i\n",teach.id);
		
	}
	fclose(ft);
	
	printf("\n\t\t\t press b for main menu: ");
scanf("%s",&cal);
system("cls");

  if(cal=='b'||cal=='B')
  start();
}

  void calculatesalary(){
		FILE *ft;
	char name[20],cal;
	int id,m,tsal,paym,resal;
	ft=fopen("teacher_teach","r");
	printf("\n\n\t\t\tEnter the name: ");
	scanf("%s",&name);
	printf("\t\t\tEnter the i'd: ");
	scanf("%d",&id);
	
	while(fread(&teach,sizeof(teach),1,ft)==1)
	{
	
	if(id==teach.id)
	{
		printf("\t\t\tEnter the month upto which salary have to paid: ");
		scanf("%d",&m);
		tsal=m*4000;
		printf("\t\t\tYour total salary is : %d\n",tsal);
		printf("\t\t\tPayment amount is : ");
		scanf("%d",&paym);
		resal=tsal-paym;
		printf("\t\t\tyour remaning salary is : %d\n",resal);
		
	}
	/*else{
		printf("\t\t\tThere is no any record.\n");
	}*/
}
printf("\n\t\t\tpress a to repeat again or press b for main menu: ");
scanf("%s",&cal);
system("cls");
if(cal=='a'||cal=='A')
  calculatesalary();
  if(cal=='b'||cal=='B')
  start();
}

void ext()
{
    int i;
    printf("\n\n\t\t Thank you for using School Billing System Project\n\n");
    system("pause");
    system("cls");
    printf("\n\n\t\t\t Exiting\n\n");
    for(i=1; i<=80; i++)
    {
        Sleep(25);
        printf("*");
    }
    exit(0);

}







