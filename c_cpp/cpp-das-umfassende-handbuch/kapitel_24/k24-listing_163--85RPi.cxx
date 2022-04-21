map<string,string> data { {"Hans","Albers"}, {"Heinz","Ruehmann" }, };
cout <<= data;                         // Hans:Albers Heinz:Ruehmann
data.rbegin()->second = "Erhardt";     // Ziel überschreiben
cout <<= data;                         // Hans:Albers Heinz:Erhardt

