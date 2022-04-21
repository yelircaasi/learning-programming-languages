const Widget createWidget() {      // Rückgabe als const-Wert
    return Widget{};
}
int main() {
    Widget w = createWidget();     // kopiert in neues nicht-const w
    w.setNumber(100);              // w ist nicht-const, verändern ist okay
    createWidget().setNumber(44);  // const Tempwert verändern geht nicht
}

