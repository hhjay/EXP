<!--
var menuOffX = 0	
var menuOffY = 18	
var fo_shadows = new Array()
//var linkset = new Array()

////No need to edit beyond here

var menuIE4 = document.all&&navigator.userAgent.indexOf("Opera")==-1 
var ie55up = IsIE55Up();
var menuNS6 = document.getElementById&&!document.all 
var menuNS4 = document.layers 
var overIframe = null;
//var jsdone = false;	
var pnum=1;
var menuObj;
var Ind;
var WLeft;
var WRight;
var currMenuGroup = 0;
var menus = new Array();
var subMenuGroups = new Array();
var subMenus = null;
var overIframes = new Array(5);

function setgroups(menuname){
	var i = 0;
	for(; i < menus.length; i++){
		if(menuname == menus[i]){
			currMenuGroup = i; 
			break;
		}
	}
	
	if(i == menus.length){
		menus[menus.length] = menuname;
		currMenuGroup = i;
	}

	if(!subMenuGroups[currMenuGroup]){
		subMenuGroups[currMenuGroup] =  new Array(4);
	}

	subMenus = subMenuGroups[currMenuGroup];
}

function showmenu(e,index,p,paging,derection,popmenu,aName,isShadow)
{       
	setgroups(popmenu);
	obj = menuIE4 ? event.srcElement : e.target;
	hideallmenu();
	menuObj=document.getElementById(""+popmenu+"");
	menuObj.style.width = '';
	
	if (!eval("window.menuReady_"+popmenu))
		return false;
	
	if (!document.all && !document.getElementById && !document.layers)
		return;

	which = aName[index];
	clearhidemenu();
	if (ie55up)
		ie_clearshadow();
		if(which == null || which == ""){DivOutSel(menuObj);return;}
		which = which.join("");

	
	menuObj = document.getElementById(""+popmenu+"");
	menuObj.thestyle=(menuIE4||menuNS6)? menuObj.style : menuObj;
	
	if (menuIE4 || menuNS6)
		menuObj.innerHTML = which;
	else
	{
		menuObj.document.write("<layer name=\"gui\" bgColor=\"#E6E6E6\" width=\"165\" onmouseover=\"clearhidemenu()\" onmouseout=\"hidemenu()\">" + which + "</layer>");
		menuObj.document.close();
	}
	
	
	
	menuObj.contentwidth = (menuIE4 || menuNS6) ? menuObj.offsetWidth : menuObj.document.gui.document.width;
	menuObj.contentheight = (menuIE4 || menuNS6) ? menuObj.offsetHeight : menuObj.document.gui.document.height;
	
	eventX = menuIE4 ?e.offsetLeft : menuNS6 ? e.clientX : e.x;
	eventY = menuIE4 ?e.offsetTop : menuNS6 ? e.clientY : e.y;
	
   if(which!=Ind)
	  {
	    WLeft=e.clientX;
	    WRight=e.clientY;
	    Ind=which;
	    
	  }
	
	var rightContent;
	var upContent;

	switch(derection)
	{
	  case 1:  
	     rightContent=(-1)*(menuObj.contentwidth);
	     upContent=(1)*(menuObj.contentheight);
	     break;
	     
	   case 2:  
	     rightContent=0;
	     upContent=(1)*(menuObj.contentheight);
	     break;
	     
	    case 3: 
	     rightContent=obj.offsetWidth;
	     upContent=(1)*(menuObj.contentheight);
	     break;
	     
	   case 4:  
	     rightContent=obj.offsetWidth;
	     upContent=(0)*(menuObj.contentheight);
	     break;
	     
	   case 5: 
	     rightContent=obj.offsetWidth;
	     upContent=(0)*(menuObj.contentheight)-22;
	     break;
	     
	    case 6: 
	      rightContent=0;
	      upContent=(0)*(menuObj.contentheight)-22;
	      break;
	      
	    case 7: 
	      rightContent=(-1)*(menuObj.contentwidth);
	      upContent=(0)*(menuObj.contentheight)-22;
	      break;
	      
	    case 8:  
	      rightContent=(-1)*(menuObj.contentwidth);
	      upContent=(0)*(menuObj.contentheight);
	      break;
	}

	if (!paging)
	{	
		menuObj.thestyle.left = menuIE4? ie_x(event.srcElement)  +rightContent : menuNS6 ? ie_x(obj) + rightContent + "px" : eventXX;
		menuObj.thestyle.top = menuIE4 ? ie_y(event.srcElement) - upContent : menuNS6 ? ie_y(obj) - upContent + "px" : eventYY;
	}

	if(menuObj.contentwidth < 100){
		menuObj.thestyle.width = "100px";
	}

	menuObj.thestyle.visibility = "visible";
	menuObj.level = 0;

	if (ie55up)
		ie_dropshadow(menuObj,"#999999",isShadow);
	DivOverSel(menuObj);
	return false;
}

