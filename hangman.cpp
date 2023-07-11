#include <iostream>
#include <time.h>
#include<conio.h>
using namespace std;

int main()
{

    int num1;
    bool flag;
    cout<<"Would you like to play against:\n1.Computer\n2.Another User\n";
    cin>>num1;
    srand(time(0));
    int y = 1 + rand() % 10;
    string bank[10] = {"hello", "animal", "pineapple", "rock", "scissors", "ronaldo", "messi", "football", "games", "programming"};

    if (num1 == 2)
    {
        bank[0] = "";
        cout << "Enter word for other user to guess\n";
        char ch;
        do {
            ch = getch();
            if (ch != '\r') { 
                bank[0] += ch;
                cout << "*"; 
            }
        } while (ch != '\r');

        cout << endl;
        y = 0;
    }
    int lives = 10;
    int count = 0;
    string word = bank[y];

    for (int i=0; bank[y][i] != '\0'; i++)
    {
        count++;
    }

    char correct[count];
    for (int i=0; i<count; i++)
        correct[i] = '*';

    char letter[count];
    for (int i=0; i<count; i++)
        letter[i] = '\0';

    char guessed[count];

    for (int i=0; i<count; i++)
        guessed[i] = '$';
    
    int j=0;
    int count3 = 0;

    while (lives >= 1)
    {
        cout<<"Hangman Game. \tLives: "<<lives<<endl<<endl;
        cout<<"Word: \t";


            for (int i=0; i<count; i++)
            {
                cout<<correct[i];
            }

        cout<<"\n\nLetters Attempted: ";
        for (int i=0; i<j+1; i++)
        {
            cout<<letter[i]<<" ";  
        }

        cout<<endl<<endl<<"Enter character: ";

        cin>>letter[j];
        bool test = 0;
        for (int i=0; i<j; i++)
        {   
            if (letter[j] == letter[i])
            {
                letter[j] = NULL;;
                cout << "Invalid input. Please enter a different letter." << endl;
                test = 1;
                break;
            }
            guessed[i] = letter[j];
        }

        if (test)
            continue;

        if (letter[j] == 'E')
            return 0;
        
        while (cin.fail() || cin.peek() != '\n')
        {
            cout << "Invalid input. Please enter a single letter." << endl;
            cin>>letter[j];
        }

        int count2 = 0;
        for (int i=0; i<count; i++)
        {
            if (letter[j] != bank[y][i])
            {
            //    cout<<correct[i];
                count2++;
            }
            else
            {
            //    cout<<letter[j]<<" ";
                correct[i] = letter[j];
                count3++;
            }

        }

        if (count2 == count)
            lives--;
        count2 = 0;

        j++;
        cout<<endl<<endl;

        for (int i=0; i<count; i++)
            cout<<correct[i];

        cout<<endl;

        if (count3 >= count)
        {
            int u;
            cout<<"You Won!\n";
                return 0;
        }


        int x;
        system("pause");
        system("CLS");
    }
    int w;
    cout<<"You lost\n";
return 0;

} 