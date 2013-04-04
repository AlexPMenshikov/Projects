//____Libraries
#include <iostream>
//____Namespace
using namespace std;
//____Global variables
int menuStatus=0;
//____Const
const unsigned long int big = 32000;
//____Classes
class Rabit
{
    public:
   /* Rabit(int ID);
    ~Rabit();
    class ID
    {
        public:
        ID(int HP,int moveRange,bool readyToChild)*/
        Rabit(int setHP,int setMoveRange,bool setReadyToChild);
        int HP;//Health Point
        int moveRange;
        bool readyToChild;
        int eat();
        ~Rabit();
    //}
};
Rabit::Rabit(int setHP,int setMoveRange,bool setReadyToChild)
{
    Rabit::HP=setHP;
    Rabit::moveRange=setMoveRange;
    Rabit::readyToChild=setReadyToChild;
}
int Rabit::eat()
{
    cout<<"No\n";
}
class Wolf
{
    public:
    int HP;//Health Point
    int moveRange;
    bool readyToChild;
    int hunt();
};
//____Function to clear all screen MUCH MORE SPAAAACCCEEEE
void cls()
{
    cout<<"Function to clear the screen";
    for(int i=0;i<25;i++)
    {
    cout<<"\n";
    }
}
//____Destructor
Rabit::~Rabit()
{
}
//____Create new rabbits
void generationRabit()
{
    Rabit Sanya(30,3,false);
    Sanya.eat();
    cout << "Sanya HP=" << Sanya.HP <<"\n";

    Sanya.HP=150;
    cout << "Sanya HP=" << Sanya.HP <<" O_o \n";
}
//____Start game
void startGame()
{
    cls();
    generationRabit();

}
//____Function ASCII characters
void lol()
{
   for(int i=0; i<256;i++)
    {
        cout << (char)i;
    }
}
//____Function Main Menu
void menu()
{
    cout << "Hi where am i???___________>1\n";
    cout << "START______________________>2\n";
    cout << "LOL________________________>3\n";
    cout << "___________________________>4\n";
    cout << "___________________________>5\n";
    cout << "___________________________>6\n";
    cout << "___________________________>7\n";
    cout << "___________________________>8\n";
    cout << "___________________________>9\n";
    cout << "Exit_______________________>0\n";
    cout << "Chouse your destiny________>";
    cin >> menuStatus;
    switch (menuStatus)
    {
    case 1: break;
    case 2: startGame(); break;
    case 3: lol(); break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    case 8: break;
    case 9: break;
    case 0: break;
    default: {menu(); }
    }
    //return 1;
}
int main()
{
    cout << "\nHello world!\nHi Master!!!\nMenu status is "<<menuStatus<<"\n";
    menu();
    //cout << menuStatus;
    return 0;
}

