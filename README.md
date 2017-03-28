# Będę grał w grę...

...czyli warsztaty z kombinatorycznej teorii gier podczas Dnia Wydziału
Matematyki i Informatyki Uniwersytetu Jagiellońskiego.

Wpisz do terminala poniższe polecenia, aby pobrać i skompilować program, który
pozwoli Ci zagrać w omawiane gry:

```
git clone https://github.com/adampolak/nim.git
cd nim
make
```

## Nim

Nim jest grą dla dwóch graczy, w którą gra się pewną liczbą kamieni
pogrupowanych w kilka stosów. Gracze na zmianę zabierają kamienie ze stosów. W
pojedynczym ruchu można zabrać dowolną (niezerową) liczbę kamieni, ale tylko z
jednego stosu na raz. Przegrywa ten gracz, który nie może wykonać ruchu, czyli, 
innymi słowy, wygrywa ten gracz, który weźmie ostatni kamień (bądź kamienie).

Aby zagrać w Nima przeciwko komputerowi, wpisz do terminala:

`./play nim`

Jeśli chcesz spróbować zagrać przy innym początkowym ustawieniem kamieni, jako
drugi argument programu możesz podać liczbę, oznaczającą numer planszy, na
przykład:

`./play nim 6`

Jak grać w tę grę tak, by wygrać zawsze, gdy tylko to możliwe? Podpowiedź
znajdziesz między innymi na
[Wikipedii](https://en.wikipedia.org/wiki/Nim#Mathematical_theory).

Teraz, kiedy już wiesz, jak wygrać w Nima, jeszcze raz zagraj z komputerem, tym
razem nie dając mu żadnych szans. Jeżeli umiesz programować w C/C++, możesz
wyedytować plik `nim-player.cpp` i zaimplementować w nim zwycięską strategię --
w ten sposób Twój kod będzie grać za Ciebie. Gdy skończysz edytować plik, nie
zapomnij przekompilować programu poleceniem `make`.

## Staircase Nim

W Staircase Nima również gra się kamieniami ułożonymi w stosy. Tym razem jednak
stosy muszą być ułożone od lewej do prawej, a ich porządek ma znaczenie. W
pojedynczym ruchu można zabrać dowolną liczbę kamieni z pojedynczego stosu i
przełożyć je na sąsiedni stos po lewej. Tylko kamienie znajdujące się na
skrajnie lewym stosie mogą zostać usunięte z gry. Podobnie jak w klasycznym
Nimie, przegrywa ten gracz, który nie może wykonać ruchu, czyli wygrywa ten,
który zabierze ostatni kamień.

Aby zagrać z komputerem w Staircase Nima, wpisz:

`./play staircase`

<details>
  <summary>Kiedy pierwszy gracz ma strategię wygrywającą w Staircase Nimie?</summary>
  Gdy `xor` rozmiarów nieparzystych stosów (numerujemy od lewej od 1) jest
  niezerowy.
</details>

Jeżeli chcesz, żeby komputer wyręczył Cię w wykonywaniu ruchów zgodnie z
wygrywającą strategią, wyedytuj plik `staircase-player.cpp`.

## Nim Minus 1,3,4

Zasady tej gry są identyczne jak zasady klasycznego Nima z tym tylko wyjątkiem,
że w pojedynczym ruchu można zabrać wyłącznie jeden, trzy lub cztery kamienie.

Aby spróbować swoich sił w rozgrywce z komputerem, wpisz:

`./play minus134`

W trakcie warsztatów zastanowimy się, jak wygrać w tę grę, zaczynając od
prostego przypadku z jednym tylko stosem i rozszerzając rozumowanie na większą
liczbę stosów. Przy okazji dowiemy się, co to są nimbery i o czym mówi
twierdzenie Sprague'a-Grundy'ego.

## Misère Nim

[Zeszłego roku w Marienbadzie](https://www.youtube.com/watch?v=bB3TTinXw4w)

<details>
  <summary>Czym ta gra się różni od klasycznego Nima?</summary>
  W klasycznym Nimie gracz, który wykona ostatni ruch wygrywa, a w Misère Nim
  gracz, który wykona ostatni ruch przegrywa.
</details>

<details>
  <summary>Kiedy pierwszy gracz ma strategię wygrywającą?</summary>
  Jeżeli w grze zostały same jedynki, pierwszy gracz wygrywa, jeśli jest ich
  parzyście wiele. W przeciwnym wypadku wygrywa ten gracz, który wygrałby
  w klasycznej wersji Nima.
</details>

## Grundy's Game

Do tej gry potrzebny jest metr krawiecki o długości *n* centymetrów oraz
nożyczki. Pierwszy gracz przecina metr w dowolnie wybranym punkcie podziałki,
z tym tylko ograniczeniem, że dwie powstałe w ten sposób części nie mogą być tej
samej długości. Po zakończonym ruchu gracz przekazuje nożyczki drugiemu. Ten
wybiera jedną z dwóch części, przecina ją według tych samych reguł, i tak dalej.
W ogólności, ruch polega na wybraniu jednego z fragmentów metra i przecięciu
go na dwie części różnej długości. Gra kończy się, gdy nie można wykonać ruchu,
czyli gdy wszystkie fragmenty mają długość jednego lub dwóch centymetrów.
Wygrywa ten gracz, który wykonał ostatni ruch.

Strategię wygrywającą w tej grze można obliczyć za pomocą programowania
dynamicznego korzystającego z twierdzenia Sprague'a-Grundy'ego w czasie
*O(n^2)*. Czy potrafisz to zrobić?
