#include "Gra.h"
#include "Komputer1.h"
#include "Czlowiek1.h"
#include <iostream>

int main()
{

    //początkowy interfejs gry
    cout << "======= WITAJ W GRZE KOLKO I KRZYZYK! =======" << endl;
    cout << "==== Plansza do gry wyglada nastepujaco ==== " << endl;
    Board p1;
    cout << p1 << endl;

    string figura;

    // Początek gry oraz oraz sprawdzenie czy użytkownik wprowadził właściwą figurę aby rozpocząć
    bool flag;
    do
    {
        flag = false;
        cout << endl << "Wybierz figure aby rozpoczac gre (O lub X): ";
        cin >> figura;
        cout << endl;

        Interfejs* wsk = nullptr;
        // Jeśli użytkownik wybrał "O" to rozpoczyna rozgrywkę, jeśli "X" to komputer rozpoczyna
        if (figura == "O" || figura == "o")
        {
            system("CLS");
            cout << "Ty zaczynasz rozgrywke" << endl;
            Czlowiek1 gra1;
            wsk = &gra1;
            wsk->rozgrywka();
        }

        else if (figura == "X" || figura == "x")
        {
            system("CLS");
            cout << "Komputer zaczyna rozgrywke" << endl;
            Komputer1 gra2;
            wsk = &gra2;
            wsk->rozgrywka();
        }

        else
        {
            system("CLS");
            cerr << "Wybrales bledna figure" << endl;
            flag = true;
            cin.clear();
            cin.ignore(500, '\n');
        }
    } while (flag);

    return 0;
}

