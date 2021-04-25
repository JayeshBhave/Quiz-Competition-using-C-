#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
using std::getline;
int student_login();
void student_view();
void quiz();
void instr();

int main(){
    system("cls");
    int a;
    cout<<"\t\t\t\t\t\t\t----------- Welcome to Quiz Competition -------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\t[Press 1] to Login/Register."<<endl<<"\t\t\t\t\t\t\t\t[Press 2] to View Instructions."<<endl<<"\t\t\t\t\t\t\t\t[Press 3] to Exit Quiz."<<endl;
    cout<<"\t\t\t\t\t\t\t\tEnter Option : ";
    cin>>a;
    switch(a){
        case 1:
            student_login();
            break;
        case 2:
            instr();
            break;
        case 3:
            exit(0);
    }
    return 0;
}
int student_login(){
    system("cls");
    bool login_successful = false;
    long long option, remain = 5;
    string account_name, account_name_login, password, password_login, username;
    
    cout << "\t\t\t\t\t\t\t\tWelcome to Student login system" << endl <<"\t\t\t\t\t\t\tKindly use _ instead of Space"<< endl << "\n\t\t\t\t\t\t\t[Press 1] to sign up" << endl << "\t\t\t\t\t\t\t[Press 2] to login" << endl << "\t\t\t\t\t\t\t[Press 3] if you forgot your account password" << endl <<"\t\t\t\t\t\t\t[Press 4] to get back to main menu."<<endl;
    cout << "\t\t\t\t\t\t\tYour Option: ";
    cin >> option;
    if (option == 1)
    {
        system("cls");
        cout << "\t\t\t\t\t\t\tCreate an user name: ";
        cin >> account_name;
        cout << endl;
        cout << "\t\t\t\t\t\t\tCreate a password: ";
        cin >> password;
        cout << endl;
        ofstream user_info;
        user_info.open("user_" + account_name + ".txt");
        user_info << account_name << endl << password;
        user_info.close();
        
        cout << "\t\t\t\t\t\t\tYour account has been Registered!" << endl << endl;
        student_login();
    }
    else if (option == 2)
    {
        do
        {
            system("cls");
            cout << "\t\t\t\t\t\t\t----------LOGIN-----------" << endl;
            cout << "\t\t\t\t\t\t\tNow, log in your account" << endl;
            
            cout << endl << "\t\t\t\t\t\t\tType in your account name: ";
            cin >> account_name_login;
            cout << endl << "\t\t\t\t\t\t\tType in your password: ";
            cin >> password_login;
            ifstream find_account("user_" + account_name_login + ".txt");
            getline(find_account, account_name);
            getline(find_account, password);
            if (account_name_login == account_name && password_login == password)
            {
                
                cout << endl << "\t\t\t\t\t\t\tYou have logged in successfully!" << endl << endl;
                login_successful = true;
                getch();
                student_view();
            }
            else
            {
                
                cout << endl << "\t\t\t\t\t\t\tInvaild username or password" << endl << "\t\t\t\t\t\t\tYou have " << remain << " times left to try!" << endl << "\t\t\t\t\t\t\tPlease try again!" << endl;
                remain--;
                login_successful = false;
            }
        } while (!login_successful && remain != -1);
        if (remain == -1)
        {
            
            cout << "\t\t\t\t\t\t\tYou have 0 times left to try" << endl << "\t\t\t\t\t\t\tThe program will now exit";
            
            return 0;
        }
    }
    else if (option == 3)
    {
        system("cls");
        cout << "\t\t\t\t\t\t\tType in your username: ";
        cin >> username;
        ifstream find_account("user_" + username + ".txt");
        if (find_account.is_open())
        {
            getline(find_account, account_name);
            getline(find_account, password);
            cout << "\t\t\t\t\t\t\tYour password is: " << password << endl << endl;
            getch();
        }
        else
        {
            cout << "\t\t\t\t\t\t\tSorry,we couldn't find your account!" << endl << endl;
        }
        student_login();
    }
    else if (option == 4)
    {
        main();
    }
    return 0;
}
void student_view(){
    system("cls");
    int us;
    string account_name, account_name_login, password, password_login, username;
    cout<<"\t\t\t\t\t\t\tWelcome to your Account"<< endl <<endl;
    cout<<"\t\t\t\t\t\t\t[Press 1] to Start Quiz "<< endl <<"\t\t\t\t\t\t\t[Press 2] to Log Out. "<< endl ;
    cout<<"\t\t\t\t\t\t\tEnter your Choice : ";
    cin>>us;
    cout<<endl;
    switch (us)
    {
    case 1:
        quiz();
        break;
    case 2:
        student_login();
        break;
    }
}
void quiz(){
    system("cls");
    int score=0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;
    cout<<"\t\t\t\t\t\t\t-------------- Lets Start Quiz -----------------\n"<<endl;
    cout<<"\t\t\t\t\t\tQ.1) Which colors must be mixed together to make green?\n\t\t\t\t\t\tA) Orange and blue \n\t\t\t\t\t\tB) Red and blue \n\t\t\t\t\t\tC) Blue and yellow \n\t\t\t\t\t\tD) Black and yellow\n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q1;
    if(q1 == 3){
        score+=2; // score = score + 2
        }
    else if(q1==1 || q1==2 || q1==4){
        score+=0; //score = score + 0
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\n\t\t\t\t\t\tQ.2) Name the currency used in Japan?\n\t\t\t\t\t\tA) Taka \n\t\t\t\t\t\tB) Dinar \n\t\t\t\t\t\tC) Ngultrum \n\t\t\t\t\t\tD) Yen\n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q2;
    if(q2 == 4){
        score+=2;
    }
    else if(q2==1 || q2==2 || q2==3){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.3) How many dots are on one six-sided die?\n\t\t\t\t\t\tA) 17 \n\t\t\t\t\t\tB) 19 \n\t\t\t\t\t\tC) 20 \n\t\t\t\t\t\tD) 21\n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q3;
    if(q3 == 4){
        score+=2; 
    }
    else if(q3==1 || q3==2 || q3==3){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.4) Who wrote Hamlet?\n\t\t\t\t\t\tA) Walt Whitman \n\t\t\t\t\t\tB) William Shakespeare \n\t\t\t\t\t\tC) Franz Kafka \n\t\t\t\t\t\tD) Leonardo da Vinci\n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q4;
    if(q4 == 2){
        score+=2; 
    }
    else if(q4==1 || q4==4 || q4==3){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.5) What's the smallest country in the world?\n\t\t\t\t\t\tA) Monaco \n\t\t\t\t\t\tB) San Marino \n\t\t\t\t\t\tC) Liechtenstein \n\t\t\t\t\t\tD) Vatican City\n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q5;
    if(q5 == 4){
        score+=2; 
    }
    else if(q5==1 || q5==2 || q5==3){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.6) Which chess piece can't move in a straight line?\n\t\t\t\t\t\tA) Knight \n\t\t\t\t\t\tB) Rook \n\t\t\t\t\t\tC) King \n\t\t\t\t\t\tD) Bishop \n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q6;
    if(q6 == 1){
        score+=2; 
    }
    else if(q6==4 || q6==2 || q6==3){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.7) Where is Mount Everest located? \n\t\t\t\t\t\tA) Tibet \n\t\t\t\t\t\tB) Nepal \n\t\t\t\t\t\tC) On the border between Tibet and Nepal \n\t\t\t\t\t\tD) Switzerland \n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q7;
    if(q7 == 3){
        score+=2; 
    }
    else if(q7==4 || q7==2 || q7==1){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.8) When is International Women's Day? \n\t\t\t\t\t\tA) January 12 \n\t\t\t\t\t\tB) March 8 \n\t\t\t\t\t\tC) August 23 \n\t\t\t\t\t\tD) December 5 \n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q8;
    if(q8 == 2){
        score+=2; 
    }
    else if(q8==4 || q8==3 || q8==1){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.9) Choose the chemical symbol for potassium? \n\t\t\t\t\t\tA) K \n\t\t\t\t\t\tB) Ts \n\t\t\t\t\t\tC) P \n\t\t\t\t\t\tD) Pt \n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q9;
    if(q9 == 1){
        score+=2; 
    }
    else if(q9==4 || q9==3 || q9==2){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    cout<<"\t\t\t\t\t\tQ.10) What is the world's most expensive spice by weight? \n\t\t\t\t\t\tA) Cinnamon \n\t\t\t\t\t\tB) Clove \n\t\t\t\t\t\tC) Vanilla \n\t\t\t\t\t\tD) Saffron \n\t";
    cout<<"\n\t\t\t\t\t\tEnter your Choice in 1,2,3,4 : ";
    cin>>q10;
    if(q10 == 4){
        score+=2; 
    }
    else if(q10==1 || q10==3 || q10==2){
        score+=0;
    }
    else{
        cout<<"\t\t\t\t\t\tInvalid Choice\n";
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue to next Question.";
    getch();
    system("cls");
    if(score>=10){
        system("Color 01");// system("Color XY"); 01 = background Black and Text Blue
        cout<<"\t\t\t\t\t\tYour Score is "<<score;
    }
    else if (score<10){
        system("Color 04");
        cout<<"\t\t\t\t\t\tYour Score is "<<score;
    }
}
void instr(){
    system("cls");
    cout<<"\t\t\t\t\t\t\t1. Quiz will contain 10 Questions ."<<endl<<"\t\t\t\t\t\t\t2. Every Question will have 2 points ."<<endl<<"\t\t\t\t\t\t\t3. Score will be Displayed at end of Quiz ."<<endl<<"\t\t\t\t\t\t\t4. No points will be deducted for wrong answers .\n"<<"\n\t\t\t\t\t\t\tPress any key to get back ...";
    getch();
    main();
}