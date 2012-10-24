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

function agregar_estatuto() {
    var x;
	var est_text=prompt("Agrega estatuto","Ejem: Fin");
	
	if (est_text!=null){
	  x='<div class="estatuto"> <span>' + est_text + '</span></div>';
	  $('.flowchart').append(x);
	}
}

function agregar_variable() {
	var x;
	var var_text=prompt("Agrega tipo, nombre y valor de la variable","Ejem: int x = 3");
	
	if (var_text!=null){
	  x='<div class="variable"> <span>' + var_text + '</span></div>';
	  $('.flowchart').append(x);
	}
}

function agregar_if() {
	var x;
	var if_text=prompt("Agrega condicion","Ejem: x > y");
	
	if (if_text!=null){
	  x='<div class="if"> <span class="textoIf">' + if_text + '</span></div>';
	  $('.flowchart').append(x);
	}
}

function agregar_operacion() {
    var x;
	var op_text=prompt("Agrega operacion","Ejem: x = x + 1");
	
	if (op_text!=null){
	  x='<div class="operacion"> <span>' + op_text + '</span></div>';
	  $('.flowchart').append(x);
	}
}

function agregar_elem(){
	switch (elem_selec){
	case 0:
	  console.log("ninguno esta seleccionado");
	  break;
	case 1:
	  agregar_estatuto();
	  elem_selec = 0;
	  break;
	case 2:
	  agregar_variable()
	  elem_selec = 0;
	  break;
	case 3:
	  agregar_if();
	  elem_selec = 0;
	  break;
	case 4:
	  agregar_operacion();
	  elem_selec = 0;
	  break;
	}
}    