
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// typedef struct BookManagement
// {
//     char bookName[50];
//     char authorName[50];
//     int bookId;
//     double rating;
//     int publishedIn;
//     double price;
// } BookManagement;

// int hardCodeValue(BookManagement *,int);
// int storeData(BookManagement *, int );
// void display(BookManagement *, int );
// void display1(BookManagement *, int );
// void searchData(BookManagement *, int );
// int searchByBookName(BookManagement *, int , char *);
// int searchByBookId(BookManagement *, int , int );
// int searchByAuthorName(BookManagement *, int , char *;);
// void deleteData( BookManagement* , int , int );
// void updateData(BookManagement* , int  );
// void updateByBookRating(BookManagement*  ,double ,int);
// void updateByBookPrice(BookManagement*  ,double,int );
// void sortData(BookManagement *, int );
// void sortByRating(BookManagement *, int );
// void sortByPrice(BookManagement *, int );

// void main()
// {
//     int choice, size = 10, ctr = 0;
//     BookManagement *book = (BookManagement *)malloc(sizeof(BookManagement) * size);
//     ctr=hardCodeValue(book,ctr);
//     do
//     {
//     printf("\n 1. add data\n 2. display data\n 3. serach data\n 4. delete data\n 5. update data\n 6. sort data\n 0. to exit\n Enter choice:");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//         {
//             if (ctr != size)
//             {
//                 int res=storeData(book, ctr);
//                 //ctr++;
//                 if(res==1){
//                     printf("\n book id allready exist");
//                 }else{
//                     ctr++;
//                     printf("\n book added successfully");
//                 }
//             }
//             else
//             {
//                 printf("\n insufficient memory");
//             }
//             break;
//         }
//         case 2:
//         {
//             if (ctr == 0)
//             {
//                 printf("\n no data present!!");
//             }
//             else
//             {
//                 display(book, ctr);
//             }
//             break;
//         }
//         case 3:
//         {
//             searchData(book, ctr);
//             break;
//         }
//         case 4:
//         {
//             int rn;
//             printf("enter Book Id:");
//             scanf("%d", &rn);
//             int res = searchByBookId(book, ctr, rn);
//             if (res == -1)
//             {
//                 printf("\n result not found");
//             }
//             else
//             {
//                 deleteData(book,res,ctr);
//                 ctr--;
//              printf("\n book removed successfully!!!!");
//             }
//             break;
//         }
//         case 5:
//         {
//             int rn;
//             printf("enter Book Id:");
//             scanf("%d", &rn);
//             int res = searchByBookId(book, ctr, rn);
//             if (res == -1)
//             {
//                 printf("\n result not found");
//             }
//             else
//             {
//                 updateData(book,ctr);
//             }
//             break;
//         }
//         case 6:
//         {
//                 sortData(book, ctr);
//                 break;
//         }
//         } 
//     } while (choice != 0);
// }
// int hardCodeValue(BookManagement *book,int ctr){
// BookManagement b;
// strcpy(b.bookName,"Harry Potter");
// strcpy(b.authorName,"J.K.Rowling");
// b.bookId=101;
// b.rating=9.9;
// b.price=500;
// b.publishedIn=1997;
// book[ctr++]=b;

// strcpy(b.bookName,"Shyamchi Aai");
// strcpy(b.authorName,"Sane Guruji");
// b.bookId=102;
// b.rating=8.9;
// b.price=300;
// b.publishedIn=1936;
// book[ctr++]=b;

// strcpy(b.bookName,"Manu Baba");
// strcpy(b.authorName,"Sane Guruji");
// b.bookId=103;
// b.rating=7.8;
// b.price=800;
// b.publishedIn=1941;
// book[ctr++]=b;

// strcpy(b.bookName,"The Hobbit");
// strcpy(b.authorName,"J.R.R.Talkien");
// b.bookId=104;
// b.rating=7.6;
// b.price=480;
// b.publishedIn=1937;
// book[ctr++]=b;

// strcpy(b.bookName,"The Alchemist");
// strcpy(b.authorName,"Paulo Coelho");
// b.bookId=105;
// b.rating=6.7;
// b.price=890;
// b.publishedIn=1988;
// book[ctr++]=b;

// return ctr;
// }

// int storeData(BookManagement *book, int ctr)
// {
//     BookManagement b;
    