function showSubMenu(e, menuDivId, aName, index){
	var subMenuObj = document.getElementById(menuDivId);
	var hrefObj = menuIE4 ? event.srcElement : e.target;

	if(subMenuObj.level){
		for(var i = subMenuObj.level - 1; i < subMenus.length; i++){
			var obj = subMenus[i];
			if (obj){
				hidemenu(obj);
			}else{
				break;
			}
		}
	}

	if(!aName) return;

	which = aName[index];
	if(which == null || which == ""){return;}
	which = which.join("");

	if (menuIE4 || menuNS6)
	subMenuObj.innerHTML = which;

	subMenuObj.thestyle=(menuIE4||menuNS6)? subMenuObj.style : subMenuObj;
	
	var newMenuRight = ie_x(hrefObj) + hrefObj.offsetWidth + subMenuObj.offsetWidth;
	if(newMenuRight < document.body.clientWidth){
		subMenuObj.thestyle.left = ie_x(hrefObj) + hrefObj.offsetWidth;
	}else{
		subMenuObj.thestyle.left = ie_x(hrefObj) -  subMenuObj.offsetWidth;
	}
	subMenuObj.thestyle.top = ie_y(hrefObj);
	subMenuObj.thestyle.visibility = "visible";

	if(!subMenuObj.level){
		for (var i = 0; i < subMenus.length; i++)
		{
			if(!subMenus[i]){
				subMenuObj.level = i + 1;
				subMenus[i] = subMenuObj;
				break;
			}
		}
	}
	/*if(!subMenus[topLevel]){
		subMenuObj.level = topLevel + 1;
		subMenus[topLevel] = subMenuObj;
		topLevel++;
	}*/
	
	DivOverSel(subMenuObj);
}

function ie_y(e)
{  
	var t = e.offsetTop;  
	while(e = e.offsetParent)
	{  
		t += e.offsetTop;  
	}  
	return t;  
}  
function ie_x(e)
{  
	var l = e.offsetLeft;  
	while(e = e.offsetParent)
	{  
		l += e.offsetLeft;  
	}  
	return l;  
}  
function ie_dropshadow(el, color, size)
{
	var i;
	for (i = size; i > 0; i--)
	{
		var rect = document.createElement('div');
		var rs = rect.style
		rs.position = 'absolute';
		rs.left = (el.style.posLeft + i) + 'px';
		rs.top = (el.style.posTop + i) + 'px';
		rs.width = el.offsetWidth + 'px';
		rs.height = el.offsetHeight + 'px';
		rs.zIndex = el.style.zIndex - i;
		rs.backgroundColor = color;
		var opacity = 1 - i / (i + 1);
		rs.filter = 'alpha(opacity=' + (100 * opacity) + ')';
		el.insertAdjacentElement('afterEnd', rect);
		fo_shadows[fo_shadows.length] = rect;
	}
}
function ie_clearshadow()
{
	for(var i = 0; i < fo_shadows.length; i++)
	{
		if (fo_shadows[i])
			fo_shadows[i].style.display = "none"
	}
	fo_shadows = new Array();
}


function contains_menuNS6(a, b)
{
	if (b)
	{
		while (b.parentNode)
			if ((b = b.parentNode) == a)
				return true;
	}
	return false;
}

