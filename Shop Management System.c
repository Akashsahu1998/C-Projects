	
	// SOFTWARE FOR MANAGE THE DATA OF SHOP         Date :- 31/09/2018

#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<windows.h>
#include<process.h> // Used for exit function

struct Record
{
	int pno;
	char pname[20];
	int price;
};

//   FUNCTION `TO ADD RECORD

void add_rec()
{
	system("cls");
	system("color 2E");
	FILE *fp;
	struct Record R;
	fp = fopen("Comp","ab");
	printf("\n Enter record to be Add : ");
	printf("\n Enter product no, product name, product price : ");
	scanf("%d %s %d",&R.pno,R.pname,&R.price);
	fwrite(&R,sizeof(R),1,fp);
	system("cls");
	printf("\n\n\t\t\t\t\tRecord Added");
	fclose(fp);
}

//   FUNCTION TO SHOW RECORD

void show_rec()
{
	system("cls");
	system("color E9");
	FILE *fp;
	struct Record R;
	fp = fopen("Comp","rb");
	printf("\n\n\t Your Record are : \n");
	printf("\t\t\t\t Product No. Product Name  Product Price\n");
	while (fread(&R, sizeof(R), 1, fp))
 	{
 		printf("\t\t\t\t    %d\t\t%s\t\t%d\n",R.pno,R.pname,R.price);	
	}
	fclose(fp);
}

//   FUNCTION TO TRAVERSE(SHOW ON MONITOR THE PREVOIUS DATA) Record

void traverse_rec()
{
	system("cls");
	system("color 1E");
	FILE *fp;
	struct Record R;
	fp = fopen("Comp","rb");
	if(fp == NULL)
	{
		printf("\n Sorry file not found...");
		return;
	}
	while(fread(&R,sizeof(R),1,fp))
	{
		printf("\n\n\t\t\t \t Product No. Product Name  Product Price\n");
		printf("\n\t\t\t\t      %d\t\t %s\t       %d",R.pno,R.pname,R.price);
		fclose(fp);
	}
}

//   FUNCTION TO SEARCH RECORD

void search_rec()
{
	system("cls");
	system("color 3B");
	FILE *fp;
	struct Record R;
	int sno;
	fp = fopen("Comp","rb");
	if(fp == NULL)
	{	
		printf("\n Sorry file not found...");
		return;
	}
	printf("\n Enter item no. to be search : ");
	scanf("%d",&sno);
	while(fread(&R,sizeof(R),1,fp))
	if(sno == R.pno)
	{
		system("cls");
		printf("\n\n\t Record Found :- \n");
		printf("\t\t\t\t Product No. Product Name  Product Price\n");
		printf("\n\t\t\t\t     %d\t        %s        %d",R.pno,R.pname,R.price);
		fclose(fp);
		return;
	}
	printf("\n Sorry Record Not Found !");
	fclose(fp);
}

//   FUNCTION TO INSERT RECORD

void insert_rec()
{
	fflush(stdin);
	system("cls");
	system("color D0");
	FILE *fp1,*fp2;
	struct Record R,t;
	int ino,flag=0;
	fp1 = fopen("Comp","rb");
	if(fp1 == NULL)
	{	
		printf("\n Sorry file not found...");
		return;
	}
	fp2 = fopen("Temp","wb");
	printf("\n Enter item no. after which you want to insert new record : ");
	scanf("%d",&ino);
	while(fread(&R,sizeof(R),1,fp1))
	{
		fwrite(&R,sizeof(R),1,fp2);
		if(ino == R.pno)
		{
			printf("\n Enter record to be inserted : \n Enter product no, product name, product price : ");
			scanf("%d %s %d",&t.pno,t.pname,&t.price);
			fwrite(&t,sizeof(t),1,fp2);
			system("cls");
			printf("\n\n\t\t\t\t\tRecord Inserted");
			flag = 1;
		}
	}
	if(flag == 0)
	{
		system("cls");
		printf("\n\n\t\t\t\t Sorry %d item no. not found",ino);
	}
	fclose(fp1);
	fclose(fp2);
	remove("Comp");
	rename("Temp","Comp");
}

//   FUNCTION TO DELETE RECORD

void delete_rec()
{
	system("cls");
	system("color 3D");
	FILE *fp1,*fp2;
	struct Record R;
	int dno;
	fp1 = fopen("Comp","rb");
	if(fp1 == NULL)
	{	
		printf("\n Sorry file not found...");
		return;
	}
	fp2 = fopen("Temp","wb");
	printf("\n Enter item no. to be deleted : ");
	scanf("%d",&dno);
	while(fread(&R,sizeof(R),1,fp1))
	{
   		if (R.pno != dno)
    		fwrite(&R, sizeof(R), 1, fp2);
  	}
  	if(R.pno != dno)
  	{
  		system("cls");
  		printf("\n\n\t\t\t\t Sorry %d item no. not found",dno);
		return 0;	
	} 
		fclose(fp1);
		fclose(fp2);
		fp1 = fopen("Comp", "w");
		fp2 = fopen("Temp", "r");
		while (fread(&R, sizeof(R), 1, fp2))
		fwrite(&R, sizeof(R), 1, fp1);
		printf("\n\n\t\t\t\t\tRECORD DELETED\n");
		fclose(fp1);
		fclose(fp2);
		remove("Comp");
		rename("Temp","Comp");
}