//     printf("\n enter the details of book:");
//     printf("\n enter book Id:");
//     scanf("%d",&b.bookId);
//     int i;
//     for(i=0;i<ctr;i++){
//     if(b.bookId==book[i].bookId){
//         return 1;
//         }
//     }
//     printf("\n enter name book:");
//     fflush(stdin);
//     gets(b.bookName);
//     printf("\n enter name of author:");
//     fflush(stdin);
//     gets(b.authorName);
//     // printf("\n enter book Id:");
//     // scanf("%d", &b.bookId);
//     printf("\n enter rating of book:");
//     scanf("%lf", &b.rating);
//       printf("\n enter price of book:");
//     scanf("%lf", &b.price);
//     printf("\n enter published year of book:");
//     scanf("%d", &b.publishedIn);
//     book[ctr] = b;
// }

// void display(BookManagement *book, int ctr)
// {
//     int i;
// printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
// printf("\n|    Book Name   |     Author Name     |    Book Id       |       Rating   |  Price         | Published Year |\n");
// printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//     for (i = 0; i < ctr; i++)
//     {
//         // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[i].rollNo, stud[i].name, stud[i].age, stud[i].marks);
       
//         display1(book,i);
//     }

// }

// void searchData(BookManagement *book, int ctr)
// {
//     int ch, i;
//     printf("\n1. search by Book Id\n2. search by book name\n3. search by author name\n enter your choice:");
//     scanf("%d", &ch);
//     if (ch == 1)
//     {
//         int id;
//         printf("enter book Id:");
//         scanf("%d", &id);
//         int result = searchByBookId(book, ctr, id);
//         if (result == -1)
//         {
//             printf("\n result not found");
//         }
//         else
//         {
//            // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[res].rollNo, stud[res].name, stud[res].age, stud[res].marks);
//             //display1(book,res);

//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//             printf("\n|    Book Name   |     Author Name     |    Book Id       |       Rating   |  Price         | Published Year |\n");
//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//             printf("\n|%15s | %20s|%17d |%16lf| %14lf | %14d |\n",book[result].bookName,book[result].authorName,book[result].bookId,book[result].rating,book[result].price,book[result].publishedIn);
//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//         }
//     }
//     else if (ch == 2)
//     {
//         char nm[20];
//         printf("enter book name:");
//         fflush(stdin);
//         gets(nm);
//         int result = searchByBookName(book, ctr, nm);
//         if (result == -1)
//         {
//             printf("\n result not found");
//         }
//         else
//         {
//            // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[result].rollNo, stud[result].name, stud[result].age, stud[result].marks);
//             //display1(book,result);

//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//             printf("\n|    Book Name   |     Author Name     |    Book Id       |       Rating   |  Price         | Published Year |\n");
//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//             printf("\n|%15s | %20s|%17d |%16lf| %14lf | %14d |\n",book[result].bookName,book[result].authorName,book[result].bookId,book[result].rating,book[result].price,book[result].publishedIn);
//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//         }
//     }
//     else if (ch == 3)
//     {
//         char nma[20];
//         printf("enter author name:");
//         fflush(stdin);
//         gets(nma);
//         int result = searchByAuthorName(book, ctr, nma);
//         if (result == -1)
//         {
//             printf("\n result not found");
//         }
//         else
//         {
//            // printf("\nroll no %d of student name %s having age %d got marks %lf", stud[result].rollNo, stud[result].name, stud[result].age, stud[result].marks);
//              //display1(book,result);

//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//             printf("\n|    Book Name   |     Author Name     |    Book Id       |       Rating   |  Price         | Published Year |\n");
//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
//             printf("\n|%15s | %20s|%17d |%16lf| %14lf | %14d |\n",book[result].bookName,book[result].authorName,book[result].bookId,book[result].rating,book[result].price,book[result].publishedIn);
//             printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");

           
//         }
//     }
// }
// int searchByBookId(BookManagement *book, int ctr, int id)
// {
//     //int flag=0;
//     for (int i = 0; i < ctr; i++)
//     {
//         if (book[i].bookId == id)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// int searchByBookName(BookManagement *book, int ctr, char *nm)
// {
//     //int flag=0;
//     for (int i = 0; i < ctr; i++)
//     {
//         if (strcasecmp(book[i].bookName, nm) == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }
// int searchByAuthorName(BookManagement *book, int ctr, char *nma)
// {
//     int flag=0;
//     for (int i = 0; i < ctr; i++)
//     {
//         if (strcasecmp(book[i].authorName, nma) == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// void display1(BookManagement *book, int res){
// // printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");
// // printf("\n|    Book Name   |     Author Name     |    Book Id       |       Rating   |  Price         | Published Year |\n");
// // printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");


