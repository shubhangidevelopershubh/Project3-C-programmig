

/*book management system  
  It provides functionality to manage a collection of books, including adding, 
  displaying, searching, deleting, updating, and sorting books. */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
1.The #include statements include the necessary standard libraries for input/output, string manipulation, 
  and memory allocation.
  
2.The Book structure defines the attributes of a book: id, rating, name, author, category, and price.*/

/*Using the typedef keyword allows us to define a new type name for a structure, 
which can make our code more readable and easier to use.*/
//Book structure to hold the details of each book:
typedef struct Book {
 int id, rating;
 char name[30], author[30], category[50];
 double price;
}Book;

//Core Functions used in the program. 
//This helps the compiler understand the function signatures before their actual definitions.
int get(Book*);
int add(Book* , int );
void display(Book* , int );
void printTitle();
void print(Book*, int);
void search(Book* , int );
int searchByID(Book* ,int ,int );
void searchByName(Book* , int , char* );
void showByAuthor(Book* , int , char* );
void showByCategory(Book* , int , char* );
void deleteBook(Book*, int, int);
void update(Book*, int);
void updatePrice(Book* b, int ,double );
void updateRating(Book* , int ,int );
void sort(Book* , int );
void sortByPrice(Book* , Book* , int );
void sortByRating(Book* , Book* , int );

/*
The main function provides a menu-driven interface for the user to interact with the book management system:

1. The main function initializes the program, preloads some book data using the get function,
   and then enters a loop where it displays a menu and processes user input.
   
2. The user can choose to add, display, search, delete, update, sort, or exit.

3. The program uses a switch statement to handle different user choices.
*/
void main()
{
 int ch, size = 10, count= 0;
 Book book[size] ;
 count = get(book);
 
 do{
  printf("\n\n 1. Add \n 2. Display \n 3. Search \n 4. Delete \n 5. Update \n 6. Sort \n 0. Exit ");
  printf("\n\n Enter - ");
  scanf("%d",&ch);
  //using switch our code becomes more readable
  switch(ch){
   case 1 : {
    if(count != size)
    {
     int res = add(book, count);
     /*Array don't have boundarie checking like string having null character to represent the end 
      of a string so we need to pass the size of an array to avoid unauthorized access*/
     if(res == 1)
     {
      printf("\n\n Book ID Already Exists");
     }
     else
     {
      count++;
      printf("\n\n Book Added Successfully !!!");
     }
    }
    else
     printf("\n\n Insufficient Memory...");
    break;
   }
   case 2 : {
    display(book, count);
    break;
   }
   case 3 : {
    search(book, count);
    break;
   }
   case 4 : {
    int id;
    printf("\n\n Enter the ID of Book to Delete - ");
    scanf("%d",&id);
    int res = searchByID(book, count, id);
    if(res == -1)
    {
     printf("\n\n No Such Book Found");
    }
    else
    {
     deleteBook(book, count, res);
     count--;
     printf("\n\n Book Removed Successfully !!!");
    }
    break;
   }
   case 5 : {
    update(book, count);
    break;
   }
   case 6 : {
    sort(book, count);
    printf("\n\n Books Sorted Successfully !!!");
    break;
   }
   case 0 : {
    printf("\n\n Thank Uhh...!!!");
    break;
   }
   default : {
    printf("\n\n Invalid Choice !!!");
   }
  }
 }while(ch != 0);
}

