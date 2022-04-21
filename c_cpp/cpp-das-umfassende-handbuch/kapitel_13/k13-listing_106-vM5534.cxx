class Widget {
    unsigned x = 0, y = 0, w = 0, h = 0; // zum Beispiel
public:
    unsigned getLeft() const;
    unsigned getTop() const;
    unsigned getRight() const;
    unsigned getBottom() const;
    void setWidth(unsigned w);
    void setHeight(unsigned h);
};

