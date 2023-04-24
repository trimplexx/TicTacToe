#include "Gra.h"
#include <iostream>
using namespace std;


//klasa Board
/**
 * przeciążenie operatora '<<', które rysuje plansze do gry
 */
ostream& operator<< (ostream& out, const Board& point)
{
    for(int i=0; i<9; i++)
    {
        out << " " << point.pole[i] << " ";
        if((i+1) % 3) out << "|";
        if (i == 2 || i == 5) out << endl << "---+---+---"<< endl;
        else if (i == 8) out << endl;
    }
    return out;
}


//klasa Interfejs (bazowa)

/**
 * Metoda ruch_gracza odpowiada za walidacje ruchu gracza oraz wstawianie danej figury w odpowiednie miejsce
 * zależnie od wybranej przez gracza figury
 *
 * @param XorO - wstawia kółko lub krzyżyk
 */
void Interfejs::ruchy_gracza(string XorO)
{
    string zmienna;
    bool flag;
    do
    {
        flag = false;
        {
            cout << endl << "Wybierz ruch: ";
            cin >> x;

            //Walidacja czy wprowadzono poprawny numer pola bądź czy to pole nie jest już zajęte
            if (x < 1 || x > 9)
            {
                cerr << "Wprowadzono bledny numer pola!" << endl;
                flag = true;
                cin.clear();
                cin.ignore(500, '\n');
            }
            else if (pole[x - 1] == "X" || pole[x - 1] == "O")
            {
                cerr << "To pole jest juz uzyte" << endl;
                flag = true;
                cin.clear();
                cin.ignore(500, '\n');
            }
            else pole.at(x - 1) = XorO;
        }
    }
    while (flag);
    system ("CLS");
    // wywołanie planszy za pomocą referencji do adresu aktualnie przetwarzanego obiektu
    cout << (*this) << endl;
    Interfejs::warunek();
}


/**
 * Metoda odpowiada za sprawdzenie czy ktoś wygrał grę bądź czy nastąpił remis
 */
void Interfejs::warunek()
{
    /**
     * Gdy wygrana = 0 <- nie robi nic;
     * Gdy wygrana = 1 <- wygrywa kółko;
     * Gdy wygrana = 2 <- wygrywa krzyżyk;
     * Gdy wygrana = 3 <- następuje remis
     */

    int wygrana = 0;

    // pętla sprawdza wiersze i kolumny
    for(int i=1;i<4;i++)
    {
        if (pole.at((1 * i)+((i*2)-2)-1) == pole.at((2 * i) + (i-1)-1) && pole.at((2 * i) + (i-1)-1) == pole.at(3 * i-1))
        {
            if (pole.at(2 * i) == "O")
                wygrana=1;
            else wygrana=2;
        }

        else if(pole.at(i-1)==pole.at(i+3-1) && pole.at(i+3-1)==pole.at(i+6-1))
        {
            if (pole.at(i-1) == "O")
                wygrana=1;
            else wygrana=2;
        }
    }

    // sprawdza dwie przekatne
    if(pole.at(0) == pole.at(4) && pole.at(4) == pole.at(8))
    {
        if (pole.at(0) == "O")
            wygrana=1;
        else wygrana=2;
    }
    else if (pole.at(2) == pole.at(4) && pole.at(4) == pole.at(6))
    {
        if (pole.at(2) == "O")
            wygrana=1;
        else wygrana=2;
    }

    // wypisuje czy ktoś wygrał, jeśli nie, to sprawdza czy może wystąpił remis
    if(wygrana==1)
    {
        system("CLS");
        cout << "Wygralo kolko!" << endl;
        cout << (*this) << endl;
        exit (0);
    }
    else if (wygrana==2)
    {
        system("CLS");
        cout << "Wygral krzyzyk!" << endl;
        cout << (*this) << endl;
        exit(0);
    }

    //jeżeli żadne pole nie będzie odpowiadać początkowej wartości to następuje remis
    if ((pole[0] != "1") && (pole[1] !=  "2") && (pole[2] !=  "3") && (pole[3] !=  "4")
        && (pole[4] !=  "5") && (pole[5] !=  "6") && (pole[6] !=  "7") && (pole[7] !=  "8") && pole[8] !=  "9")
        wygrana =3;

    if (wygrana==3)
    {
        system("CLS");
        cout << "Remis!" << endl;
        cout << (*this) << endl;
        exit(0);
    }
}

/**
 * Metody, które odpowiadaja za automatyczne wygrywanie poprzez wstawianie w następnym ruchu przez komputer
 * brakującej figury w linii
 *
 * @param jeden - kółko lub krzyżyk
 * @param dwa - krzyżyk lub kółko
 */