//The get function preloads four books with predefined attributes and returns the count of preloaded books.
int get(Book* book)
{
 book[0].id = 100; 
 strcpy(book[0].name,"1984");// 1984 is store in dummy which is char array and book[0].name is also a char array
        // we can't assign an array to another array directly i.e we copy it.
strcpy(book[0].author,"George Orwell");
 strcpy(book[0].category,"Science Fiction");
 book[0].price = 159;
 book[0].rating = 4;
 
 book[1].id = 101; 
 strcpy(book[1].name,"Harry Potter");
 strcpy(book[1].author,"J.K.Rowling");
 strcpy(book[1].category,"Fantacy");
 book[1].price = 142;
 book[1].rating = 5;
 
 book[2].id = 102; 
 strcpy(book[2].name,"Gone Girl");
 strcpy(book[2].author,"Gillian Flynn");
 strcpy(book[2].category,"Mystery");
 book[2].price = 264;
 book[2].rating = 5;
 
 book[3].id = 103; 
 strcpy(book[3].name,"The Hobbit");
 strcpy(book[3].author,"J.R.R.Tolkein");
 strcpy(book[3].category,"Adventure");
 book[3].price = 202;
 book[3].rating = 3;
 
 return 4;
}

/*
1. The add function adds a new book to the collection.

2. It first checks if the book ID already exists.

3. If not, it ask the user for book details and adds the book to the array.*/
int add(Book* book, int count)
{
 Book b;
 
 printf("\n\n Enter The Details Of the Book \n");
 printf(" Id       -  ");
 scanf("%d",&b.id);
 int i ;
 for(i = 0; i < count; i++)
 {
  if(b.id == book[i].id)
  {
   return 1;
  }
 }
 printf(" Name     -  ");
 fflush(stdin);
 gets(b.name);
 printf(" Author   -  ");
 gets(b.author);
 printf(" Category -  ");
 gets(b.category);
 printf(" Price    -  ");
 scanf("%lf",&b.price);
 printf(" Rating   -  ");
 scanf("%d",&b.rating);
   
 book[count] = b;
 return 0;
}

//The display function prints all the books in a tabular format.
void display(Book* b, int count)
{
 int i;
 printf("\n\n Book Details");
 printf("\n +--------+--------------------+--------------------+--------------------+----------+----------+");
 printf("\n |   ID   |        Name        |       Author       |       Category     |   Price  |  Rating  |");
 printf("\n +--------+--------------------+--------------------+--------------------+----------+----------+");
 for(i = 0; i < count; i++)
 {
  printf("\n | %6d | %18s | %18s | %18s | %3.2lf   |%10d|",b[i].id,b[i].name,b[i].author,b[i].category,b[i].price,b[i].rating);
  printf("\n +--------+--------------------+--------------------+--------------------+----------+----------+");
 }
}

/*
1. 'printTitle' prints the header for the book display table.

2. 'print' prints the details of a single book.*/
void printTitle()
{
 printf("\n\n Book Details");
 printf("\n +--------+--------------------+--------------------+--------------------+----------+----------+");
 printf("\n |   ID   |        Name        |       Author       |       Category     |   Price  |  Rating  |");
 printf("\n +--------+--------------------+--------------------+--------------------+----------+----------+");
}
void print(Book* b, int i)
{
 printf("\n | %6d | %18s | %18s | %18s |  %3.2lf  |%10d|",b[i].id,b[i].name,b[i].author,b[i].category,b[i].price,b[i].rating);
 printf("\n +--------+--------------------+--------------------+--------------------+-----------+---------+");
}

/*
1. The search function presents the user with options to search for a book by ID, name, author, or category.
   It then prompts the user to choose the type of search.
2. If the user chooses to search by ID, the program prompts the user to enter the ID of the 
   book they are searching for.
3. It then calls the searchByID function to find the book with the specified ID.
4. If the book is found (res != -1), it prints the details of the book using the printTitle function to print 
   the table header and the print function to print the book details.
5. If the book is not found (res == -1), it displays a message indicating that no such book was found.
6. If the user chooses to search by name, author, or category, the program prompts the user to enter the
   corresponding name or category.
7. Then, it calls the respective search functions 
   (searchByName, showByAuthor, showByCategory) to find and display the matching books. */
