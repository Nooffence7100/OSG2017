//From this it should be very simple to increase the size of the map,add color,add points, basically pretty easy from now to do anything we want...
//Not a bad idea to figure out how to remove the flicker, could ask the guy again...
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<cstdlib>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACEBAR 32
#define KEY_ESCAPE 27
int map1[10][10] =
    {
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,3,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,4,1,0,0,0,0,6,0,
    1,1,1,1,1,1,1,1,1,1,
    6,0,0,1,0,3,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,4,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,3,0,0,0,
       };
class Character
{
public:
    int itsPreviousXcoord;
    int itsPreviousYcoord;
    int itsPreviousValue;
    int itsXcoord;
    int itsYcoord;
    int monster1Xcoord;
    int monster1PreviousXcoord;
    int monster1Ycoord;
    int monster1PreviousYcoord;
    int monster1PreviousValue;
    void setStartingValues()
    {
        itsXcoord = 4;
        itsYcoord = 4;
        itsPreviousXcoord = 4;
        itsPreviousYcoord = 4;
        itsPreviousValue = 0;
        monster1Xcoord = 7;
        monster1Ycoord = 7;
        monster1PreviousXcoord = 7;
        monster1PreviousYcoord = 7;
        monster1PreviousValue = map1[7][7];

    }
    void createMap()
    {
        for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ;j < 10; j++)
            {
                if(map1[i][j] == 0)
                {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout<<"$";
                }
                else if(map1[i][j] == 1)
                {
                    SetConsoleTextAttribute(hConsole,9);
                    cout<<"#";
                }
                else if(map1[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole,12);
                    cout<<"X";
                }
                else if(map1[i][j] == 3)
                {
                    SetConsoleTextAttribute(hConsole,6);
                    cout<<"M"; //minerals
                }
                else if(map1[i][j] == 4)
                {
                    SetConsoleTextAttribute(hConsole,10);
                    cout<<"W"; //wood
                }
                else if(map1[i][j] == 5)
                {
                    SetConsoleTextAttribute(hConsole,14);
                    cout<<"Z"; //gold
                }
                else if(map1[i][j] == 6)
                {
                    SetConsoleTextAttribute(hConsole,4);
                    cout << "F"; //food
                }

        }
        cout << endl;

    }
    }
    int getXCoord()
    {
        return itsXcoord;
    }

    void setXcord(int xCoord){
        itsXcoord = itsXcoord + xCoord;
    }

    void setMonsterXcoordm()
    {
        monster1Xcoord = monster1Xcoord - 1;
    }

    void setMonsterXcoordp()
    {
        monster1Xcoord = monster1Xcoord + 1;
    }

    void setMonsterYcoordm()
    {
        monster1Ycoord = monster1Ycoord - 1;
    }

    void setMonsterYcoordp()
    {
        monster1Ycoord = monster1Ycoord + 1;
    }


    void setXcordm(int a){
        if(itsXcoord > 0)
        {
            itsXcoord = itsXcoord - a ;
    }
    }

    void setXcordp(int a){
        if(itsXcoord < 9){
            itsXcoord = itsXcoord + a;
    }
    }

    int getYCoord()
    {
        return itsYcoord;
    }

    void setYcord(int yCoord){
        if(yCoord > -1){
            itsYcoord = itsYcoord + yCoord;
    }
    }

    void setYcordm(int a){

        if(itsYcoord > 0)
    {
            itsYcoord = itsYcoord - a;
    }
    }
void setMonsterXcoord()
    {
        monster1Xcoord = monster1Xcoord + 1;
    }
    void setYcordp(int a){
        if(itsYcoord < 9){
            itsYcoord = itsYcoord + a;
                         }
    }

    int printCharacter()
    {
        int a = itsXcoord,b = itsYcoord;
        int ma= monster1Xcoord, mb = monster1Ycoord;
        int px = itsPreviousXcoord;
        int pmx = monster1PreviousXcoord;
        itsPreviousXcoord = itsXcoord;
        monster1PreviousXcoord = monster1Xcoord;
        int py = itsPreviousYcoord;
        int pmy = monster1PreviousYcoord;
        itsPreviousYcoord = itsYcoord;
        monster1PreviousYcoord = monster1Ycoord;
        int pv = itsPreviousValue;
        int pmv = monster1PreviousValue;
        if(map1[a][b]!=2)
        {
            itsPreviousValue = map1[a][b];
        }
        if(map1[a][b]!=5)
        {
            monster1PreviousValue = map1[a][b];
        }
        map1[pmx][pmy] = pmv;
        map1[px][py] = pv;
        map1[a][b] = 2;
        map1[ma][mb] = 5;
        system("cls");
        createMap();
        if(map1[a][b]==map1[ma][mb])
        {
            cout<<"You were eaten!"<<endl;
            exit(0);
        }
    }
    void characterMovement()
    {
        int c = 0;
        do
            {
                c = 0;

                switch ( ( c = getch() ) ) {
                case KEY_UP:
                    setXcordm(1);
                    printCharacter();
                    break;

                case KEY_DOWN:
                    setXcordp(1);
                    printCharacter();
                    break;

                case KEY_LEFT:
                    setYcordm(1);
                    printCharacter();
                    break;

                case KEY_RIGHT:
                    setYcordp(1);
                    printCharacter();
                    break;

                case KEY_SPACEBAR:
                    map1[itsXcoord][itsYcoord] = 0 ;
                    printCharacter();
                    break;

                case KEY_ESCAPE:
                    string exit_game;
                    cout<<"Do you want to exit?(Y/N) : ";
                    cin>> exit_game;
                    if(exit_game == "Y" || exit_game == "y" || exit_game == "yes" || exit_game == "YES" || exit_game == "Yes")
                    exit(0);
                    else
                    {
                        system("cls");
                        printCharacter();
                    }

        }
        Sleep(25);
    }
    while(1);
    }
};
int main()
{
    string start_game;
    cout << "Do you want to start the game?(Y/N)" << endl;
    cin >>  start_game;
    //Sleep(500);

    if ((start_game == "yes") || (start_game == "YES") || (start_game == "Y") || (start_game == "y"))
        {
            Character Hero;
            Hero.setStartingValues();
            Hero.createMap();
            Hero.printCharacter();
            Hero.characterMovement();
        }
    else if ((start_game == "no") || (start_game == "NO") || (start_game == "n") || (start_game == "N"))
    {
        cout << "Are you sure?" << endl;
        cin >> start_game;
        if ((start_game == "no") || (start_game == "NO") || (start_game == "N") || (start_game == "n"))
        {
            Character Hero;
            Hero.setStartingValues();
            Hero.createMap();
            Hero.printCharacter();
            Hero.characterMovement();
        }
        else
        {
            cout << "You left the game" << endl;
        }
    }





    else if ((start_game == "no") || (start_game == "NO") || (start_game == "n") || (start_game == "N"))
    cout << "You left the game" << endl;



return 0;
}
