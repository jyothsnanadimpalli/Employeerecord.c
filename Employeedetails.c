#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee
{
    char name[50];
    int Eid;
    float rating;
};
struct Employee e;
long int size=sizeof(e);
FILE *fp,*ft;
void add_record()
{
    printf("Enter Employee Name:");
    scanf("%s",e.name);
    printf("Enter Employee id:");
    scanf("%d",&e.Eid);
    printf("Enter rating:");
    scanf("%f",&e.rating);
    fwrite(&e,size,1,fp);
    printf("Employee record added \n");
}
void delete_record_with_Employee_name()
{
    char sname[50];
    printf("Enter Employee name to delete record:");
    scanf("%s",sname);
    ft=fopen("temp.txt","wb");
    rewind(fp);
    while(fread(&e,size,1,fp)==1)
    {
        if(strcmp(e.name,sname)!=0)
        {
            fwrite(&e,size,1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("temp.txt","data.txt");
    fp=fopen("data.txt","rb+");
    printf("Employee record deleted \n");
}
void display()
{
    printf("\t\t\t\tDetails\t\t\t\t\t\t\n");
    rewind(fp);
    while(fread(&e,size,1,fp)==1)
    {
        printf("%s\t\t\t%d\t\t\t%f\n",e.name,e.Eid,e.rating);
    }
}
void display_record_with_Employee_name()
{
    char sname[50];
    rewind(fp);
    printf("Enter Employee name to display record:");
    scanf("%s",sname);
    while(fread(&e,size,1,fp)==1)
    {
        if(strcmp(sname,e.name)==0)
        {
            printf("%s\t\t\t%d\t\t\t%f\n",e.name,e.Eid,e.rating);
        }
    }
}
void display_record_with_Employee_id()
{
    int roll;
    rewind(fp);
    printf("Enter Employee id to display record:");
    scanf("%d",&roll);
    while(fread(&e,size,1,fp)==1)
    {
        if(roll==e.Eid)
        {
            printf("%s\t\t\t%d\t\t\t%f\n",e.name,e.Eid,e.rating);
        }
    }
}
void modify_with_Employee_name()
{
    char sname[50];
    printf("Enter Employee name to modify:");
    scanf("%s",sname);
    rewind(fp);
    while(fread(&e,size,1,fp)==1)
    {
        if(strcmp(sname,e.name)==0)
        {
            printf("Enter modified name:");
            scanf("%s",e.name);
            printf("Enter modified id:");
            scanf("%d",&e.Eid);
            printf("Enter modified rating");
            scanf("%f",&e.rating);
            fseek(fp, -size, SEEK_CUR);
            fwrite(&e,size,1,fp);
            break;
            printf("Employee record modified  \n");
        }
    }
}
int main()
{
    int c;
    fp=fopen("data.txt","wb+");
    if(fp==NULL)
    {
        printf("Cannot open file");
        exit(1);
    }
    while(1)
    {
        printf("Enter your choice:\n1.Add a record\n2.delete a record\n3.display all data\n4.display data of Employee using Employee name\n5.display data of Employee using id\n6.modify record using name\n7.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: add_record();break;
            case 2: delete_record_with_Employee_name();break;
            case 3: display();break;
            case 4: display_record_with_Employee_name();break;
            case 5: display_record_with_Employee_id();break;
            case 6: modify_with_Employee_name();break;
            case 7: exit(0);break;
            default: printf("Invalid option");
        }
    }
}
