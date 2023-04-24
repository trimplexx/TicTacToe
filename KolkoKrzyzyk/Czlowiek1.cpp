#include "Czlowiek1.h"
using namespace std;


/**
 * Metoda posiadająca wszystkie możliwe opcje gry, gdy człowiek zaczyna rozgrywkę
 */
void Czlowiek1::rozgrywka()
{
    //ruch gracza
    cout << (*this) << endl;
    Interfejs::ruchy_gracza("O");

    //Gdy człowiek wybierze pole 1 lub 9
    if (x == 1 || x == 9)
    {
        pole.at(4) = "X";
        Interfejs::formula();
        Interfejs::ruchy_gracza("O");

        if (x == 1 || x == 9)
        {
            pole.at(1) = "X";
            Interfejs::formula();

            for (int i = 1; i <= 3; i++) {
                Interfejs::ruchy_gracza("O");
                Interfejs::warunek();
                Interfejs::blok("O", "X");
            }
        }
        else
        {
            for (int i = 1; i <= 4; i++)
            {
                Interfejs::blok("O", "X");
                Interfejs::ruchy_gracza("O");
                Interfejs::warunek();
            }
        }
    }

    //Gdy człowiek wybierze pole 3 lub 7
    else if (x == 3 || x == 7)
    {
        pole.at(4) = "X";
        Interfejs::formula();

        Interfejs::ruchy_gracza("O");
        if (x == 3 || x == 7)
        {
            pole.at(7) = "X";
            Interfejs::formula();

            for (int i = 1; i <= 3; i++) {
                Interfejs::ruchy_gracza("O");
                Interfejs::warunek();
                Interfejs::blok("O", "X");
            }
        }
        else
        {
            for (int i = 1; i <= 4; i++)
            {
                Interfejs::blok("O", "X");
                Interfejs::ruchy_gracza("O");
                Interfejs::warunek();
            }
        }
    }

    //Gdy człowiek wybierze środek
    else if (x == 5)
    {
        pole.at(8) = "X";
        Interfejs::formula();

        Interfejs::ruchy_gracza("O");
        if (x == 1)
        {
            pole.at(2) = "X";
            Interfejs::formula();

            for (int i = 1; i <= 3; i++)
            {
                Interfejs::ruchy_gracza("O");
                Interfejs::warunek();
                Interfejs::blok("O", "X");
            }
        }
        else
        {
            for (int i = 1; i <= 4; i++)
            {
                Interfejs::blok("O", "X");
                Interfejs::ruchy_gracza("O");
                Interfejs::warunek();
            }
        }
    }

    // Gdy człowiek wybierze pole 2, 4, 6 lub 8
    else
    {
        pole.at(4) = "X";
        Interfejs::formula();

        for (int i = 1; i <= 4; i++)
        {
            Interfejs::ruchy_gracza("O");
            Interfejs::blok("O", "X");
        }
    }
}
