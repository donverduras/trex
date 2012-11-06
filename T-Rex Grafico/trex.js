/*
ninguno seleccionado = 0
estatuto = 1
variable = 2
if = 3
operacion = 4
for = 5
while = 6
else = 7
funcion = 8
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

function click_else(){  
  elem_selec=7;
  console.log(elem_selec);
  console.log("else");
}

function click_funcion(){  
  elem_selec=8;
  console.log(elem_selec);
  console.log("funcion");
}

function agregar_estatuto(elemento, tipo) {
    var x;
	var est_text=prompt("Agrega estatuto","Ejem: Fin");
	
	if (est_text!="" && tipo!="end"){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="estatuto"> <span>' + est_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
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
	
	if (var_text!="" && tipo!="end"){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="variable"> <span>' + var_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
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
	
	if (if_text!="" && tipo!="end"){
	  x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="if"><span>' + if_text + '</span></div><div class="conector"></div></div><div class="endif" onclick="agregar_elem(this, \'end\')">End if</div><div class="conector"></div></div>';
	  $(elemento).after(x);
	  $('.escondido').css('display', 'block');
	}
	else if(tipo=="end"){
	  	x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="if"><span>' + if_text + '</span></div><div class="conector"></div></div><div class="endif" onclick="agregar_elem(this, \'end\')">End if</div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	  $('.escondido').css('display', 'block');
	}
	else{
		alert("No declaraste un if");
	}
}

function agregar_else(elemento, tipo) {
	var x;
	var else_text=prompt("Agrega else","Ejem: y > x");
	
	if (else_text!="" && tipo!="end"){
	  x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="else"><span>' + else_text + '</span></div><div class="conector"></div></div><div class="endelse" onclick="agregar_elem(this, \'end\')">End else</div><div class="conector"></div></div>';
	  $(elemento).after(x);
	  $('.escondido').css('display', 'none');
	}
	else if(tipo=="end"){
	  	x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="else"><span>' + else_text + '</span></div><div class="conector"></div></div><div class="endelse" onclick="agregar_elem(this, \'end\')">End else</div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	  $('.escondido').css('display', 'none');
	}
	else{
		alert("No declaraste un else");
	}
}

function agregar_operacion(elemento, tipo) {
    var x;
	var op_text=prompt("Agrega operacion","Ejem: x = x + 1");
	
	if (op_text!="" && tipo!="end"){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="operacion"> <span>' + op_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);    
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
	
	if (for_text!="" && tipo!="end"){
	  x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="for"><span>' + for_text + '</span></div><div class="conector"></div></div><div class="endfor" onclick="agregar_elem(this, \'end\')">End For</div><div class="conector"></div></div>';
	  $(elemento).after(x);
	}
	else if(tipo=="end"){
	  x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="for"><span>' + for_text + '</span></div><div class="conector"></div></div><div class="endfor" onclick="agregar_elem(this, \'end\')">End For</div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un for");
	}
}

function agregar_while(elemento, tipo) {
    var x;
	var while_text=prompt("Agrega while","Ejem: x < 10");
	
	if (while_text!="" && tipo!="end"){
	  x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="while"><span>' + while_text + '</span></div><div class="conector"></div></div><div class="endwhile" onclick="agregar_elem(this, \'end\')">End While</div><div class="conector"></div></div>';
	  $(elemento).after(x);
	}
	else if(tipo=="end"){
	  	x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="while"><span>' + while_text + '</span></div><div class="conector"></div></div><div class="endwhile" onclick="agregar_elem(this, \'end\')">End While</div><div class="conector"></div></div>';
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un while");
	}
}

function agregar_funcion(elemento, tipo) {
    var x;
	var funcion_text=prompt("Agrega funcion","Ejem: nombre(x, y)");
	
	if($(elemento).parent().attr('class') == "flowchart"){
		if (funcion_text!="" && tipo!="end"){
		  x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="funcion"><span>' + funcion_text + '</span></div><div class="conector"></div></div><div class="endfuncion" onclick="agregar_elem(this, \'end\')">End Funcion</div><div class="conector"></div></div>';
		  $(elemento).after(x);
		}
		else if(tipo=="end"){
		  	x='<div class="elemento padre"><div class="elemento" onclick="agregar_elem(this)"> <div class="while"><span>' + funcion_text + '</span></div><div class="conector"></div></div><div class="endfuncion" onclick="agregar_elem(this, \'end\')">End Funcion</div><div class="conector"></div></div>';
		  $(elemento).parent().after(x);
		}
		else{
			alert("No declaraste una funcion");
		}
	}
	else{
		alert("No se puede agregar una funcion aqui")
	}
}


function borrar_elemento(elemento){
	var r=confirm("Quieres borrar este elemento?");
	var padre = $(elemento).parent().attr('class');
	if (r==true && padre=="elemento"){
		$(elemento).remove();
	}
	else if(r==true && padre=="elemento padre"){
		$(elemento).parent().remove();
	}
	else{
	alert("No se borro el elemento");
	}
}

function agregar_elem(elemento, tipo){
	switch (elem_selec){
	case 0:
		borrar_elemento(elemento);
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
	case 7:
	  agregar_else(elemento, tipo);
	  elem_selec = 0;
	  break;
	case 8:
	  agregar_funcion(elemento, tipo);
	  elem_selec = 0;
	  break;	  	  
	}
}