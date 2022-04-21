#include <iostream>                // cout
#include "database.hpp"            // Einbinden der fremden Programmierschnittstelle
class Database {
    db_handle_t db_;               // eingepackte Ressource
public:
    Database(const char* filename);
    ~Database();
    int execute(const char* query);
};
Database::Database(const char* filename)
    : db_{db_open(filename)}       // Anfordern der Ressource
    { }
Database::~Database() {
    db_close(db_);                 // Freigeben der Ressource
}
int Database::execute(const char* query) {
    return db_execute(db_, query); // Nutzen der Ressource
}
int main() {
    Database db{ "kunden.dat" };   // Erzeugen des Wrappers
    std::cout << "Anzahl: "<< db.execute("select * from kunden") << "\n";
}                                  // automatisches Entfernen des Wrappers

