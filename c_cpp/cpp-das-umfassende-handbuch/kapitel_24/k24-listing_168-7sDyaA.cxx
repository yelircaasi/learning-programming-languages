#include <string>
#include <iterator> // distance
struct Person {
  std::string name;
  friend bool operator<(const Person &a, const Person &b) {  // nur erster Buchstabe
    return a.name.size()==0 ? true
      : (b.name.size()==0 ? false : a.name[0] < b.name[0]);
  }
};
// ...
multiset<int> data{ 1, 4,4, 2,2,2, 7, 9 };
auto [von1, bis1] = data.equal_range(2);
cout << "Anzahl 2en: "
  << std::distance(von1, bis1) << '\n'; // Ausgabe: Anzahl 2en: 3
auto [von2, bis2] = data.equal_range(5);
cout << "Anzahl 5en: "
  << std::distance(von2, bis2) << '\n'; // Ausgabe: Anzahl 5en: 0
multiset<Person> raum{
  Person{"Karl"}, Person{"Kurt"}, Person{"Peter"}, Person{"Karl"}, Person{"Ken"}};
auto [p, q] = raum.equal_range(Person{"K"});
for( ; p != q; ++p) {
  cout << p->name << ' ';
}
cout << '\n'; // Ausgabe: Karl Kurt Karl Ken

