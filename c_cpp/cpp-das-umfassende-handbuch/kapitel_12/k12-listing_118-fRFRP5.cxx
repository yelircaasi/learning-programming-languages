class Rect {
    int area_;  // private Daten
public:
    int x_, y_;
    void set(int x, int y) { x_=x; y_=y; area_=x_*y_; }
    int calc() { return area_; }
};

