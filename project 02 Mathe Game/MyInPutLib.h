#pragma once

#include <iostream>
using namespace std;

namespace MyInPut
{
    int RandomNumber(int From, int To)
    {
       
        int randNum = rand() % (To - From + 1) + From;
        return randNum; 
    }

    int ShowHowManyRound()
    {
        int Rounds = 1;
        do
        {
            cout << "How Many Questuions do you need to to answer ?";
            cin >> Rounds;

        } while (Rounds > 10 || Rounds < 1);

        return Rounds;

    }

}