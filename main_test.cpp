#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include "map.hpp"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77            // here we define, the characters for the key press monitor function
#define KEY_SPACEBAR 32
#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_ESCAPE 27

class Character // character class ,but it holds basically everything
{
public:
    int maptXcoord;
    int maptYcoord;
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
    int stone;
    int food;
    int wood;
    int directionSymbol;
    int directionSymbolXcoord;
    int directionSymbolYcoord;
    int directionSymbolPreviousXcoord;
    int directionSymbolPreviousYcoord;
    int directionSymbolPreviousValue;
    bool backpack;
    double energy;

    void setStartingValues() // sets the starting values of the variables
    {
        backpack = false;
        maptXcoord = 45;
        maptYcoord = 45;
        itsXcoord = 54;
        itsYcoord = 59;
        itsPreviousXcoord = 54;
        itsPreviousYcoord = 59;
        itsPreviousValue = map2[54][59];
        monster1Xcoord = 60;
        monster1Ycoord = 60;
        monster1PreviousXcoord = 60;
        monster1PreviousYcoord = 60;
        monster1PreviousValue = map2[60][60];
        directionSymbol = 0;
        directionSymbolPreviousXcoord = 0;
        directionSymbolPreviousYcoord = 0;
        directionSymbolPreviousValue = 1;
        stone = 0;
        food = 0;
        wood = 0;
        energy = 5;
    }
    void createMap2() // function to print the map on the screen
    {
        SetConsoleTextAttribute(hConsole,14); // changes the colour
        cout<<"                         ###############################"<<endl;
        for(int i = maptXcoord ; i < maptXcoord + 19 ; i++)
        {
        cout<<"                         #";
        for(int j = maptYcoord ; j < maptYcoord + 29 ; j++)
            {
                if(map2[i][j] == 0)
                {
                    SetConsoleTextAttribute(hConsole, 2); // changes the colour
                    cout << "$"; //grass
                }
                else if(map2[i][j] == 1)
                {
                    SetConsoleTextAttribute(hConsole,9); // changes the colour
                    cout << "#";  //water
                }
                else if(map2[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole,12); // changes the colour
                    cout << "X";  //player
                }
                else if(map2[i][j] == 3)
                {
                    SetConsoleTextAttribute(hConsole,6); // changes the colour
                    cout << "R"; //stone
                }
                else if(map2[i][j] == 4)
                {
                    SetConsoleTextAttribute(hConsole,10); // changes the colour
                    cout << "W"; //wood
                }
                else if(map2[i][j] == 5)
                {
                    SetConsoleTextAttribute(hConsole,14); // changes the colour to gold
                    cout << "Z"; //zombie
                }
                else if(map2[i][j] == 6)
                {
                    SetConsoleTextAttribute(hConsole,4); // changes the colour
                    cout << "F"; //food
                }
                else if(map2[i][j] == 7)
                {
                    SetConsoleTextAttribute(hConsole,12); // changes the colour to red
                    cout << "+"; //direction Symbol
                }
                else if(map2[i][j] == 8)
                {
                    SetConsoleTextAttribute(hConsole,10); // changes the colour to green
                    cout << "#"; //Wood Block
                }
                else if(map2[i][j] == 9)
                {
                    SetConsoleTextAttribute(hConsole,6); // changes the colour to brown
                    cout << "#"; //Stone Block
                }
        }
        SetConsoleTextAttribute(hConsole,14); // changes the colour
        cout<<"#";
        cout << endl;

        }
    SetConsoleTextAttribute(hConsole,14); // changes the colour
        cout<<"                         ###############################"<<endl;
    }


