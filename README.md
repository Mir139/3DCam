# 3DCam
3D Rendering Engine auf des Qt Framework basiert, für die Wissenschaftliches Programmieren für Ingenieure Vorlesung der KIT entwickelt.
Dieses Programm wird von Robin Loebl entwickelt.

########## Programm starten ##########
Um 3DCam zu starten, gehen Sie in dem Ordner, der das Programm enthält, und nutzen diese Kommandozeile:

./3DCam

Das Programm wird mit einer Szene, die eine Kamera und einen Würfel enthält, starten.

Hinweis: das 1.0 Release probiert, um eine XML Datei, die "cube.xml" heisst, zu öffnen. Falls es keine so gennante XMl Datei in Programmordner gibt, wird das Programm mit einer leere Szene starten.


########## Programm nutzen ##########
Das Programmfenster unterteilt sich in 2 Felder :

* Das Render field
* Das Control field

Die ganze Szene wird durch das Render field gezeigt.
Die Kamera wird durh das Control field gesteuert.

1. Das Render field
Dieses Teil hat die Rolle, um die ganze Szene darzustellen. Sie liegt am linke obere Ecke dem Programmfenster. Die Dimensionnen von diesem Teil sind 1280px Breite und 720px Höhe.

2. Das Control field
Dieses Teil hat die Rolle, um die Kamera zu steuern. Die Kamera wird durch 7 Parametern gesteuert:

* 3 Parametern für die Koordinaten der Kamera (x, y, z)
* 3 Parametern für die Winkeln der Kamera (a, b, c)
* 1 Parameter für die Brennweite der Kamera (focal)

Die Kamera guckt in der x-Richtung. a, b und c sind bzw. die Winkeln um die x-, y- und z-Achsen. Diese Winkeln sind gleich zu den Eulerwinkeln:
* a: Rollwinkel
* b: Nickwinkel
* c: Gierwinkel

Mit Hilfe den x-, y-, z-, a-, b-, c- und focal-Felder können Sie die Kamera steuern. Ausserdem man kann auch mit Hilfe den Up-, Down-, Left-, Right-, Forward- und Backward-Knöpfe die Kamera in seinem eigenes Frame bewegen.


########## Release Notes ##########
---------- 1.0 ----------
* User Interface:
	* Render field:
		* Einstellung den einfachen Darstellungsfunktionen
		* Solidfarben werden ignoriert
	* Control field:
		* Einstellung den wesentlichen Steuerungsfunktionen
		* Im Gegensatz zu der Koordinaten, kann man nicht die Winkeln und die Brennweite mit Knopfen steuern
* Algorithmus:
	* Das Rendering-Algorithums wird eingestellt
	* Nur die erste Kamera wird betrachtet
	* Die Lichter werden ignoriert
