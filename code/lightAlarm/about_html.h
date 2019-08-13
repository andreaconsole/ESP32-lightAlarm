// about.html file in raw data format for PROGMEM
//
#define about_html_version 170626
const char about_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
 <head>
  <title>About BlindAlarm</title>
  <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
  <link rel="Shortcut Icon" type="image/ico" href="favicon.ico">
  <link rel="stylesheet" type="text/css" href="radio.css">
 </head>
 <body>
  <ul>
   <li><a class="pull-left" href="#">BlindAlarm Config</a></li>
   <li><a class="pull-left" href="/index.html">Radio Config</a></li>
   <li><a class="pull-left" href="/config.html">Network Config</a></li>
   <li><a class="pull-left" href="/mp3play.html">MP3 player Config</a></li>
   <li><a class="pull-left active" href="/about.html">About</a></li>
  </ul>
  <br><br><br>
  <center>
   <h1>** BlindAlarm **</h1>
  </center>
	<p>ESP32 Radio -- Webradio receiver for ESP32, 1.8" color display and VS1053 MP3 module.<br>
	This project is documented at <a target="blank" href="https://github.com/Edzelf/ESP32-radio">Github</a>.</p>
	<p>Author: Andrea Console (andreaconsole.altervista.org)</p>
	<p>ESP32-Radio code: Ed Smallenburg (ed@smallenburg.nl)</p>
 </body>
</html>
)=====" ;
