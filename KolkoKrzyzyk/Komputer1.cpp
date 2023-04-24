#include "Komputer1.h"
using namespace std;

/**
 * Metoda posiadająca wszystkie możliwe opcje gry, gdy komputer zaczyna rozgrywkę
 */
void Komputer1::rozgrywka()
{
    //ruch komputera; komputer zawsze zaczyna rozgrywkę w prawym dolnym rogu
    pole.at(8) = "O";
    Interfejs::formula();

    //ruch gracza
    Interfejs::ruchy_gracza("X");

    //Gdy człowiek wybierze pole 1
    if (x == 1)
    {
        pole.at(2) = "O";
        Interfejs::formula();
        Interfejs::ruchy_gracza("X");

        if(x == 6)
        {
            pole.at(6) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else Interfejs::wygrywanie("O", "X");
    }

    //Gdy człowiek wybierze pole 4 lub 6
    if (x == 4 || x == 6)
    {
        pole.at(4) = "O";
        Interfejs::formula();
        Interfejs::ruchy_gracza("X");

        if(x == 1)
        {
            pole.at(6) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else Interfejs::wygrywanie("O", "X");
    }

    //Gdy człowiek wybierze pole 8 lub 2
    if (x == 8 || x == 2)
    {
        pole.at(4) = "O";
        Interfejs::formula();
        Interfejs::ruchy_gracza("X");

        if(x == 1)
        {
            pole.at(2) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else Interfejs::wygrywanie("O", "X");
    }

    //Gdy człowiek wybierze pole 3
    if (x == 3)
    {
        pole.at(6) = "O";
        Interfejs::formula();
        Interfejs::ruchy_gracza("X");

        if(x == 8)
        {
            pole.at(0) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else Interfejs::wygrywanie("O", "X");
    }

    //Gdy człowiek wybierze pole 7
    if (x == 7)
    {
        pole.at(2) = "O";
        Interfejs::formula();
        Interfejs::ruchy_gracza("X");

        if(x == 6)
        {
            pole.at(0) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else Interfejs::wygrywanie("O", "X");
    }

    //Gdy człowiek wybierze środek
    if (x == 5)
    {
        pole.at(0) = "O";
        Interfejs::formula();
        Interfejs::ruchy_gracza("X");

        if (x == 3)
        {
            pole.at(6) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else if (x == 7)
        {
            pole.at(2) = "O";
            Interfejs::formula();
            Interfejs::ruchy_gracza("X");
            Interfejs::wygrywanie("O", "X");
        }
        else
        {
            Interfejs::blok("X", "O");
            Interfejs::ruchy_gracza("X");
            Interfejs::blok("X", "O");
            Interfejs::ruchy_gracza("X");
            Interfejs::blok("X", "O");
        }
    }
}