// printf("\n|%15s | %20s|%17d |%16lf| %14lf | %14d |\n",book[res].bookName,book[res].authorName,book[res].bookId,book[res].rating,book[res].price,book[res].publishedIn);
// printf("\n+----------------+---------------------+------------------+----------------+----------------+----------------+\n");

// }

// void deleteData( BookManagement* book, int res, int ctr){
// for(int i=res;i<ctr;i++){
//     book[i]=book[i+1];
// }
// }

//  void updateData(BookManagement *book, int ctr) {
//     int ch;
//     int bookId;
   
//   printf("\n enter book id:");
//   scanf("%d",&bookId);
//    int res=searchByBookId(book,ctr,bookId);
//   if( res==-1){
//   printf("\n not found");
//   }else{
//   printf("\n1. Update rating\n2. Update price\nEnter your choice: ");
//     scanf("%d", &ch);
//     if(ch==1){
//             double bookrating;
//             printf("Enter new rating: ");
//             scanf("%lf", &bookrating);
//             updateByBookRating(book, bookrating,res);
        
//     }else if(ch==2){
//             double bookprice;
//             printf("Enter new price: ");
//             scanf("%lf", &bookprice);
//             updateByBookPrice(book, bookprice,res);
            
//     }
// }
   
// }

// void updateByBookRating(BookManagement *book, double bookrating,int res) {
//     book[res].rating = bookrating;
//     printf("\n book rating updated successfully!!!!");

// }

// void updateByBookPrice(BookManagement *book, double bookprice,int res) {
//     book[res].price = bookprice;
//     printf("\n book price updated successfully!!!!");
// }

//   void sortData(BookManagement *book, int ctr){
//   int ch;
//     printf("\n1. sort by book rating\n2. sort by book price\n enter your choice:");
//     scanf("%d", &ch);
//     if (ch == 1)
//     {
//         sortByRating(book, ctr);
//     }
//     else if (ch == 2)
//     {
//            sortByPrice(book, ctr);
//     }
//  }

// void sortByRating(BookManagement *book,int ctr) {
//     for(int i=0;i<ctr;i++){
//         for(int j=i+1;j<ctr;j++){
//             if(book[i].rating<book[j].rating){
//                 BookManagement temp=book[i];
//                 book[i]=book[j];
//                 book[j]=temp;
//             }
//         }
//     }
//     display(book,ctr);
// }

// void sortByPrice(BookManagement *book,int ctr) {
//      for(int i=0;i<ctr;i++){
//         for(int j=i+1;j<ctr;j++){
//             if(book[i].price<book[j].price){
//                 BookManagement temp=book[i];
//                 book[i]=book[j];
//                 book[j]=temp;
//             }
//         }
//     }
//     display(book,ctr);
// }


// #include <stdio.h>
// #include <string.h>

// #define MAX_PLAYERS 100

// struct Player {
//     int jerseyNumber;
//     char name[100];
//     int runs;
//     int wickets;
//     int matchesPlayed;
// };

// struct Team {
//     struct Player players[MAX_PLAYERS];
//     int count;
// };

// // Function prototypes
// void addPlayer(struct Team *team, int jerseyNumber, char name[], int runs, int wickets, int matchesPlayed);
// void removePlayer(struct Team *team, int jerseyNumber);
// struct Player* searchPlayerByNumber(struct Team *team, int jerseyNumber);
// struct Player* searchPlayerByName(struct Team *team, char name[]);
// void updatePlayer(struct Team *team, int jerseyNumber, int runs, int wickets, int matchesPlayed);
// void displaySortedPlayersByRuns(struct Team *team);
// void displaySortedPlayersByWickets(struct Team *team);
// void displayAllPlayers(struct Team *team);

// int main() {
//     struct Team team = { .count = 0 };

//     // Add some initial players
//     addPlayer(&team, 10, "Player1", 500, 20, 30);
//     addPlayer(&team, 7, "Player2", 300, 15, 25);
//     addPlayer(&team, 18, "Player3", 700, 25, 35);

//     // Display all players
//     printf("All Players:\n");
//     displayAllPlayers(&team);

//     // Remove a player
//     removePlayer(&team, 7);

//     // Search a player by number
//     struct Player* player = searchPlayerByNumber(&team, 10);
//     if (player != NULL) {
//         printf("\nPlayer found by number:\n");
//         printf("Jersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches Played: %d\n", player->jerseyNumber, player->name, player->runs, player->wickets, player->matchesPlayed);
//     }

//     // Search a player by name
//     player = searchPlayerByName(&team, "Player3");
//     if (player != NULL) {
//         printf("\nPlayer found by name:\n");
//         printf("Jersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches Played: %d\n", player->jerseyNumber, player->name, player->runs, player->wickets, player->matchesPlayed);
//     }

