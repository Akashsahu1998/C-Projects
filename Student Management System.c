
	// SOFTWARE TO MANAGE THE RECORDS OF STUDENTS 			Date :- 02/10/2018

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<process.h>

struct Student{
    char ID[20];
    char name[30];
    char branch[30];
    char father[30];
    char mother[30];
    char phone_no[15];
	char add[50];
	int n;
};
										
struct Marks{
	char ID[15];
	int m_m,p_m,c_m,e_m,h_m;
	float per;
};

//   FUNCTION TO ADD STUDENT RECORD

void add_stu_rec()
{
	system("cls");
	system("color E9");
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t   1 Personal Details");
	printf("\n\t\t\t\t\t   2 Marks");
	printf("\n\t\t\t\t\t   3 Both Personal Details & Marks");
	printf("\n\t\t\t\t\t   4 Back To Main Menu");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&n);
	if(n == 1)
	{
		system("cls");
		printf("\n\n\t\t\t\t\t Enter Personal Details");
		FILE *fp;
		struct Student S;
		fp = fopen("PersonalInformation","ab");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n\n\t\t\t\t\t Enter Sudent ID : ");
		fflush(stdin);
		gets(S.ID);
		printf("\n\t\t\t\t\t Enter Sudent Name : ");
		gets(S.name);
		printf("\n\t\t\t\t\t Enter Branch : ");
		gets(S.branch);
		printf("\n\t\t\t\t\t Enter Fathers Name : ");
		gets(S.father);
		printf("\n\t\t\t\t\t Enter Mothers Name : ");
		gets(S.mother);
		printf("\n\t\t\t\t\t Enter Mobile No : ");
		gets(S.phone_no);
		fflush(stdin);
		printf("\n\t\t\t\t\t Enter Address : ");
		gets(S.add);
		fwrite(&S,sizeof(S),1,fp);
		system("cls");
		printf("\n\n\t\t\t\t\t\tRecord Added");
		fclose(fp);
	}
	else if(n == 2)
	{
		system("cls");
		printf("\n\n\t\t\t\t\t Enter Marks");
		FILE *fp;
		struct Marks M;
		struct Student S;
		fp = fopen("MarksInformation","ab");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n\n\t\t\t\t\t Enter Sudent ID : ");
		fflush(stdin);
		gets(M.ID);
		printf("\n\n\t\t\t\t\t Maths Subject : ");
		scanf("%d",&M.m_m);
		printf("\n\t\t\t\t\t Physics Subject : ");
		scanf("%d",&M.p_m);
		printf("\n\t\t\t\t\t Chemistry Subject : ");
		scanf("%d",&M.c_m);
		printf("\n\t\t\t\t\t English Subject : ");
		scanf("%d",&M.e_m);
		printf("\n\t\t\t\t\t Hindi Subject : ");
		scanf("%d",&M.h_m);
		M.per = (float)(M.m_m + M.p_m + M.c_m + M.e_m + M.h_m)/5.0;
		fwrite(&M,sizeof(M),1,fp);
		system("cls");
		printf("\n\n\t\t\t\t\t\tRecord Added");
		fclose(fp);
	}
	else if(n == 3)
	{
		system("cls");
		FILE *fp1,*fp2;
		struct Student S;
		struct Marks M;
		fp1 = fopen("PersonalInformation","ab");
		if(fp1 == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n\n\t\t\t\t\t Enter Personal Details");
		printf("\n\n\t\t\t\t\t Enter Sudent ID : ");
		fflush(stdin);
		gets(S.ID);
		printf("\n\t\t\t\t\t Enter Sudent Name : ");
		gets(S.name);
		printf("\n\t\t\t\t\t Enter Branch : ");
		gets(S.branch);
		printf("\n\t\t\t\t\t Enter Fathers Name : ");
		gets(S.father);
		printf("\n\t\t\t\t\t Enter Mothers Name : ");
		gets(S.mother);
		printf("\n\t\t\t\t\t Enter Mobile No : ");
		gets(S.phone_no);
		fflush(stdin);
		printf("\n\t\t\t\t\t Enter Address : ");
		gets(S.add);
		
		fp2 = fopen("MarksInformation","ab");
		if(fp2 == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n\n\t\t\t\t\t Enter Marks\n");
		fflush(stdin);
		strcpy(M.ID,S.ID);
		printf("\n\t\t\t\t\t Maths Subject : ");
		scanf("%d",&M.m_m);
		printf("\n\t\t\t\t\t Physics Subject : ");
		scanf("%d",&M.p_m);
		printf("\n\t\t\t\t\t Chemistry Subject : ");
		scanf("%d",&M.c_m);
		printf("\n\t\t\t\t\t English Subject : ");
		scanf("%d",&M.e_m);
		printf("\n\t\t\t\t\t Hindi Subject : ");
		scanf("%d",&M.h_m);
		M.per = (float)(M.m_m + M.p_m + M.c_m + M.e_m + M.h_m)/5.0;
		
		fwrite(&S,sizeof(S),1,fp1);
		fwrite(&M,sizeof(M),1,fp2);
		system("cls");
		printf("\n\n\t\t\t\t\t\tRecord Added");
		fclose(fp1);
		fclose(fp2);
	}
	else if(n == 4)
	{
		main();
	}
	else
	{
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tInvalid Choice");
		printf("\n\n Press any key to continue...");
		getch();
		add_stu_rec();	
	}
	
}

//   FUNCTION TO DELETE STUDENT RECORD

void delete_stu_rec()
{
	system("cls");
	system("color 3D");
	FILE *fp1,*fp2,*fp3,*fp4;                                                     
	struct Student S;
	struct Marks M;
	char DID[15];
	fp1 = fopen("PersonalInformation","rb");
	fp3 = fopen("MarksInformation","rb");
	if(fp1 == NULL && fp3 == NULL)
	{	
		printf("\n Sorry file not found...");
		return;
	}
	fp2 = fopen("Temp1","wb");
	fp4 = fopen("Temp2","wb");
	if(fp2 == NULL && fp4 == NULL)
	{	
		printf("\n Sorry file not found...");
		return;
	}
	fflush(stdin);
	printf("\n Enter ID no. to delete data : ");
	gets(DID);
	
	while(fread(&S,sizeof(S),1,fp1))
	{
   		if(strcmp(DID,S.ID)!= 0)
    		fwrite(&S, sizeof(S), 1, fp2);
	}
	while(fread(&M,sizeof(M),1,fp3))
	{
   		if(strcmp(DID,M.ID)!= 0)
    		fwrite(&M, sizeof(M), 1, fp4);
	}
	
  	if(strcmp(DID,S.ID)!=0 && strcmp(DID,M.ID)!=0)
  	{
  		system("cls");
  		printf("\n\n\t\t\t\t\t\tSorry Record not found");
		return;	
	} 
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		
		fp1 = fopen("PersonalInformation", "w");
		fp2 = fopen("Temp1", "r");
		fp3 = fopen("MarksInformation", "w");
		fp4 = fopen("Temp2", "r");
		
		while (fread(&S, sizeof(S), 1, fp2))
		fwrite(&S, sizeof(S), 1, fp1);
		while (fread(&M, sizeof(M), 1, fp4))
		fwrite(&M, sizeof(M), 1, fp3);
		system("cls");
		printf("\n\n\n\t\t\t\t\t\tRECORD DELETED\n");
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		remove("PersonalInformation");
		rename("Temp1","PersonalInformation");
		remove("MarksInformation");
		rename("Temp2","MarksInformation");
}

//   FUNCTION TO UPDATE STUDENT RECORD

void modify_stu_rec()
{
	system("cls");
	system("color 2E");
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t   1 Personal Details");
	printf("\n\t\t\t\t\t   2 Marks");
	printf("\n\t\t\t\t\t   3 Both Personal Details & Marks");
	printf("\n\t\t\t\t\t   4 Back To Main Menu");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&n);
	if(n == 1)
	{
		system("cls");
		FILE *fp;
		struct Student S;	
		char UID[20];
		fp = fopen("PersonalInformation","rb+");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n Enter ID no. to be updated : ");
		fflush(stdin);
		gets(UID);
		while(fread(&S,sizeof(S),1,fp))
		{
			if(strcmp(UID,S.ID) == 0)
			{
				printf("\n\n\t\t\t\t\t Enter New Personal Details\n");
				printf("\n\t\t\t\t\t Enter New Sudent Name : ");
				gets(S.name);
				fflush(stdin);
				printf("\n\t\t\t\t\t Enter New Branch : ");
				gets(S.branch);
				fflush(stdin);
				printf("\n\t\t\t\t\t Enter New Fathers Name : ");
				gets(S.father);
				fflush(stdin);
				printf("\n\t\t\t\t\t Enter New Mothers Name : ");
				gets(S.mother);
				fflush(stdin);
				printf("\n\t\t\t\t\t Enter New Mobile No : ");
				fflush(stdin);
				gets(S.phone_no);
				fflush(stdin);
				printf("\n\t\t\t\t\t Enter New Address : ");
				fflush(stdin);
				gets(S.add);
				system("cls");
				fseek(fp,-sizeof(S),1);
				fwrite(&S,sizeof(S),1,fp);
				system("cls");
				printf("\n\n\n       \t\t\t\t\t\tRecord Updated");
				fclose(fp);
				return;
			}
		}
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");
		fclose(fp);
	}
	else if(n == 2)
	{
		system("cls");
		FILE *fp;
		struct Marks M;
		char UID[20];
		fp = fopen("MarksInformation","rb+");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n Enter ID no. to be updated : ");
		fflush(stdin);
		gets(UID);
		while(fread(&M,sizeof(M),1,fp))
		{
			if(strcmp(UID,M.ID) == 0)
			{
				printf("\n\n\t\t\t\t\t Enter New Marks\n");
				printf("\n\n\t\t\t\t\t Enter New Marks OF Maths Subject : ");
				scanf("%d",&M.m_m);
				printf("\n\t\t\t\t\t Enter New Marks OF Physics Subject : ");
				scanf("%d",&M.p_m);
				printf("\n\t\t\t\t\t Enter New Marks OF Chemistry Subject : ");
				scanf("%d",&M.c_m);
				printf("\n\t\t\t\t\t Enter New Marks OF English Subject : ");
				scanf("%d",&M.e_m);
				printf("\n\t\t\t\t\t Enter New Marks OF Hindi Subject : ");
				scanf("%d",&M.h_m);
				M.per = (float)(M.m_m + M.p_m + M.c_m + M.e_m + M.h_m)/5.0;
				fseek(fp,-sizeof(M),1);
				fwrite(&M,sizeof(M),1,fp);
				system("cls");
				printf("\n\n\n       \t\t\t\t\t\tRecord Updated");
				fclose(fp);
				return;
			}
		}
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");
		fclose(fp);
	}
	else if(n == 3)
	{
		system("cls");
		FILE *fp1,*fp2;
		struct Student S;
		struct Marks M;
		char UID[20];
		int t=0,flag=0;
		fp1 = fopen("PersonalInformation","rb+");
		if(fp1 == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		fp2 = fopen("MarksInformation","rb+");
		if(fp2 == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n Enter ID no. to be updated details : ");
		fflush(stdin);
		gets(UID);
		
		while(fread(&S,sizeof(S),1,fp1))
		{
			if(strcmp(UID,S.ID)==0)
			{
				printf("\n\n\t\t\t\t\t Enter New Personal Details\n");
				printf("\n\t\t\t\t\t Enter New Sudent Name : ");
				gets(S.name);
				printf("\n\t\t\t\t\t Enter New Branch : ");
				gets(S.branch);
				printf("\n\t\t\t\t\t Enter New Fathers Name : ");
				gets(S.father);
				printf("\n\t\t\t\t\t Enter New Mothers Name : ");
				gets(S.mother);
				printf("\n\t\t\t\t\t Enter New Mobile No : ");
				gets(S.phone_no);
				printf("\n\t\t\t\t\t Enter New Address : ");
				gets(S.add);
				fseek(fp1,-sizeof(S),1);
				fwrite(&S,sizeof(S),1,fp1);
				flag = 1;
				fclose(fp1);
			}
		}
		if(flag==0)
		{
			system("cls");
			printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");	
			fclose(fp1);	
			return;
		}
		
		while(fread(&M,sizeof(M),1,fp2))
		{
			if(strcmp(UID,M.ID) == 0)
			{
				printf("\n\n\t\t\t\t\t Enter New Marks\n");
				printf("\n\t\t\t\t\t Enter New Marks OF Maths Subject : ");
				scanf("%d",&M.m_m);
				printf("\n\t\t\t\t\t Enter New Marks OF Physics Subject : ");
				scanf("%d",&M.p_m);
				printf("\n\t\t\t\t\t Enter New Marks OF Chemistry Subject : ");
				scanf("%d",&M.c_m);
				printf("\n\t\t\t\t\t Enter New Marks OF English Subject : ");
				scanf("%d",&M.e_m);
				printf("\n\t\t\t\t\t Enter New Marks OF Hindi Subject : ");
				scanf("%d",&M.h_m);
				M.per = (float)(M.m_m + M.p_m + M.c_m + M.e_m + M.h_m)/5.0;
				fseek(fp2,-sizeof(M),1);
				fwrite(&M,sizeof(M),1,fp2);
				system("cls");
				printf("\n\n\n       \t\t\t\t\t\tRecord Updated");
				fclose(fp2);
				return;
			}
		}
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");	
		fclose(fp1);
		fclose(fp2);
	}
	else if(n == 4)
	{
		main();
	}
	else
	{
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tInvalid Choice");
		printf("\n\n Press any key to continue...");
		getch();
		modify_stu_rec();	
	}
}

//   FUNCTION TO SEARCH STUDENT RECORD

void search_stu_rec()
{
	system("cls");
	system("color 3B");
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t   1 Personal Details Wise");
	printf("\n\t\t\t\t\t   2 Marks Wise");
	printf("\n\t\t\t\t\t   3 Both Personal Details & Marks Wise");
	printf("\n\t\t\t\t\t   4 Back To Main Menu");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&n);
	if(n == 1)
	{
		system("cls");
		FILE *fp;
		struct Student S;
		char SID[15];
		fp = fopen("PersonalInformation","rb");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n Enter ID no. to be search : ");
		fflush(stdin);
		gets(SID);
		while(fread(&S,sizeof(S),1,fp))
		if(strcmp(SID,S.ID) == 0)
		{
			system("cls");
			printf("\n\n\t\t\t\t\t   Student Personal Details\n");
			printf("\t\t\t\t\t==============================\n\n");
			printf("\n       ID\t    Name\t  Branch Father Name    Mother Name     Phone Number\t    Address\n\n");
			printf("  %6s\t %6s\t %6s\t %6s\t %6s\t %6s\t %6s\n",S.ID,S.name,S.branch,S.father,S.mother,S.phone_no,S.add);	
			fclose(fp);
			return;
		}
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");
		fclose(fp);
	}
	else if(n == 2)
	{
		system("cls");
		FILE *fp;
		struct Marks M;
		char SID[15];
		fp = fopen("MarksInformation","rb");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n Enter ID no. to be search : ");
		fflush(stdin);
		gets(SID);
		while(fread(&M,sizeof(M),1,fp))
		if(strcmp(SID,M.ID) == 0)
		{
			system("cls");
			printf("\n\n\t\t\t\t\t\t Student Marks\n");
			printf("\t\t\t\t\t      ===================\n\n");
			printf("\n       ID\t     Maths\t   Physics\t   Chemistry\t   English\t    Hindi\tPercentage\n\n");
			printf("  %7s\t %7d\t %7d\t %7d\t %7d\t %7d\t %7f\n",M.ID,M.m_m,M.p_m,M.c_m,M.e_m,M.h_m,M.per);
			fclose(fp);
			return;
		}
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");
		fclose(fp);
	}
	else if(n == 3)
	{
		system("cls");
		FILE *fp1,*fp2;
		struct Student S;
		struct Marks M;
		char SID[15];
		int flag=0;
		
		fp1 = fopen("PersonalInformation","rb");
		if(fp1 == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n Enter ID no. to be search : ");
		fflush(stdin);
		gets(SID);
		while(fread(&S,sizeof(S),1,fp1))
		if(strcmp(SID,S.ID) == 0)
		{
			printf("\n\n\t\t\t\t\t   Student Personal Details\n");
			printf("\t\t\t\t\t==============================\n\n");
			printf("\n       ID\t    Name\t  Branch Father Name    Mother Name     Phone Number\t    Address\n\n");
			printf("  %6s\t %s\t %6s\t %6s\t %6s\t %6s\t %6s\n",S.ID,S.name,S.branch,S.father,S.mother,S.phone_no,S.add);	
			flag = 1;
			fclose(fp1);
		}
		if(flag==0)
		{
			system("cls");
			printf("\n\n\n       \t\t\t\t\t\tSorry Record not found");	
			fclose(fp1);	
			return;
		}
		
		fp2 = fopen("MarksInformation","rb");
		if(fp2 == NULL)
		{	
			printf("\n Sorry file not found...");
			return;
		}
		printf("\n\n\t\t\t\t\t\t Student Marks\n");
		printf("\t\t\t\t\t      ===================\n\n");
		printf("\n       ID\t     Maths\t   Physics\t   Chemistry\t   English\t    Hindi\tPercentage\n\n");
		while(fread(&M,sizeof(M),1,fp2))
		if(strcmp(SID,M.ID) == 0)
		{
			printf("  %7s\t %7d\t %7d\t %7d\t %7d\t %7d\t %7f\n",M.ID,M.m_m,M.p_m,M.c_m,M.e_m,M.h_m,M.per);
			fclose(fp2);
			return;
		}
		system("cls");
		printf("\n\n\n       \t\t\t\t\t Sorry Record not found");		
		fclose(fp1);
		fclose(fp2);
	}
	else if(n == 4)
	{
		main();
	}
	else
	{
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tInvalid Choice");
		printf("\n\n Press any key to continue...");
		getch();
		search_stu_rec();	
	}
}

//   FUNCTION TO SHOW STUDENT RECORD

void display_stu_rec()
{
	system("cls");
	system("color 1E");
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t   1 Personal Details");
	printf("\n\t\t\t\t\t   2 Marks");
	printf("\n\t\t\t\t\t   3 Both Personal Details & Marks");
	printf("\n\t\t\t\t\t   4 Back To Main Menu");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&n);
	if(n == 1)
	{
		system("cls");
		FILE *fp;
		struct Student S;
		fp = fopen("PersonalInformation","rb");
		printf("\n\n\t\t\t\t\t   Student Personal Details\n");
		printf("\t\t\t\t\t===============================\n\n");
		printf("\n       ID\t    Name\t  Branch Father Name    Mother Name     Phone Number\t    Address\n\n");
		while (fread(&S, sizeof(S), 1, fp))
	 	{
	 		printf("  %6s\t %6s\t %6s\t %6s\t %6s\t %6s\t %6s\n",S.ID,S.name,S.branch,S.father,S.mother,S.phone_no,S.add);	
		}
		fclose(fp);
	}
	else if(n == 2)
	{
		system("cls");
		FILE *fp;
		struct Marks M;
		fp = fopen("MarksInformation","rb");
		printf("\n\n\t\t\t\t\t\t Student Marks\n");
		printf("\t\t\t\t\t      ===================\n\n");
		printf("\n       ID\t     Maths\t   Physics\t   Chemistry\t   English\t    Hindi\tPercentage\n\n");
		while (fread(&M, sizeof(M), 1, fp))
	 	{
	 		printf("  %7s\t %7d\t %7d\t %7d\t %7d\t %7d\t %7f\n",M.ID,M.m_m,M.p_m,M.c_m,M.e_m,M.h_m,M.per);
		}
		fclose(fp);
	}
	else if(n == 3)
	{
		system("cls");
		FILE *fp1,*fp2;
		struct Student S;
		struct Marks M;
		
		fp1 = fopen("PersonalInformation","rb");
		fp2 = fopen("MarksInformation","rb");
		
		
		printf("\n\n\t\t\t\t\t   Student Personal Details\n");
		printf("\t\t\t\t\t==============================\n\n");
		printf("\n       ID\t    Name\t  Branch Father Name    Mother Name     Phone Number\t    Address\n\n");
		while (fread(&S, sizeof(S), 1, fp1))
	 	{
	 		printf("  %6s\t %6s\t %6s\t %6s\t %6s\t %6s\t %6s\n",S.ID,S.name,S.branch,S.father,S.mother,S.phone_no,S.add);	
	 		fflush(stdin);
		}
		
		printf("\n\n\n\t\t\t\t\t\t Student Marks\n");
		printf("\t\t\t\t\t      ===================\n\n");
		printf("\n       ID\t     Maths\t   Physics\t   Chemistry\t   English\t    Hindi\tPercentage\n\n");
		while (fread(&M, sizeof(M), 1, fp2))
	 	{
	 		printf("  %7s\t %7d\t %7d\t %7d\t %7d\t %7d\t %7f\n",M.ID,M.m_m,M.p_m,M.c_m,M.e_m,M.h_m,M.per);	
		}
		
		fclose(fp1);
		fclose(fp2);
	}
	else if(n == 4)
	{
		main();
	}
	else
	{
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tInvalid Choice");
		printf("\n\n Press any key to continue...");
		getch();
		display_stu_rec();	
	}
}

//   FUNCTION TO SORT STUDENT RECORD

void sort_stu_rec()
{
	system("cls");
	system("color 4F");
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t   1 ID Wise");
	printf("\n\t\t\t\t\t   2 Marks Wise");
	printf("\n\t\t\t\t\t   3 Back To Main Menu");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&n);
	if(n == 1)
	{
		system("cls");
		struct Student S,*p;
		int nor,i=0,j,t;
		FILE *fp;
		fp = fopen("PersonalInformation","rb");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found");
			return;
		}
		fseek(fp,0,2);
		nor = ftell(fp)/sizeof(S);
		p = (struct Record *)malloc(nor * sizeof(S));
		rewind(fp);
		while(fread(&S,sizeof(S),1,fp))
		{
			p[i++] = S;
		}
		for(i=0;i<nor-1;i++)
		{
			for(j=i+1;j<nor;j++)
			{
				if(strcmp(p[j].ID,p[i].ID)==0)
				{
					printf("Aksh Sahu");
					S = p[i];
					
					p[i] = p[j];
					p[j] = S; 
				}
			}
		}
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t Sort By Student ID\n");
		printf("\t\t\t\t\t      ========================\n\n");
		printf("\n       ID\t    Name\t  Branch Father Name    Mother Name     Phone Number\t    Address\n\n");
		for(i=nor-1;i>=0;i--)
		{
			printf("  %6s\t %s\t %6s\t %6s\t %6s\t %6s\t %6s\n",p[i].ID,p[i].name,p[i].branch,p[i].father,p[i].mother,p[i].phone_no,p[i].add);
			fclose(fp);
		}
	}
	else if(n == 2)
	{
		system("cls");
		struct Marks M,*p;
		int nor,i=0,j;
		FILE *fp;
		fp = fopen("MarksInformation","rb");
		if(fp == NULL)
		{	
			printf("\n Sorry file not found");
			return;
		}
		fseek(fp,0,2);
		nor = ftell(fp)/sizeof(M);
		p = (struct Record *)malloc(nor * sizeof(M));
		rewind(fp);
		while(fread(&M,sizeof(M),1,fp))
		{
			p[i++] = M;
		}
		for(i=0;i<nor-1;i++)
		{
			for(j=i+1;j<nor;j++)
			{
				if(p[j].per<p[i].per)
				{
					M = p[i];
					p[i] = p[j];
					p[j] = M; 
				}
			}
		}
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t Sort By Student Marks\n");
		printf("\t\t\t\t\t      ===========================\n\n");
		printf("\n       ID\t     Maths\t   Physics\t   Chemistry\t   English\t    Hindi\tPercentage\n\n");
		for(i=0;i<nor;i++)
		{
			printf("  %7s\t %7d\t %7d\t %7d\t %7d\t %7d\t %7f\n",p[i].ID,p[i].m_m,p[i].p_m,p[i].c_m,p[i].e_m,p[i].h_m,p[i].per);
			fclose(fp);
		}
	}
	else if(n == 3)
	{
		main();
	}
	else
	{
		system("cls");
		printf("\n\n\n       \t\t\t\t\t\tInvalid Choice");
		printf("\n\n Press any key to continue...");
		getch();
		sort_stu_rec();
	}
	
	
}

