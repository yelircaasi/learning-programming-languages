#include <iostream>                                // cout
#include "database.hpp"            // Einbinden der fremden Programmierschnittstelle

class Database {
    const db_handle_t db_;                         // konstant machen
public:
    Database(const char* filename);
    ~Database();
    int execute(const char* query);
    Database(const Database&) = delete;            // Kopieren verbieten
    Database& operator=(const Database&) = delete; // Zuweisung verbieten
};
// ... Implementierungen wie gehabt ...
int main() {
    Database db{ "kunden.dat" };
    std::cout << "Anzahl: "<< db.execute("select * from kunden") << "\n";
    Database db2{ db }; // Compiler verhindert gefährliche Kopie
    db = db2;           // Compiler verhindert gefährliche Zuweisung
}

