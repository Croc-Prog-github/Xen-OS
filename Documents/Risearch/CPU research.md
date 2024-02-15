# CPU research
Questa ricerca è mirata a descrivere i comportamenti e la struttura di una CPU, in modo da ottimizzare gli utilizzi del sistema operativo Xen-OS.

## Cicli
- fetch-decode-execute

Il ciclo di **fetch-decode-execute** è il processo fondamentale che la CPU compie per eseguire un'istruzione. Si divide in tre fasi:

1. **Fetch (Recupero)**:
La CPU carica l'istruzione dalla memoria principale in un registro speciale chiamato "instruction register".
L'indirizzo dell'istruzione è prelevato dal program counter (PC), un registro che tiene traccia dell'istruzione successiva da eseguire.

2. **Decode (Decodifica)**:
L'istruzione viene decodificata per capire il suo significato e quali operazioni devono essere eseguite.
Vengono identificati i codici operativi (opcode) e gli operandi (valori o indirizzi di memoria) dell'istruzione.

3. **Execute (Esecuzione)**:
L'unità di controllo della CPU orchestra l'esecuzione dell'istruzione.
L'unità di calcolo e logica (ALU) esegue le operazioni aritmetiche e logiche.
L'unità di memoria gestisce l'accesso ai dati nella memoria principale.
Al termine dell'esecuzione, il program counter viene incrementato per puntare alla prossima istruzione da eseguire. Il ciclo di fetch-decode-execute si ripete continuamente finché non termina il programma