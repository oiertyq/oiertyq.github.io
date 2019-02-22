
window.onload = function () {
  var current = 0;
  document.getElementById('xz').onclick = function () {
    current = (current + 90) % 360;
    this.style.transform = 'rotate(' + current + 'deg)';
    alert("恭喜发现彩蛋！！！")
  }
};

function detectBrowser() {
  var browser = navigator.appName
  var b_version = navigator.appVersion
  var version = parseFloat(b_version)
  if ((browser == "Netscape" || browser == "Microsoft Internet Explorer") && (version >= 4)) {
    return 0;
  } else {
    window.location.href = "IE.html";
  }
}

