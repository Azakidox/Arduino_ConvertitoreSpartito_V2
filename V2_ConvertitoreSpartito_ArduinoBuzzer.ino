#include "pitches.h"
#define buzzer 10

// Gli unici valori da modificare sono i BPM, nella riga sotto e le note nell'array spartito.
// Per il resto vi invito di stare fermi se non avete dimistichezza. 
// Per qualsiasi tipo di domanda o altro contact me (Discord: azakidox)

const int BPM = 150; // BPM impostati

struct Nota { // Impostazione della struttura della nota
    int pitch; // Intero Pitch (frequenza/Nota)
    const char* durata; // Durata espressa in "stringa" con const char*
    bool puntato; // Valore booleano, true o false se puntato o meno
    bool legata; // Valore booleano, true o false se legato o meno
};

int durataInMs(const char* durata, bool puntato) {  // Converte la durata epspressa in stringa in millisecondi e tiene conto delle note puntate
    float beatDuration = 60000.0 / BPM; // Calcolo della durata di un battito in millisecondi
/* 
La funzione 'strcmp' (funzione del C) confronta due stringhe.
Nel codice, 'strcmp' viene usata per confrontare la "durata" di una nota (espressa in stringa)

Esempio:  if (strcmp(durata, "breve") == 0) 

All'interno della funzione strcmp viene confrontato il "valore" di 'durata' con "breve".
Se le due stringhe sono identiche, quindi contengono le stesse lettere il risultato sarà 0.
Il ciclo if verifica che lo 0 (dato dalla funzione strcmp) è uguale a 0 o no. Se è uguale restituisce un true (altrimenti false)

Considerando l'esempio di prima, se 'durata' equivale in quel momento a "breve" allora la differenza sarà 0 e la funzione strcmp darà 0 e l'if sarà true.

Sotto l'if c'è un'altro if :)

 */

    if (strcmp(durata, "breve") == 0) 
      {
        if (puntato) return  8 * beatDuration + durataInMs("semibreve", false); // Controlla se la nota è puntata o meno
        else return 8 * beatDuration; // Calcola il suo valore in millisecondi
    }
      
    if (strcmp(durata, "semibreve") == 0)
        {
        if (puntato) return  4 * beatDuration + durataInMs("minima", false);
        else return 4 * beatDuration;
    }
  
    if (strcmp(durata, "minima") == 0)
      {
        if (puntato) return 2 * beatDuration + durataInMs("semiminima", false);
        else return 2* beatDuration;
    }
  
    if (strcmp(durata, "semiminima") == 0)
    {
        if (puntato) return beatDuration + durataInMs("croma", false);
        else return beatDuration;
    }
    if (strcmp(durata, "croma") == 0)
          {
        if (puntato) return  beatDuration / 2 + durataInMs("semicroma", false);
        else return beatDuration / 2;
    }
    if (strcmp(durata, "semicroma") == 0)
      {
        if (puntato) return  beatDuration / 4 + durataInMs("biscroma", false);
        else return beatDuration / 4;
    }
  if (strcmp(durata, "biscroma") == 0) return beatDuration / 8;
  
  // pause
  if (strcmp(durata, "pbreve") == 0) return 8 * beatDuration;
  if (strcmp(durata, "psemibreve") == 0) return 4 * beatDuration;
  if (strcmp(durata, "pminima") == 0) return 2 * beatDuration;
  if (strcmp(durata, "psemiminima") == 0) return beatDuration;
  if (strcmp(durata, "pcroma") == 0) return beatDuration / 2;
  if (strcmp(durata, "psemicroma") == 0) return beatDuration / 4;
  if (strcmp(durata, "pbiscroma") == 0) return beatDuration / 8;

}

int durataPuntataInMs(const char* durata) {
    return durataInMs(durata, true);
}

int durataLegataInMs(const char* durata1, const char* durata2) {
    return durataInMs(durata1, false) + durataInMs(durata2, false);
}

