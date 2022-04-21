class CalendarClock : public Clock, public Calendar {
public:
    CalendarClock(int y, int m, int d, int hh, int mm, int ss)
    : Calendar{y,m,d}, Clock{hh,mm,ss} {}

    void tick() {         // +1 Sekunde
        auto prev_h = h_;
        Clock::tick();    // Aufruf Basisklassenmethode
        if(h_ < prev_h) { // falls neuer Tag
            advance();    // ... Kalender fortschreiten
        }
    }
    friend ostream& operator<<(ostream&os, const CalendarClock& cc) {
        operator<<(os, (Calendar&)cc) << " "; // Aufruf freie Funktion
        operator<<(os, (Clock&)cc);           // Aufruf freie Funktion
        return os;
    }
};

