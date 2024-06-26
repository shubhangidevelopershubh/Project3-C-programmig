

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Player 
{
  int jerseyNo, age, runs, wickets;
  char name[80];
  int matches;
} Player;

void storeData(Player*,int);
void displayData(Player*,int);
int search(Player*,int);
int searchByjerseyNo(Player*,int,int);
int searchByName(Player*,int,char*);
void deleteData(Player*,int,int);
void updateData(Player*,int,int);
void sortData(Player*,int);
void noOfMatches(Player*,int);
void sortByRuns(Player*,int);
void sortByWicket(Player*,int);
void ascendingOrder(Player*,int);
void ascendingOrder1(Player*,int);
void ascendingOrder2(Player* play,int ctr);
void descendingOrder(Player*,int);
void descendingOrder1(Player*,int);
void descendingOrder2(Player*,int);
int hardCodeValue(Player*,int);

void main() 
{
  int choice, size = 11, ctr = 0;
  Player* play = (Player*)malloc(sizeof(Player)*size);
  ctr = hardCodeValue(play,ctr);
  do {
    printf("\n1.Add Data \n2.Display Data \n3.Search Data \n4.Delete Data \n5.Update Data \n6.sort Data \n0.to exit\n");
    printf("\n Enter your choice :- ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: {
        if(ctr!=size)
    {
          storeData(play,ctr);
          ctr++;
        }
    else
    {
      char x;
          printf("\n Insufficient memory");
          printf("\nDo you want to increase memory ?(y/n)");
          fflush(stdin);
          scanf("%c",&x);
          if(x == 'y')
          {
            size = size + 2;
            play = (Player *) realloc(play , size * sizeof(Player));
            storeData(play,ctr);
            ctr++;
      }
        }
        break;
      }
      case 2: {
        if(ctr==0)
    {
          printf("\n There is no data in player's database.\n");
        } 
    else 
    {
          displayData(play,ctr);
        }
        break;
      }
      case 3: {
        search(play,ctr);
        break;
      }
      case 4: {
        int jn;
        printf("Enter the jersy No :-");
        scanf("%d",&jn);
        int res=searchByjerseyNo(play,ctr,jn);
        if(res == -1) 
    {
          printf("\n player  not found");
        } 
    else 
    {
          deleteData(play,res,ctr);
          ctr--;
          printf("\n Data Deleted successsfully");
          break;
        }
        case 5: 
    {
          int jn;
          printf("Enter the jersy No :- ");
          scanf("%d",&jn);
          int res=searchByjerseyNo(play,ctr,jn);
          if(res==-1) 
      {
            printf("\n Data is Not Found!!");
            break;
          } 
      else
      {
            updateData(play,res,ctr);
            printf("\n updated Sucessfully");
            break;
          }

        }
        case 6: 
    {
          sortData(play,ctr);
          break;
        }
        case 0: 
    {
          printf("\n Thank You");
          break;
        }
        default:
          printf("Invalid choice");
      }
    }
  } 
  while(choice!=0);
}


int hardCodeValue(Player*play,int ctr) 
{
  Player p;
  p.jerseyNo=8;
  strcpy(p.name,"Sachin Tendulkar");
  p.runs=14000;
  p.age=31;
  p.wickets=159;
  p.matches=420;
  play[ctr++]=p;

  p.jerseyNo = 6;
  strcpy(p.name,"Virender Sehwag");
  p.runs=2500;
  p.age=36;
  p.wickets=140;
  p.matches=600;
  play[ctr++]=p;

  p.jerseyNo=3;
  strcpy(p.name,"Harbhajan singh");
  p.runs=1500;
  p.age=33;
  p.wickets=375;
  p.matches=300;
  play[ctr++]=p;

  p.jerseyNo=1;
  strcpy(p.name,"Ravindra Jadeja");
  p.runs=2000;
  p.age=29;
  p.wickets=250;
  p.matches=900;
  play[ctr++]=p;

  p.jerseyNo=7;
  strcpy(p.name,"Viv Richards");
  p.runs=6000;
  p.age=36;
  p.wickets=200;
  p.matches=600;
  play[ctr++]=p;

  p.jerseyNo=5;
  strcpy(p.name,"VVS Laxman");
  p.runs=650;
  p.age=26;
  p.wickets=220;
  p.matches=980;
  play[ctr++]=p;

  p.jerseyNo=8;
  strcpy(p.name,"Shikhar dhawan");
  p.runs=1500;
  p.age=33;
  p.wickets=170;
  p.matches=400;
  play[ctr++]=p;

  p.jerseyNo=15;
  strcpy(p.name,"kapil dev");
  p.runs=900;
  p.age=29;
  p.wickets=150;
  p.matches=600;
  play[ctr++]=p;
p.jerseyNo=45;
  strcpy(p.name,"Rohit Sharma");
  p.runs=14899;
  p.age=36;
  p.wickets=89;
  p.matches=306;
  play[ctr++]=p;
  return ctr;
}