Nota spartito[] = {
    {0, "pcroma", false, false},
    {DO6, "croma", false, false}, 
    {DO6, "croma", false, false},
    {DO6, "croma", false, false}, 
      
    {SI5, "croma", true, false}, // Puntata
    {LA5, "semicroma", false, false},
    {SOL5, "semiminima", false, true}, //legato a quello sotto
    {SOL5, "croma", false, false},
      
    {FA6, "croma", false, false},
    {FA6, "croma", false, false},
    {FA6, "croma", false, false},
      
    {MI6, "croma", true, false}, // Puntata
    {RE6, "semicroma", false, false},
    {DO6, "semiminima", false, true}, //legato a quello sotto
    {DO6, "croma", false, false},
      
    {SOL6, "croma", false, false},
    {SOL6, "croma", false, false},
    {SOL6, "croma", false, false},

    {SOL6, "croma", true, false}, // Puntata
    {MI6, "semicroma", false, false},
    {MI6, "croma", false, false},
    {DO6, "croma", false, false},
      
    {DO6, "croma", true, false}, // Puntata
    {RE6, "semicroma", false, false},
    {RE6, "croma", false, false},
    {DO6, "croma", false, false}, 

    {SI5, "croma", true, false}, // Puntata
    {LA5, "semicroma", false, false},
    {SOL5, "semiminima", false, true}, //legato a quello sotto
    {SOL5, "croma", false, false},
      
    {SOL5, "croma", false, false},
    {SI5, "croma", false, false},
    {RE6, "croma", false, false},
      
    {FA6, "semiminima", false, false},
    {FA6, "semiminima", false, true}, //legato a quello sotto
    {FA6, "croma", false, false},

    {SOL6, "croma", false, false},
    {FA6, "croma", false, false},
    {MI6, "croma", false, false},

    {RE6, "minima", false, true}, //legato a quello sotto
    {RE6, "croma", false, false},

    {SOL5, "croma", false, false},
    {SI5, "croma", false, false},
    {RE6, "croma", false, false},
    
    {FA6, "croma", true, false}, // Puntata
    {RE6, "semicroma", false, false},
    {MI6, "croma", false, false},
    {FA6, "croma", false, false},

    {SOL6, "croma", false, false},
    {FA6, "croma", false, false},
    {MI6, "croma", false, false},
    {RE6, "croma", false, false},

    {DO6, "croma", false, false},
    {0, "pcroma", false, false},
    {DO6, "croma", true, false}, // Puntata
    {DO6, "semicroma", false, false},

    {DO6, "semicroma", false, false},
    {0, "psemicroma", false, false},
    {0, "pminima", false, false},

};

void setup() {
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int size = sizeof(spartito) / sizeof(spartito[0]); // Calcola il numero di elementi nell'array spartito
    for (int i = 0; i < size; i++) {

              if (Serial.available() > 0) {
            String input = Serial.readStringUntil('\n');
            input.trim();
            if (input.equalsIgnoreCase("stop")) {
                noTone(buzzer); // Usa la funzione noTone per interrompere l'esecuzione del buzzer
                while (true) {
                    delay(100);
                }
            }
        }

        int wait;
        if (spartito[i].puntato) {
            wait = durataPuntataInMs(spartito[i].durata);
        } else {
            if (spartito[i].legata && i < size - 1) {
                wait = durataLegataInMs(spartito[i].durata, spartito[i + 1].durata);
                i++; // Salta la nota legata successiva
            } else {
                wait = durataInMs(spartito[i].durata, false);
            }
        }
        
        // Stampa la durata calcolata
        Serial.print("Nota: ");
        Serial.print(spartito[i].pitch);
        Serial.print(", Durata: ");
        Serial.println(wait);

        if (spartito[i].pitch != 0) { // Suona la nota se non è una pausa
            tone(buzzer, spartito[i].pitch, wait);
        }
        delay(wait);
    }
}
