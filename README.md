# V2 - Conversione canzone da Spartito (per Arduino Buzzer)

## Introduzione al Buzzer
Il cicalino piezoelettronico è un piccolo dispositivo che produce suoni quando viene alimentato con segnali elettrici. È spesso utilizzato nei progetti Arduino per emettere beep o toni musicali. Il buzzer è collegato a un pin di uscita del microcontrollore, come Arduino, e produce suoni variando la frequenza del segnale elettronico inviato.

## Collegamento del Buzzer ad Arduino (Arduino UNO) (uguale alla V1)

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

## Leggere le note sul pentagramma (Spartito)

Leggere un pentagramma è fondamentale per interpretare e suonare una canzone da spartito.

### Pentagramma

Il *pentagramma* è composto da 5 linee parallele e 4 spazi. Ogni linea e spazio rappresenta una nota musicale.

<img src="https://www.scuola-e-cultura.it/wp-content/uploads/2022/11/pentagramma.jpeg" width=500 />

Per sapere a quale linea o spazio corrisponde una nota, dobbiamo considerare la chiave musicale utilizzata. Esistono tre tipi principali di chiavi musicali:
- Chiave di Sol (o chiave di violino)
- Chiave di Fa (o chiave di basso)
- Chiave di Do

<img src="https://www.icoloridellamusica.com/wp-content/uploads/2023/09/Setticlavio-chiavi.png" width=400 />

Le note possono essere posizionate sulle linee o negli spazi del pentagramma. Ogni posizione rappresenta una nota differente.

Ipotizziamo di avere una chiave di Sol. Quando vedrai questa chiave all'inizio del pentagramma, saprai che la seconda linea dal basso equivale a un SOL.

<img src="https://www.pianosegreto.com/wp-content/uploads/2017/01/Schermata-2017-01-16-alle-12.06.42.png" width=400 />

Quindi, tutti i "simboli" (pallini) scritti sulla seconda linea rappresenteranno la nota SOL.

<img src="https://pianoforteweb.it/wp-content/uploads/2021/11/chiave-di-violino-chiave-di-sol-1024x874.png" width=200 />

Avendo trovato una nota, possiamo determinare anche le altre note.

<img src="https://cp.shb-cdn.com/cdn/app/statics/contents/books/CP2022_2613694F/html/50/assets/images/050_a.jpg" width=500 />

Per approfondire e capire meglio la chiave di Fa o di Do, ti consiglio di guardare qualche video. Ho scelto di spiegare solo la chiave di Sol perché è la più comune.

### Durate delle note

Nel pentagramma, oltre alle note, vengono rappresentate anche le durate, che indicano per quanto tempo deve essere suonata una nota. Le durate sono indicate tramite simboli specifici.

<img src="https://musicadiffusa.it/wp-content/uploads/2019/03/schema-per-durata-delle-note.jpg" width=300 />

*Sul programma, basterà inserire la nota e il nome del valore che leggiamo quindi semiminima, croma, semicroma ecc,dopo ovviamente aver inserito i BPM della canzone a inizio codice, in automatico calcolerà la durata della nota in millisecondi.*

Quindi, in base al simbolo che leggiamo, possiamo determinare la durata della nota.

Per le **pause** ci basterà seguire questa tabella.

<img src="https://www.pianosegreto.com/wp-content/uploads/2017/01/Schermata-2017-01-16-alle-13.27.54-1024x480.png" width=600 />

In base al simbolo della pausa vediamo a cosa corrisponde, se una minima, semiminima o altro e ci basterà aggiungere prima una "p".
Quindi psemiminima, pcroma, psemicroma, psemibreve...con la "p" davanti si indica la pausa.


## Inserimento delle note

Nel codice si utilizza una struttura ```Nota``` per definire ogni singola nota della melodia. 
Questa struttura include informazioni sulla frequenza della nota (```pitch```), sulla durata della nota (```durata```) e su altri paramenti come nota puntata o legata.

## 1° Passaggio
### Individuare le note dallo spartito e inserirle nell'array

<img src="https://www.leoravera.it/wp-content/uploads/2018/12/MI-SOL-SI-RE-FA.png" width=600 />

Se leggiamo questo pentagramma sappiamo quindi che le note sono ```MI```, ```SOL```, ```SI```, ```RE```, ```FA```.
Una volta trovate le note (che per comodità nell'immagine precedente sono già state segnate) potremmo procedere con l'inserimento :)

```
Nota spartito[] = {
    {MI, "", false, false},
    {SOL, "", false, false},
    {SI, "", false, false},
    {RE, "", false, false},
    {FA, "", false, false},
};
```

## 2° Passaggio
### Individuare il valore della durata tramite il simbolo della nota

Seguendo la tabella che segue possiamo inserire per ogni nota il suo valore di durata.

<img src="https://musicadiffusa.it/wp-content/uploads/2019/03/schema-per-durata-delle-note.jpg" width=300 />

Nel mio caso, hanno tutte lo stesso simbolo, che equivale ad una semiminima.
Quindi procediamo a inserire il valore di semiminima tra le virgolette accanto ad ogni nota.

```
Nota spartito[] = {
    {MI7, "semiminima", false, false},
    {SOL7, "semiminima", false, false},
    {SI7, "semiminima", false, false},
    {RE7, "semiminima", false, false},
    {FA7, "semiminima", false, false},
};
```
*Il numero vicino le note indica l'ottava, nel codice partono da 1 e arrivano fino a 8. Se si lascia la nota da sola senza numero il programma (l'IDE) darà errore e non eseguirà il codice.*

## 3° Passaggio
### Inserire i BPM per la nostra melodia.

```const int BPM = 150;``` --> Più saranno alti, più la melodia sarà veloce, più saranno bassi più sarà lenta (le note dureranno di più o di meno in base ai BPM)

## Note Puntate o Legate
In caso di note *puntate* o *legate* ci basterà modificare i valori di ```true/false``` e ```true/false```.
Nella prima condizione, il true equivale ad una nota puntata.
Nella seconda condizione, il true equivale ad una nota legata (a quella sotto)

```
Nota spartito[] = {
    {MI7, "semiminima", true, false},    // Nota puntata
    {SOL7, "semiminima", false, false},
    {SI7, "semiminima", true, false},     //Nota puntata
    {RE7, "semiminima", false, false},
    {FA7, "semiminima", false, false},
};
```

Oppure se è legata

```
Nota spartito[] = {
    {MI7, "semiminima", false, false},   
    {SOL7, "semiminima", false, true},   // Legata a quella sotto
    {SI7, "semiminima", false, false},  
    {RE7, "semiminima", false, true},    // Legata a quella sotto
    {FA7, "semiminima", false, false},
};
```