//   FUNCTION TO EXIT FROM SOFWARE

void exit_menu()
{
	system("cls");
	system(" color D");
	printf("\n\n Thank You For Using Software...\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t Created By Akash Sahu\n");
	exit(1);
}

int main()
{
	int ch;
	do
	{
		system("cls");
	    system("color 6B");
		printf("\n\n\t\t\t\t        **Student Management System**\n");
		printf("\t\t\t\t     ===================================\n");
		printf("\n\t\t\t\t\t------------------------------");
		printf("\n\t\t\t\t\t|   1 Add Student Record     |");
		printf("\n\t\t\t\t\t|   2 Delete Student Record  |");
		printf("\n\t\t\t\t\t|   3 Modify Student Record  |");
		printf("\n\t\t\t\t\t|   4 Search Student Record  |");
		printf("\n\t\t\t\t\t|   5 Display Student Record |");
		printf("\n\t\t\t\t\t|   6 Sort Students Record   |");
		printf("\n\t\t\t\t\t|   0 Exit                   |");
		printf("\n\t\t\t\t\t------------------------------");
		printf("\n\n\n\t\t\t\t\t Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : add_stu_rec();
					break;
			case 2 : delete_stu_rec();
					break;
			case 3 : modify_stu_rec();
					break;
			case 4 : search_stu_rec();
					break;
			case 5 : display_stu_rec();
					break;
			case 6 : sort_stu_rec();
					break;
			case 0 : exit_menu();
					break;
			default : printf("\n Invalid Choice");
		}
		printf("\n\n\n Press any key to continue...");
		getch();
	}while(ch != 0);
	return 0;
}

