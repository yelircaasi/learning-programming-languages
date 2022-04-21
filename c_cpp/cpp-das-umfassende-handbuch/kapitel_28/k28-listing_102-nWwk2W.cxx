// ... wie zuvor ...

int main() {
  tuple ps = praeser(2015);
  cout << get<int>(ps) << '\n'; // Ausgabe: 1940
  cout << get<string>(ps) << '\n'; // nicht eindeutig
}

