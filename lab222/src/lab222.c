#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main(void) {
puts("Dolaczanie bibliotek dynamicznych");
puts("===================================");
int status_wyjscia; // do dlclose
void *Biblioteka; // wskaznik do bilbioteki
int(*Funkcja)(int, int); //wskzanik do fukcji
//double(*Funkcja1)(int, int); //wskzanik do fukcji1
Biblioteka = dlopen("/home/x/eclipse-workspace2/bibdyn/src/biblioteka.so", RTLD_LAZY); //lub RTLD_NOW
if(!Biblioteka) {
printf ("Error otwarcia: %s\n", dlerror());
return(1);
}
Funkcja = dlsym(Biblioteka, "odejmowanie");
if (Funkcja== NULL) {
printf ("Blad wywolania funkcji 'odejmowanie()': brak w bibliotece\n");
} else {
printf ("różnica:%d \n", Funkcja (8, 2));
}
Funkcja = dlsym(Biblioteka, "iloczyn");
if (Funkcja== NULL) {
printf ("Blad wywolania funkcji 'iloczyn()': brak w bibliotece\n");
} else {
printf ("iloczyn:%d \n", Funkcja (8, 2));
}

status_wyjscia = dlclose (Biblioteka);
if(status_wyjscia) {
	printf ("Error zamkniecia: %s\n", dlerror());
	return(1);
}
else {
	printf("Biblioteka zamknięta poprawnie");
}

//===================
return EXIT_SUCCESS;
}
