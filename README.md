# Xen-OS
Il sistema operativo della console Xenos.

La console Xenos e Xen-OS sono un progetto con lo scopo di ricreare una console di gioco (come la PS4, XBOX,...) aggiungendogli un sistema operativo sfruttando la scheda Arduino e un box esterno stampato in 3D. Il Proggetto è stato fondato da @Croc-Prog-github in collaborazione con @ZEUSSTARSOP

**IMPORTANTE**: Per contribuire allo sviluppo del progetto crea una Pull Request e quando hai finito, inviala per l'approvazione.

Ci sono aggiornamenti e info sul progetto nelle Discussioni.

#### Per i Contibutori:
<div title="Task List" style="display: flex; background: darkgray; width: fit-content; border-radius: 5px; align-items: center;font-family: -apple-system,BlinkMacSystemFont,&quot;Segoe UI&quot;,&quot;Noto Sans&quot;,Helvetica,Arial,sans-serif,&quot;Apple Color Emoji&quot;,&quot;Segoe UI Emoji&quot;;">
  <svg aria-hidden="true" height="16" width="16" data-view-component="true" style="border-inline: 4px solid dimgray; border-block: 7px solid dimgray; border-radius: 4px;"><path d="M0 1.75C0 .784.784 0 1.75 0h12.5C15.216 0 16 .784 16 1.75v12.5A1.75 1.75 0 0 1 14.25 16H1.75A1.75 1.75 0 0 1 0 14.25ZM6.5 6.5v8h7.75a.25.25 0 0 0 .25-.25V6.5Zm8-1.5V1.75a.25.25 0 0 0-.25-.25H6.5V5Zm-13 1.5v7.75c0 .138.112.25.25.25H5v-8ZM5 5V1.5H1.75a.25.25 0 0 0-.25.25V5Z"></path></svg>
<a href="https://github.com/users/Croc-Prog-github/projects/5/views/1" style="padding: 4px;">Task list</a>
</div>

## Caratteristiche principali

| **RAM** |**CONTROLLER**|**HARD DISK**       |**AUDIO**            |**ALIMENTAZIONE**|**SCHERMO**  |
|--------------|--------------|--------------------|---------------------|-----------------|-------------|
|Slot:1        | MAX: 2     Lettore-scrittore SD |Integrato: X         |Batteria: X      |Integrato: X |
|Dimensione:1GB|Comand: Wirles|Size os: 8GB        |Connettore:          |Alimentatore: OK |HDMI: X      |
|              |              |User space: 4GB     |Jack: X              |                 |Pres.Scart: X|
|              |              |                    |USB: X               |                 |RCA: OK      |
|              |              |                    |RCA: OK              |                 |VGA: X       |
|              |              |                    |Port.Ser.25PIN: X    |                 |             |
|              |              |                    |Buffer Altern.Audi: X|                 |             |


## RCA video e audio
**RCA: Rosso, Bianco, Giallo**
|Colore|Segnale|
|------|-------|
|Rosso|audio destra|
|Bianco|audio sinistra|
|Giallo|video|
<!--
## Config. delle schede
|**Tutto in Arduino Mega**|**Separati in schede**|
|-------------------------|------------------|
|Economico: true|Economico: false|
|Prestazioni: false|Prestazioni: true|
|Problemi stimati: 30%|Problemi stimati: 45%|
|Flessibilità di prog.: false|Flessibilità di prog.: true|
|Stima Tempo 1°modello: 15h|Stima Tempo 1°modello: 34h|
-->