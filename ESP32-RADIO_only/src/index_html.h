// index.html file in raw data format for PROGMEM
//
#define index_html_version 180102
const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
 <head>
  <title>ESP32-radio</title>
 <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
  <link rel="stylesheet" type="text/css" href="radio.css">
  <link rel="shortcut icon" type="image/ico" href="/favicon.png">
  <link rel="apple-touch-icon" href="/favicon.png" />
 </head>
 <body>
  <ul>
   <li><a class="pull-left active" href="/index.html">HOME</a></li>
   <li><a class="pull-left" href="/config.html">Config</a></li>
   <li><a class="pull-left" href="/search.html">Search</a></li>
   <li><a class="pull-left" href="/mp3play.html">MP3 player</a></li>
  </ul>
  <div id="container">
  <br><br><br>
  <center>
   <br>
   <button class="button" onclick="httpGet('downvolume=2')">VOLUME--</button>
   <button class="button" onclick="httpGet('upvolume=2')">VOLUME++</button>
   <br><br>
   <button class="button" onclick="httpGet('mute')">(un)MUTE</button>
   <button class="button" onclick="httpGet('stop')">(un)STOP</button>
   <br><br>
   <button class="button buttonr" onclick="httpGet('reset')">RESET</button>
   <br><br> <br><br>
    <label for="preset">RADIO:</label>
    <br>
    <select class="select selectw" onChange="handlepreset(this)" id="preset">
    <option value="-1">Select a preset here</option>
    </select>
  <br><br> <br><br>
    <label for="seltrack">MP3 files on SD card:</label>
    <br>
    <select class="select selectw" onChange="trackreq(this)" id="seltrack">
    <option value="-1">Select a track here</option>
    </select>
   <br><br> <br><br>
    <button class="button" onclick="httpGet('downpreset=1', true)">PREV</button>
    <button class="button" onclick="httpGet('uppreset=1', true)">NEXT</button>
    <button class="button" onclick="httpGet('mp3track=0', true)">RANDOM</button>
   <br> <br> <br> <br>
    <input type="text" width="600px" size="72" id="resultstr" placeholder="Waiting for a command...."><br>
   <br> <br> <br> <br>

  <script>
  
   function httpGet ( theReq )
   {
    var theUrl = "/?" + theReq + "&version=" + Math.random() ;
    var xhr = new XMLHttpRequest() ;
    xhr.onreadystatechange = function() {
      if ( xhr.readyState == XMLHttpRequest.DONE )
      {
        resultstr.value = xhr.responseText ;
      }
    }
    xhr.open ( "GET", theUrl ) ;
    xhr.send() ;
   }

   function handlepreset ( presctrl )
   {
     httpGet ( "preset=" + presctrl.value ) ;
   }
   
  function trackreq ( presctrl )
   {
    if ( presctrl.value != "-1" )
    {
      httpGet ( "mp3track=" + presctrl.value, false ) ;
    }
   }

   function setstat()
   {
     var theUrl = "/?station=" + station.value + "&version=" + Math.random() ;
     var xhr = new XMLHttpRequest() ;
     xhr.onreadystatechange = function() {
       if ( xhr.readyState == XMLHttpRequest.DONE )
       {
         resultstr.value = xhr.responseText ;
       }
     }
     xhr.open ( "GET", theUrl, false ) ;
     xhr.send() ;
   }

   function selectItemByValue(elmnt, value)
   {
     var sel = document.getElementById(elmnt) ;
     for(var i=0; i < sel.options.length; i++)
     {
       if(sel.options[i].value == value)
         sel.selectedIndex = i;
     }
   }
   
   // Fill preset list initially
   //
   var i, sel, opt, lines, parts, tracks, strparts ;
   var theUrl = "?settings" + "&version=" + Math.random() ;
   var xhr = new XMLHttpRequest() ;
   xhr.onreadystatechange = function() {
     if ( xhr.readyState == XMLHttpRequest.DONE )
     {
       lines = xhr.responseText.split ( "\n" ) ;
       for ( i = 0 ; i < ( lines.length-1 ) ; i++ )
       {
         sel = document.getElementById ( "preset" ) ;
         parts = lines[i].split ( "=" ) ;
         if ( parts[0].indexOf ( "preset_" ) == 0 )
         {
           opt = document.createElement ( "OPTION" ) ;
           opt.value = parts[0].substring ( 7 ) ;
           opt.text = parts[1] ;
           sel.add( opt ) ;
         }
       }
     }
   }
   xhr.open ( "GET", theUrl, false ) ;
   xhr.send() ;
   // Fill track list initially
   //
   sel = document.getElementById("seltrack") ;
   theUrl = "/?mp3list" ;
   var xhr1 = new XMLHttpRequest() ;
   xhr1.onreadystatechange = function(){
     if ( xhr1.readyState == XMLHttpRequest.DONE )
     {
       tracks = xhr1.responseText.split ( "\n" ) ;
       for ( i = 0 ; i < ( tracks.length - 1 ) ; i++ ){
         opt = document.createElement( "OPTION" ) ;
         strparts = tracks[i].split ( "/" ) ;
         opt.value = strparts[0] ;
         opt.text = strparts[1] ;
         sel.add( opt ) ;
       }
     }
   }
   xhr1.open ( "GET", theUrl, false ) ;
   xhr1.send() ;
   
  </script>
  </div>
 </body>
</html>
<noscript>
  <link rel="stylesheet" href="radio.css">
  Sorry, ESP-radio does not work without JavaScript!
</noscript>

)=====" ;
