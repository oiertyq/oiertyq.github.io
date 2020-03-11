function orzyyb() {
    document.getElementById("mainarea").innerHTML="\
<span style="\"font-size:" 48px;color: #ff0000\">wyxkk是我们的红太阳，没有他我们会死！</span>\
<p></p>\
<div id="\"orz\"" align="\"center\""><p align="\"center\"">\
<button style="\"font-size:" 30px; color: #ff0000\" onclick="\"orzorz()\"">\
点击膜拜\
</button>\
</p></div>\
";
}
function orzorz() {
    document.getElementById("orz").innerHTML="\
<p style="\"margin:10px\"">\
<span style="\"font-size:" 40px; color: #ff0000\">\
膜拜成功！\
<br>\
wyxkk又变强了！\
</span>\
</p>\
<br>\
<button style="\"font-size:" 24px\" onclick="\"ORZINF()\"" id="\"orzbutton\"">继续膜拜1次</button>\
<div style="\"font-size:" 50px;background:rgba(255,255,255,0.7);width:auto\" id="\"orzTimes\""></div>\
<div style="\"font-size:" 40px;color:red\" id="\"yybsays\""></div>\
<div style="\"font-size:" 20px;height:30px\" id="\"yybsays2\""></div>\
";
    document.title="orz wyxkk!";
}
var orzCount=0,orzDelta=1,says2_restTime=0;
var sayslist=new Array("你个菜逼我今天AK了","NOI怎么这么水啊，这不是用来随手AK的吗","你怎么还在乱膜啊？？？你快吸掉我RP的0.000000001‰了","今天考试又是三个傻逼题，我不仅AK了还把2048玩到了2^1000000","怎么我出的题全场爆零啊，我以为会有人负分的啊","你们还是naive，我怎么可能不AK？","今天题真的水，你们不AK的都退役吧");
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
    }
    if(orzCount>=10000) {
        document.getElementById("mainarea").innerHTML="<h1 style="\"color:red\"" align="\"center\"">wyxkk:你这个辣鸡，怎么天天膜我？<br>我还要去THU吊打集训队，还要去MIT秒题<br>（wyxkk说着走起了路准备离开）</h1><br><br><div id="\"walkyyb\"" align="\"center\""></div><br><button style="\"font-size:" 24px\" onclick="\"last_orz()\"" id="\"lastorz\"">继续膜拜...</button>";
    }
}

function last_orz() {
    document.getElementById("mainarea").innerHTML="<h1 style="\"color:red\"">wyxkk:你怎么回事小老弟？？？<br>你被wyxkk秒了<br><br>被秒乃蒟蒻常事<br>请蒟蒻重新来过！<br></h1>";
}