function hidemenu(oMenu)
{
	if (oMenu){
		if(oMenu.thestyle  && (oMenu.thestyle.visibility !=  "hidden" || oMenu.thestyle.visibility != "hide"))
			oMenu.thestyle.visibility = (menuIE4 || menuNS6) ? "hidden" : "hide";
		DivOutSel(oMenu);
	}
	ie_clearshadow();
}

function hideallmenu()
{
	hidemenu(menuObj);
	if(subMenus != null){
	hideallsubmenu(1);
	}
}

function hideallsubmenu(index){
	for(var i = index  - 1; i < subMenus.length; i++){
		var obj = subMenus[i];
		if (obj){
			hidemenu(obj);
		}else{
			break;
		}
	}
}

function hideSubMenu(){
	var divObj = currentMenuObj;
	var subMenuLevel = divObj.level + 1;

	for(var i = subMenuLevel; i < subMenus.length; i++){
		var obj = subMenus[i];
		if (obj){
			hidemenu(obj);
		}else{
			break;
		}
	}
}

function delayhidemenu()
{
  
	if (menuIE4 || menuNS6 || menuNS4)
		delayhide = setTimeout(hideallmenu,400);
}

function clearhidemenu()
{

	if (window.delayhide)
		clearTimeout(delayhide)
		
}

/*function delaydynamichide()
{
	if (menuIE4 || menuNS6 || menuNS4)
		delayhidemenu = setTimeout(hideallmenu,400);
}

function cleardynamichide(){
	clearhidemenu();
	if (window.delayhidemenu)
		clearTimeout(delayhidemenu);
}*/

function dynamichide(e, oMenuDivId)
{
	var oMenuDiv = document.getElementById(oMenuDivId);
	if (menuIE4&&!oMenuDiv.contains(e.toElement)){
		delayhidemenu();//delaydynamichide();
	}else if (menuNS6 && e.currentTarget != e.relatedTarget && !contains_menuNS6(e.currentTarget, e.relatedTarget)){
		delayhidemenu();//delaydynamichide();
	}
}

function highlightmenu(e,state,popmenu,num)
{
   
   
	if (document.all)
		source_el = event.srcElement
	else if (document.getElementById)
		source_el = e.target
	if (source_el.className == "menuitems"+num)
	{
		source_el.id=(state == "on") ? "mouseoverstyle"+num : ""
	}
	else
	{
		while(source_el.id != ""+popmenu+"")
		{
			source_el = document.getElementById ? source_el.parentNode : source_el.parentElement
			if (source_el.className == "menuitems"+num)
			{
				source_el.id = (state == "on") ? "mouseoverstyle"+num : ""
			}
		}
	}
}

function DivOverSel(obj)
{
	var overIframe = overIframes[obj.level];
	var objW = obj.offsetWidth;
	if (ie55up)
	{
		if (!overIframe)
		{
			overIframe = document.createElement("<iframe src='about:blank' style='position:absolute;left:0;top:0;z-index:998;display:none' scrolling='no' frameborder='0' allowtransparency='true'></iframe>");
			overIframes[obj.level] = overIframe;
		}
		document.body.insertAdjacentElement("beforeEnd",overIframe);
		overIframe.contentWindow.document.write("<body style='BACKGROUND-COLOR:transparent'><table width='100%' height='100%' style='z-index:998;'><tr><td>&nbsp;</td></tr></table></body>");
		with(overIframe.style)
		{
			top = obj.style.top;
			left = obj.style.left;
			width = objW;
			height = obj.offsetHeight;
			overIframe.style.visibility = 'visible';
			display = 'block';
		}obj.style.width = objW;
		obj.style.zIndex = "999";
	}
}

function DivOutSel(obj)
{
	if (ie55up)
	{
		var overIframe = overIframes[obj.level];
		if (overIframe)
		{
			overIframe.style.visibility = 'hidden';
		}
	}
}


function IsIE55Up ()
{
	var agt = navigator.userAgent.toLowerCase();
	var isIE = (agt.indexOf("msie") != -1);
	if (isIE)
	{
		var stIEVer = agt.substring(agt.indexOf("msie ") + 5);
		var verIEFull = parseFloat(stIEVer);
		return verIEFull >= 5.5;
	}
	return false;
}

if (menuIE4 || menuNS6) document.onclick = hideallmenu;
// -->