#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

void heading();
void takePassword();
void loginPassword();
void adminPass();
void userPass();
void mainMenu();
void userMenu();
void addBook();
void viewBook();
void userViewBook();
void searchBook();
void userSearchBook();
void editBook();
void deleteBook();
void help();
void userHelp();
void close();

struct Book_info{

    int id;
    char name[10];
    char author[10];
    int quantity;
    int rack;
};

struct login{
    char fullName[50];
    char email[50];
    char phone[50];
    char username[50];
    char password[50];
};

char generateUserName(char email[50], char username[50]){
    for(int i=0; i<strlen(email); i++){
        if(email[i] == '@') break;
        else username[i] = email[i];
    }
}

struct Book_info a;
struct login l;

FILE *file, *file2, *log;

int d = 1;

int main(void)
{
    system("color 0b");
    loginPassword();
    return 0;
}

void takePassword(char pwd[50]){
    int i;
    char ch;
    while(1){
        ch = getch();
        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b\b");
            }
        }else{
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

void registe(){


    FILE *log;

    struct login l;
    char password2[50];

    system("CLS");
    heading();
    printf("\t\t\t\t***********************   Sign Up   *************************\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*  | Enter Full Name:\t\t");
    scanf("%s", l.fullName);
    printf("\t\t\t\t*  | Enter Email:\t\t");
    scanf("%s", l.email);
    printf("\t\t\t\t*  | Enter Contact No:\t\t");
    scanf("%s", l.phone);
    printf("\t\t\t\t*  | Enter Password:\t\t");
    takePassword(l.password);
    printf("\n\t\t\t\t*  | Confirm Password:\t\t");
    takePassword(password2);
    printf("\n\t\t\t\t*                                                           *\n");

    if(!strcmp(l.password, password2))
    {
        generateUserName(l.email, l.username);
        log = fopen("login3.txt", "ab+");
        fwrite(&l, sizeof(l), 1, log);

        if(fwrite != 0) {
            printf("\t\t\t\t*************************************************************\n");
            printf("\t\t\t\t*                                                           *\n");
            printf("\t\t\t\t*                Registration Successfull,                  *\n");
            printf("\t\t\t\t*                Your UserId is %s                   *", l.username);
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*************************************************************");
        }else printf("\n\n\t\t\t\tSorry! User Not Found");
            fclose(log);
    }else{
            printf("\n\nYour password didnot match");
            Beep(750,300);
    }
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*            Now Login with UserId and password             *");
    printf("\n\t\t\t\t*            Press any key to continue.........             *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*************************************************************\n");
    getch();
    system("CLS");

    login();
}

void login(){

    int opt;

    char username[50], password[50];
    char adminName[50] = {"admin"};
    char adminPass[50] = {"admin"};

    FILE *log;
    log = fopen("login3.txt", "rb");
    struct login l;
    heading();

    printf("\t\t\t\t************************** LogIn ****************************\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*               Please Choose Your Operation                *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*                        1. Admin                           *\n");
    printf("\t\t\t\t*                        2. User                            *\n");
    printf("\t\t\t\t*                        3. Exit                            *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*************************************************************\n\n");
    printf("\t\t\t\t                  Enter Your Choice: .... ");
    scanf("%d", &opt);

    if(opt == 1)
        {
            system("cls");
            heading();

            printf("\n\t\t\t\t\t\t | Enter UserId: ");
            scanf("%s", &username);
            printf("\n\t\t\t\t\t\t | Password:  \t");
            takePassword(password);

            if(!strcmp(password, adminPass) && !strcmp(username, adminName))
            {
                mainMenu();
            }else{
                if( d == 3 )
                {
                    exit(0);
                }
                printf("\n\n\n\n\t\t\t\t\t\t Wrong Password!! %d to 3\n", d);
                printf("\n\n\t\t\t\t\t\t    Try Again....");
                d++;

                fflush(stdin);
                getchar();

                login();
            }
            system("cls");
        }else if(opt == 2)
        {
            system("cls");
            heading();

            printf("\n\t\t\t\t\tEnter UserId:\t");
            scanf("%s", &username);
            printf("\n\t\t\t\t\tPassword:\t");
            takePassword(password);

            while(fread(&l, sizeof(l), 1, log))
            {
                if (!strcmp(username, l.username)){
                if (!strcmp(password, l.password)){
                system("cls");
               /*
                printf("\n\t\t\t\t\t\tLogin Successfull");
                printf("\n\t\t\t\t\t\tWelcome %s", l.username);
                printf("\n\n\n\t\t\t\t\t|Full Name:\t%s", l.fullName);
                printf("\n\t\t\t\t\t|Email:\t\t%s", l.email);
                printf("\n\t\t\t\t\t|Contact no:\t%s\n\n\n", l.phone);
                printf("\n\t\t\t--------------------------------------------------\n\n\n\n\n\n");
               */

            } else {
                    printf("\n\nInvalid Password!");
                    Beep(800, 300);
                }
            }
            userMenu();
            fclose(log);
        }
    }else{
        printf("\n\n\n\t\t\t\t\t\t   Bye Bye :)\n");
        printf("\n\t\t\t-------------------------------------------------------------------\n\n\n\n\n\n");
        return 0;
    }
}


void mainMenu(){

    system("cls");
    heading();
    int opt;

    printf("\n\t\t\t\t************************** Main Menu ************************\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*                      1. Add Book                          *\n");
    printf("\t\t\t\t*                      2. View Book                         *\n");
    printf("\t\t\t\t*                      3. Search Book                       *\n");
    printf("\t\t\t\t*                      4. Edit Book                         *\n");
    printf("\t\t\t\t*                      5. Delete Book                       *\n");
    printf("\t\t\t\t*                      6. Help                              *\n");
    printf("\t\t\t\t*                      7. Exit                              *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*************************************************************\n\n");
    printf("\t\t\t\t\t\t      Enter Your Choice: ");
    scanf("%d", &opt);


    if( opt == 1 ){
        addBook();
    }else if( opt == 2 ){
        viewBook();
    }else if( opt == 3 ){
        searchBook();
    }else if( opt == 4 ){
        editBook();
    }else if( opt == 5 ){
        deleteBook();
    }else if( opt == 6 ){
        help();
    }else if( opt == 7 ){
        close();
    }else{
        printf("\n\n\t\t\t\t\t\tChoose any option first!!");

        fflush( stdin );
        getchar();
        mainMenu();
    }

    fflush( stdin );
    getchar();
}

void userMenu(){
    system("cls");
    int opt;

    printf("\n\t\t\t\t************************ Main Menu ************************\n");
    printf("\t\t\t\t*                                                         *\n");
    printf("\t\t\t\t*                                                         *\n");
    printf("\t\t\t\t*                      1. View Book                       *\n");
    printf("\t\t\t\t*                      2. Search Book                     *\n");
    printf("\t\t\t\t*                      3. Help                            *\n");
    printf("\t\t\t\t*                      4. Exit                            *\n");
    printf("\t\t\t\t*                                                         *\n");
    printf("\t\t\t\t***********************************************************\n\n");
    printf("\t\t\t\t\t\t      Enter Your Choice: ");
    scanf("%d", &opt);


    if( opt == 1 ){
        userViewBook();
    }else if( opt == 2 ){
        userSearchBook();
    }else if( opt == 3 ){
        userHelp();
    }else if( opt == 4 ){
        close();
    }else{
        printf("\n\n\t\t\t\t\t\tChoose any option first!!");

        fflush( stdin );
        getchar();
        userMenu();
    }

    fflush( stdin );
    getchar();
}

void heading(){

    system("cls");
    printf("\n\t\t\t\t*************************************************************\n");
    printf("\t\t\t\t*****************  NSU Library Management  ******************\n");
    printf("\n\t\t\t\t-------------------------------------------------------------\n\n");
}

void loginPassword(){


    int cho;
    heading();

    printf("\t\t\t\t******************* Authentication System *******************\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*               Please Choose Your Operation                *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*                      1. Sign Up                           *\n");
    printf("\t\t\t\t*                      2. Login                             *\n");
    printf("\t\t\t\t*                      3. Exit                              *\n");
    printf("\t\t\t\t*                                                           *\n");
    printf("\t\t\t\t*************************************************************\n\n");
    printf("\t\t\t\t                Enter Your Choice:......... ");
    scanf("%d", &cho);

    if(cho == 1)
    {
        system("cls");
        registe();
    }else if(cho == 2)
    {
        system("cls");
        login();
    }else{
        printf("\n\n\n\t\t\t\t\t\t   Bye Bye :)\n");
        printf("\n\t\t\t-------------------------------------------------------------------\n\n\n\n\n\n");
        return 0;
    }
    fflush(stdin);
    getchar();

    mainMenu();
}

void addBook(){

    system("cls");
    heading();
    int d, count = 0;

    printf("\n\t\t\t\t************************ Add Book ************************\n\n");

    file = fopen("books.dat", "ab+");

    printf("\t\t\t\t\t\t Enter Book Id: \t");
    fflush(stdin);
    scanf("%d", &d);

    rewind(file);

    while(fread(&a, sizeof(a), 1, file) == 1){

        if( d== a.id){
            printf("\n\n\t\t\t\t\t This Id is Already Booked");
            count = 1;
        }
    }

    if(count == 1){

        fflush(stdin);
        getchar();
        mainMenu();
    }

    a.id = d;

    printf("\t\t\t\t\t\t Enter Book Name: \t");
    fflush(stdin);
    scanf("%s", &a.name);

    printf("\t\t\t\t\t\t Enter Author Name: \t");
    fflush(stdin);
    scanf("%s", &a.author);

    printf("\t\t\t\t\t\t Enter Quantity: \t");
    fflush(stdin);
    scanf("%d", &a.quantity);

    printf("\t\t\t\t\t\t Enter Rack Number: \t");
    fflush(stdin);
    scanf("%d", &a.rack);

    fseek(file, 0, SEEK_END);
    fwrite(&a, sizeof(a), 1, file);
    fclose(file);

    printf("\n\t\t\t\t\t\t Book Added Successfully!");
    printf("\n\t\t\t\t***********************************************************\n");

    fflush(stdin);
    getchar();
    mainMenu();
}

void viewBook(){

    system("cls");

    int count = 0;

    printf("\t\t\t********************************** Available Book *******************************\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*\tId\tName\t\t\tAuthor\t\t\tQty\tRack\t*\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*********************************************************************************\n");

    file = fopen("books.dat", "rb");

    while( fread(&a, sizeof(a), 1, file) == 1){

        printf("\t\t\t*\t%d", a.id);
        printf("\t%s", a.name);
        printf("\t\t\t%s", a.author);
        printf("\t\t\t%d", a.quantity);
        printf("\t%d\t*\n", a.rack);

        count = count + a.quantity;
    }

    fclose(file);

    printf("\t\t\t*********************************************************************************\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*                                Total Books:%d                                *\n", count);
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*                        Press ENTER back to Main Menu...                       *\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*********************************************************************************\n");

    fflush(stdin);
    getchar();
    mainMenu();

}

void userViewBook(){

    system("cls");

    int count = 0;

    printf("\t\t\t********************************** Available Book *******************************\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*\tId\tName\t\t\tAuthor\t\t\tQty\tRack\t*\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*********************************************************************************\n");

    file = fopen("books.dat", "rb");

    while( fread(&a, sizeof(a), 1, file) == 1){

        printf("\t\t\t*\t%d", a.id);
        printf("\t%s", a.name);
        printf("\t\t\t%s", a.author);
        printf("\t\t\t%d", a.quantity);
        printf("\t%d\t*\n", a.rack);

        count = count + a.quantity;
    }

    fclose(file);

    printf("\t\t\t*********************************************************************************\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*                                Total Books:%d                                 *\n", count);
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*                       Press ENTER | Back to Main Menu...                      *\n");
    printf("\t\t\t*                                                                               *\n");
    printf("\t\t\t*********************************************************************************\n");

    fflush(stdin);
    getchar();
    userMenu();
}

void searchBook(){

    int d, count = 0;

    system("cls");
    heading();

    printf("\n\t\t\t\t********************* Search Book ***************************");

    file = fopen("books.dat", "rb");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*\t\t    | Enter Id: ");
    scanf("%d", &d);

    while( fread(&a, sizeof(a), 1, file) == 1){

        if( d == a.id ){
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t********************* Book is Found *************************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*                 *** Book  Details ***                     *");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*\t\tID:\t\t %d", a.id);
            printf("\n\t\t\t\t*\t\tName:\t\t %s", a.name);
            printf("\n\t\t\t\t*\t\tAuthor:\t\t %s", a.author);
            printf("\n\t\t\t\t*\t\tQuantity:\t %d", a.quantity);
            printf("\n\t\t\t\t*\t\tRack:\t\t %d", a.rack);

            count = 1;
        }
    }

    if(count == 0){
        printf("\t\t\t\t\t\t Book is not found !");
    }
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*           Press ENTER | Back to Main Menu...              *");
    printf("\n\t\t\t\t*************************************************************\n\n");
    fflush(stdin);
    getchar();
    mainMenu();
}

