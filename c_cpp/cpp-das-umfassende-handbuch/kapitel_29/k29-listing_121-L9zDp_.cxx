friend void swap(MxStack& re, MxStack& li) {
    if(&re==&li) return;           // Adresse dieselbe? Mit sich selbst tauschen unnötig
    std::lock( re.mx_, li.mx_ );   // mehrere Sperren gleichzeitig
    std::lock_guard lkre{re.mx_, std::adopt_lock}; // schon gesperrt
    std::lock_guard lkli{li.mx_, std::adopt_lock}; // schon gesperrt
    std::swap(li.data_, re.data_); // vertauschen ausführen
}

