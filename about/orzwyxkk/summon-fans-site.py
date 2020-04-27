# This is an program write in python. You can run this program to summon a fans site for somebody.
# Usage
# Replace name, copyright, pictures1, pictures2, ..., pictures7 to what you want.
# Then run it. If you are using hexo blog, just put it in source/about then run it and run "hexo g" and "hexo d" in order.
# Remember: You should put some pictures (might be something he said) named 1.png, 2.png, ... 7.png in folder that created by this program, or no pictures will be shown.
# If you don't want to use pictures, just replace pictures1, pictures2, ..., pictures7 to "<p>" + some sentences + "</p>" (like "<p> wyxkk ak ioi </p>").

# settings
name = r"""connect"""
pictures1 = r"""<img src=\"1.png\">"""
pictures2 = r"""<img src=\"2.png\">"""
pictures3 = r"""<img src=\"3.png\">"""
pictures4 = r"""<img src=\"4.png\">"""
pictures5 = r"""<img src=\"5.png\">"""
pictures6 = r"""<img src=\"6.png\">"""
pictures7 = r"""<img src=\"7.png\">"""
copyright = r"""tyqtyq"""

# say hello

print("Welcome to use this program by tyqtyq.");
print("Want to see more options? you can use editors to open this file.");

# print usage in the screen

print("Please input the name of the person that you want to summon fans site for:");
name = input();
print("Start summon fans site.");