void Interfejs::wygrywanie(string jeden, string dwa)
{
    for(int i=1;i<4;i++)
    {
        // sprawdzanie poziome
        if (pole.at((1 * i)+((i*2)-2)-1) == jeden && pole.at((2 * i) + (i-1)-1) == jeden && pole.at((3 * i-1)) != dwa)
        {
            pole.at((3 * i-1)) = jeden;
        }
        else if (pole.at((2 * i) + (i-1)-1) ==jeden && pole.at(3 * i-1) == jeden && pole.at((1 * i)+((i*2)-2)-1) != dwa)
        {
            pole.at((1 * i)+((i*2)-2)-1) = jeden;
        }
        else if (pole.at((1 * i)+((i*2)-2)-1) == jeden && pole.at(3 * i-1) == jeden && pole.at((2 * i) + (i-1)-1) != dwa)
        {
            pole.at((2 * i) + (i-1)-1) = jeden;
        }
        // sprawdzanie pionowe
        if(pole.at(i-1)== jeden && pole.at(i+3-1) == jeden && pole.at(i+6-1) != dwa)
        {
            pole.at(i+6-1) = jeden;
        }
        else if (pole.at(i-1) == jeden &&  pole.at(i+6-1) == jeden && pole.at(i+3-1) != dwa)
        {
            pole.at(i+3-1) = jeden;
        }
        else if(pole.at(i+6-1) == jeden && pole.at(i+3-1) == jeden && pole.at(i-1) != dwa)
        {
            pole.at(i-1) = jeden;
        }
    }
    // sprawdzanie pionowe
    if(pole.at(0) == jeden && pole.at(4) == jeden && pole.at(8) != dwa)
    {
        pole.at(8) = jeden;
    }
    else if(pole.at(0) == jeden && pole.at(8) == jeden && pole.at(4) != dwa)
    {
        pole.at(4) = jeden;
    }
    else if(pole.at(4) == jeden && pole.at(8) == jeden && pole.at(0) != dwa)
    {
        pole.at(0) = jeden;
    }

    else if (pole.at(2) == jeden && pole.at(4) == jeden && pole.at(6) != dwa)
    {
        pole.at(6) = jeden;
    }
    else if (pole.at(2) == jeden && pole.at(6) == jeden && pole.at(4) != dwa)
    {
        pole.at(4) = jeden;
    }
    else if (pole.at(4) == jeden && pole.at(6) == jeden && pole.at(2) != dwa)
    {
        pole.at(2) = jeden;
    }

    formula();
}


/**
 * Metoda odpowiada za automatyczne wygrywanie bądź blokowanie gracza przez komputer w kolejnym ruchu
 * W pierwszej kolejności sprawdzane jest czy w kolejnym ruchu nie ma możliwości wygrania poprzez wywołanie metody wygrywania
 * jeśli gracz jednak w kolejnym ruchu będzie mógł wygrać to komputer uprzedza jego ruch blokując.
 */
void Interfejs::blok(string jeden, string dwa)
{
    wygrywanie(dwa, jeden);

    for (int i = 1; i < 4; i++)
    {
        // sprawdzanie poziome
        if (pole.at((1 * i) + ((i * 2) - 2) - 1) == jeden && pole.at((2 * i) + (i - 1) - 1) == jeden  &&
            pole.at((3 * i - 1)) != dwa)
        {
            pole.at((3 * i - 1)) = dwa;
            formula();
            return;
        }
        else if (pole.at((2 * i) + (i - 1) - 1) == jeden  && pole.at(3 * i - 1) == jeden  &&
                   pole.at((1 * i) + ((i * 2) - 2) - 1) != dwa)
        {
            pole.at((1 * i) + ((i * 2) - 2) - 1) = dwa;
            formula();
            return;
        }
        else if (pole.at((1 * i) + ((i * 2) - 2) - 1) == jeden  && pole.at(3 * i - 1) == jeden  &&
                   pole.at((2 * i) + (i - 1) - 1) != dwa)
        {
            pole.at((2 * i) + (i - 1) - 1) = dwa;
            formula();
            return;
        }

        // sprawdzanie pionowe
        if (pole.at(i - 1) == jeden  && pole.at(i + 3 - 1) == jeden  && pole.at(i + 6 - 1) != dwa)
        {
            pole.at(i + 6 - 1) = dwa;
            formula();
            return;
        }
        else if (pole.at(i - 1) == jeden  && pole.at(i + 6 - 1) == jeden  && pole.at(i + 3 - 1) != dwa)
        {
            pole.at(i + 3 - 1) = dwa;
            formula();
            return;
        }
        else if (pole.at(i + 6 - 1) == jeden  && pole.at(i + 3 - 1) == jeden  && pole.at(i - 1) != dwa)
        {
            pole.at(i - 1) = dwa;
            formula();
            return;
        }
    }

    // sprawdzanie przekątnych
    if (pole.at(0) == jeden  && pole.at(4) == jeden  && pole.at(8) != dwa)
    {
        pole.at(8) = dwa;
        formula();
        return;
    }
    else if (pole.at(0) == jeden  && pole.at(8) == jeden  && pole.at(4) != dwa)
    {
        pole.at(4) = dwa;
        formula();
        return;
    }
    else if (pole.at(4) == jeden  && pole.at(8) == jeden  && pole.at(0) != dwa)
    {
        pole.at(0) = dwa;
        formula();
        return;
    }
    else if (pole.at(2) == jeden  && pole.at(4) == jeden  && pole.at(6) != dwa)
    {
        pole.at(6) = dwa;
        formula();
        return;
    }
    else if (pole.at(2) == jeden  && pole.at(6) == jeden  && pole.at(4) != dwa)
    {
        pole.at(4) = dwa;
        formula();
        return;
    }
    else if (pole.at(4) == jeden  && pole.at(6) == jeden  && pole.at(2) != dwa)
    {
        pole.at(2) = dwa;
        formula();
        return;
    }

    // Jeżeli powyższe warunki nie zostaną wykonane, to w pierwsze wolne miejsce na planszy wstawi "X"
    else
    {
        for (int j=0; j<9; j++)
        {
            if (pole.at(j) != jeden  && pole.at(j) != dwa)
            {
                pole.at(j)=dwa;
                formula();
                return;
            }
        }
    }
}


/**
 * formuła pokazująca ruch kompuetra na planszy oraz sprawdzająca czy rozgrywka nie zakończyła się po tym ruchu
 */
void Interfejs::formula()
{
    system("CLS");
    cout << endl << "Komputer wybral ruch" << endl;
    cout << (*this) << endl;
    warunek();
}

