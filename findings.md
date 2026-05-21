# Viktor och Ziad, mars 24
Första 6 packets är handshakes (3 fram och tillbaka). 
Headern i acks är 28 (0x1C) bytes (två siffror är en byte). 
headern ser ut så här:

[Header length (2) | IRP ID (8) | USB status (4) | USB function (2) | Direction (1) | bus id (2) | device adress (2) | endpoint (1) | URB transfer type (1) | packet data length (4) | Control transfer stage setup (1)]

Control transfer stage finns bara i handshake header, alltså har andra headers längd 27 (0x1B)

Verkar finnas olika ips för sources: 1.29.0, 1.29.3, 1.29.4, 1.29.5 och 1.29.6 där 29 är device adress.
1.29.0 är för usb handshaken
1.29.3 har alla längd 91 byte om det skickas till oss och 27 som vi skickar baka (gissar en ack)
1.29.4 samma som 3 fast tvärtom. Så antagligen en port för att skicka och en för att ta emot.
1.29.5 har två större paket på längd 300-400, och vi skickar tillbaka en ack (antagligen alltså)
1.29.6 har bara ett paket skickat med 106 byte och 27 tillbaka, antagligen en ack. På samma sätt verkar vi skicka acks när vi får in stora paket på .5. 

De mesta av informationen är att vi skickar en paket på 91 till .4, får tillbaka en på 27 från .4 och sen skickar en på 27 till .3 och sen får en på 91 från .3. Detta repeteras massa gånger.

Värt att kolla upp:
Hur skiljer sig paketen som går igenom portarna 3->6. Framförallt headern för att det är lättast att se skillnad. På något sätt borde det förklara vad man ska göra med informationen gissningsvis.

# Ziad, mars 25
Enligt hur de beskriver handshaken i driver-guide.md borde handshaken vara:
    Frame 7  - OUT type 0x0d, cmd 0x00              host   -> device
    Frame 8  - bekräftelse                          device -> host
    Frame 9  - Ber om data                          host   -> device
    Frame 10 - type 0x0d, cmd 0x07, status ff       device -> host
    Frame 11 - OUT type 0x08, cmd 0x01              host   -> device
    Frame 12 - bekräftelse                          device -> host
    Frame 13 - Ber om data                          host   -> device 
    Frame 14 - IN  type 0x09, cmd 0x01, status 40   device -> host
               statusen 40 står inte på samma
               ställe som ff? konstigt         
    Frame 15 - OUT type 0x08, cmd 0x19              device -> host 
    ...
    Frame 19 - OUT type 0x08, cmd 0x68              device -> host
    ..
    Frame 23 - OUT type 0x08, cmd 0x18              device -> host 
    ..
     
Alla 

ChatGPT:
| Type   | Role                  |
| ------ | --------------------- |
| `0x08` | Host command          |
| `0x09` | Command response      |
| `0x0D` | Session/control/reset |
| `0x0B` | Pipe/transfer setup   | 
| `0x18` | Data stream packets   | Verkar inte finnas?

# Ziad, mars 26
Enligt docs sen innan finns det en header inuti själva payloaden, och det verkar inte som vi behöver bry oss så mycket om usb headern vi har kollat på innan

Docsen snackar om att det finns ett fält för type och command, men vissa cmd och type värden dyker aldrig upp, vilket betyder att någonstans finns det något fel. Antigen att vissa värden på typer och commands är dokumenterade fel, men kan även vara så att de fälten inte alls vad vi tror de är.

Docsen nämer också aldrig port nummer 6, så det verkar missats någonting där, oklart om det är viktigt då inte många paket skickas där. De nämner aldrig port 0 men det är en usb handshake som jag tror vi inte behöver bry oss om.

# Bartek, 26 mars
1.20.5 verkar vara data under en mätning. Den stora payloaden är 512 bytes, dock formen på själva värden är oklar för stunden. Det verkar som att de är inte traditionella 8 byte floating-points eller fixed-points utifrån testning av att läsa av en mätning.

# Bartek, 30 mars
Har laddat ner ILSpy samt MicroLab PC och dekompilerat .dll filer till C#. Har börjat leta runt på information gällande omvandling av sampling datan samt resultat outputen. Har inte hittat några fourier transformen i koden men har hittat klasserna där resultatet förvaras.
Samt fått en genomgång på hur man gör en mätning med spektrometer i labbsalen och dokumeterat det.

# Albin, 4 april
Spektrometern mäter konstant data. Mest troligen finns det flaggor i nåt paket (hypotes är 91 bytes paket) som säger om datan ska skickas vidare.

Mycket findings om de olika paketen har hittats, finns i paket_findings och 91_bytes filerna

Storleken på paketen som innehåller datan ändras om inställningen "Spectral resolution" ändras. 

Använt musklickningar för att se när olika paket skickas och vad de kan vara. Fann då att 103 bytes paketen är när man klickar på "Next" på olika sidor i programmet och det är dom paketen som skickar vidare vissa parametrar till spektrometern.