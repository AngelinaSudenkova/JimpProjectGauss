#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(){
char* polecenie = "czytstruct.exe macierz.txt";
system(polecenie);
printf("\nSleep() ustawiony jest na 10 sekund aby zobaczyć wynik działania programu.\n");
Sleep(10000);
}