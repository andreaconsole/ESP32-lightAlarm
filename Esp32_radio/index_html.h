// index.html file in raw data format for PROGMEM
//
#define index_html_version 180102
const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
 <head>
  <title>RadioAlarm</title>
  <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
  <link rel="stylesheet" type="text/css" href="radio.css">
  <link rel="shortcut icon" type="image/ico" href="/favicon.png">
  <link rel="apple-touch-icon" href="/favicon.png" />
 </head>
 <body>
  <ul>
   <li><a class="pull-left active" href="/index.html">ESP32 - Radio, mp3 player, alarm clock</a></li>
   <li><a class="pull-right" href="/config.html">System Configuration</a></li>
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
   <br><br>
      <label for="alarmh">HOUR </label>
      <span>&nbsp;  &nbsp;</span>
      <label for="alarmm"> MINUTES</label>
      <br>
      <select class="select selects" onChange="handlealarm(this)" id="alarmh">
       <option value="00" selected>00</option>
       <option value="01">01</option>
       <option value="02">02</option>
       <option value="03">03</option>
       <option value="04">04</option>
       <option value="05">05</option>
       <option value="06">06</option>
       <option value="07">07</option>
       <option value="08">08</option>
       <option value="09">09</option>
       <option value="10">10</option>
       <option value="11">11</option>
       <option value="12">12</option>
       <option value="13">13</option>
       <option value="14">14</option>
       <option value="15">15</option>
       <option value="16">16</option>
       <option value="17">17</option>
       <option value="18">18</option>
       <option value="19">19</option>
       <option value="20">20</option>
       <option value="21">21</option>
       <option value="22">22</option>
       <option value="23">23</option>
      </select>
      <span>&nbsp; : &nbsp;</span>
      <select class="select selects" onChange="handlealarm(this)" id="alarmm">
       <option value="00" selected>00</option>
       <option value="05">05</option>
       <option value="10">10</option>
       <option value="15">15</option>
       <option value="20">20</option>
       <option value="25">25</option>
       <option value="30">30</option>
       <option value="35">35</option>
       <option value="40">40</option>
       <option value="45">45</option>
       <option value="50">50</option>
       <option value="55">55</option>
      </select>
      <br><br>
      
      <label for="alarmv">INITIAL VOLUME: </label>
       <select class="select selects" onChange="handlealarm(this)" id="alarmv">
       <option value="10">10</option>
       <option value="20">20</option>
       <option value="30" selected>30</option>
       <option value="40">40</option>
       <option value="50">50</option>
       <option value="60">60</option>
       <option value="70">70</option>
       <option value="80">80</option>
       <option value="90">90</option>
      </select>
      &nbsp; &nbsp; &nbsp; &nbsp;
      <label class="switch">
        <input type="checkbox" id="alarmon" onChange="handlealarm(this)">
        <span class="slider round"></span>
      </label>
      
      
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
   
    function handlealarm ( alarmctrl )
  {
    var alarmOn = document.getElementById("alarmon");
    var alarmH = document.getElementById("alarmh");
    var alarmM = document.getElementById("alarmm");
    var alarmV = document.getElementById("alarmv");
    if (alarmctrl.id !="alarmon")
    {
      alarmOn.checked = true ;
    }
    var theUrl = "/?alarm_time=" + alarmH.value + ":" + alarmM.value +
                 "-" + alarmV.value + "-" + +alarmOn.checked + 
                 "&version=" + Math.random() ;
    var xhr = new XMLHttpRequest() ;
    console.log(theUrl);
    xhr.onreadystatechange = function() {
      if ( xhr.readyState == XMLHttpRequest.DONE )
      {
        resultstr.value = xhr.responseText ;
      }
    }
    xhr.open ( "GET", theUrl, false ) ;
    xhr.send() ;
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
         if ( ( parts[0] == "alarmh"  ) ||
              ( parts[0] == "alarmm"  ) ||
              ( parts[0] == "alarmv"  ) ||
              ( parts[0] == "preset" ) )
         {
           selectItemByValue ( parts[0], parts[1] ) ;
         }
         if (parts[0] == "alarmon")
         {
            if (parts[1] == "1")
            { 
                  sel = document.getElementById ( "alarmon" ) ;
                  sel.checked = true;
            }
              else
            { 
                psel = document.getElementById ( "alarmon" ) ;
                sel.checked = false;
            }
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
