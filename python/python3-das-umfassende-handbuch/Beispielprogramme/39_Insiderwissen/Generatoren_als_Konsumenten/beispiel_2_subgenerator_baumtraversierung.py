#!/usr/bin/env python


class KnotenOhneYieldFrom:
    def __init__(self, wert, links=None, rechts=None):
        self.links = links
        self.wert = wert
        self.rechts = rechts

    def traversiere(self):
        if self.links:
            for k in self.links.traversiere():
                yield k
        yield self.wert
        if self.rechts:
            for k in self.rechts.traversiere():
                yield k


class KnotenMitYieldFrom:
    def __init__(self, wert, links=None, rechts=None):
        self.links = links
        self.wert = wert
        self.rechts = rechts

    def traversiere(self):
        if self.links:
            yield from self.links.traversiere()
        yield self.wert
        if self.rechts:
            yield from self.rechts.traversiere()


if __name__ == "__main__":
    #Knoten = KnotenOhneYieldFrom
    Knoten = KnotenMitYieldFrom

    bl_ = Knoten(links=Knoten(12), wert=1, rechts=Knoten(3))
    bl = Knoten(links=bl_, wert=5, rechts=Knoten(6))

    br_ = Knoten(links=Knoten(2), wert=8)
    br = Knoten(links=Knoten(9), wert=7, rechts=br_)

    baum = Knoten(links=bl, wert=11, rechts=br)

    print(list(baum.traversiere()))