    void backPack() // prints the backpack, with current resources and resources needed to create stuff
    {
        SetConsoleTextAttribute(hConsole,14);
        cout<<"                         ###############################"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #     Resource  Backpack:     #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         # Current resources available:#"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #"; SetConsoleTextAttribute(hConsole,10); cout<<"    Wood: "<<wood; SetConsoleTextAttribute(hConsole,6);if(wood<99 && wood>9)cout<<" ";else if(wood<10)cout<<"  ";  cout<<" Stone: "<<stone; SetConsoleTextAttribute(hConsole,14);if(stone>9 && stone <99) cout<<" ";else if(stone<10)cout<<"  "; cout<<"     #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #"; SetConsoleTextAttribute(hConsole,4); cout<<"    Food: "<<food;SetConsoleTextAttribute(hConsole,11);cout<<"   Diamond: 0";SetConsoleTextAttribute(hConsole,14);cout<<"     #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         # Resources Needed To Create: #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #"; SetConsoleTextAttribute(hConsole,6); cout<<"    Stone Block: 3 Stones.";SetConsoleTextAttribute(hConsole,14);cout<<"   #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #"; SetConsoleTextAttribute(hConsole,10); cout<<"    Wooden Block : 3 Wood.";SetConsoleTextAttribute(hConsole,14);cout<<"   #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #"; SetConsoleTextAttribute(hConsole,11); cout<<"  Diamond Armour: 7 Diamonds.";SetConsoleTextAttribute(hConsole,14);cout<<" #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         #   To Exit Press F3 Again.   #"<<endl;
        cout<<"                         #                             #"<<endl;
        cout<<"                         ###############################"<<endl;

    }


    void setMonsterCoordNew() // sets the new X,Y coordinates for the Zombie
    {
        int mnp = rand() % 5 + 1; // creates random number between 1 and 4, to choose direction

        if(mnp == 1) // zombie goes down
        {
            if(monster1Xcoord < 97 && map2[monster1Xcoord + 1][monster1Ycoord] != 1 && map2[monster1Xcoord + 1][monster1Ycoord] != 9)
            {
                monster1Xcoord++;
            }
            else
            {
                setMonsterCoordNew();
            }
        }
        else if(mnp == 2) // zombie goes left
        {
            if(monster1Ycoord > 0 && map2[monster1Xcoord][monster1Ycoord - 1] != 1 && map2[monster1Xcoord][monster1Ycoord - 1] != 9)
            {
                monster1Ycoord--;
            }
            else
            {
                setMonsterCoordNew();
            }
        }
        else if(mnp == 3) // zombie goes right
        {
            if(monster1Ycoord < 97 && map2[monster1Xcoord][monster1Ycoord + 1] != 1 && map2[monster1Xcoord][monster1Ycoord + 1] != 9)
            {
                monster1Ycoord++;
            }
            else
            {
                setMonsterCoordNew();
            }

        }
        else if(mnp == 4) // zombie goes up
        {
            if(monster1Xcoord > 0 && map2[monster1Xcoord + 1][monster1Ycoord] != 1 && map2[monster1Xcoord + 1][monster1Ycoord] != 9)
            {
                monster1Xcoord--;
            }
            else
            {
                setMonsterCoordNew();
            }
        }
    }

    void setDirectionSymbolCoord(int d) // Direction Display Symbol
    {
        if(d == 1) // checks if the character wants to move up
        {
            if(itsXcoord < 96) // if character is within the map - 1 position
            {
                map2[directionSymbolPreviousXcoord][directionSymbolPreviousYcoord] = directionSymbolPreviousValue;
                directionSymbolXcoord = itsXcoord - 1;
                directionSymbolYcoord = itsYcoord;
                if(map2[directionSymbolXcoord][directionSymbolYcoord] != 7 && map2[directionSymbolXcoord][directionSymbolYcoord] != 5)
                {
                directionSymbolPreviousValue = map2[directionSymbolXcoord][directionSymbolYcoord];
                }
                map2[directionSymbolXcoord][directionSymbolYcoord] = 7;
                directionSymbolPreviousXcoord = directionSymbolXcoord;
                directionSymbolPreviousYcoord = directionSymbolYcoord;
            }
        }

        else if(d == 2) // checks if the character wants to move down
        {
            if(itsXcoord > 0) // if character is within the map - 1 position
            {
                map2[directionSymbolPreviousXcoord][directionSymbolPreviousYcoord] = directionSymbolPreviousValue;
                directionSymbolXcoord = itsXcoord + 1;
                directionSymbolYcoord = itsYcoord;
                if(map2[directionSymbolXcoord][directionSymbolYcoord] != 7 && map2[directionSymbolXcoord][directionSymbolYcoord] != 5)
                {
                directionSymbolPreviousValue = map2[directionSymbolXcoord][directionSymbolYcoord];
                }
                map2[directionSymbolXcoord][directionSymbolYcoord] = 7;
                directionSymbolPreviousXcoord = directionSymbolXcoord;
                directionSymbolPreviousYcoord = directionSymbolYcoord;
            }
        }

        else if(d == 3) // checks if the character wants to move left
        {
            if(itsYcoord < 96) // if character is within the map - 1 position
            {
                map2[directionSymbolPreviousXcoord][directionSymbolPreviousYcoord] = directionSymbolPreviousValue;
                directionSymbolXcoord = itsXcoord;
                directionSymbolYcoord = itsYcoord - 1;
                if(map2[directionSymbolXcoord][directionSymbolYcoord] != 7 && map2[directionSymbolXcoord][directionSymbolYcoord] != 5)
                {
                directionSymbolPreviousValue = map2[directionSymbolXcoord][directionSymbolYcoord];
                }
                map2[directionSymbolXcoord][directionSymbolYcoord] = 7;
                directionSymbolPreviousXcoord = directionSymbolXcoord;
                directionSymbolPreviousYcoord = directionSymbolYcoord;
            }
        }

        else if(d == 4) // checks if the character wants to move right
        {
            if(itsYcoord > 0) // if character is within the map - 1 position
            {
                map2[directionSymbolPreviousXcoord][directionSymbolPreviousYcoord] = directionSymbolPreviousValue;
                directionSymbolXcoord = itsXcoord;
                directionSymbolYcoord = itsYcoord + 1;
                if(map2[directionSymbolXcoord][directionSymbolYcoord] != 7 && map2[directionSymbolXcoord][directionSymbolYcoord] != 5)
                {
                directionSymbolPreviousValue = map2[directionSymbolXcoord][directionSymbolYcoord];
                }
                map2[directionSymbolXcoord][directionSymbolYcoord] = 7;
                directionSymbolPreviousXcoord = directionSymbolXcoord;
                directionSymbolPreviousYcoord = directionSymbolYcoord;
            }
        }
    }

