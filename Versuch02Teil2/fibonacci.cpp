//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

long long fibonacci(int n)
{
	long long previousFib = 1;
	long long currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    // ERR: start bei 3, da schon prev und curr gleich 1 bis f(2)
    for (int i = 3; i <= n; i++)
    {
    	long long newFib = previousFib + currentFib ;
        //ERR: sowohl prev, als auch curr wird durch new ersetzt -> new > curr; curr -> prev
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
	// ERR: unnötige Leertaste
    std::cout << "Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    // ERR: i=1 -> i=0
    // WARN: Je größer die Anzahl der Fib Nummern, deste länger läuft der Code (Rekursion (exp O(2^n)))
    // WARM: Ab der Fib Nummer 47 (Index 46) falsch -> 32Bit -> 2.147.483.647, aber Fib47 = 2.971.215.073, daher auf einmal -1323752223
    // Lösung "long long" mit 64Bit Speicherplatz
    for (int i = 0; i <= 46; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
