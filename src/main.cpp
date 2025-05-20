/*
Universidad Amerike
Author: José Sierra
Final Project
Date: 28/04/25
Description: This is my final project
*/

#include <iostream>
#include <limits>
using namespace std;

//These variables are used to determine which direction the game will play
int Decision = 0;
int *pDecision = &Decision;
int Race = 0;

//This Class is used to modify values of the character
class Events
{
private:
    int Life = 100;
    int Ki = 5;
    int Stamina = 4;
public:

void RecoverStamina()
{
    if (Stamina != 4)
    {
        Stamina = Stamina + 1;
    }
}

void Dodge()
{   
    if (Stamina >= 2)
    {
        Stamina = Stamina - 2;
    }
}

int getStamina()
{
    cout << "Stamina: " << Stamina << "\n";

    return Stamina;
}

void LoseLife(int Value)
{
    bool Loop = true;
    if (Value > Life)
    {
        while (Loop)
        {
            Value = Value - 1;
            
            if (Value == Life)
            {
                Loop = false;
            }
            
        }
        
        
    }
    
    Life = Life - Value;

    cout << "Life left: " << Life << "\n";
}

void getLife()
{
    cout << "Life: " << Life << "\n";;
}

int getLifeForControlStatements()
{
    return Life;
}

void LoseKi(int Value)
{
    if (Value <= Ki)
    {
        Ki = Ki - Value;
    }
    
}

void getKi()
{
    cout << "Ki: " << Ki << "\n";
}

void RecoverKi(int Value)
{
    Ki = Ki + Value;    
}

int getKiForControlStatements()
{
    return Ki;
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

//This function automates the way of the selection boxes for actions are structured.
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
    system("cls");

}

void FinalDecision(string Text)
{
    bool Loop = true;
    while (Loop)
    {
        system("cls");
        NewEvents.getLife();
        NewEvents.getKi();
        NewEvents.getStamina();
        
        text_box(Text);
        text_box("What will you do?");
        special_text_box("1-Combo Attack");
        special_text_box("2-Kamehameha");
        special_text_box("3-Sun");
        special_text_box("4-Exit game");

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
    system("cls");

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

        // Attack SCENE #1

    *pKeepTextOfTextBox = "Cooler lunges at you looking to connect a blow!!!!!";
    Decisions(*pKeepTextOfTextBox);
        
    switch (*pDecision)
    {
    case 1:
        text_box("You also attacked him, exchanging blows with great aggressiveness, causing a great damage to him, but also a little of damage to you.....");
        NewEvents.LoseLife(20);
        break;
    case 2:

        text_box("You tried to launch ki blast at Cooler, but that was not enough to make him step back, causing Cooler to punch you in the face, sending you at a bunch of rocks, causing great damage");
        NewEvents.LoseLife(30);
        NewEvents.LoseKi(2);
        NewEvents.getKi();
        break;
    case 3:
        text_box("Cooler tried to punch you, but you dodge it to attack him from behind");
        NewEvents.Dodge();
        break;
    case 4:
        text_box("You made yourself stronger than before making your Ki go up, but same time making Cooler angrier");
        NewEvents.RecoverKi(10);
        NewEvents.getKi();
        break;

    case 5:
    
        exit(0);
        break;
    }
    cin.ignore();
    cin.get();
    system("cls");
    
        //Cinematic SCENE #1

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
        *pKeepTextOfTextBox = "You Keep punching Cooler, but then Cooler Dodges one of your attacks and tries to punch you!!!";
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

        //Attack SCENE #2

    Decisions(*pKeepTextOfTextBox);
    system("cls");

    switch (*pDecision)
    {
    case 1:
        *pKeepTextOfTextBox = "You attacked him aswell, for luck you connect more hits than him, causing great damage to him!!!";
        text_box(*pKeepTextOfTextBox);
        NewEvents.LoseLife(15);
        NewEvents.RecoverStamina();
        break;
    case 2:
        *pKeepTextOfTextBox = "That is not effective on him, which causes him to keep hitting you, causing more damage.";
        text_box(*pKeepTextOfTextBox);
        NewEvents.LoseLife(15);
        NewEvents.LoseKi(2);
        NewEvents.getKi();
        NewEvents.RecoverStamina();
        break;
    case 3:
        *pKeepTextOfTextBox = "You dodge him again to keep punching him";
        text_box(*pKeepTextOfTextBox);
        NewEvents.Dodge();
        break;
    case 4:
        *pKeepTextOfTextBox = "You decided to keep charging Ki causing that Cooler can punch you directly on the face, causing great damage";
        text_box(*pKeepTextOfTextBox);
        NewEvents.RecoverKi(10);
        NewEvents.getKi();
        NewEvents.LoseLife(15);
        break;
    case 5:

        exit(0);
        break;
    }
    cin.ignore();
    cin.get();
    system("cls");

        //Cinematic SCENE #2

    switch (*pDecision)
    {
    case 1:   
        *pKeepTextOfTextBox = "Cooler increases its power even further beyond decided to Kill you and he goes right to your position!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 2:
        *pKeepTextOfTextBox = "You get recover from the attack and watch that Cooler wants to Keep punchin you!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 3:
        *pKeepTextOfTextBox = "You Keep punching Cooler, but then Cooler Dodges one of your attacks and tries to punch you again!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 4:
        *pKeepTextOfTextBox = "Cooler is getting closer to you to attack again!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 5:

        exit(0);
        break;
    }

        //Attack SCENE #3

    Decisions(*pKeepTextOfTextBox);
    system("cls");

    switch (*pDecision)
    {
    case 1:
        *pKeepTextOfTextBox = "You Keep attacking causing more damage, but causing a great damage to you!!!";
        text_box(*pKeepTextOfTextBox);
        NewEvents.LoseLife(25);
        NewEvents.RecoverStamina();
        break;
    case 2:
        
        if (NewEvents.getKiForControlStatements() >= 15 )
        {
            *pKeepTextOfTextBox = "You charged a great Ki attack causing great great damage against him";
            text_box(*pKeepTextOfTextBox);
            NewEvents.LoseKi(15);
            NewEvents.getKi();
        }
        else if (NewEvents.getKiForControlStatements() >= 10 )
        {
            *pKeepTextOfTextBox = "You charged a Ki attack causing great damage against him";
            text_box(*pKeepTextOfTextBox);
            NewEvents.LoseKi(10);
            NewEvents.getKi();
        }
        else if (NewEvents.getKiForControlStatements() < 10)
        {
            *pKeepTextOfTextBox = "You had not enough Ki to attack him so he punched again....";
            text_box(*pKeepTextOfTextBox);
            NewEvents.LoseLife(20);
            NewEvents.getKi();
            NewEvents.RecoverStamina();
        }

        break;
    case 3:
        *pKeepTextOfTextBox = "You dodge him again";
        text_box(*pKeepTextOfTextBox);
        NewEvents.Dodge();
        break;
    case 4:
        *pKeepTextOfTextBox = "You decided to charge Ki causing that Cooler can punch you directly on the face, causing great damage";
        text_box(*pKeepTextOfTextBox);
        NewEvents.LoseLife(25);
        NewEvents.RecoverKi(15);
        break;
    case 5:

        exit(0);
        break;
    }
    cin.ignore();
    cin.get();
    system("cls");

        //Cinematic SCENE #3

        switch (*pDecision)
    {
    case 1:   
        *pKeepTextOfTextBox = "Cooler is getting tired of it, so he is disposed to destroy you with a powerfull attack!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 2:
        *pKeepTextOfTextBox = "Cooler is very mad at you and its disposed to destroy the planet only for kill you!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 3:
        
        *pKeepTextOfTextBox = "Cooler gets angrier and increases its speed so you cant dodge him causing you a lot of damage";
        text_box(*pKeepTextOfTextBox);
        NewEvents.LoseLife(30);

    case 4:
        *pKeepTextOfTextBox = "Cooler Laughs at you and starts to creating a powerfull attack!!!";
        text_box(*pKeepTextOfTextBox);
        break;
    case 5:

        exit(0);
        break;
    }
    cin.ignore();
    cin.get();
    system("cls");

    // Final SCENE
    
    if (NewEvents.getLifeForControlStatements() <= 30)
    {
        *pKeepTextOfTextBox = "You tried everything you could to defeat him... But that was not enough... You lost against Cooler, making Goku lost against Freezer and his brother, corrupting the timeline....";
        text_box(*pKeepTextOfTextBox);
        cin.ignore();
        cin.get();
        exit(0);
    }
    else if (NewEvents.getLifeForControlStatements() >= 35)
    {
        if (Race == 1)
        {
            *pKeepTextOfTextBox = "Somenthing deep inside of you starts to burn feeling so angry and you start to feeling stronger, an aura starts to surround you....";
            text_box(*pKeepTextOfTextBox);
            cin.ignore();
            cin.get();
            system("cls");
            system("COLOR 0E");
            *pKeepTextOfTextBox = "You Transformed into a Super Saiyan!!!!";
            text_box(*pKeepTextOfTextBox);
            cin.ignore();
            cin.get();
            system("cls");
            *pKeepTextOfTextBox = "Cooler and Freezer looked at you terrified, the only thing you can thing is only destroy Cooler";
            text_box(*pKeepTextOfTextBox);
            cin.ignore();
            cin.get();
            system("cls");
            *pKeepTextOfTextBox = "This will be your final attack";
            FinalDecision(*pKeepTextOfTextBox);
            switch (*pDecision)
            {
            case 1:   
                *pKeepTextOfTextBox = "You attacked Cooler before he could launch its attack, with no mercy, you maked him fall to its dead inside of the planet";
                text_box(*pKeepTextOfTextBox);
                break;
            case 2:
                *pKeepTextOfTextBox = "You charged a powerfull Kamehameha making the SuperNova of Cooler get back to him, eliminating him in the process";
                text_box(*pKeepTextOfTextBox);
                break;
            case 3:
                
                *pKeepTextOfTextBox = "You attacked Cooler causing cancel its attack and you make him fly away, taking the oportunity to charge a Kamehameha and send him at the Sun";
                text_box(*pKeepTextOfTextBox);

            case 4:
                exit(0);
                break;
            }
            cin.ignore();
            cin.get();
            system("cls");
        }
        else if (Race == 2)
        {
            
        }
        else if (Race == 3)
        {
            /* code */
        }
        
        *pKeepTextOfTextBox = "Thanks to you the time line is safe again helping Goku with Freezers brother and dont let him destroy the time line";
        text_box(*pKeepTextOfTextBox);
        cin.ignore();
        cin.get();
        special_text_box("The End");
        cin.ignore();
        cin.get();
        

    }
    
    else if (NewEvents.getLifeForControlStatements() > 60)
    {
        *pKeepTextOfTextBox = "Cooler was trying to charge his super attack when you managed to attack him from behind sending him to the center of the planet where he dies desintegrated";
        text_box(*pKeepTextOfTextBox);
    }
    
    system("COLOR 0F");

    return 0;
    
}