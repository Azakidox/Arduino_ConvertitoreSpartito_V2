# V2 - Conversione canzone da Spartito (per Arduino Buzzer)

### Introduzione al Buzzer
Il cicalino piezoelettronico è un piccolo dispositivo che produce suoni quando viene alimentato con segnali elettrici. È spesso utilizzato nei progetti Arduino per emettere beep o toni musicali. Il buzzer è collegato a un pin di uscita del microcontrollore, come Arduino, e produce suoni variando la frequenza del segnale elettronico inviato.

### Collegamento del Buzzer ad Arduino (Arduino UNO) (uguale alla V1)

1) Collegare il pin positivo (+) del buzzer ad un PIN DIGITALE di Arduino. (esempio 10)
2) Collegare il pin negativo (-) del buzzer ad una resistenza da 220Ohm e successivamente collegare l'altra estremità al GND (terra) di Arduino.

*Il circuito dovrà essere simile a questo:*

<img src="https://github.com/Azakidox/Arduino_Convertire_Canzoni/blob/main/CollegamentoBuzzer.png" width="500" height="250">

## Preparazione delle NOTE con le relative frequenze.

In modo semplice, diremo ad Arduino di suonare determinate note. Per "istruire" il nostro Arduino è necessario creare un file separato (per comodità) e definire il nome della nota con la sua frequenza corrispondente. Nel progetto, è già presente un file chiamato pitches.h con tutte le note rinominate in modo da essere più comprensibili, insieme alle loro relative frequenze. Ogni nota corrisponde a una frequenza diversa. Le note nel mio file pitches.h vanno da DO1 a RE8, includendo tutte le note diesis (#) contrassegnate con una "d" minuscola dopo il nome della nota. Ad esempio: DOd1 è DO# della prima ottava, SOLd2 è SOL# della seconda ottava, e così via. La scelta delle frequenze non è casuale; è possibile trovare facilmente la corrispondenza tra note e frequenze su internet.

```
#define DO1  32.70 //DO1
#define DOd1 34.65 //DO# (do diesis) o Reb =re bemolle
#define RE1  36.71 //RE
#define REd1 38.89 //RE#
#define MI1  41.20 //MI
#define FA1  43.65 //FA
#define FAd1 46.25 //FA#
#define SOL1  49.00 //SOL
#define SOLd1 51.91 //SOL#
#define LA1  55.00 //LA
#define LAd1 58.27 //LA#
#define SI1  61.74 //SI
#define DO2  65.41 //DO2
```

## Inserimento delle note

Nel codice si utilizza una struttura ```Nota``` per definire ogni singola nota della melodia. 
Questa struttura include informazioni sulla frequenza della nota (```pitch```), sulla durata della nota (```durata```) e su altri paramenti come nota puntata o legata.

Tralasciando gli aspetti tecnici, per creare una melodia l'inserimento delle note basterà recarsi nel codice nell'array Spartito.

```
Nota spartito[] = {
    {DO6, "breve", true, false}, // Puntata
    {0, "pausa-croma", false, false},
    {DO6, "croma", false, false},
    // Aggiungi altre note qui
};
```

Le durate delle note sono definite come stringhe (```breve```, ```semibreve```, ```minima```, ```semiminima```, ecc.
Trovi la spiegazione completa sulla V1 nel file README.

Come si vede nell'esempio, tramite lo spartito bisognerà leggere la nota, inserirla, quindi DO, RE, MI, FA, SOL o altro, tenendo conto se è una nota # e tenendo conto anche dell'ottava utilizzata.

Poi basterà leggere la simbologia e capire quindi la durata della nota, quindi inserire breve, semibreve, semiminima ecc. e poi inserire se puntata o legata.

