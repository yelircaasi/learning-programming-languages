std::vector v{ 1, 2, 3, 4, 5, 6 };
v.erase(v.begin()+1, v.begin()+5); // v ist nun {1, 6}
v.erase(v.begin(), v.end());       // löscht den Rest