//   FUNCTION TO UPDATE RECORD

void update_rec()
{
	system("cls");
	system("color CF");
	FILE *fp;
	struct Record R;
	int uno;
	fp = fopen("Comp","rb+");
	if(fp == NULL)
	{	
		printf("\n Sorry file not found...");
		return;
	}
	printf("\n Enter item no. to be updated : ");
	scanf("%d",&uno);
	while(fread(&R,sizeof(R),1,fp))
	{
		if(uno == R.pno)
		{
			printf("\n Enter new price : ");
			scanf("%d",&R.price);
			system("cls");
			fseek(fp,-sizeof(R),1);
			fwrite(&R,sizeof(R),1,fp);
			printf("\n\n\t\t\t\t Record Updated");
			fclose(fp);
			return;
		}
	}
	printf("\n Sorry %d item no. not found",uno);
	fclose(fp);
}

//   FUNCTION TO SORT RECORD

void sort_rec()
{
	system("cls");
	system("color 4F");
	struct Record R,*p;
	int nor,i=0,j,w;
	FILE *fp;
	fp = fopen("Comp","rb");
	if(fp == NULL)
	{	
		printf("\n Sorry file not found");
		return;
	}
	printf("\n Price  Wise :- 1 \n Serial Wise :- 2\n\n You Choose = ");
	scanf("%d",&w);
	fseek(fp,0,2);
	nor = ftell(fp)/sizeof(R);
	p = (struct Record *)malloc(nor * sizeof(R));
	rewind(fp);
	while(fread(&R,sizeof(R),1,fp))
	{
		p[i++] = R;
	}
	for(i=0;i<nor-1;i++)
	{
		for(j=i+1;j<nor;j++)
		{
			if(w == 1)
			{
				if(p[j].price<p[i].price)
				{
					R = p[i];
					p[i] = p[j];
					p[j] = R; 
				}	
			}
			else if(w == 2)
			{
				if(p[j].pno<p[i].pno)
				{
					R = p[i];
					p[i] = p[j];
					p[j] = R; 
				}
			}
			else if(w !=1 && w !=2)
			{
				printf("\n Invalid Choice");
			    return;	
			}
		}
	}
	system("cls");
	printf("\n\n\t Sorted data are : \n");
	printf("\t\t\t\t Product No. Product Name  Product Price\n");
	for(i=0;i<nor;i++)
	{
		printf("\t\t\t\t    %d\t\t%s\t\t%d\n",p[i].pno,p[i].pname,p[i].price);
		fclose(fp);
	}
}

//   FUNCTION TO EXIT FROM SOFTWARE

void exit_rec()
{
	system("cls");
	system(" color D");
	printf("\n\n Thanks For Using Software...\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\tCreated By Akash Sahu\n");
	exit(1);
}

int main()
{
	int ch;
	do
	{
		fflush(stdin);
		system("cls");
		system("color 6B");
		printf("\n\n\t\t\t\t        **Shop Management System**\n");
		printf("\t\t\t\t     ================================\n");
		printf("\n\t\t\t\t\t------------------------");
		printf("\n\t\t\t\t\t|   1 Add Record       |");
		printf("\n\t\t\t\t\t|   2 Show Record      |");
		printf("\n\t\t\t\t\t|   3 Traverse Record  |");
		printf("\n\t\t\t\t\t|   4 Search Record    |");
		printf("\n\t\t\t\t\t|   5 Insert Record    |");
		printf("\n\t\t\t\t\t|   6 Delete Record    |");
		printf("\n\t\t\t\t\t|   7 Update Record    |");
		printf("\n\t\t\t\t\t|   8 Sort Records     |");
		printf("\n\t\t\t\t\t|   0 Exit             |");
		printf("\n\t\t\t\t\t------------------------");
		printf("\n\n\n\t\t\t\t\t Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : add_rec();
					break;
			case 2 : show_rec();
					break;
			case 3 : traverse_rec();
					break;
			case 4 : search_rec();
					break;
			case 5 : insert_rec();
					break;
			case 6 : delete_rec();
					break;
			case 7 : update_rec();
					break;
			case 8 : sort_rec();
					break;
			case 0 : exit_rec();
					break;
			default : printf("\n Invalid Choice");
		}
		printf("\n\n Press any key to continue...");
		getch();
	}while(ch != 0);
	return 0;
}
