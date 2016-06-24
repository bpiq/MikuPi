# MikuPi by MikuQ.com

	git clone https://github.com/bpiq/MikuPi.git
	cd MikuPi
	sudo make

because Arduino based C++, update MikuDuino to C++, 2016-6-4

<pre><code>
cd examples
gcc -Wall -o blink blink.cpp -lMikuDuino
sudo ./blink
</code></pre>

<pre><code>
 +-----+-----+---------+------+---+- MikuPi -+---+------+---------+-----+-----+
 | CPU | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | CPU |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 | 229 |   8 |   SDA.1 |   IN | 0 |  3 || 4  |   |      | 5V      |     |     |
 | 228 |   9 |   SCL.1 |   IN | 0 |  5 || 6  |   |      | GND     |     |     |
 | 362 |   7 |    GCLK |  OUT | 1 |  7 || 8  | 0 | IN   | TxD0    | 15  | 32  |
 |     |     |     GND |      |   |  9 || 10 | 0 | IN   | RxD0    | 16  | 33  |
 |  68 |   0 |    GEN0 | ALT3 | 0 | 11 || 12 | 0 | IN   | GEN1    | 1   | 35  |
 |  71 |   2 |    GEN2 | ALT3 | 0 | 13 || 14 |   |      | GND     |     |     |
 |  81 |   3 |    GEN3 | ALT3 | 0 | 15 || 16 | 0 | IN   | GEN4    | 4   | 34  |
 |     |     |    3.3v |      |   | 17 || 18 | 1 | OUT  | GEN5    | 5   | 360 |
 |  64 |  12 |    MOSI | ALT4 | 0 | 19 || 20 |   |      | GND     |     |     |
 |  65 |  13 |    MISO | ALT4 | 0 | 21 || 22 | 1 | OUT  | GEN6    | 6   | 361 |
 |  66 |  14 |    SCLK | ALT4 | 0 | 23 || 24 | 0 | ALT4 | CE0     | 10  | 67  |
 |     |     |     GND |      |   | 25 || 26 | 0 | IN   | CE1     | 11  | 234 |
 | 227 |  30 |   SDA.0 |   IN | 0 | 27 || 28 | 0 | IN   | SCL.0   | 31  | 226 |
 |  82 |  21 | GPIO.21 | ALT3 | 0 | 29 || 30 |   |      | GND     |     |     |
 | 202 |  22 | GPIO.22 | ALT2 | 0 | 31 || 32 | 0 | ALT3 | GPIO.26 | 26  | 205 |
 | 203 |  23 | GPIO.23 | ALT3 | 0 | 33 || 34 |   |      | GND     |     |     |
 | 204 |  24 | GPIO.24 |  OUT | 0 | 35 || 36 | 0 | ALT3 | GPIO.27 | 27  | 133 |
 | 132 |  25 | GPIO.25 | ALT3 | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | 146 |
 |     |     |     GND |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | 147 |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | CPU | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | CPU |
 +-----+-----+---------+------+---+- BPI-M3 -+---+------+---------+-----+-----+
</code></pre>

	1.(2016-05-30) start & sayhello
	2.(2016-06-02) gpio for M2+,M3 & blink
	3.(2016-06-04) update to C++ & add Relay
	4.(2016-06-05) add Wire & SHT2x 
	5.(2016-06-24) add MikuOLED

upload

	git add .
	git commit -a -m "md"
	git push origin master
