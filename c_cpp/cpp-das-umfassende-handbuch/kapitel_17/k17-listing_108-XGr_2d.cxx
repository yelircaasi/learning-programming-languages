#include <string>
#include <sqlite3.h>
class DbWrapper {
  sqlite3 *db_;
public:
  DbWrapper(const std::string& dbname)
    : db_{nullptr}
  {
    const int errCode = sqlite3_open(dbname.c_str(), &db_);
    if(errCode) db_ = nullptr;  // als 'nicht erfolgreich' markieren
  }
  explicit operator bool() const {
    return db_ != nullptr;      // Markierung auswerten
  }
  ~DbWrapper() {
    if(db_) sqlite3_close(db_);
  }
  // ... Rest wie zuvor ...
};
bool dbExec(const std::string &dbname, const std::string &sql) {
  DbWrapper db { dbname };
  if(db) {                 // prüfe auf erfolgreiche Initialisierung
    const int errCode = sqlite3_exec(*db,sql.c_str(),nullptr,nullptr,nullptr);
    if(errCode)
      return false; // immer noch korrektes RAII
  }
  return (bool)db;
}

