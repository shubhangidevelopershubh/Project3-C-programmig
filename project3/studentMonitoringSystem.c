#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Student
{
    int rollNo;
    char name[20];
    double marks;
    int age;
} Student;

void storeData(Student *, int);
void display(Student *, int);
void display1(Student *, int );
void search(Student *, int);
int searchByName(Student *, int, char *);
int searchByRollNo(Student *, int, int);
void deleteData( Student*, int , int );
void sortByMarks( Student *, int );
void sort(Student *, int );
void sortByRating(Student *, int );
void sortByAge(Student *, int );
void main()
{
    int choice, size = 10, ctr = 0;
    Student *stud = (Student *)malloc(sizeof(Student) * size);
    do
    {
        printf("\n1. add data\n 2. display data\n 3. serach data\n 4. delete data\n5. sort data\n 0. to exit :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (ctr != size)
            {
                storeData(stud, ctr);
                ctr++;
            }
            else
            {
                printf("\n insufficient memory");
            }
            break;
        }
        case 2:
        {
            if (ctr == 0)
            {
                printf("\n no data present!!");
            }
            else
            {
                display(stud, ctr);
            }
            break;
        }
        case 3:
        {
            search(stud, ctr);
            break;
        }
        case 4:
        {
            int rn;
            printf("enter roll no:");
            scanf("%d", &rn);
            int res = searchByRollNo(stud, ctr, rn);
            if (res == -1)
            {
                printf("\n result not found");
            }
            else
            {
                deleteData(stud,res,ctr);
                ctr--;
            }
            break;
        }
        case 5:
        {
            sort(stud, ctr);
            break;
        }
         case 0:
        {
           printf("\n thank you");
            break;
        }
        default:printf("\n invalid choice!!");

        }
    } while (choice != 0);
}

void storeData(Student *stud, int ctr)
{
    Student s;
    printf("\n enter roll no:");
    scanf("%d", &s.rollNo);
    printf("\n enter name of student:");
    fflush(stdin);
    gets(s.name);
    // fgets(s.name,50);
    printf("\n enter age of stuent:");
    scanf("%d", &s.age);
    printf("\n enter marks of student:");
    scanf("%lf", &s.marks);
    stud[ctr] = s;
}

void display(Student *stud, int ctr)
{
    int i;
    for (i = 0; i < ctr; i++)
    {
        // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[i].rollNo, stud[i].name, stud[i].age, stud[i].marks);
        display1(stud,i);
    }
}

void search(Student *stud, int ctr)
{
    int ch, i;
    printf("\n1. search by roll no\n2. search by name\n enter your choice:");
    scanf("%d", &ch);
    if (ch == 1)
    {
        int rn;
        printf("enter roll no:");
        scanf("%d", &rn);
        int res = searchByRollNo(stud, ctr, rn);
        if (res == -1)
        {
            printf("\n result not found");
        }
        else
        {
           // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[res].rollNo, stud[res].name, stud[res].age, stud[res].marks);
            display1(stud,res);
        }
    }
    else if (ch == 2)
    {
        char nm[20];
        printf("enter name:");
        fflush(stdin);
        gets(nm);
        int result = searchByName(stud, ctr, nm);
        if (result == -1)
        {
            printf("\n result not found");
        }
        else
        {
           // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[result].rollNo, stud[result].name, stud[result].age, stud[result].marks);
            display1(stud,result);
        }
    }
}
int searchByRollNo(Student *stud, int ctr, int rn)
{
    for (int i = 0; i < ctr; i++)
    {
        if (stud[i].rollNo == rn)
        {
            return i;
        }
    }
    return -1;
}

int searchByName(Student *stud, int ctr, char *nm)
{
    for (int i = 0; i < ctr; i++)
    {
        if (strcasecmp(stud[i].name, nm) == 0)
        {
            return i;
        }
    }
    return -1;
}
void display1(Student *stud, int res){
printf("\n+---------------+---------------+---------------+---------------+");
printf("\n|    Roll No    |     Name      |    Age        |       Marks   |");
printf("\n+---------------+---------------+---------------+---------------+");
printf("\n| %12d  | %12s  | %6d        | %.3lf         |",stud[res].rollNo,stud[res].name,stud[res].age,stud[res].marks);
printf("\n+---------------+---------------+---------------+---------------+");

}

void deleteData( Student* stud, int res, int ctr){
for(int i=res;i<ctr;i++){
    stud[i]=stud[i+1];
}
}
void sort(Student* stud,int ctr){
    int ch;
    printf("\n1.sort by marks \n2.sort bye age\n");
    scanf("%d",&ch);
    if(ch==1){
        sortByMarks(stud, ctr);
    }else if(ch==2){
        sortByAge(stud,ctr);
    }
}
void sortByMarks( Student *stud, int ctr){
    for(int i=0;i<ctr;i++){
        for(int j=i+1;j<ctr;j++){
            if(stud[i].marks<stud[j].marks){
                Student temp=stud[i];
                stud[i]=stud[j];
                stud[j]=temp;
            }
        }
    }
    display(stud,ctr);
}
void sortByAge(Student* stud,int ctr){
for(int i=0;i<ctr;i++){
        for(int j=i+1;j<ctr;j++){
            if(stud[i].age<stud[j].age){
                Student temp=stud[i];
                stud[i]=stud[j];
                stud[j]=temp;
            }
        }
    }
    display(stud,ctr);
}