void storeData(Player* play,int ctr) 
{
  Player p;
  printf("\n Enter the jersy no of player :- ");
  scanf("%d",&p.jerseyNo);
  printf("\n Enter the Name of player :-");
  fflush(stdin);
  gets(p.name);
  printf("\n Enter the age of player :- ");
  scanf("%d",&p.age);
  printf("\n Enter the runs of player :-");
  scanf("%d",&p.runs);
  printf("\n Enter the No of wickets of player :- ");
  scanf("%d",&p.wickets);
  printf("\n Enter the No of matches of player :-");
  scanf("%d",&p.matches);

  play[ctr]=p;
}

void displayData(Player*play,int ctr)
{
  printf("\n+--------------+-----------------+-------------+-------------+-------------+-------------+\n");
  printf("\n|  jersey No   |  Name           |  Age        |  Runs       |  Wickets    | Matches     |\n");
  printf("\n+--------------+-----------------+-------------+-------------+-------------+-------------+\n");
  int i;
  for(i=0; i<ctr; i++) 
  {
    printf("\n| %11d | %15s | %11d | %12d| %11d |%11d  |\n",play[i].jerseyNo,play[i].name,play[i].age,play[i].runs,play[i].wickets,play[i].matches);
    printf("\n+-------------+-----------------+-------------+-------------+-------------+-------------+\n");
  }
}

int search(Player*play,int ctr ) 
{
  int ch;
  printf("\n 1.search by jersy No \n 2.search by name\nEnter your choice:-");
  scanf("%d",&ch);
  if(ch==1) 
  {
    int jn;
    printf("Enter the jersey No :-");
    scanf("%d",&jn);
    int res = searchByjerseyNo(play,ctr,jn);
    if(res ==-1) 
  {
      printf("\n player  not found");
    } 
  else 
  {
      printf("\n+--------------+-----------------+-------------+-------------+-------------+-------------+\n");
      printf("\n|  jersey No   |  Name           |  Age        |  Runs       |  Wickets    |  Matches    |\n");
      printf("\n+--------------+-----------------+-------------+-------------+-------------+-------------+\n");
      printf("\n| %11d | %15s | %11d | %12d| %11d | %11d |\n",play[res].jerseyNo,play[res].name,play[res].age,play[res].runs,play[res].wickets,play[res].matches);
      printf("\n+-------------+-----------------+-------------+-------------+-------------+-------------+\n");
    }
  } 
  else if(ch==2) 
  {
    char nm[20];
    printf("Enter the Name:-");
    fflush(stdin);
    gets(nm);
    int res=searchByName(play,ctr,nm);
    if(res ==-1)
  {
      printf("\n player is not found");
    }
  else {
      printf("\n+--------------+----------------+-------------+-------------+-------------+-------------+\n");
      printf("\n|  jersey No   |  Name          |  Age        |  Runs       |  Wickets    |   Matches   |\n");
      printf("\n+--------------+----------------+-------------+-------------+-------------+-------------+\n");
      printf("\n| %11d | %15s | %11d | %12d| %11d |%11d\n",play[res].jerseyNo,play[res].name,play[res].age,play[res].runs,play[res].wickets,play[res].matches);
      printf("\n+-------------+----------------+-------------+-------------+-------------+-------------+\n");
    }
  }
}

int searchByjerseyNo(Player*play,int ctr,int jn) 
{
  int i;
    for(i=0; i<ctr; i++) 
  {
    if(play[i].jerseyNo==jn) 
  {
      return i;
    }
  }
  return -1;
}

int searchByName(Player*play,int ctr,char*nm) 
{
  int i;
  for(i=0; i<ctr; i++) 
  {
    if(strcasecmp(play[i].name,nm)==0) 
  {
      return i;
    }
  }
  return -1;
}

