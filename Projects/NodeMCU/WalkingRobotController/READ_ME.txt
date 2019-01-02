This Code is meant for the NODEMCU 1.0
You need to install the board drivers into the Arduino IDE to get it to compile.
And to write to the NodeMCU, set the baud rate to 115200.

If you want to change the webpage that is displayed, I recommend making changes to the 
index.html file first, and then copying it's contents to the index.h file so that the new 
code is inbetween 
	const char MAIN_page[] PROGMEM = R"=====(
	<!--New/Modified HTML Code -->
	)=====";
