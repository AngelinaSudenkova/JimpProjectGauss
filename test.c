#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(){
<<<<<<< HEAD
char* polecenie = "czytstruct.exe macierz.txt";
=======
char* polecenie = "obliczEliminacjaGaussa.exe nieistniejacamacierz.txt";
>>>>>>> 41464b91699c4af4fad81ff22bc9df0b92790f64
system(polecenie);
printf("\nSleep() ustawiony jest na 10 sekund aby zobaczyć wynik działania programu.\n");
Sleep(10000);
}