void deleteData(Player*play,int res,int ctr) 
{
  int i;
    for(i=res; i<ctr; i++) 
  {
      play[i]=play[i+1];
  }
}
void updateData(Player*play,int res,int ctr) 
{
  int choice;
  printf("\n1.Update Runs \n2.Update Wickets \n3.Update number of matches");
  printf("\n Enter the choice of update");
  scanf("%d",&choice);
   if(choice==1) 
    {
      int r;
      printf("\n Enter the updated runs :- ");
      scanf("%d",&r);
      play[res].runs=r;
    }
     else if(choice==2) 
     {
      int w;
      printf("\n Enter the updated wickets :- ");
      scanf("%d",&w);
      play[res].wickets=w;
  } 
  else if(choice==3) 
  {
      int m;
      printf("\n Enter the updated matches :-");
      scanf("%d",&m);
      play[res].matches=m;
    } 
    else 
    {
      printf("\n Invalid choice");
    }
}

void sortData(Player* play,int ctr) 
{
  int ch;
  printf("\n 1. Runs\n  2. Wicket\n  3. No. of Matches\n");
  scanf("%d",&ch);
  if(ch == 1) 
  {
    sortByRuns(play,ctr);
  } 
  else if(ch == 2) 
  {
    sortByWicket(play,ctr);
  }
  else if(ch == 3) 
  {
    noOfMatches(play,ctr);
  }
}

void sortByRuns(Player* play,int ctr) 
{
  int ch;
  printf("\n 1.ascending order \n 2.descending order\n ");
  printf("Enter choice : ");
  scanf("%d",&ch);
  if(ch==1) 
  {
    ascendingOrder(play,ctr);
  } 
  else if(ch==2) 
  {
    descendingOrder(play,ctr);
  } 
  else 
  {
    printf("Invalid Choice!!");
  }
  displayData(play,ctr);
}

void ascendingOrder(Player* play,int ctr) {
  int i;
  for(i=0 ; i<ctr ; i++)
  {
    int j;
    for(j=i+1 ; j<ctr ; j++)
  {
      if(play[i].runs > play[j].runs)
    {
        Player temp = play[i];
        play[i] = play[j];
        play[j] = temp;
      }
    }
  }
}

void descendingOrder(Player* play,int ctr) 
{
  int i;
  for(i=0 ; i<ctr ; i++)
  {
    int j;
    for(j=i+1 ; j<ctr ; j++) 
  {
      if(play[i].runs < play[j].runs) 
    {
        Player temp = play[i];
        play[i] = play[j];
        play[j] = temp;
      }
    }
  }
}

void sortByWicket(Player* play,int ctr)
{
  int ch;
  printf("\n 1.ascending order \n 2.descending order\n ");
  printf("Enter choice : ");
  scanf("%d",&ch);
  if(ch==1)
  {
    ascendingOrder1( play, ctr);
    }
  else if(ch == 2) 
  {
    descendingOrder1(play,ctr);
    }
    else 
  {
    printf("Invalid Choice!!");
    }
    displayData(play,ctr);
}

void ascendingOrder1(Player* play,int ctr) 
{
  int i;
  for(i=0 ; i<ctr ; i++) 
  {
    int j;
    for(j=i+1 ; j<ctr ; j++) 
  {
      if(play[i].wickets > play[j].wickets) 
    {
        Player temp = play[i];
        play[i] = play[j];
        play[j] = temp;
      }
    }
  }
}

void descendingOrder1(Player* play,int ctr) 
{
  int i;
  for(i=0 ; i<ctr ; i++) 
  {
    int j;
    for(j=i+1 ; j<ctr ; j++) 
  {
      if(play[i].wickets < play[j].wickets) 
    {
        Player temp = play[i];
        play[i] = play[j];
        play[j] = temp;
      }
    }
  }
}

void noOfMatches(Player* play,int ctr) 
{  
  int ch;
  printf("\n 1.ascending order \n 2.descending order\n ");
  printf("Enter choice : ");
  scanf("%d",&ch);
  if(ch==1) 
  {
    ascendingOrder2( play, ctr);
  } 
  else if(ch == 2) 
  {
    descendingOrder2(play,ctr);
  }
  else 
  {
    printf("Invalid Choice!!");
  }
  displayData(play,ctr);
}


void ascendingOrder2(Player* play,int ctr) 
{
  int i;
  for(i=0 ; i<ctr ; i++) {
    int j;
    for(j=i+1 ; j<ctr ; j++) {
      if(play[i].matches > play[j].matches) 
    {
        Player temp = play[i];
        play[i] = play[j];
        play[j] = temp;
      }
    }
  }
}


void descendingOrder2(Player* play,int ctr) 
{
  int i;
  for(i=0 ; i<ctr ; i++) 
  {
    int j;
    for(j=i+1 ; j<ctr ; j++) 
  {
      if(play[i].matches < play[j].matches) 
    {
        Player temp = play[i];
        play[i] = play[j];
        play[j] = temp;
      }
    }
  }
}