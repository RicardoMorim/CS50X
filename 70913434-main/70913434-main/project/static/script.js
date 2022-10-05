//Functions to do the zooms
function zoomin() {
  var myImg = document.getElementById("output");
  var currWidth = myImg.clientWidth;
  if (currWidth == 500) {
    alert("Maximum zoom-in level reached.");
  } else {
    myImg.style.width = currWidth + 50 + "px";
  }
}
function zoomout() {
  var myImg = document.getElementById("output");
  var currWidth = myImg.clientWidth;
  if (currWidth == 50) {
    alert("Maximum zoom-out level reached.");
  } else {
    myImg.style.width = currWidth - 50 + "px";
  }
}

//values of each filter
let brightness = 100;
let contrast = 100;
let saturate = 100;
let grayscale = 0;
let invert = 0;
let huerotate = 0;
let blur = 0;
let opacity = 100;
let sepia = 0;
let dropshadow = 0;

//get the image and the reset buttom elements
const imgture = document.getElementById("output");
const resetAll = document.getElementById("resetAll");

//get the element of all sliders and values
const slider1 = document.getElementById("slider1");
const value1 = document.getElementById("bright");
const slider2 = document.getElementById("slider2");
const value2 = document.getElementById("contrast");
const slider3 = document.getElementById("slider3");
const value3 = document.getElementById("saturate");
const slider4 = document.getElementById("slider4");
const value4 = document.getElementById("gray");
const slider5 = document.getElementById("slider5");
const value5 = document.getElementById("invert");
const slider6 = document.getElementById("slider6");
const value6 = document.getElementById("hue");
const slider7 = document.getElementById("slider7");
const value7 = document.getElementById("blur");
const slider8 = document.getElementById("slider8");
const value8 = document.getElementById("opacity");
const slider9 = document.getElementById("slider9");
const value9 = document.getElementById("sepia");

//Update filters
function updateFilters() {
  imgture.style.filter =
    "brightness(" +
    brightness +
    "%) contrast(" +
    contrast +
    "%) saturate(" +
    saturate +
    "%) grayscale(" +
    grayscale +
    "%) invert(" +
    invert +
    "%) hue-rotate(" +
    huerotate +
    "deg) blur(" +
    blur +
    "px) opacity(" +
    opacity +
    "%) sepia(" +
    sepia +
    "%)";
}
//Reset All
resetAll.addEventListener("click", function () {
  console.log("resset");
  brightness = 100;
  slider1.value = 100;
  value1.innerHTML = slider1.value + "%";
  contrast = 100;
  slider2.value = 100;
  value2.innerHTML = slider2.value + "%";
  saturate = 100;
  slider3.value = 100;
  value3.innerHTML = slider3.value + "%";
  grayscale = 0;
  slider4.value = 0;
  value4.innerHTML = slider4.value + "%";
  invert = 0;
  slider5.value = 0;
  value5.innerHTML = slider5.value + "%";
  huerotate = 0;
  slider6.value = 0;
  value6.innerHTML = slider6.value + "px";
  blur = 0;
  slider7.value = 0;
  value7.innerHTML = slider7.value + "°";
  opacity = 100;
  slider8.value = 0;
  value8.innerHTML = 100 - slider8.value + "%";
  sepia = 0;
  slider9.value = 0;
  value9.innerHTML = slider9.value + "%";
  updateFilters();
});

//Brightness slider
slider1.addEventListener("input", function () {
  console.log(slider1.value);
  value1.innerHTML = slider1.value + "%";
  brightness = slider1.value;
  updateFilters();
});

slider1.addEventListener("focus", function () {
  console.log("focus gotten");
  value1.style.visibility = "visible";
});

slider1.addEventListener("blur", function () {
  console.log("focus lost");
  value1.style.visibility = "hidden";
});

//Contrast slider
slider2.addEventListener("input", function () {
  value2.innerHTML = slider2.value + "%";
  contrast = slider2.value;
  updateFilters();
});

slider2.addEventListener("focus", function () {
  value2.style.visibility = "visible";
});

slider2.addEventListener("blur", function () {
  value2.style.visibility = "hidden";
});

//Saturation slider
slider3.addEventListener("input", function () {
  value3.innerHTML = slider3.value + "%";
  saturate = slider3.value;
  updateFilters();
});

slider3.addEventListener("focus", function () {
  value3.style.visibility = "visible";
});

slider3.addEventListener("blur", function () {
  value3.style.visibility = "hidden";
});

//Grayscale slider
slider4.addEventListener("input", function () {
  value4.innerHTML = slider4.value + "%";
  grayscale = slider4.value;
  updateFilters();
});

slider4.addEventListener("focus", function () {
  value4.style.visibility = "visible";
});

slider4.addEventListener("blur", function () {
  value4.style.visibility = "hidden";
});

//Invert slider
slider5.addEventListener("input", function () {
  value5.innerHTML = slider5.value + "%";
  invert = slider5.value;
  updateFilters();
});

slider5.addEventListener("focus", function () {
  value5.style.visibility = "visible";
});

slider5.addEventListener("blur", function () {
  value5.style.visibility = "hidden";
});

//Hue-rotate slider
slider6.addEventListener("input", function () {
  value6.innerHTML = slider6.value + "°";
  huerotate = slider6.value;
  updateFilters();
});

slider6.addEventListener("focus", function () {
  value6.style.visibility = "visible";
});

slider6.addEventListener("blur", function () {
  value6.style.visibility = "hidden";
});

//Blur slider
slider7.addEventListener("input", function () {
  value7.innerHTML = slider7.value + "px";
  blur = slider7.value;
  updateFilters();
});

slider7.addEventListener("focus", function () {
  value7.style.visibility = "visible";
});

slider7.addEventListener("blur", function () {
  value7.style.visibility = "hidden";
});

//Opacity slider
slider8.addEventListener("input", function () {
  value8.innerHTML = 100 - slider8.value + "%";
  opacity = 100 - slider8.value;
  updateFilters();
});

slider8.addEventListener("focus", function () {
  value8.style.visibility = "visible";
});

slider8.addEventListener("blur", function () {
  value8.style.visibility = "hidden";
});

//Sepia slider
slider9.addEventListener("input", function () {
  value9.innerHTML = slider9.value + "%";
  sepia = slider9.value;
  updateFilters();
});

slider9.addEventListener("focus", function () {
  value9.style.visibility = "visible";
});

slider9.addEventListener("blur", function () {
  value9.style.visibility = "hidden";
});
