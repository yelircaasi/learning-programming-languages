// ... wie zuvor ...

int main() {
  using std::tie; using std::ignore;
  string nachname {};
  int gebj {};

  tie(ignore, nachname, ignore, gebj) = praeser(2015);
  cout << nachname << ' ' << gebj << '\n'; // Ausgabe: Gauck 1940
}

