// radio.css file in raw data format for PROGMEM
//
const char radio_css[] PROGMEM = R"=====(

*{
  margin:0;
  padding:0;
}

body {
  font-family:  verdana,sans-serif;
  font-size: 1.5em;
  color: #282E34; 
  background-color: #145567; 
  touch-action: pan-y;
}

input[type=submit]{
  font-family:  verdana,sans-serif;
  font-size: 1.2em;
  color: #84c5d7;
  background-color: #145567; 
}

textarea{
  padding:10px;
  margin:10px;
}

img { border: none; }

p {
text-align: center;
}

.center {
  display:block ;
  margin-left:auto ;
  margin-right:auto ;
  left: 0;
  right: 0;
}




/*container*/

#container {    
  margin: auto;
  max-width: 800px;
  width: 100%;
  height:100%;
  -moz-box-shadow: 0 0 40px #000;
  -webkit-box-shadow: 0 0 40px #000;
  box-shadow: 0 0 60px #000;
  background-color: #64a5b7;
}


h1 {
   color: navy;
   margin-left: 20px;
   font-size: 120%
}

ul {
   list-style-type: none;
   margin: 0;
   margin-left: -10px;
   overflow: hidden;
   background-color: #2C3E50;
   position:fixed;
   top:0;
   width:100%;
   z-index:100;
}

li .pull-left {
   float: left;
}

li .pull-right {
   float: right;
}

li a {
   display: block;
   color: white;
   text-align: center;
   padding: 14px 16px;
   text-decoration: none;
}

li a:hover, a.active {
   background-color: #111;
}

.button {
   width: 300px;
   background-color: #2C3E50;
   font-size: 1.5em;
   border: none;
   color: white;
   text-align: center;
   text-decoration: none;
   display: inline-block;
   margin: 20px 20px;
   padding: 20px;
   cursor: pointer;
   border-radius: 4px;
}

.buttonr {background-color: #D62C1A;}

.select {
   width: 160px;
   height: 80px;
   padding: 5px;
   background: white;
   font-size: 2em;
   line-height: 1;
   border: 1;
   border-radius: 5px;
   -webkit-border-radius: 5px;
   -moz-border-radius: 5px;
   -webkit-appearance: none;
   border: 1px solid black;
   border-radius: 10px;
}

.selectw {width: 700px;}

.selects {width: 80px;}

label {
  font-size: 1.5em;
}

input[type="text"] {
  width: 700px;
   height: 50px;
   padding: 5px;
   background: white;
   font-size: 1.5em;
   margin: 0;
   background: white;
   appearance: none;
   box-shadow: none;
   border-radius: 5px;
   -webkit-border-radius: 5px;
   -moz-border-radius: 5px;
   -webkit-appearance: none;
   border: 1px solid black;
   border-radius: 10px;
}

input[type="text"]:focus {
  outline: none;
}

input[type=submit] {
  width: 200px;
  height: 40px;
  background-color: #128F76;
  border: none;
  color: white;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
  border-radius: 5px;
}

textarea {
  width: 180;
  height: 25;
  border: 1px solid black;
  border-radius: 10px;
  padding: 5px;
  font-family: Courier, "Lucida Console", monospace;
  background-color: white;
  resize: none;
}

/* The switch - the box around the slider */
.switch {
  position: relative;
  display: inline-block;
  width: 114px;
  height: 64px;
}

/* Hide default HTML checkbox */
.switch input {
  opacity: 0;
  width: 0;
  height: 0;
}

/* The slider */
.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ccc;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 55px;
  width: 55px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2196F3;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}


input:checked + .slider:before {
  -webkit-transform: translateX(50px);
  -ms-transform: translateX(50px);
  transform: translateX(50px);
}

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;
}

table.table2 td {
 background-color: #128F76;
 border: 1px solid black;
}


)=====" ;
