const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
 <head>
 <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
 <meta charset='utf-8'>
 
<style>

.base-grid{
  display: grid;
  grid-template-columns: auto auto;
  grid-template-rows: auto auto;
}

.grid-container {
  display: grid;
  grid-gap: 10px 10px;
  grid-template-columns: auto auto auto;
  background-color: #FFFFFF;
  padding: 10px;
}

.grid-item {
  background-color: rgba(255, 255, 255, 255);
  font-size: 30px;
  text-align: center;
}
.grid-item2 {
  background-color: rgba(255, 255, 255, 255);
  text-align: left;
 }

.button {
    background-color: #efefef; /* Gray */
    border: 2px solid black;
	border-radius: 8px;
    color: black;
    padding: 10px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 30px;
    margin: 4px 2px;
    cursor: pointer;
}
.panicbutton {
    background-color: #ff0000; /* RED */
    border: 2px solid black;
	border-radius: 8px;
    color: white;
    padding: 10px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 30px;
    margin: 4px 2px;
    cursor: pointer;
}
.hellobutton {
    background-color: #00ff00; /* GREEN */
    border: 2px solid black;
	border-radius: 8px;
    color: black;
    padding: 10px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 30px;
    margin: 4px 2px;
    cursor: pointer;
}
.switch {
  position: relative;
  display: inline-block;
  width: 60px;
  height: 34px;
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
  border: 2px solid black;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #00ff00;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(26px);
  -ms-transform: translateX(26px);
  transform: translateX(26px);
}

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;
}

</style>

<script>
function upClick(){
	ajaxLoad('UP');
}

function leftClick(){
	ajaxLoad('LEFT');
}
	
function rightClick(){
	ajaxLoad('RIGHT');
}

function downClick(){
	ajaxLoad('DOWN');
}

function stopClick(){
	ajaxLoad('STOP');
}

function helloClick(){
	ajaxLoad('HELLO');
}
function hello2Click(){
	ajaxLoad('WAVE');
}
function continueClick(){
	ajaxLoad('CONT');
}
function fastClick(){
	ajaxLoad('FAST');
}

var ajaxRequest = null;
if (window.XMLHttpRequest)  { ajaxRequest =new XMLHttpRequest(); }
else                        { ajaxRequest =new ActiveXObject("Microsoft.XMLHTTP"); }

function ajaxLoad(ajaxURL)
{
  if(!ajaxRequest){ alert("AJAX is not supported."); return; }
  
  ajaxRequest.open("GET",ajaxURL,true);
  ajaxRequest.onreadystatechange = function()
  {
    if(ajaxRequest.readyState == 4 && ajaxRequest.status==200)
    {
      var ajaxResult = ajaxRequest.responseText;
      document.getElementById("reply").innerHTML = ajaxResult;
    }
  }
  ajaxRequest.send();
}
</script>

<title>Fall 2018 ECE Capstone</title>
</head>

<body>
<div class="grid">
<div class="grid-item2"><b>Continuous Mode</b></div>
<div> <label class="switch">
		<input type="checkbox">
		<span class="slider round" onclick ="continueClick()"></span>
	</label>
</div>
<div class="grid-item2"><b>Fast Mode</b></div>
<div> <label class="switch">
		<input type="checkbox">
		<span class="slider round" onclick ="fastClick()"></span>
	</label>
</div>

</div>


<!--
<b>Continuous Mode</b>
<label class="switch">
  <input type="checkbox">
  <span class="slider round" onclick ="continueClick()"></span>
</label>
<b>Fast Mode</b>
<label class="switch">
  <input type="checkbox">
  <span class="slider round" onclick ="fastClick()"></span>
</label>
-->

<div class="grid-container">
  <div class="grid-item"></div>
  <div class="button" onmousedown ="upClick()">&uarr;</div>
  <div class="grid-item"></div>  
  <div class="button" onmousedown ="leftClick()">&larr;</div>
  <div class="panicbutton" onmousedown="stopClick()">Stop</div>
  <div class="button" onmousedown ="rightClick()">&rarr;</div>  
  <div class="grid-item"></div>
  <div class="button" onmousedown ="downClick()">&darr;</div>
  <div class="grid-item"></div>  
</div>

<div class="hellobutton" onmousedown = "helloClick()"> Wave 1</div>
<div class="hellobutton" onmousedown = "hello2Click()"> Wave 2</div>
<!-- Uncomment if you need to test each leg
<div class="button" onmousedown = "LFClick()"> LF </div>
<div class="button" onmousedown = "LMClick()"> LM </div>
<div class="button" onmousedown = "LBClick()"> LB </div>
<div class="button" onmousedown = "RFClick()"> RF </div>
<div class="button" onmousedown = "RMClick()"> RM </div>
<div class="button" onmousedown = "RBClick()"> RB </div>
-->
<p> Last Command Sent </p> 
<p id="reply"> Reply Here</p>
</body>
</html>

)=====";
