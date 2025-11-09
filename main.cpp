#include <iostream>
#include <cmath>    // dla sqrt() i log10()
using namespace std;

int main() {
    double a, b;
    char oper;
    bool kontynuuj = true;

    cout << "=== Rozszerzony kalkulator ===" << endl;
    cout << "Dostępne operacje:" << endl;
    cout << "+  - dodawanie" << endl;
    cout << "-  - odejmowanie" << endl;
    cout << "*  - mnożenie" << endl;
    cout << "/  - dzielenie" << endl;
    cout << "s  - pierwiastek kwadratowy" << endl;
    cout << "l  - logarytm dziesiętny (log10)" << endl;
    cout << "q  - wyjście z programu" << endl;

    while (kontynuuj) {
        cout << "\nPodaj operator: ";
        cin >> oper;

        switch (oper) {
            case '+':
            case '-':
            case '*':
            case '/':
                cout << "Podaj pierwszą liczbę: ";
                cin >> a;
                cout << "Podaj drugą liczbę: ";
                cin >> b;
                cout << "Wynik: ";
                if (oper == '+') cout << a + b;
                else if (oper == '-') cout << a - b;
                else if (oper == '*') cout << a * b;
                else if (oper == '/') {
                    if (b != 0)
                        cout << a / b;
                    else
                        cout << "Błąd: dzielenie przez zero!";
                }
                cout << endl;
                break;

            case 's':
                cout << "Podaj liczbę do spierwiastkowania: ";
                cin >> a;
                if (a >= 0)
                    cout << "Wynik: " << sqrt(a) << endl;
                else
                    cout << "Błąd: nie można pierwiastkować liczby ujemnej!" << endl;
                break;

            case 'l':
                cout << "Podaj liczbę do obliczenia log10: ";
                cin >> a;
                if (a > 0)
                    cout << "Wynik: " << log10(a) << endl;
                else
                    cout << "Błąd: logarytm z liczby niedodatniej nie istnieje!" << endl;
                break;

            case 'q':
                kontynuuj = false;
                cout << "Zamykanie kalkulatora..." << endl;
                break;

            default:
                cout << "Nieznany operator!" << endl;
        }
    }

    return 0;
}