void userSearchBook(){
    int d, count = 0;

    system("cls");
    heading();

    printf("\n\t\t\t\t********************* Search Book ***************************");
    file = fopen("books.dat", "rb");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*\t\t    | Enter Id: ");
    scanf("%d", &d);

    while( fread(&a, sizeof(a), 1, file) == 1){

        if( d == a.id ){
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t********************* Book is Found *************************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*                 *** Book  Details ***                     *");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*\t\tID:\t\t %d", a.id);
            printf("\n\t\t\t\t*\t\tName:\t\t %s", a.name);
            printf("\n\t\t\t\t*\t\tAuthor:\t\t %s", a.author);
            printf("\n\t\t\t\t*\t\tQuantity:\t %d", a.quantity);
            printf("\n\t\t\t\t*\t\tRack:\t\t %d", a.rack);

            count = 1;
        }
    }

    if(count == 0){
        printf("\t\t\t\t\t\t Book is not found !");
    }
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*           Press ENTER | Back to Main Menu...              *");
    printf("\n\t\t\t\t*************************************************************\n\n");
    fflush(stdin);
    getchar();
    userMenu();
}

void editBook(){
    int d, count = 0;

    system("cls");
    heading();

    printf("\n\t\t\t\t************************ Edit Book **************************");

    file = fopen("books.dat", "rb+");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*\t\t      | Enter Id: ");
    scanf("%d", &d);

        while( fread(&a, sizeof(a), 1, file) == 1){

        if( d == a.id ){
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*********************** Book is Found ***********************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*\t\t  ID:\t\t\t%d", a.id);
            printf("\n\n\t\t\t\t*\t\t  | Enter New Name:\t");
            scanf("%s", &a.name);
            printf("\n\t\t\t\t*\t\t  | Enter New Author:\t");
            scanf("%s", &a.author);
            printf("\n\t\t\t\t*\t\t  | Enter New Quantity:\t");
            scanf("%d", &a.quantity);
            printf("\n\t\t\t\t*\t\t  | Enter New Rack:\t");
            scanf("%d", &a.rack);

            fseek(file, ftell(file)-sizeof(a), 0);

            fwrite(&a, sizeof(a), 1, file);
            fclose(file);

            count = 1;
        }
    }
    if(count == 0){
        printf("\t\t\t\t\t\t Book is not found !");
    }
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*             Press ENTER | Back to Main Menu...            *");
    printf("\n\t\t\t\t*************************************************************\n\n");
    fflush(stdin);
    getchar();
    mainMenu();
}

