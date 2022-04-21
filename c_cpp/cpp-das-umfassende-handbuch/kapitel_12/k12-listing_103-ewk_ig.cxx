auto erzeuge(string name, int alter, string ort) {
    return Person{name, alter, ort};       // auto verlangt Konstruktornamen
}
auto erzeuge2(string name, int alter, string ort) {
    return {name, alter, ort};       // auto mit initializer_list geht nicht
}

