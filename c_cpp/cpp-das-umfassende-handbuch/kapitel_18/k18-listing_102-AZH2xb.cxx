class Base {
public:
    int xPublic = 1;
protected:
    int xProtected = 2;
private:
    int xPrivate = 3;
};
class DerivedPublic : public Base {
    // xPublic wird 'public'
    // xProtected wird 'protected'
    // xPrivate ist hier nicht sichtbar
};
class DerivedProtected : protected Base {
    // xPublic wird 'protected'
    // xProtected wird 'protected'
    // xPrivate ist hier nicht sichtbar
};
class DerivedPrivate : private Base { // oder wenn nichts angegeben
    // xPublic wird 'private'
    // xProtected wird 'private'
    // xPrivate ist hier nicht sichtbar
};

