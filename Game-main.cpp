//From this it should be very simple to increase the size of the map,add color,add points, basically pretty easy from now to do anything we want...
//Not a bad idea to figure out how to remove the flicker, could ask the guy again...
#include<iostream>
#include<windows.h>
#include<conio.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
int map1[10][10] =
    {
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,
       };
class Character
{
public:
    int itsPreviousXcoord;
    int itsPreviousYcoord;
    int itsPreviousValue;
    int itsXcoord;
    int itsYcoord;
    void setStartingValues()
    {
        itsXcoord=4;
        itsYcoord=4;
        itsPreviousXcoord=4;
        itsPreviousYcoord=4;
        itsPreviousValue=0;
    }
    void createMap()
    {
        for(int i = 0 ; i<10 ; i++)
    {
        for (int j=0;j<10;j++)
            {
                if(map1[i][j]==0)
                {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout<<"$";
                }
                else if(map1[i][j]==1)
                {
                    SetConsoleTextAttribute(hConsole,9);
                    cout<<"#";
                }
                else if(map1[i][j]==2)
                {
                    SetConsoleTextAttribute(hConsole,12);
                    cout<<"X";
                }

        }
        cout<<endl;

    }
    }
    int getXCoord()
    {
        return itsXcoord;
    }

    void setXcord(int xCoord){
    itsXcoord = itsXcoord + xCoord;
    }

    void setXcordm(int a){
        if(itsXcoord>0)
        {
            itsXcoord = itsXcoord - a ;
    }
    }

    void setXcordp(int a){
        if(itsXcoord<9){
    itsXcoord= itsXcoord + a;
    }
    }

    int getYCoord()
    {
        return itsYcoord;
    }

    void setYcord(int yCoord){
    if(yCoord>-1){
    itsYcoord = itsYcoord + yCoord;
    }
    }

    void setYcordm(int a){

    if(itsYcoord>0)
    {
    itsYcoord=itsYcoord-a;
    }
    }

    void setYcordp(int a){
        if(itsYcoord<9){
    itsYcoord=itsYcoord+a;
    }
    }

    int printCharacter()
    {
        int a=itsXcoord,b=itsYcoord;
        int px=itsPreviousXcoord;
        itsPreviousXcoord=itsXcoord;
        int py=itsPreviousYcoord;
        itsPreviousYcoord=itsYcoord;
        int pv=itsPreviousValue;
        itsPreviousValue=map1[a][b];
        map1[px][py]=pv;
        map1[a][b]=2;
        system("cls");
        createMap();
    }
    void characterMovement()
    {
        int c=0,a=0,b=0;
        do
            {
                c = 0;

                switch((c=getch())) {
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
        }

    }
    while(1);
    }
};
int main()
{
Character Hero;
Hero.setStartingValues();
Hero.createMap();
Hero.printCharacter();
Hero.characterMovement();
return 0;
}
