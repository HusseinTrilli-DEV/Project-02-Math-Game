#include <iostream>
#include<cstdlib>
#include "MyInPutLib.h";

using namespace std;
  
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Max = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };


int ReadLevel()
{
    int Choice = 1;
    do
    {

        cout << "Enter Questions Level [1]Easy, [2]Med, [3]Hard, [4]Max. ? " ;
        cin >> Choice;
    } while (Choice < 1 || Choice>4);
    return Choice;
}

int ReadOperationType()
{
    int Choice2 = 1;
    do
    {

        cout << "Enter Operation Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix. ? " ;
        cin >> Choice2;
    } while (Choice2 < 1 || Choice2>4);
    return Choice2;
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

int QuestionLevelNumber(enQuestionLevel LEVEL)
{
    switch (LEVEL)
    {
    case enQuestionLevel::Easy:
        return MyInPut::RandomNumber(1, 30);
        break;
    case enQuestionLevel::Med:
        return MyInPut::RandomNumber(30, 60);
        break;
    case enQuestionLevel::Hard:
        return MyInPut::RandomNumber(60, 90);
        break;
    default:
        return MyInPut::RandomNumber(1, 90);
    }
}

char OperationType(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return '+';
        break;
    case enOperationType::Sub:
        return '-';
        break;
    case enOperationType::Mul:
        return '/';
        break;
    case enOperationType::Div:
        return '*';
        break;
    default:
        return '+';
    }
}

int GetResults(char opTYPE,int Number1,int Number2)
{
    switch (opTYPE)
    {
    case '+':
        return Number1 + Number2;
        break;
    case '-':
        return Number1 - Number2;
        break;
    case '/':
        return Number1 / Number2;
        break;
    case '*':
        return Number1 * Number2;
        break;

    }
}

struct stGameInfo
{
    int PassTimes=0;
    int FailTimes=0;
    int gameRound=0;
    int LEVEL=0;
    int OperationTYPE=0;
    int RightAnswer=0;
};

void FillRoundsInfo(int HowManyRound, stGameInfo &Game)
{   
 Game.LEVEL=   ReadLevel();
 Game.OperationTYPE =   ReadOperationType();
 char opTYPE = OperationType((enOperationType)Game.OperationTYPE);
 Game.gameRound = HowManyRound;
 
     for (short GameRound = 1; GameRound <= HowManyRound; GameRound++)
     {
         int Number1 = QuestionLevelNumber((enQuestionLevel)Game.LEVEL);
         int Number2 = QuestionLevelNumber((enQuestionLevel)Game.LEVEL);
         int GessResults=0;
       
       Game.RightAnswer = GetResults(opTYPE, Number1, Number2);
         ////////////////////
         cout << "\nQuestions [" << GameRound << "/" << HowManyRound << "]\n" << endl;
         cout << Number1 << endl;;
         cout << Number2 << " " << opTYPE;
         cout << "\n-----------\n";
         cin >> GessResults;

         if (GessResults == Game.RightAnswer)
         {
;
             Game.PassTimes++;
             system("color 2F"); //green
             cout << "\nRight Answer :-)\n";

         }
         else
         {

             Game.FailTimes++;
             cout << "\a";
             cout << "\nwrong Answer :-)" << endl;
             system("color 4F");  //red 
             cout << "the Right Answer is : " << Game.RightAnswer << endl;

         }
         
       
     }
   
}

void FinalResultsShow(stGameInfo &Game)
{
    cout << "\n-----------------------------------------\n" << endl;
    if (Game.PassTimes > Game.FailTimes)
    {
        system("color 2F"); //green
        cout << "\tFinal Results is PASS :-)\n";
        cout << "\n-----------------------------------------\n" << endl;

    }    
    else
    {
        system("color 4F");  //red
        cout << "\tFinal Results is FAIL :-)\n";
        cout << "\a";
        cout << "\n-----------------------------------------\n" << endl;

    }
       
}

void Finalresults(stGameInfo &Game)
{
    string arrQlevel[4] = { "Easy","Med","Hard","Mix" };
    string arrOpType[5] = { "Add","Sub","Mul","Div","Mix" };
    cout << "Number Of Questions: "<<Game.gameRound<< endl;
    cout << "Question Level: " << arrQlevel[Game.LEVEL-1] << endl;
    cout << "Operation Type: " << arrOpType[Game.OperationTYPE-1] << endl;
    cout << "Number Of right Answers: "<<Game.PassTimes << endl;
    cout << "Number Of Wrong Answers: " << Game.FailTimes << endl;
    cout << "\n----------------------------------------\n";

}



void StartGame()
{
   
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();  stGameInfo Game;
        FillRoundsInfo(MyInPut::ShowHowManyRound(),Game);
      
        FinalResultsShow( Game);
        Finalresults(Game);
        cout << "\ndo you want to play again y/n ?\n" << endl;
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)(NULL));
   StartGame();

	return 0;
}
