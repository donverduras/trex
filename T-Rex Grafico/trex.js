/*
ninguno seleccionado = 0
estatuto = 1
variable = 2
if = 3
operacion = 4
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

function agregar_estatuto(elemento) {
    var x;
	var est_text=prompt("Agrega estatuto","Ejem: Fin");
	
	if (est_text!=""){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="estatuto"> <span>' + est_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
	}
	else{
		alert("No declaraste un estatuto");
	}
}

function agregar_variable(elemento) {
	var x;
	var var_text=prompt("Agrega tipo, nombre y valor de la variable","Ejem: int x = 3");
	
	if (var_text!=""){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="variable"> <span>' + var_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
	}
	else{
		alert("No declaraste un elemento");
	}
}

function agregar_if(elemento) {
	var x;
	var if_text=prompt("Agrega condicion","Ejem: x > y");
	
	if (if_text!=""){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="if"> <span class="textoIf">' + if_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);  
	}
	else{
		alert("No declaraste un if");
	}
}

function agregar_operacion(elemento) {
    var x;
	var op_text=prompt("Agrega operacion","Ejem: x = x + 1");
	
	if (op_text!=""){
	  x='<div class="elemento" onclick="agregar_elem(this)"><div class="operacion"> <span>' + op_text + '</span></div><div class="conector"></div></div>';
	  $(elemento).after(x);    
	}
	else{
		alert("No declaraste una operacion");
	}
}

function agregar_elem(elemento){
	switch (elem_selec){
	case 0:
	  alert("Selecciona un simbolo antes de agregar");
	  break;
	case 1:
	  agregar_estatuto(elemento);
	  elem_selec = 0;
	  break;
	case 2:
	  agregar_variable(elemento)
	  elem_selec = 0;
	  break;
	case 3:
	  agregar_if(elemento);
	  elem_selec = 0;
	  break;
	case 4:
	  agregar_operacion(elemento);
	  elem_selec = 0;
	  break;
	}
}