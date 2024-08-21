#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <iterator>
#include <windows.h>
#include <ctime>
using namespace std;
///CLASS STORE
///OWNER FUNCTIONS
//ownerLogin()//
//ownerMenu()//
//viewTotalIncome()//
///CART FUNCTIONS
//addGameToCart()//
//removeGameFromCart()//
//purchaseGames()//
//ViewCart()//
///CUSTOMER FUNCTIONS
//getCustomerDetails()//
//customerMenu()//
///GENERAL FUNCTIONS
//addGameToStore()//
//RemoveGameFromStore()//
//viewGamesInStore()//
//loadGamesFromFile()//
//saveGamesToFile()//
//printBill()//
class Game
{
private:
string name;
double price;
int quantity;
public:
static int total_games;
Game(string name, double price, int quantity)
{
this-> name = name;
this-> price = price;
this-> quantity = quantity;
total_games++;
}
// Getter functions
string getName()
{
return name;
}
double getPrice()
{
return price;
}
int getQuantity()
{
return quantity;
}
void setQuantity(int q)
{
quantity=q;
}
// Decrease quantity by n
void decreaseQuantity()
{
quantity = quantity - 1;
}
};
///Static variable for total number of games
int Game :: total_games=0;
///Global Variable for Total Games in Cart
int games_in_cart=0;
///Vector used in this Program
//Vector for Games in Store
vector <Game> games;
//Vector for Games in Cart
vector <Game> cart;
class Store
{
public:
///OWNER FUNCTIONS
void ownerLogin()
{
string owner_name;
int password;
system("CLS");
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "***************************OWNER LOGIN PAGE: ********************************" << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tEnter Name of the Owner: ";
cin >> owner_name;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tEnter Owner Password: ";
cin >> password;
cout << "*****************************************************************************" << endl;
Sleep(1000);
if((owner_name=="SWASTIK" || owner_name=="swastik") && password == 2810)
{
system("CLS");
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tYOU HAVE ENTERED CORRECT USER NAME AND PASSWORD!!!" << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(1000);
system("CLS");
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tLOGGING IN AS OWNER..." << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(1000);
system("CLS");
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tYOU ARE BEING REDIRECTED TO OWNER MENU..." << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(1000);
ownerMenu();
}
else
{
system("CLS");
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tYOU HAVE ENTERED WRONG USER NAME AND PASSWORD!!!" << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(1000);
system("CLS");
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tReturning to Previous Menu..." << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(1000);
return;
}
}
void ownerMenu()
{
int owner_choice=0;
system("CLS");
Sleep(100);
while(owner_choice!=5)
{
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "*********************************Owner Menu:*********************************" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\t1. Add game" << endl;
Sleep(200);
cout << "\t2. Remove game" << endl;
Sleep(200);
cout << "\t3. View games in store" << endl;
Sleep(200);
cout << "\t4. View total income" << endl;
Sleep(200);
cout << "\t5. Logout" << endl << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(500);
cout << "\tEnter choice: ";
cin >> owner_choice;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(500);
if(owner_choice == 1)
{
addGameToStore();
}
else if(owner_choice == 2)
{
removeGameFromStore();
}
else if(owner_choice == 3)
{
viewGamesInStore();
}
else if(owner_choice == 4)
{
viewTotalIncome();
}
else if(owner_choice == 5)
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tLoging Out of Owner Page..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tReturning to Log-In Menu...\n" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
break;
}
else
{
cout << "\nEnter a Valid input..." << endl;
}
}
}
void viewTotalIncome()
{
ifstream owner_file("E://COLLEGE WORK//C++ CODING//PROJECT//owner.txt");
string income;
getline(owner_file, income);
system("CLS");
Sleep(500);
int pin;
cout << "*****************************************************************************" << endl;
cout << "\tEnter Password: ";
cin >> pin;
Sleep(200);
if(pin == 2810)
{
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tTotal Income: " << income << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
}
else
{
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tYOU HAVE ENTERED WRONG PIN!!!" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
}
cout << endl;
owner_file.close();
}
///STORE FUNCTIONS
void addGameToStore()
{
string name;
double price;
int quantity;
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tEnter Name of the Game: ";
cin >> name;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "Enter the Price of the Game: ";
cin >> price;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "Enter the Quantity of the Game: ";
cin >> quantity;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << endl;
int flag=0;
vector <Game> :: iterator itr;
for(itr=games.begin(); itr!=games.end(); itr++)
{
if(name==itr->getName())
{
flag++;
break;
}
}
if(flag>0)
{
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tThis Game already exists in the Store..." << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tKindly Enter New Game..." << endl;
Sleep(500);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tReturning to Previous Menu..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(500);
return;
}
else
{
games.push_back(Game(name, price, quantity));
fstream MyFile("E://COLLEGE WORK//C++ CODING//PROJECT//games.txt", ios :: app);
MyFile << name << endl;
MyFile << price << endl;
MyFile << quantity << endl;
MyFile.close();
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tGAME ADDED SUCCESSFULLY TO THE STORE..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
}
}
void removeGameFromStore()
{
string game_name_to_remove;
system("CLS");
viewGamesInStore();
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tEnter the Name of the Game to Remove: ";
cin >> game_name_to_remove;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << endl;
int flag=-1;
int i;
int j;
for(i=0; i<games.size(); i++)
{
if(games[i].getName() == game_name_to_remove)
{
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\t\tGame Found" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tRemoving this Game: " << game_name_to_remove << endl;
Sleep(200);
flag=i;
break;
}
}
if(flag==-1)
{
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tGame Not Found" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tReturning to Previous Menu..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(500);
return;
}
for(j=flag; j<games.size()-1; j++)
{
games[j]=games[j+1];
}
//REDUCES THE TOTAL DISTINCT GAMES
Game :: total_games--;
//REMOVES THE LAST GAME WHICH IS EXTRA
games.pop_back();
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tGame Successfully Removed..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tReturning to Previous Menu..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << endl;
return;
}
void viewGamesInStore()
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "*********************************GAMES IN STORE:*****************************" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << endl;
if(games.size() == 0)
{
cout << "\tCURRENTLY THE STORE DOES NOT HAVE ANY GAMES..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tKINDLY ASK THE OWNER TO ADD GAMES TO THE STORE..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
return;
}
else
{
int i;
for(i=0; i<games.size(); i++)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "GAME NAME: " << games[i].getName() << endl;
Sleep(100);
cout << "PRICE: " << games[i].getPrice() << endl;
Sleep(100);
cout << "QUANTITY: " << games[i].getQuantity() << endl;
Sleep(100);
}
cout << "*****************************************************************************" << endl;
Sleep(200);
}
cout << endl;
}
void loadGamesFromFile()
{
ifstream main_file1("E://COLLEGE WORK//C++ CODING//PROJECT//games.txt");
string name, p, q;
double price;
int quantity;
int i;
int c=0;
while(getline(main_file1, p))
{
c++;
}
c=c/3;
main_file1.close();
ifstream main_file("E://COLLEGE WORK//C++ CODING//PROJECT//games.txt");
for(i=0; i<c; i++)
{
getline(main_file, name);
getline(main_file, p);
getline(main_file, q);
price=stoi(p);
quantity=stod(q);
games.push_back(Game(name, price, quantity));
}
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "************************GAMES LOADED IN THE SERVER...************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
main_file.close();
}
void saveGamesToFile()
{
ofstream main_file2 ("E//COLLEGE WORK//C++ CODING//PROJECT//games.txt");
int i;
for(i=0; i< games.size(); i++)
{
main_file2 << games[i].getName() << endl;
main_file2 << games[i].getPrice() << endl;
main_file2 << games[i].getQuantity() << endl;
}
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tSaving Games from the Server to the Database..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
main_file2.close();
}
void printBill()
{
Sleep(200);
if(cart.size() == 0)
{
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tYOUR CART IS EMPTY..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tKINDLY ADD GAMES IN YOUR CART TO PURCHASE THEM..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
return;
}
else
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "****************************NEXUS GAMING LOUNGE****************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "***********************************BILL************************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "-------------------------------------------------------------------" << endl;
cout << endl;
time_t now = time(0);
char * date_time = ctime(&now);
cout << "\tBill Date and Time: " << date_time << endl;
Sleep(100);
cout << "-------------------------------------------------------------------" << endl;
Sleep(100);
ifstream cust_file("E://COLLEGE WORK//C++ CODING//PROJECT//customer.txt");
string cust_name;
string cust_phone;
string cust_email;
getline(cust_file, cust_name);
getline(cust_file, cust_phone);
getline(cust_file, cust_email);
cust_file.close();
cout << endl;
cout << "\tName of the Customer: " << cust_name << endl;
Sleep(100);
cout << "\tPhone No of the Customer: " << cust_phone << endl;
Sleep(100);
cout << "\tEmail Id of the Customer: " << cust_email << endl;
Sleep(100);
cout << endl;
cout << "-------------------------------------------------------------------" << endl;
cout << "\tGames Purchased:" << endl;
viewGamesInCart();
double total_price=0;
vector <Game> :: iterator itr;
for(itr=cart.begin(); itr!=cart.end(); itr++)
{
total_price += itr->getPrice();
}
cout << "-------------------------------------------------------------------" << endl;
Sleep(100);
cout << "\tTotal Cost Paid: " << total_price << endl;
Sleep(100);
cout << "-------------------------------------------------------------------" << endl;
Sleep(100);
for(int i=0; i<cart.size(); i++)
{
cart.pop_back();
}
cout << endl;
}
}
///CUSTOMER FUNCTIONS
void getCustomerDetails()
{
ofstream cust("E://COLLEGE WORK//C++ CODING//PROJECT//customer.txt");
string cust_name;
long long int cust_phone_no;
string cust_email;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Customer Name: ";
cin >> cust_name;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Customer Phone Number: ";
cin >> cust_phone_no;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Customer Email: ";
Sleep(100);
cin >> cust_email;
cout << "*****************************************************************************" << endl;
Sleep(100);
cust << cust_name << endl;
cust << cust_phone_no << endl;
cust << cust_email << endl;
cout << endl;
cust.close();
}
void customerMenu()
{
getCustomerDetails();
int cust_choice=0;
system("CLS");
Sleep(100);
while(cust_choice!=6)
{
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "**********************************Customer Menu:*****************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\t1. Add game to Cart" << endl;
Sleep(100);
cout << "\t2. Remove game from Cart" << endl;
Sleep(100);
cout << "\t3. View games in Store" << endl;
Sleep(100);
cout << "\t4. View games in Cart" << endl;
Sleep(100);
cout << "\t5. Purchase Games" << endl;
Sleep(100);
cout << "\t6. Logout" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "\tEnter choice: ";
cin >> cust_choice;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
if(cust_choice == 1)
{
addGameToCart();
system("CLS");
}
else if(cust_choice == 2)
{
removeGameFromCart();
system("CLS");
}
else if(cust_choice == 3)
{
system("CLS");
Sleep(100);
viewGamesInStore();
Sleep(100);
}
else if(cust_choice == 4)
{
system("CLS");
Sleep(100);
viewGamesInCart();
Sleep(100);
cout << endl;
}
else if(cust_choice == 5)
{
string sub_choice;
system("CLS");
Sleep(200);
viewGamesInCart();
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tDo you want to Finally Purchase the games in your cart?(Y/N): " << endl;
cin >> sub_choice;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
if(sub_choice=="y" || sub_choice=="Y" || sub_choice=="YES" || sub_choice=="yes" || sub_choice=="Yes")
{
system("CLS");
Sleep(200);
purchaseGames();
printBill();
}
else
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "Returning to Previous Menu..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(200);
}
}
else if(cust_choice == 6)
{
Sleep(200);
cout << "\nLoging Out of Customer Page..." << endl;
Sleep(200);
cout << "Returning to Log-In Menu...\n" << endl;
break;
}
else
{
cout << "\nEnter a Valid input..." << endl;
}
}
}
///CART FUNCTIONS
//View Games Inside Cart
void viewGamesInCart()
{
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "*********************************GAMES IN CART: *****************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
if(cart.size() == 0)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tYOUR CART IS EMPTY..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tKINDLY ADD GAMES IN YOUR CART..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
return;
}
else
{
int i;
for(i=0; i<cart.size(); i++)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tGAME NAME: " << cart[i].getName() << endl;
Sleep(100);
cout << "\tPRICE: " << cart[i].getPrice() << endl;
Sleep(100);
cout << "\tQUANTITY: " << cart[i].getQuantity() << endl;
Sleep(100);
}
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
}
}
void addGameToCart()
{
int cart_sub_menu;
system("CLS");
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "****************************Add Game to Cart:********************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\t1. Search Game by Name" << endl;
Sleep(100);
cout << "\t2. Return to Previous Menu\n" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Choice: ";
cin >> cart_sub_menu;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
while(cart_sub_menu!=2)
{
system("CLS");
Sleep(100);
if(cart_sub_menu == 1)
{
viewGamesInStore();
string game_to_add_to_cart;
int flag1 = 0;
double game_price=0;
int game_quanitity=1;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Game Name to add to Cart: ";
cin >> game_to_add_to_cart;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
vector <Game> :: iterator itr;
for(itr=games.begin(); itr!=games.end(); itr++)
{
if(game_to_add_to_cart == itr->getName())
{
flag1++;
game_price = itr->getPrice();
vector <Game> :: iterator itr2;
for(itr2=cart.begin(); itr2!=cart.end(); itr2++)
{
if(game_to_add_to_cart == itr2->getName())
{
flag1++;
game_quanitity++;
break;
}
}
break;
}
}
if(flag1 == 1)
{
cart.push_back(Game(itr->getName(), itr->getPrice(), game_quanitity));
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tGame added to Cart Successfully..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
}
else if(flag1 == 2)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tGame already added in cart..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
}
else
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tPlease Enter Correct Game Name!!!" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
}
}
else if(cart_sub_menu == 2)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tReturning to Previous Menu..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
return;
}
else
{
cout << "Please Enter a Valid Input..." << endl;
}
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "****************************Add Game to Cart:********************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\t1. Search Game by Name" << endl;
Sleep(100);
cout << "\t2. Return to Previous Menu\n" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Choice: ";
cin >> cart_sub_menu;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
}
}
void removeGameFromCart()
{
string game_to_remove_from_cart;
int cart_remove_menu;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "***************************Remove Game from Cart:******************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\t1. Search Game by Name" << endl;
Sleep(100);
cout << "\t2. Return to Previous Menu\n" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "Enter Choice: ";
cin >> cart_remove_menu;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
while(cart_remove_menu!=2)
{
if(cart_remove_menu == 1)
{
viewGamesInCart();
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tEnter Game Name to Remove from Cart: ";
cin >> game_to_remove_from_cart;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
int flag2 = 0;
int i;
for(i=0; i<games.size(); i++)
{
if(game_to_remove_from_cart == games[i].getName())
{
int game_count=0;
int index_of_game_in_cart;
int j;
for(j=0; j<games_in_cart; j++)
{
if(cart[j].getName() == game_to_remove_from_cart)
{
game_count = cart[j].getQuantity() -1;
index_of_game_in_cart = j;
break;
}
}
int k;
for(int k=index_of_game_in_cart; k<cart.size()-1; k++)
{
cart[k]=cart[k+1];
}
cart.pop_back();
flag2=1;
break;
}
}
if(flag2 == 1)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tGame removed from Cart Successfully..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
}
else
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tPlease Enter Correct Game Name!!!" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
}
}
else if(cart_remove_menu == 2)
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tReturning to Previous Menu..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
break;
}
else
{
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "Please Enter a Valid Input..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
}
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "***************************Remove Game from Cart:******************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\t1. Search Game by Name" << endl;
Sleep(100);
cout << "\t2. Return to Previous Menu\n" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "Enter Choice: ";
cin >> cart_remove_menu;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
}
}
void purchaseGames()
{
int i, j;
for(i=0; i<games.size(); i++)
{
for(j=0; j<cart.size(); j++)
{
if(games[i].getName() == cart[j].getName())
{
games.at(i)=(Game(games[i].getName(), games[i].getPrice(), games[i].getQuantity()-1));
//ADD INCOME OF THE OWNER
ifstream owner_file("E://COLLEGE WORK//C++ CODING//PROJECT//owner.txt");
string income;
getline(owner_file, income);
owner_file.close();
int int_income = stoi(income);
int_income += cart[j].getPrice();
///Updating Data into File
ofstream owner_file1("E://COLLEGE WORK//C++ CODING//PROJECT//owner.txt");
owner_file1 << int_income;
owner_file1.close();
}
}
}
}
};
int main()
{
system("color B0");
//Choice variable for Main Menu Options
int choice=0;
//Object of Store Class
Store s;
Sleep(500);
cout << "\n*****************************************************************************" << endl;
Sleep(200);
cout << "**********************LOADING GAMES IN THE SERVER...*************************" << endl;
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << endl;
//Loading Games from File
s.loadGamesFromFile();
Sleep(100);
system("CLS");
while(choice!=3)
{
system("CLS");
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "**********************WELCOME TO NEXUS GAMING LOUNGE***********************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << endl;
cout << "\tWhich type of Account do you want to log-in?" << endl;
Sleep(100);
cout << "\t1. Owner" << endl;
Sleep(100);
cout << "\t2. Customer" << endl;
Sleep(100);
cout << "\t3. Exit the Store?" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "Enter your Choice: ";
cin >> choice;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(500);
switch(choice)
{
case 1:
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "****************You are being redirected to Owner Login Page...**************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(200);
s.ownerLogin();
s.saveGamesToFile();
break;
}
case 2:
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "******************You are being redirected to Customer Menu...***************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(200);
s.customerMenu();
break;
}
case 3:
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "\tThank You for coming to Nexus Gaming Lounge..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tVisit again next time..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(200);
cout << "\tExiting the Store..." << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(600);
system("CLS");
Sleep(200);
cout << "This Project was made by the students of JIIT: " << endl;
Sleep(100);
cout << "ENROLL NO: NAME: BATCH:" << endl;
cout << "22103209 Swastik Garg B8" << endl;
Sleep(100);
cout << "22103220 Gaurav Rajput B8" << endl;
Sleep(100);
cout << "22103214 Varun Bharadwaj B8" << endl;
Sleep(100);
cout << "22103236 Kshitij Gupta B8" << endl;
Sleep(200);
break;
}
default:
{
system("CLS");
Sleep(200);
cout << "*****************************************************************************" << endl;
Sleep(100);
cout << "***********************PLEASE ENTER CORRECT INPUT!!!*************************" << endl;
Sleep(100);
cout << "*****************************************************************************" << endl;
Sleep(100);
Sleep(200);
system("CLS");
}
}
cout << endl;
}
}
