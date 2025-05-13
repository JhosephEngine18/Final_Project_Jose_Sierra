/*
Universidad Amerike
Author: José Sierra
Final Project
Date: 28/04/25
Description: This codes uses contructors with default parameters
*/

#include <iostream>
#include <limits>
using namespace std;

int Decision = 0;
int *pDecision = &Decision;
int Race = 0;
class Events
{
private:
    int Life = 100;
    int Ki = 5;
    int Stamina = 6;
public:

void RecoverStamina()
{
    Stamina = Stamina + 1;
}

void Dodge()
{
    Stamina = Stamina - 2;
}

void getStamina()
{
    cout << "Stamina: " << Stamina << "\n";
}

void LoseLife(int Value)
{
    Life = Life - Value;

    cout << "Life left: " << Life << "\n";
}

void getLife()
{
    cout << "Life: " << Life << "\n";;
}

void LoseKi(int Value)
{
    Ki = Ki - Value;
}

void getKi()
{
    cout << "Ki: " << Ki << "\n";;
}

void RecoverKi(int Value)
{
    Ki = Ki + Value;    
}

};

//This function simulates the way text boxes work in a video game and saves a few lines of code
void text_box(string text)
{
    cout << text << "\n"; 
}

//This function is being used to represent the action options within the game
void special_text_box(string text)
{
    cout << "|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << text << "\n";
}

//This function establishes the selected character apart from checking if the player actually selects a playable character
void CharacterSelection()
{
    bool Loop = true;
    while (Loop)
    {
        system("cls");
        text_box("Choose your Character");
        special_text_box("1-Saiyan");
        special_text_box("2-Namekian");
        special_text_box("3-Freezer Race");
        cin >> Race;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            system("cls");
        }
        
        if (Race <= 0 || Race >= 4)
        {
            system("cls");
            text_box("You have not chosen any character");
            cin.ignore();
            cin.get();
        }
        
        
        if (Race > 0 && Race < 4)
        {
            Loop = false;
        }


    }
    
}

Events NewEvents;

//This function automates the way the selection boxes for actions are structured.
void Decisions(string Text)
{
    bool Loop = true;
    while (Loop)
    {
        system("cls");
        NewEvents.getLife();
        NewEvents.getKi();
        NewEvents.getStamina();
        
        text_box(Text);
        text_box("What do you want to do?");
        special_text_box("1-Attack");
        special_text_box("2-Attack from a distance");
        special_text_box("3-Dodge");
        special_text_box("4-Charge Ki");
        special_text_box("5-Exit game");

        cin >> *pDecision;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            system("cls");
        }
        if (*pDecision <= 0 || *pDecision >= 6)
        {
            system("cls");
            text_box("You have not selected any option");
            cin.ignore();
            cin.get();
        }
        else
        {
            Loop = false;
        }
    }

}


int main()
{
    string KeepTextOfTextBox;
    string *pKeepTextOfTextBox = &KeepTextOfTextBox;
    system("cls");
    text_box("You are a time patroller whose duty is to prevent bad people from altering the main time line");
    text_box("they called you to let you know that someone has broken into the sacred timeline in the year 762");
    text_box("when you arrive at the place you get the surprise that Goku will not only face Freezer in the Namek fight");
    text_box("his brother Cooler meets him ready to defeat him,");
    text_box("however, it's not the only thing you notice...");
    cout << "\n";
    text_box("You notice that Cooler and Freezer have an unusual increase in power.");
    text_box("Your duty will be to help Goku defeat Cooler and weaken Freezer enough for Goku to defeat him.");
    cout << "\n";
    text_box("But be careful if you make the mistake of not letting history fluctuate as it should, the consequences can be dire......");
    cin.get();
    CharacterSelection();
    system("cls");

    *pKeepTextOfTextBox = "Cooler lunges at you looking to connect a blow!!!!!";
    Decisions(*pKeepTextOfTextBox);
        
    switch (*pDecision)
    {
    case 1:
        text_box("You also attacked him, exchanging blows with great aggressiveness, causing a great damage to him, but also a little of damage to you.....");
        NewEvents.LoseLife(15);
        break;
    case 2:

        text_box("You tried to launch ki blast at Cooler, but that was not enough to make him step back, causing Cooler to punch you in the face, sending you at a bunch of rocks, causing great damage");
        NewEvents.LoseLife(25);
        break;
    case 3:
        text_box("Cooler tried to punch you, but you dodge it to attack him from behind");
        NewEvents.Dodge();
        break;
    case 4:
        text_box("You made yourself stronger than before making your Ki go up, but same time making Cooler angrier");
        NewEvents.RecoverKi(20);
        NewEvents.getKi();
        break;

    case 5:
    
        exit(0);
        break;
    }
    cin.ignore();
    cin.get();
    system("cls");
    
    switch (*pDecision)
    {
    case 1:
        *pKeepTextOfTextBox = "Just for a moment you escape from Cooler to rest just a moment, but Cooler finds you and wants to Connect another attack!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 2:
        *pKeepTextOfTextBox = "You get recover from the attack and watch that Cooler wants to Keep punchin you!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 3:
        *pKeepTextOfTextBox = "You Keep punching Cooler, but then Cooler Dodges one of your attacks and try to punch you!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 4:
        *pKeepTextOfTextBox = "Cooler is getting closer to you!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 5:

        exit(0);
        break;
    }

    Decisions(*pKeepTextOfTextBox);
    system("cls");

            
    return 0;
    
}