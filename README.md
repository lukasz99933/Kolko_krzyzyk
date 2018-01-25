<h2>1. Wprowadzenie</h2>
<p>W sprawozdaniu znajduje się opis gry oraz stosowane w niej metody
sztucznej inteligencji. Wybrałem grę kółko i krzyżyk.</p>
<h2>2. Opis gry:</h2>
<p>Kółko i krzyżyk – gra strategiczna rozgrywana przez dwóch graczy. Gracze
obejmują pola na przemian dążąc do objęcia trzech pól w jednej linii, przy
jednoczesnym uniemożliwieniu tego samego przeciwnikowi. Pole może być
objęte przez jednego gracza i nie zmienia swego właściciela przez cały
przebieg gry.
Na samym początku gry wybieramy rozmiar pola oraz liczbę figur w rzędzie.
Rozmiar pola może być np. 3x3, 4x4 itd. Liczba figur w rzędzie mówi nam ile
takich samych figur musi być obok siebie, żeby dany gracz wygrał.
Również możemy wybrać z kim dany gracz ma grać, do wyboru ma
kolejnego gracza lub komputer.
Gracz 1 ma znak „x” , a Gracz 2 lub komputer znak „o”.
Podczas rozgrywki gracz podaje naprzemiennie z komputerem lub drugim
graczem dwie współrzędne. Komputer wybiera współrzędne na podstawie
algorytmu i wybiera dla siebie najlepszy ruch. Współrzędne w nawiasie w
pionie to 1 współrzędna, a w poziomie to 2 współrzędna. W przypadku
powtórzenia współrzędnych oraz przekroczenia współrzędnych poza zakres,
dostajemy komunikat i powtarzamy czynność.
Gra kończy się gdy ktoś wygrywa komunikatem „Wygrał dany gracz !”, lub
gdy wszystkie pola są zajęte. Gdy nikt nie wygrywa, a wszystkie pola są
zajęte gra kończy się remisem.
Stosowana w grze metoda sztucznej inteligencji bazuje na algorytmie
minmax. 
</p>
