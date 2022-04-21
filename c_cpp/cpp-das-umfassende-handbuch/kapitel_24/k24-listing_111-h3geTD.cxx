auto zaehle(vector<int> arg) { return arg.size(); }
// ...
vector input{1,2,3};           // vector<int>
vector outputA(input);         // Kopie
vector outputB = input;        // auch Kopie, keine Zuweisung
cout << zaehle(input) << '\n'; // Aufruf per Copy-by-Value

