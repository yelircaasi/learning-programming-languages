std::vector v{ 1, 2, 3, 4, 5, 6 };
for(auto it=v.begin(); it!=v.end(); ++it) {
  it = v.erase(it);
}
// Hier ist v: { 2, 4, 6 }

