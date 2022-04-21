struct Widget {
    int num_ = 0;
    void setNumber(int x) {        // eine Nicht-const-Methode
        num_ = x;
    }
};
Widget createWidget() {            // Rückgabe als Wert
    return Widget{};               // Erzeugen
}
int main() {
    Widget w = createWidget();     // Rückgabe als Wert erzeugt Kopie
    w.setNumber(100);              // verändern, natürlich okay, w ist nicht-const
    createWidget().setNumber(44);  // auch Tempwert verändern okay
}

