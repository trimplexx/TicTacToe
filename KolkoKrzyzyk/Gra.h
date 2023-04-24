#ifndef PROJEKT_PK_GRA_H
#define PROJEKT_PK_GRA_H
#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
    vector<string>pole = {"1","2","3","4","5","6","7","8","9"};
    friend ostream& operator<<(ostream& out, const Board& point);
};


//"Interfejs" to tylko nazwa klasy, jest to imitacja klasy abstrakcyjnej
class Interfejs : public Board{

protected:
    int x{};

public:
    //metody "statyczne" dziedziczone do klas pochodnych (nie są one przysłaniane w klasach pochodnych)
    void warunek();
    void formula();
    void ruchy_gracza(string);
    void blok(string, string);
    void wygrywanie(string, string);

    //metoda czysto wirtualna, która jest przesłaniania w klasach dziedziczących
    virtual void rozgrywka() = 0;
    virtual ~Interfejs() = default;
};

#endif
