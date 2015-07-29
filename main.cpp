#include <fstream>
#include <iostream>
#include "library.h"

int main() {
    Library UWLibrary;
    ifstream patrons("data4patrons.txt");
    ifstream actions("data4commands.txt");
    ifstream publications("data4books.txt");
    if(!publications) {
        cout << "File not found" << endl;
        return 1;
    }
    UWLibrary.buildPatrons(patrons);
	UWLibrary.displayPatrons();
    UWLibrary.buildShelf(publications);
	UWLibrary.displayShelf();
    UWLibrary.buildLibrarian(actions);
    UWLibrary.runLibrarian();
	UWLibrary.displayShelf();
    return 0;
};
