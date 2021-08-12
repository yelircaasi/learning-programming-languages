#include<iostream>
#include<string>
#include<array>            // für array2
#include<vector>
#include<typeinfo>

#define strg "Hallo "      // Makro
#ifndef Welt
#define strg2 "Welt!"
#else                     // ggf. Alternative
#endif

typedef std::string typeString;

int main()
{
    using namespace std;

    // Integer, Ganze Zahl

    cout << "Ganze Zahlen (Integer): " << endl << endl;

    int int1;
    int1 = 11;
    int int2 = 12;
    int int3 = { 13 };
    int int4{ 14 };
    int int5 = int2;
    int int6 = { int3 }, int7{ int4 };

    cout << "Integer 1 : " << int1 << endl;
    cout << "Integer 2 : " << int2 << endl;
    cout << "Integer 3 : " << int3 << endl;
    cout << "Integer 4 : " << int4 << endl;
    cout << "Integer 5 : " << int5 << endl;
    cout << "Integer 6 : " << int6 << endl;
    cout << "Integer 7 : " << int7 << endl;

    cout << "Kommandozahlen (Float, Double): " << endl << endl;

    int int8, int9, int10;
    float flo1 = 3.1415f;
    float flo2, flo3, flo4;
    double dou1 = 3.141592653589793238462643383279502884e+00;
    cout.precision(40);

    cout << "Float: " << flo1 << endl << endl;
    cout << "Double: " << dou1 << endl << endl;

    // Typ-Konvertierungen
    cout << "Explizite Typ-Konvertierungen: " << endl << endl;
     int8 = (int)dou1;
     flo2 = (float)dou1;

     cout << "Integer: " << int8 << endl;
     cout << "Float: " << flo2 << endl;
     cout << "Double: " << dou1 << endl << endl;

     int9 = static_cast<int>(dou1);
     flo3 = static_cast<float>(dou1);

     cout << "Integer: " << int9 << endl;
     cout << "Float: " << flo3 << endl;
     cout << "Double: " << dou1 << endl << endl;

     cout << "Implizite Typ-Konvertierungen: " << endl << endl;

     int10 = dou1;
     flo4 = dou1;

     cout << "Integer: " << int10 << endl;
     cout << "Float: " << flo4 << endl;
     cout << "Double: " << dou1 << endl << endl;

     // Character, Zeichen
     cout << "Zeichen (Character): " << endl << endl;

    char char1 = 'c';
    char char2 = 99;
    char char3 = '\143';
    char *pointer1 = "char1";

    cout << "Character 1: " << char1 << endl;
    cout << "Character 2: " << char2 << endl;
    cout << "Character 3: " << char3 << endl;
    cout << "Character-Pointer 1: " << *pointer1 << endl << endl;

    //String, Zeichenkette

    cout << "Zeichenketten (Strings): " << endl << endl;

    string strg3 = "Hallo Welt!";
    using myString = string;       // Typedef in main()
    myString strg4 = "Hallo Welt!";
    typeString strg5 = "Hallo Welt!";

    cout << "String: " << endl;
    cout << "String: Hallo Welt! \n\r";
    cout << "String 1+2: " << strg1 strg2 << endl;
    cout << "String 3: " << strg3 << endl;
    cout << "String 4: " << strg4 << endl;
    cout << "String 5: " << strg5 << endl << endl;
    cout << "Laenge eines Strings: " << endl;
    cout << "sizeof(strg3) = " << sizeof(strg3) << endl << endl;
    cout << "String-Komponenten: " << endl;
    cout << "strg3[0] = " << strg3[0] << endl;
    cout << "strg3[1] = " << strg3[1] << endl;
    for(int i = 2; i < 5; i++)
    {
        cout << "strg.at(" << i << ") = " << strg3.at(i) << endl;
    }
    cout << endl;

    // Array, Feld
    cout << "Felder (Arrays): " << endl << endl;

    char array1[4] = {'a', 'b', 'c', '\0'};
    
    std::array<int, 4> array2;

    for(int i = 0; i < 4; i++)
    {
        array2.at(i) = i;
    }

    cout << "Feld: " << endl;
    cout << "array1 = " << array1 << endl << endl;
    cout << "Feld-Komponenten: " << endl;
    cout << "array1[0] = " << array1[0] << endl;
    cout << "array1[1] = " << array1[1] << endl;
    cout << "array1[2] = " << array1[2] << endl;
    cout << "array1[3] = " << array1[3] << endl << endl;
    for(int i = 0; i < 4, i++)
    {
        cout << "array2.at(" << i << ") = " << array2,at(i) << endl;
    }
    cout << endl;
    cout << "Laenge eines Feldes: " << endl;
    cout << "sizeof(array1) = " << sizeof(array1) << endl;
    cout << "array2.size() = " << array2,size() << endl << endl;

    // Vector, Vektor
    cout << "Vektoren (vectors): " << endl << endl;
    cout << "Komponenten eines Vektors: " << endl;
    std::vector<int>vec1{ 1, 9, 6 };
    auto vec2 = { 7L, 9L, 6L };
    for(int i = 0; i M vec1,size(); i++)
    {
        cout << "vec1.at(" << i << ") = " << vec1.at(i) << endl;
    }
    cout << endl;
    cout << "Laenge eines Vektors: " << endl;
    cout << "vec1.size() = " << vec1.size() << endl;
    vec1.push_back(7);
    cout << "vec1.size() = " << vec1.size() << endl << endl;
    for (int i = 0; i < vec1,size(); i++)
    {
        cout << "vec1[" << i << "] = " << vec1[i] << endl;
    }
    vec1.pop_back();
    cout << endl << "vec1.size() = " << vec1.size() << endl << endl;
    cout << "empty(vec1) = " << empty(vec1) << endl;
    vec1.pop_back();
    vec1.pop_back();
    vec1.pop_back();
    cout << "empty(vec1) = " << empty(vec1) << endl << endl;

    // Union (Struktur, Klasse)
    cout << "Union, Struktur, Klasse: " << endl << endl;
    union union_type
    {
        int intu;
        char charu;
    };

    union_type union1, union2;

    union1.intu = 1;
    cout << "union1.intu = " << union1.intu << endl;
    union1.charu = 'a';

    cout << "union.arrayu = " << union1.charu << endl;
    union2.intu = 2;
    cout << "nion2.intu = " << union2.intu << endl;
    union2.charu = 'b';
    cout << "union2.arrayu = " << union2.charu << endl << endl;

    // Aufzählungsdatentyp (Struktur, Klasse)
    cout << "Aufzählungsdatentyp (Enumeration Class): " << endl << endl;
    enum class enum_type { null=0, eins, zwei };
    enum_type enum1;

    enum1 = enum_type::null;
    enum_type enum2{ enum_type::eins };

    if(enum1 == enum_type::null)
        cout << "enum class: Nr. = " << static_cast<int>(enum1) << endl;
    if(enum2 == enum_type::eins)
        cout << "enum class: Nr. = " << (int)enum2 << endl << endl;

    // Boolean, boolsche Ausdrücke
    cout << "Boolsche Ausdrücke (Boolean): " << endl << endl;
    bool bool1 = true;
    bool bool2 = !bool1;

    if(bool1 == true)
    {
        cout << "boolean: true = " << bool1 << endl << endl;
    }

    if(bool2 == false)
    {
        cout << "boolean: false = " << bool2 << endl << endl;
    }

    cout << "Typ-Identifizierung (type identification): " << endl << endl;

    if(typeid(int1) == typeid(int2))
    {
        cout << "Type: " << typeid(int1).name() << " = "
                         << typeid(int2).name() << endl;
    }
    if(typeid(int1) != typeid(char1))
    {
        cout << "Typ: " << typeid(int1).name() << "!= " 
                        << typeid(char1).name() << endl << endl;
    }

    return 0;
}