    void setXcordm(int a){ // decreases the X value, character moves up
        if(itsXcoord > 0)
        {
            itsXcoord = itsXcoord - a ;
    }
    }

    void setXcordp(int a){ // increases the X value, character moves down
        if(itsXcoord < 97){
            itsXcoord = itsXcoord + a;
    }
    }


    void setYcordm(int a){ // decreases the Y value, character moves left

        if(itsYcoord > 0)
    {
            itsYcoord = itsYcoord - a;
    }
    }

    void setYcordp(int a){ // increases the Y value, character moves right
        if(itsYcoord < 97){
            itsYcoord = itsYcoord + a;
                         }
    }

    int printCharacter() // sets character previous value/coordinates , updates the information of the map
    {
        setDirectionSymbolCoord(directionSymbol);
        int a = itsXcoord,b = itsYcoord;
        int ma= monster1Xcoord, mb = monster1Ycoord;
        int px = itsPreviousXcoord;
        int pmx = monster1PreviousXcoord;
        itsPreviousXcoord = a;
        monster1PreviousXcoord = ma;
        int py = itsPreviousYcoord;
        int pmy = monster1PreviousYcoord;
        itsPreviousYcoord = b;
        monster1PreviousYcoord = mb;
        int pv = itsPreviousValue;
        int pmv = monster1PreviousValue;
        if(map2[a][b] != 2 && map2[a][b] != 7)
        {
            itsPreviousValue = map2[a][b];
        }
        if(map2[ma][mb] != 5 && map2[ma][mb] != 2 && map2[ma][mb] != 7)
        {
            monster1PreviousValue = map2[ma][mb];
        }
        if(pmv != 5)
        {
        map2[pmx][pmy] = pmv;
        }
        map2[px][py] = pv;
        map2[a][b] = 2;
        map2[ma][mb] = 5;
        system("cls");
        cout<<endl;
        if(backpack == false)
        {
        createMap2();
        cout<<"                          Stones: "<<stone;
        cout<<"   Wood: "<<wood;
        cout<<"   Food: "<<food<<endl;
        cout<<"                         Energy:  "<<energy;
        cout<<"   To Open BP Press F3"<<endl;
        }
        else if(backpack == true)
        {
            backPack();
        }
        if(map2[a][b]==map2[ma][mb])
        {
            cout<<"You were eaten!"<<endl;
            exit(0);
        }
        else if(energy < 0.05)
        {
            gameOver();
        }
    }
    void add_resource(int pv) // resource counter
    {
        if (pv == 3)
        {
            stone += 5; // adds five more stones to the resources
        }
        else if (pv == 4)
        {
            wood++; // adds 1 wood to the resources
        }
        else if (pv == 6)
        {
            if (energy < 1)
            {
                energy += 1;
            }
            else
            {
                food++; //adds 1 food to the resources
            }
        }

    }

