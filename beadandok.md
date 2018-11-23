## Beadandó feladatok

A megoldásokat mindig teszteljétek le néhány érdekes bemenettel a `main()` függvényben.

### Stringek

#### Egyedi karakterek
Irjatok egy függvényt, ami a paraméterül kapott stringről megmondja, hogy csupa egyedi karakterből áll-e!  
Ha igen, a függvény térjen vissza 0-val, ha nem, akkor valamilyen nemnulla számmal. Példa deklaráció: 

`int is_unique_chars(const char *s);` 

#### Permutációk
Irjatok egy függvényt, ami a két paraméterül kapott stringről megmondja, hogy egymás permutációi-e!  
Ha igen, a függvény térjen vissza 0-val, ha nem, akkor valamilyen nemnulla számmal. 

`int is_permutation(const char *s, const char *t);`

#### Squeeze
Irjatok egy függvényt, ami egy adott stringből eltávolitja a kapott karakter összes előfordulását, helyben!  

`void squeeze(char *s, char taboo);`  

Upgrade: a függvény az összes olyan karaktert távolitsa el a stringből, amik egy másik stringben szerepelnek!  

`void squeeze(char *s, const char *taboo);`

#### Run length encoding
Irjatok egy függvényt, ami a karakterek előfordulási gyakoriságával kódolja el a kapott stringet, pl.  
`aaaabcddddefffggg` -> `4a1b1c4d1e3f3g`.  

Feltételezhetitek, hogy csak az angol abc kis- és nagybetűi szerepelnek az bemeneti stringben,
és hogy az első paraméterként kapott irható karaktertömbben elfér az eredmény.

`void run_length_encode(char *dest, const char *src);`

#### Caesar-kód
Implementáljuk a [Caesar-kód](https://en.wikipedia.org/wiki/Caesar_cipher) egy speciális fajtáját, a
[ROT13](https://en.wikipedia.org/wiki/ROT13) kódolást! 
[Segitség.](https://docs.cs50.net/2018/x/psets/2/caesar/caesar.html)  

```void rot13_encode(char *dest, const char *src);```

#### Vigenère-kód
Implementáljuk a [Vigenère-kódolást](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)! 
[Segitség.](https://docs.cs50.net/2018/x/psets/2/vigenere/vigenere.html)  

`void vigenere_encode(char *dest, const char *src, const char *key);`


### Tömbök, számitások

#### Polinom
A feladat egy polinom adott helyen vett helyettesitési értékének kiszámitása.
1. verzió: a polinom fokát, a helyet, ahol a helyettesitési értéket keressük, és az együtthatókat
a felhasználótól kérjük be. Használhatunk tömböket.
2. verzió: a polinom fokát nem kérjük be, és nem használunk tömböket, hanem alkalmazzuk a 
[Horner-elrendezést](https://hu.wikipedia.org/wiki/Horner-elrendez%C3%A9s).

#### Mátrixok
Irjunk egy függvényt, ami egy kétdimenziós tömböt, mátrixot vár paraméterként. Transzponáljuk 
a mátrixot, majd szorozzuk össze a transzponáltat az eredetivel, és irjuk ki az eredményt!