void search(Book* b, int count)
{
 int ch,no;
 printf("\n\n 1. Search By Id \t 2. Search By Name \t 3. Search By Author \t 4. Search By Category ");
 printf("\n\n Search Book By - ");
 if(scanf("%d",&ch))
 {
  if(ch == 1)
  {
   int no;
   printf("\n\n Enter the ID - "); 
   scanf("%d",&no);
   int res = searchByID(b,count,no);
   if(res == -1)
    printf("\n\n No such Book Found...!!!");
   else
   {
    printTitle();
    print(b, res);
   }
  }
  else if(ch == 2)
  {
   char nm[20];
   printf("\n\n Enter the Book Name - ");
   fflush(stdin);
   gets(nm);
   searchByName(b,count,nm);
  }
  else if(ch == 3)
  {
   char nm[20];
   printf("\n\n Enter the Author Name - ");
   fflush(stdin);
   gets(nm);
   showByAuthor(b,count,nm);
  }
  else if(ch == 4)
  {
   char cat[20];
   printf("\n\n Enter the Category - ");
   fflush(stdin);
   gets(cat);
   showByCategory(b,count,cat);
  }
  else
   printf("\n Try Again !!!");
 }
 else
 {
  printf("\n\n Invalid Input");
  fflush(stdin);
 } 
}

/*
1. These functions perform specific searches based on ID, name, author, or category.

2. They iterate through the book array and check if the search criteria match any book.

3. If a matching book is found, it prints its details using the printTitle and print functions. 

4. If no match is found, it displays a message. */
int searchByID(Book* b,int count,int no)
{
 int i;
 for(i = 0; i < count; i++) 
  if(b[i].id == no)
   return i;
 return -1;
}
void searchByName(Book* b, int count, char* nm)
{
 int i, flag = 0;
 printTitle();
 for(i = 0; i < count; i++)
 {
  if(strstr(b[i].name, nm) != NULL)
  {
   print(b,i);
   flag++;
  }
 }
 if(flag == 0)
 {
  printf("\n\n No such Book Found...!!!");
 }
}
void showByAuthor(Book* b, int count, char* nm)
{
 int i, flag = 0;
 printTitle();
 for(i = 0; i < count; i++)
 {
  if(strstr(b[i].author, nm) != NULL)
  {
   print(b,i);
   flag++;
  }
 }
 if(flag == 0)
 {
  printf("\n\n No such Book Found...!!!");
 }
}
void showByCategory(Book* b, int count, char* cat)
{
 int i, flag = 0;
 printTitle();
 for(i = 0; i < count; i++)
 {
  if(strstr(b[i].category, cat) != NULL)
  {
   print(b,i);
   flag++;
  }
 }
 if(flag == 0)
 {
  printf("\n\n No such Book Found...!!!");
 }
}

/*The deleteBook function removes a book from the array by shifting all subsequent books 
  to fill the gap created by the deleted book.*/
void deleteBook(Book* b, int count, int res)
{
 int i;
 for(i = res; i < count; i++)
 {
  b[i] = b[i + 1];
 }
}

/*
The update function allows the user to update the price or rating of a book.
It prompts the user to enter the book ID for the book they want to update.
If the book is found, it prompts the user to choose whether to update the price or rating.
It then updates the corresponding attribute and displays a success message.*/
void update(Book* b, int count)
{
 int ch, id;
 printf("\n\n Enter the Book ID to Update -");
 scanf("%d",&id);
 int res = searchByID(b,count,id);
 if(res == -1)
 {
  printf("\n\n No such Book Found...!!!");
 }
 else
 {
  printf("\n\n UPDATE... - ");
  printf("\n\n 1. Update Price \t 2. Update Rating");
  scanf("\n%d",&ch);
  if(ch == 1)
  {
   double value;
   printf("\n\n Enter the New Price - ");
   scanf("%lf",&value);
   updatePrice(b,res,value);
  }
  else if(ch == 2)
  {
   int rat;
   printf("\n\n Enter the Rating - ");
   scanf("%d",&rat);
   updateRating(b,res,rat);
  }
  printf("\n\n Updated Successfully !!!");
 }
}
void updatePrice(Book* b, int res,double value)
{
 b[res].price = value;
}
void updateRating(Book* b, int res, int rat)
{
 b[res].rating = rat;
}