# templates
import os
str = r"""<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link type="text/css" rel="stylesheet" href="./main.css">
	<title>wyxkk粉丝站点 </title>
	<style type="text/css"></style>
	<script text="text/javascript">
	function orzyyb() {
			document.getElementById("mainarea").innerHTML="\
	<span style=\"font-size: 48px;color: #FF0000\">wyxkk是我们的红太阳，没有他我们会死！</span>\
	</p>\
	<div id=\"orz\" align=\"center\"><p align=\"center\">\
	<button style=\"font-size: 30px; color: #FF0000\" onclick=\"orzorz()\">\
	点击膜拜\
	</button>\
	</div>\
	";
	}
	function orzorz() {
			document.getElementById("orz").innerHTML="\
	<p style=\"margin:10px\">\
	<span style=\"font-size: 40px; color: #FF0000\">\
	膜拜成功！\
	<br>\
	wyxkk又变强了！\
	</span>\
	</p>\
	<br>\
	<button style=\"font-size: 24px\" onclick=\"ORZINF()\" id=\"orzbutton\">继续膜拜1次</button>\
	<div style=\"font-size: 50px;background:rgba(255,255,255,0.7);width:auto\" id=\"orzTimes\"></div>\
	<div style=\"font-size: 40px;color:red\" id=\"yybsays\"></div>\
	<div style=\"font-size: 20px;height:30px\" id=\"yybsays2\"></div>\
	";
			document.title="orz wyxkk!";
	}
	var orzCount=0,orzDelta=1,says2_restTime=0;
	var sayslist=new Array("<img src=\"1.png\">","<img src=\"2.png\">","<img src=\"3.png\">","<img src=\"4.png\">","<img src=\"5.png\">","<img src=\"6.png\">","<img src=\"7.png\">");
	function ORZINF() {
		var says2_restTime_Default=50;
			orzCount+=orzDelta;
			document.getElementById("orzTimes").innerHTML='Orzwyxkk!*'+orzCount;
			//document.getElementById("yybsays").innerHTML='YYB：'+sayslist[Math.floor(Math.random()*sayslist.length)];
			--says2_restTime;
			if(says2_restTime==0)document.getElementById("yybsays2").innerHTML="";
			if(orzCount==1)document.getElementById("yybsays2").innerHTML='wyxkk：诶又有一个来膜拜我的，来吧来吧继续膜',says2_restTime=says2_restTime_Default;
			if(orzCount==2)document.getElementById("yybsays2").innerHTML='wyxkk：你们还是naive，我又AK了',says2_restTime=says2_restTime_Default;
			if(orzCount==10)document.getElementById("yybsays2").innerHTML='wyxkk：虽然我是大佬，但是你这样一直膜我是会掉RP的',says2_restTime=says2_restTime_Default;
			if(orzCount==20)document.getElementById("yybsays2").innerHTML='wyxkk：MDZZ你怎么还在膜信不信我把你从5楼扔下去',says2_restTime=says2_restTime_Default;
			if(orzCount==50)document.getElementById("yybsays2").innerHTML='wyxkk：没错我就是这么强，让你好好膜',says2_restTime=says2_restTime_Default;
			if(orzCount==50)orzDelta=5,document.getElementById("orzbutton").innerHTML="继续膜拜"+orzDelta+"次";
			if(orzCount==1000)document.getElementById("yybsays2").innerHTML='wyxkk：你真棒，我感受到了我又变强了，让你一次多膜一点',says2_restTime=says2_restTime_Default;
			if(orzCount>=1000) {
					orzDelta=Math.floor(Math.random()*100+5);
					document.getElementById("orzbutton").innerHTML="继续膜拜"+orzDelta+"次";
					document.getElementById("yybsays2").innerHTML="wyxkk："+sayslist[(Math.floor(Math.random()*19260817))%7];
			}
			if(orzCount>=10000) {
					document.getElementById("mainarea").innerHTML="<h1 style=\"color:red\" align=\"center\">wyxkk:你这个辣鸡，怎么天天膜我？<br>我还要去THU吊打集训队，还要去MIT秒题<br>（wyxkk说着走起了路准备离开）</h1><br><br><div id=\"walkyyb\" align=\"center\"></div><br><button style=\"font-size: 24px\" onclick=\"last_orz()\" id=\"lastorz\">继续膜拜...</button>";
			}
	}
	function last_orz() {
			document.getElementById("mainarea").innerHTML="<h1 style=\"color:red\">wyxkk:你怎么回事小老弟？？？<br>你被wyxkk秒了<br><br>被秒乃蒟蒻常事<br>请蒟蒻重新来过！<br></h1> <a onclick=\"tbc()\"><img src=\"https://dss1.bdstatic.com/70cFuXSh_Q1YnxGkpoWK1HF6hhy/it/u=509235117,300471380&fm=111&gp=0.jpg\"></a>";
	}
	</script>
	<script text="text/javascript">
		function load() {
			document.getElementById("mainarea").innerHTML="<button style=\"font-size: 24px\" onclick=\"orzyyb()\">点击免费膜wyxkk</button>";
		}
		function tbc() {
			location.reload();
		}
	</script>
</head>
<body>
	<div id="mainarea" align="center" style="margin-top:150px;">
		<h1 style="color:red">Do you want to Orzwyxkk?</h1>
		<button style="font-size: 24px" onclick="load()">Yes!</button>
	</div>
	<div style="background:rgba(255,255,255,0.7);text-align:center; font-family: 黑体;font-weight: bold;margin-top:100px">
		Copyright © tyqtyq 2019<br>
		转载(魔改)自 https://yyb.akioi.cn<br>
		<div id="about"></div>
		<br>
	</div>
</body>
</html>
"""

# replace

str = str.replace(r"wyxkk", name); str = str.replace(r"""<img src=\"1.png\">""", pictures1); str = str.replace(r"""<img src=\"2.png\">""", pictures2); str = str.replace(r"""<img src=\"3.png\">""", pictures3); str = str.replace(r"""<img src=\"4.png\">""", pictures4); str = str.replace(r"""<img src=\"5.png\">""", pictures5); str = str.replace(r"""<img src=\"6.png\">""", pictures6); str = str.replace(r"""<img src=\"7.png\">""", pictures7); str = str.replace(r"tyqtyq", copyright);
os.mkdir("orz"+name); f=open("orz"+name+"/index.html", 'w', encoding='utf-8'); f.write(str); f.close();
print("Finished. The fans site is in the file floder named orz"+name+"."); print("Press any key to continue."); input();
