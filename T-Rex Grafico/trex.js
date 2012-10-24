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
    $('.flowchart').append('<div class="estatuto Draggable"> <textarea></textarea></div>');
}

function agregar_variable() {
    $('.flowchart').append('<div class="variable Draggable"> <textarea></textarea></div>');
}

function agregar_if() {
    $('.flowchart').append('<div class="if Draggable"> <textarea class="textoIf"> </textarea></div>');
}

function agregar_operacion() {
    $('.flowchart').append('<div class="operacion Draggable"> <textarea></textarea></div>');
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