void deleteBook(){
    int d, count = 0;

    system("cls");

    printf("\n\t\t\t***************************** Delete Book ******************************\n\n");

    printf("\n\t\t\t\t\t\t Enter Id for Delete Book: ");
    scanf("%d", &d);

    file = fopen("books.dat", "rb+");
    rewind(file);
    while( fread(&a, sizeof(a), 1, file) == 1){

        if( d == a.id ){
            printf("\n\t\t\t\t\t********* Book is Available *********\n\n\n");
            printf("\n\t\t\t\t\t Book Name:\t\t %s", a.name);
            printf("\n\t\t\t\t\t Author:\t %s", a.author);
            printf("\n\t\t\t\t\t Quantity:\t %d", a.quantity);
            printf("\n\t\t\t\t\t Rack:\t\t %d", a.rack);

            count = 1;
        }
    }
    if(count == 0){
        printf("\t\t\t Book is not found !");
    }else{
        file2 = fopen("text.dat", "wb+");

        rewind(file);
        while( fread(&a, sizeof(a), 1, file) == 1){

            if(d != a.id){

                fseek(file2, ftell(file2)-sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, file2);
            }
        }
            fclose(file);
            fclose(file2);

            remove("books.dat");

            rename("text.dat", "books.dat");

            file = fopen("books.dat", "rb");

            fclose(file);
    }
    printf("\n\n\n\n\n\t\t\t\t\t\t Press any key.....");
    printf("\n\t\t\t****************************************8******************************\n\n");
    fflush(stdin);
    getchar();
    mainMenu();
}

