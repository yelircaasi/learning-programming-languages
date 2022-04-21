struct Tag {
    Tag(int a, int b) : Tag{} {       // delegiert
        if(a==0 || b == 0)
            throw 666; // löst Ausnahme aus
    }
    Tag() {}
};
int main() {
    try {
        Tag tag{1,2};
    } catch(int) { }
}