   void characterMovement() // Character movement, key press monitor
    {
        int c = 0;

        do
            {
                c = 0;

                switch ( ( c = getch() ) ) {

                case KEY_UP: // character moves up when the up arrow key is pressed
                    if(directionSymbol == 1 && directionSymbolPreviousValue != 1) //----> Water movement correction
                       {
                           if(maptXcoord>0 && maptXcoord == itsXcoord - 9) //checks for map location, so that the character does't leave the map
                        {
                            maptXcoord--;
                        }
                        setXcordm(1);
                        setMonsterCoordNew();
                        directionSymbol = 1;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                       }
                    else if (map2[itsXcoord -1][itsYcoord] != 1 && directionSymbol != 1) //----> Water movement correction
                    {
                        if(maptXcoord>0 && maptXcoord == itsXcoord - 9) //checks for map location, so that the character does't leave the map
                        {
                            maptXcoord--;
                        }
                        setXcordm(1);
                        setMonsterCoordNew();
                        directionSymbol = 1;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                    }
                    else{
                        directionSymbol = 1;
                        printCharacter();
                            break;}


                case KEY_DOWN: //character moves down when the down arrow key is pressed
                    if(directionSymbol == 2 && directionSymbolPreviousValue != 1) //----> Water movement correction
                       {
                           if(maptXcoord<79 && maptXcoord == itsXcoord - 9) //checks for map location, so that the character does't leave the map
                        {
                            maptXcoord++;
                        }
                        setXcordp(1);
                        setMonsterCoordNew();
                        directionSymbol = 2;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                       }
                    else if (map2[itsXcoord +1][itsYcoord] != 1 && directionSymbol != 2) //----> Water movement correction
                    {


                    if(maptXcoord<79 && maptXcoord == itsXcoord - 9) //checks for map location, so that the character does't leave the map
                    {
                        maptXcoord++;
                    }
                        setXcordp(1);
                        setMonsterCoordNew();
                        directionSymbol = 2;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                    }
                    else
                    {
                        directionSymbol =2;
                        printCharacter();
                        break;
                    }


                case KEY_LEFT: //character moves left when the left arrow key is pressed
                    if(directionSymbol == 3 && directionSymbolPreviousValue != 1) //----> Water movement correction
                       {
                           if(maptYcoord>0 && maptYcoord == itsYcoord - 9) //checks for map location, so that the character does't leave the map
                        {
                            maptYcoord--;
                        }
                        setYcordm(1);
                        setMonsterCoordNew();
                        directionSymbol = 3;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                       }

                    else if (map2[itsXcoord][itsYcoord -1] != 1 && directionSymbol != 3) //----> Water movement correction
                    {
                        if(maptYcoord>0 && maptYcoord == itsYcoord - 9) //checks for map location, so that the character does't leave the map
                        {
                            maptYcoord--;
                        }
                        setYcordm(1);
                        setMonsterCoordNew();
                        directionSymbol = 3;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                    }

                    else
                    {
                        directionSymbol = 3;
                        printCharacter();
                        break;
                    }


                case KEY_RIGHT: // character moves right when right arrow key is pressed
                    if(directionSymbol == 4 && directionSymbolPreviousValue != 1) //----> Water movement correction
                    {
                        if(maptYcoord<69 && maptYcoord == itsYcoord -14) //checks for map location, so that the character does't leave the map
                    {
                        maptYcoord++;

                    }
                        setYcordp(1);
                        setMonsterCoordNew();
                        directionSymbol = 4;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                    }

                    else if (map2[itsXcoord][itsYcoord +1] != 1 && directionSymbol != 4) //----> Water movement correction
                    {


                    if(maptYcoord<69 && maptYcoord == itsYcoord -14) //checks for map location, so that the character does't leave the map
                    {
                        maptYcoord++;
                    }
                        setYcordp(1);
                        setMonsterCoordNew();
                        directionSymbol = 4;
                        energy -= 0.05;
                        if (energy < 0.5 && food > 0)
                        {
                            energy += 1;
                            food -= 1;
                        }
                        printCharacter();
                        break;
                    }
                    else
                    {
                        directionSymbol = 4;
                        printCharacter();
                        break;
                    }

                case KEY_SPACEBAR: // Collects Resources when the spacebar is pressed

                    if(itsPreviousValue == 3 || itsPreviousValue == 4 || itsPreviousValue == 6)
                    {
                        add_resource(itsPreviousValue);
                        map2[itsXcoord][itsYcoord] = 0;
                    }
                    printCharacter();
                    break;

                case KEY_F3: //displays backpack when F3 is pressed
                    if(backpack == true)
                    {
                        backpack = false;
                        printCharacter();
                        break;
                    }
                    else if ( backpack == false)
                    {
                        backpack = true;
                        printCharacter();
                        break;
                    }

                case KEY_F1: // creates wood block when F1 is pressed
                    if(directionSymbolPreviousValue==1 && wood>2 && directionSymbolPreviousValue != 9 && directionSymbolPreviousValue != 8)
                    {
                    directionSymbolPreviousValue = 8;
                    wood = wood - 3;
                    printCharacter();
                    break;
                    }
                    else break;

                case KEY_F2: // creates stone block when F2 is pressed
                    if(directionSymbolPreviousValue==0 && stone>2 && directionSymbolPreviousValue != 1 && directionSymbolPreviousValue != 9)
                    {
                    directionSymbolPreviousValue = 9;
                    stone = stone - 3;
                    printCharacter();
                    break;
                    }
                    else break;

                case KEY_ESCAPE: // ask the player if they want to leave when they press ESC
                    string exit_game;
                    cout<<"Do you want to exit?(Y/N) : ";
                    cin>> exit_game;
                    if(exit_game == "Y" || exit_game == "y" || exit_game == "yes" || exit_game == "YES" || exit_game == "Yes")
                        {
                            exit(0);
                        }

                    else
                    {
                        system("cls");
                        printCharacter();
                    }

        }
        Sleep(10);
    }
    while(1);
    }
    void gameOver() //displays when users has been depeated
    {
     char response;
         cout<<"                         ###############################"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #          Game Over!         #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #           You Died          #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         #                             #"<<endl;
         cout<<"                         ###############################"<<endl;
 
         cout<<"Do you want to restart the game?(y/n)"<< endl;
         cin >>  response;
     if ((response == "y") || (response ==  "Y"))
     {

             setStartingValues();
             createMap2();
             printCharacter();
             characterMovement();
     }
     else if ((response == "n") || (response == "N"))
     {
       exit(0);
     }
 
 }
};
    void classSelection() // users gets to what type of character they want
    {
        string tclass;

        cout << "\nType your Dwarf class: \n\n";

        cout << "1   Collector - crafting skills & energy \n";
        cout << "2   Miner     - energy & health \n";
        cout << "3   Builder   - crafting skills \n";
        cout << "4   Warrior   - energy, health \n";
        cout << "5   Farmer    - health & crafting skills \n";
        cin >>  tclass;


    }

    void theName() // users gets to input their name

    {
        string myName;
        cout << "\nName of your character:  " << endl;
        cin >> myName;
    }

    void theIntro() // users gets to input their gender

    {
        string intro_gender;
        cout << "                           Welcome to The Fortress... \n" << endl;
        cout << "An infinite world of opportunities, riddled with treasure and danger!" << endl;
        cout << "Journey the vast land cautiously... here lurk monsters ready for Dwarf blood. \n" << endl;
        cout << "Choose your Dwarf wisely... \n\n";
        cout << "Male or Female? " << endl;
        cin >> intro_gender;
    }  
int main()
  {
    system("COLOR 02 ");
        theIntro();
        classSelection();
        theName();
      
    string start_game;
    cout << "Do you want to start the game?(Y/N)" << endl;
    cin >>  start_game;

    if ((start_game == "yes") || (start_game == "YES") || (start_game == "Y") || (start_game == "y"))
        {
            Character Hero;
            Hero.setStartingValues();
            Hero.createMap2();
            Hero.printCharacter();
            Hero.characterMovement();

        }
    else if ((start_game == "no") || (start_game == "NO") || (start_game == "n") || (start_game == "N"))
    {
        cout << "Are you sure?" << endl;                                                                                    // whole main function determines whether the player wants to play or not.
        cin >> start_game;
        if ((start_game == "no") || (start_game == "NO") || (start_game == "N") || (start_game == "n"))
        {
            Character Hero;
            Hero.setStartingValues();
            Hero.createMap2();
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