void help(){

    system("cls");

    printf("\n\t\t\t******************************* Help ********************************");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                     Library Management System                     *");
    printf("\n\t\t\t*                  Created By, Mehedi Hasan Parash                  *");
    printf("\n\t\t\t*                         Department of ECE                         *");
    printf("\n\t\t\t*                      North South University                       *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*               1. User Name is: admin                              *");
    printf("\n\t\t\t*               2. Password is: admin                               *");
    printf("\n\t\t\t*               3. You can Add Book in Library                      *");
    printf("\n\t\t\t*               4. See All Features Under Main Menu                 *");
    printf("\n\t\t\t*               5. You can Use All Of Them                          *");
    printf("\n\t\t\t*               6. Press ENTER | Back to Main Menu                  *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                   Stay connected | Thank You                      *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*            ©All Right Reserved | Mehedi Hasan Parash              *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*********************************************************************");

    fflush(stdin);
    getchar();
    mainMenu();
}

void userHelp(){

    system("cls");

    printf("\n\t\t\t******************************* Help ********************************");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                     Library Management System                     *");
    printf("\n\t\t\t*                  Created By, Mehedi Hasan Parash                  *");
    printf("\n\t\t\t*                         Department of ECE                         *");
    printf("\n\t\t\t*                      North South University                       *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*               1. See All Features Under Main Menu                 *");
    printf("\n\t\t\t*               2. You can Use All Of Them                          *");
    printf("\n\t\t\t*               3. Press ENTER | Back to Main Menu                  *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                   Stay connected | Thank You                      *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*            ©All Right Reserved | Mehedi Hasan Parash              *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*********************************************************************");

    fflush(stdin);
    getchar();
    userMenu();
}

void close(){

    int i;
    system("cls");

    printf("\n\t\t\t******************************* Exit ********************************");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                     Library Management System                     *");
    printf("\n\t\t\t*                  Created By, Mehedi Hasan Parash                  *");
    printf("\n\t\t\t*                         Department of ECE                         *");
    printf("\n\t\t\t*                      North South University                       *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                       Please Wait a Moment                        *");
    printf("\n\t\t\t*                    System will close soon....                     *");
    printf("\n\t\t\t*                    Stay connected | Thank You                     *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*            ©All Right Reserved | Mehedi Hasan Parash              *");
    printf("\n\t\t\t*                                                                   *");
    printf("\n\t\t\t*********************************************************************");

    for(i=1; i<1000000000; i++){

    }
    exit(0);
}










