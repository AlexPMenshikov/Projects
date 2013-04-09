//____Libraries
#include <iostream>
#include <conio.h>

//____Namespace
using namespace std;

//____Global variables
int menuStatus=0;

//____Const
const unsigned long int big = 65000;

//____Function to clear all screen MUCH MORE SPAAAACCCEEEE
void cls()
{
    cout<<"Function to clear the screen";
    for(int i=0;i<90;i++)
    {
    cout<<"\n";
    }
}

//____Classes
//____Class Rabit
class ID
    {
        public:
        ID(int HP,int moveRange,bool readyToChild);
        ~ID() {}
        //Rabit(int setHP,int setMoveRange,bool setReadyToChild);
        //~Rabit() {}
        int HP;//Health Point
        int moveRange;
        bool readyToChild;
        int positionX;
        int positionY;
        void eat();
    }
class Rabit
{
    public:
    Rabit();
    ~Rabit() {}
    ID Rab;
};

//_____Constructor
Rabit::Rabit(int setHP,int setMoveRange,bool setReadyToChild)
{
    HP=setHP;
    moveRange=setMoveRange;
    readyToChild=setReadyToChild;
}

//____Eat func
void Rabit::ID::eat()
{
    cout<<"No\n";
    ID.HP++;
}

//____Create new rabbits
void generationRabit()
{
    Rabit Sanya(10,1,false);
    cout << "Sanya HP=" << Sanya.HP <<"\n";
    Sanya.eat();
    cout << "Sanya HP=" << Sanya.HP <<" ^_^ \n";
    Sanya.HP=150;
    cout << "Sanya HP=" << Sanya.HP <<" O_o \n";
    getch();
    cls();
   /*for(int i=1;i<10;i++)
    {
        Rabit id(30,3,false);
        cout << id.HP;
    }*/
    //cout << "!!!!  " <<id.HP;
}

//_____WRONG CLASSSS!!!!!!!!!!!!!!!!!!!!SSS!!!!!!!!!!!!!!
class Wolf
{
    public:
    int HP;//Health Point
    int moveRange;
    bool readyToChild;
    int hunt();
};


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
int exit()
{
    return 0;
}
//____Function Main Menu
void menu()
{
    //cls();
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
    case 0: exit(); break;
    //default: {exit(); }
    }
    //return 1;
}

int main()
{
    cout << "\nHello world!\nHi Master!!!\nMenu status is "<<menuStatus<<"\n";
    menu();
    cout << "SSSS " <<menuStatus;

    return 0;
}