//The sort function allows the user to sort books based on either price or rating.
void sort(Book* b, int count)
{
 int i, ch;
 /*It dynamically allocates memory for an array sort of type Book to store the sorted books.
It then copies the contents of the original book array b into the sort array
   to preserve the original data.*/
 Book* sort = (Book*)malloc(count * sizeof(Book));
 for ( i = 0; i < count; i++) 
 {
  sort[i] = b[i];
 }
 
 printf("\n\n Sort Book By - \n 1. Price \t 2. Rating ");
 scanf("%d",&ch);
 if(ch == 1)
 {
  sortByPrice(b,sort,count);
  display(sort,count);
  free(sort);
 }
 else if(ch == 2)
 {
  sortByRating(b,sort,count);
  display(sort,count);
  free(sort);
 }
 else
 {
  printf("\n\n Invalid Choice !!!");
 }
}
/*If the user chooses to sort by price (ch == 1) or rating (ch == 2), 
  it calls the corresponding sorting function: sortByPrice or sortByRating.
After sorting, it displays the sorted books using the display function.
Finally, it frees the dynamically allocated memory for the sort array to prevent memory leaks.*/
void sortByPrice(Book* b, Book* sort,int count)
{
 int ch;
 printf("\n\n Sort Books in \n 1. Ascending Order \t 2. Descending Order");
 scanf("%d",&ch);
 if(ch == 1)
 {
  int i, j;
  for(i = 0; i < count; i++)
  {
   for(j = i+1; j < count; j++)
   {
    if(sort[i].price < sort[j].price)
    {
     Book temp = sort[i];
     sort[i] = sort[j];
     sort[j] = temp;
    }
   }
  } 
 }
 else if(ch == 2)
 {
  int i, j;
  for(i = 0; i < count; i++)
  {
   for(j = i+1; j < count; j++)
   {
    if(sort[i].price > sort[j].price)
    {
     Book temp = sort[i];
     sort[i] = sort[j];
     sort[j] = temp;
    }
   }
  }
 }
}
void sortByRating(Book* b, Book* sort, int count)
{
 int ch;
 printf("\n\n Sort Books in \n 1. Ascending Order \t 2. Descending Order");
 scanf("%d",&ch);
 if(ch == 1)
 {
  int i, j;
  for(i = 0; i < count; i++)
  {
   for(j = i+1; j < count; j++)
   {
    if(sort[i].rating < sort[j].rating)
    {
     Book temp = sort[i];
     sort[i] = sort[j];
     sort[j] = temp;
    }
   }
  } 
 }
 else if(ch == 2)
 {
  int i, j;
  for(i = 0; i < count; i++)
  {
   for(j = i+1; j < count; j++)
   {
    if(sort[i].rating > sort[j].rating)
    {
     Book temp = sort[i];
     sort[i] = sort[j];
     sort[j] = temp;
    }
   }
  }
 }
 
}
/*
1. When you dynamically allocate memory using functions like malloc, calloc, or realloc , 
   you're essentially requesting memory from the heap at runtime. 
   
2. Once you're done using this memory, it's important to release it back to the system to avoid memory leaks.

3. A memory leak occurs when memory that's been allocated dynamically isn't properly deallocated 
   or released when it's no longer needed. 
   
4. Over time, this can lead to your program consuming more and more memory unnecessarily, 
   potentially causing performance issues or crashes.
   
5. By doing this, you're telling the system that you no longer need the memory allocated for the sort array, 
   allowing it to be reused for other purposes. 
   
6. This prevents memory leaks and helps keep your program's memory usage efficient.*/