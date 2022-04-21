unordered_set<int> nums{ 1,2,3,4,5,6,7,8,9,10 };
cout <<= nums;               // Ausgabe ähnlich: 9 1 2 3 4 5 6 7 8 10
auto it = nums.begin();
while(it != nums.end()) {
    if(*it % 2 == 0) {       // gerade Zahl?
        it = nums.erase(it); // Restelemente verändern nicht Reihenfolge
    } else {
        ++it;
    }
}
cout <<= nums;               // Ausgabe ähnlich: 9 1 3 5 7

