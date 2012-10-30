/*
ninguno seleccionado = 0
estatuto = 1
variable = 2
if = 3
operacion = 4
for = 5
while = 6
*/

var elem_selec=0;

function click_estatuto(){  
  elem_selec=1;
  console.log(elem_selec);
  console.log("estatuto");
}  

function click_var(){  
  elem_selec=2;
  console.log(elem_selec);
  console.log("variable");
}  

function click_if(){  
  elem_selec=3;
  console.log(elem_selec);
  console.log("if");
}

function click_op(){  
  elem_selec=4;
  console.log(elem_selec);
  console.log("operacion");
}

function click_for(){  
  elem_selec=5;
  console.log(elem_selec);
  console.log("for");
}

function click_while(){  
  elem_selec=6;
  console.log(elem_selec);
  console.log("while");
}

function agregar_estatuto(elemento, tipo) {
    var x;
	var est_text=prompt("Agrega estatuto","Ejem: Fin");
	
	if (est_text!="" && tipo!="end" && tipo!="mid"){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="estatuto"> <span>' + est_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
	}
	else if(tipo=="mid"){
		alert("No puedes agregar un estatuto aqui");
	}
	else if(tipo=="end"){
		x='<div class="elemento" onclick="agregar_elem(this)"><div class="estatuto"> <span>' + est_text + '</span></div><div class="conector"></div></div>';
		$(elemento).parent().after(x);  
	}
	else{
		alert("No declaraste un estatuto");
	}
}

function agregar_variable(elemento, tipo) {
	var x;
	var var_text=prompt("Agrega tipo, nombre y valor de la variable","Ejem: int x = 3");
	
	if (var_text!="" && tipo!="end" && tipo!="mid"){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="variable"> <span>' + var_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
	}
	else if(tipo=="mid"){
		x='<div class="elemento" onclick="agregar_elem(this, \'mid\')"><div class="variable"> <span>' + var_text + '</span></div><div class="conector"></div></div>';
		$(elemento).after(x);
		$(elemento).siblings(".conector2").height($(elemento).siblings(".conector2").height() + 70);
		$(elemento).siblings(".conector2").css('margin-top', function (index, curValue) {
			return parseInt(curValue, 10) - 70 + 'px';
		});
	}
	else if(tipo=="end"){
		x='<div class="elemento" onclick="agregar_elem(this)"><div class="variable"> <span>' + var_text + '</span></div><div class="conector"></div></div>';
		$(elemento).parent().after(x);  
	}
	else{
		alert("No declaraste una variable");
	}
}

function agregar_if(elemento, tipo) {
	var x;
	var if_text=prompt("Agrega condicion","Ejem: x > y");
	
	if (if_text!="" && tipo!="end" && tipo!="mid"){
	  x='<div class="elemento"><div class="elemento" onclick="agregar_elem(this, \'mid\')"> <div class="if"><span>' + if_text + '</span></div><div class="conector"></div></div><div class="endif" onclick="agregar_elem(this, \'end\')">End if</div><div class="conector2"></div><div class="conector"></div></div>';
	  $(elemento).after(x);
	}
	else if(tipo=="mid"){
		alert("No se pueden anidar ciclos");
	}
	else if(tipo=="end"){
	  	x='<div class="elemento"><div class="elemento" onclick="agregar_elem(this, \'mid\')"> <div class="if"><span>' + if_text + '</span></div><div class="conector"></div></div><div class="endif" onclick="agregar_elem(this, \'end\')">End if</div><div class="conector2"></div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un if");
	}
}

function agregar_operacion(elemento, tipo) {
    var x;
	var op_text=prompt("Agrega operacion","Ejem: x = x + 1");
	
	if (op_text!="" && tipo!="end" && tipo!="mid"){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="operacion"> <span>' + op_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);    
	}
	else if(tipo=="mid"){
		x='<div class="elemento" onclick="agregar_elem(this, \'mid\')"><div class="operacion"> <span>' + op_text + '</span></div><div class="conector"></div></div>';
		$(elemento).after(x);
		$(elemento).siblings(".conector2").height($(elemento).siblings(".conector2").height() + 70);
		$(elemento).siblings(".conector2").css('margin-top', function (index, curValue) {
			return parseInt(curValue, 10) - 70 + 'px';
		});  
	}
	else if(tipo=="end"){
		x='<div class="elemento" onclick="agregar_elem(this)"><div class="operacion"> <span>' + op_text + '</span></div><div class="conector"></div></div>';
		$(elemento).parent().after(x);  
	}
	else{
		alert("No declaraste una operacion");
	}
}

function agregar_for(elemento, tipo) {
    var x;
	var for_text=prompt("Agrega for","Ejem: i = 0; i < 10; i++");
	
	if (for_text!="" && tipo!="end" && tipo!="mid"){
	  x='<div class="elemento"><div class="elemento" onclick="agregar_elem(this, \'mid\')"> <div class="for"><span>' + for_text + '</span></div><div class="conector"></div></div><div class="endfor" onclick="agregar_elem(this, \'end\')">End For</div><div class="conector2"></div><div class="conector"></div></div>';
	  $(elemento).after(x);
	}
	else if(tipo=="mid"){
		alert("No se pueden anidar ciclos");
	}
	else if(tipo=="end"){
	  x='<div class="elemento"><div class="elemento" onclick="agregar_elem(this, \'mid\')"> <div class="for"><span>' + for_text + '</span></div><div class="conector"></div></div><div class="endfor" onclick="agregar_elem(this, \'end\')">End For</div><div class="conector2"></div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un for");
	}
}

function agregar_while(elemento, tipo) {
    var x;
	var while_text=prompt("Agrega while","Ejem: x < 10");
	
	if (while_text!="" && tipo!="end" && tipo!="mid"){
	  x='<div class="elemento"><div class="elemento" onclick="agregar_elem(this, \'mid\')"> <div class="while"><span>' + while_text + '</span></div><div class="conector"></div></div><div class="endwhile" onclick="agregar_elem(this, \'end\')">End While</div><div class="conector2"></div><div class="conector"></div></div>';
	  $(elemento).after(x);
	}
	else if(tipo=="mid"){
		alert("No se pueden anidar ciclos");
	}
	else if(tipo=="end"){
	  	x='<div class="elemento"><div class="elemento" onclick="agregar_elem(this, \'mid\')"> <div class="while"><span>' + while_text + '</span></div><div class="conector"></div></div><div class="endwhile" onclick="agregar_elem(this, \'end\')">End While</div><div class="conector2"></div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un while");
	}
}

function agregar_elem(elemento, tipo){
	switch (elem_selec){
	case 0:
	  //alert("Selecciona un simbolo antes de agregar");
	  var r=confirm("Quieres borrar este elemento?");
	  	if (r==true){
		  $(elemento).remove();
		}
		else{
		  alert("No se borro el elemento");
		}
	  break;
	case 1:
	  agregar_estatuto(elemento, tipo);
	  elem_selec = 0;
	  break;
	case 2:
	  agregar_variable(elemento, tipo)
	  elem_selec = 0;
	  break;
	case 3:
	  agregar_if(elemento, tipo);
	  elem_selec = 0;
	  break;
	case 4:
	  agregar_operacion(elemento, tipo);
	  elem_selec = 0;
	  break;
	case 5:
	  agregar_for(elemento, tipo);
	  elem_selec = 0;
	  break;
	case 6:
	  agregar_while(elemento, tipo);
	  elem_selec = 0;
	  break;	  
	}
}