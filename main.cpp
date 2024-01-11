#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;

int sceltaDimensione();
void generazioneNumeroDaIndovinare(int casuale[], int dimensione);
void inputTentativi(int tentativi[], int dimensione);
// void stampaArray(int array[], int dimensione);
bool mastermind(int tentativi[], int machine[], int dimensione);
void gioco();

int main()
{
    gioco();
}

int sceltaDimensione()
{
    int dimensione;
    cout << "con quante cifre vuoi giocare (3, 4, 5)" << endl;
    do
    {
        cin >> dimensione;
        if (dimensione < 3)
        {
            cout << "numero troppo piccolo" << endl;
        }
        else if (dimensione > 5)
        {
            cout << "numero troppo grande" << endl;
        }
    } while (!(dimensione >= 3 && dimensione <= 5));
    return dimensione;
}

void generazioneNumeroDaIndovinare(int casuale[], int dimensione)
{
    srand(time(NULL));
    for (int i = 0; i < dimensione; i++)
    {
        casuale[i] = rand() % 10;
        cout << casuale[i];
    }
}

void inputTentativi(int tentativi[], int dimensione)
{
    string input;
    cout << endl;
    cout << "Inserisci il tentativo: ";
    cin >> input;

    for (int i = 0; i < dimensione; i++)
    {
        if (i < input.length())
        {
            tentativi[i] = input[i] - '0';
        }
        else
        {
            break;
        }
    }
    //   stampaArray(tentativi, dimensione);
}
/*
void stampaArray(int array[], int dimensione)
{
    for (int i = 0; i < dimensione; i++)
    {
        cout << "Elemento " << i + 1 << ": " << array[i] << endl;
    }
}
*/
bool mastermind(int tentativi[], int machine[], int dimensione)
{
    char posCx = '+';
    char posSx = '-';
    char Sbagliato = ' ';

    for (int i = 0; i < dimensione; i++)
    {
        if (tentativi[i] == machine[i])
        {
            cout << posCx;
        }
        else
        {
            bool trovato = false;
            for (int j = 0; j < dimensione; j++)
            {
                if (j != i && tentativi[j] == machine[i])
                {
                    cout << posSx;
                    trovato = true;
                    break;
                }
            }
            if (!trovato)
            {
                cout << Sbagliato;
            }
        }
    }
    for (int i = 0; i < dimensione; i++)
    {
        if (tentativi[i] != machine[i])
        {
            return false;
        }
    }
    return true;
    cout << endl;
}

void gioco()
{
    int dimensione = sceltaDimensione();
    int arrayMacchina[dimensione];
    generazioneNumeroDaIndovinare(arrayMacchina, dimensione);
    int tentativi[dimensione];
    do
    {
        inputTentativi(tentativi, dimensione);
    } while (!mastermind(tentativi, arrayMacchina, dimensione));
}