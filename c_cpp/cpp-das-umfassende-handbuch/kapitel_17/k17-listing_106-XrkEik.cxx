#include <string>
#include <stdexcept>
#include <sqlite3.h>

using std::string; using std::runtime_error;

void dbExec(const string &dbname, const string &sql) {
  sqlite3 *db;

  int errCode = sqlite3_open(dbname.c_str(), &db);  // Acquire
  if(errCode) {
    throw runtime_error("Fehler beim Öffnen der DB.");
  }

  errCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
  if(errCode) {
    throw runtime_error("Fehler SQL-Exec.");        // Nicht gut!
  }

  errCode = sqlite3_close(db);                      // Release
}