//     // Update player data
//     updatePlayer(&team, 10, 550, 22, 32);

//     // Display sorted players by runs
//     printf("\nSorted players by runs:\n");
//     displaySortedPlayersByRuns(&team);

//     // Display sorted players by wickets
//     printf("\nSorted players by wickets:\n");
//     displaySortedPlayersByWickets(&team);

//     return 0;
// }

// // Function to add a player
// void addPlayer(struct Team *team, int jerseyNumber, char name[], int runs, int wickets, int matchesPlayed) {
//     if (team->count < MAX_PLAYERS) {
//         struct Player player;
//         player.jerseyNumber = jerseyNumber;
//         strcpy(player.name, name);
//         player.runs = runs;
//         player.wickets = wickets;
//         player.matchesPlayed = matchesPlayed;
//         team->players[team->count++] = player;
//     } else {
//         printf("Team is full!\n");
//     }
// }

// // Function to remove a player
// void removePlayer(struct Team *team, int jerseyNumber) {
//     for (int i = 0; i < team->count; i++) {
//         if (team->players[i].jerseyNumber == jerseyNumber) {
//             for (int j = i; j < team->count - 1; j++) {
//                 team->players[j] = team->players[j + 1];
//             }
//             team->count--;
//             printf("Player with Jersey Number %d removed.\n", jerseyNumber);
//             return;
//         }
//     }
//     printf("Player with Jersey Number %d not found.\n", jerseyNumber);
// }

// // Function to search a player by number
// struct Player* searchPlayerByNumber(struct Team *team, int jerseyNumber) {
//     for (int i = 0; i < team->count; i++) {
//         if (team->players[i].jerseyNumber == jerseyNumber) {
//             return &team->players[i];
//         }
//     }
//     return NULL;
// }

// // Function to search a player by name
// struct Player* searchPlayerByName(struct Team *team, char name[]) {
//     for (int i = 0; i < team->count; i++) {
//         if (strcmp(team->players[i].name, name) == 0) {
//             return &team->players[i];
//         }
//     }
//     return NULL;
// }

// // Function to update a player's runs, wickets, and matches played
// void updatePlayer(struct Team *team, int jerseyNumber, int runs, int wickets, int matchesPlayed) {
//     struct Player *player = searchPlayerByNumber(team, jerseyNumber);
//     if (player != NULL) {
//         player->runs = runs;
//         player->wickets = wickets;
//         player->matchesPlayed = matchesPlayed;
//         printf("Player with Jersey Number %d updated.\n", jerseyNumber);
//     } else {
//         printf("Player with Jersey Number %d not found.\n", jerseyNumber);
//     }
// }

// // Function to display sorted players by runs
// void displaySortedPlayersByRuns(struct Team *team) {
//     struct Player temp;
//     for (int i = 0; i < team->count - 1; i++) {
//         for (int j = 0; j < team->count - i - 1; j++) {
//             if (team->players[j].runs < team->players[j + 1].runs) {
//                 temp = team->players[j];
//                 team->players[j] = team->players[j + 1];
//                 team->players[j + 1] = temp;
//             }
//         }
//     }
//     for (int i = 0; i < team->count; i++) {
//         printf("Jersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches Played: %d\n", team->players[i].jerseyNumber, team->players[i].name, team->players[i].runs, team->players[i].wickets, team->players[i].matchesPlayed);
//     }
// }

// // Function to display sorted players by wickets
// void displaySortedPlayersByWickets(struct Team *team) {
//     struct Player temp;
//     for (int i = 0; i < team->count - 1; i++) {
//         for (int j = 0; j < team->count - i - 1; j++) {
//             if (team->players[j].wickets < team->players[j + 1].wickets) {
//                 temp = team->players[j];
//                 team->players[j] = team->players[j + 1];
//                 team->players[j + 1] = temp;
//             }
//         }
//     }
//     for (int i = 0; i < team->count; i++) {
//         printf("Jersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches Played: %d\n", team->players[i].jerseyNumber, team->players[i].name, team->players[i].runs, team->players[i].wickets, team->players[i].matchesPlayed);
//     }
// }

// // Function to display all players
// void displayAllPlayers(struct Team *team) {
//     for (int i = 0; i < team->count; i++) {
//         printf("Jersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches Played: %d\n", team->players[i].jerseyNumber, team->players[i].name, team->players[i].runs, team->players[i].wickets, team->players[i].matchesPlayed);
//     }
// }