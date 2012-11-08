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
read = 9
*/

var elem_selec=0;
var codigo = "";

function click_estatuto(){  
  elem_selec=1;
}  

function click_var(){  
  elem_selec=2;
}  

function click_if(){  
  elem_selec=3;
}

function click_op(){  
  elem_selec=4;
}

function click_for(){  
  elem_selec=5;
}

function click_while(){  
  elem_selec=6;
}

function click_else(){  
  elem_selec=7;
}

function click_funcion(){  
  elem_selec=8;
}

function agregar_estatuto(elemento, tipo) {
    var x;
	var est_text=prompt("Agrega estatuto","Ejem: Fin");
	x='<div class="elemento" onclick="agregar_elem(this)"><div class="estatuto"> ' + est_text + '</div><div class="conector"></div></div>';
	
	if (est_text!="" && tipo!="end"){
	  $(elemento).after(x);  
	}
	else if(tipo=="end"){
		$(elemento).parent().after(x);  
	}
	else{
		alert("No declaraste un estatuto");
	}
}

function agregar_variable(elemento, tipo) {
	var x;
	var var_text=prompt("Agrega tipo, nombre y valor de la variable","Ejem: int x = 3");
	x='<div class="elemento" onclick="agregar_elem(this)"><div class="variable"> ' + var_text + '</div><div class="conector"></div></div>';
	
	if (var_text!="" && tipo!="end"){
	  $(elemento).after(x);  
	}
	else if(tipo=="end"){
		$(elemento).parent().after(x);  
	}
	else{
		alert("No declaraste una variable");
	}
}

function agregar_if(elemento, tipo) {
	var x;
	var if_text=prompt("Agrega condicion","Ejem: x > y");
	x='<div class="elemento padre"><div class="elemento padre" onclick="agregar_elem(this)"><div class="if">' + if_text + '</div><div class="conector"></div></div><div class="elemento padre" onclick="agregar_elem(this, \'end\')"><div class="endif">End if</div><div class="conector"></div></div></div>';

	
	if (if_text!="" && tipo!="end"){
	  $(elemento).after(x);
	  $('.escondido').css('display', 'block');
	}
	else if(tipo=="end"){
	  $(elemento).parent().after(x);
	  $('.escondido').css('display', 'block');
	}
	else{
		alert("No declaraste un if");
	}
}

function agregar_else(elemento, tipo) {
	var x;
	x='<div class="elemento padre"><div class="elemento padre" onclick="agregar_elem(this)"> <div class="else">else</div><div class="conector"></div></div><div class="elemento padre" onclick="agregar_elem(this, \'end\')"><div class="endelse">End else</div><div class="conector"></div></div></div>';

	
	if (tipo!="end"){
	  $(elemento).after(x);
	  $('.escondido').css('display', 'none');
	}
	else if(tipo=="end"){
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
	x='<div class="elemento" onclick="agregar_elem(this)"><div class="operacion"> ' + op_text + '</div><div class="conector"></div></div>';

	
	if (op_text!="" && tipo!="end"){
	  $(elemento).after(x);    
	}
	else if(tipo=="end"){
		$(elemento).parent().after(x);  
	}
	else{
		alert("No declaraste una operacion");
	}
}

function agregar_for(elemento, tipo) {
    var x;
	var for_text=prompt("Agrega for","Ejem: i = 0; i < 10; i++");
	x='<div class="elemento padre"><div class="elemento padre" onclick="agregar_elem(this)"> <div class="for">' + for_text + '</div><div class="conector"></div></div><div class="elemento padre" onclick="agregar_elem(this, \'end\')"><div class="endfor">End For</div><div class="conector"></div></div></div>';

	
	if (for_text!="" && tipo!="end"){
	  $(elemento).after(x);
	}
	else if(tipo=="end"){
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un for");
	}
}

function agregar_while(elemento, tipo) {
    var x;
	var while_text=prompt("Agrega while","Ejem: x < 10");
	x='<div class="elemento padre"><div class="elemento padre" onclick="agregar_elem(this)"> <div class="while">' + while_text + '</div><div class="conector"></div></div><div class="elemento padre" onclick="agregar_elem(this, \'end\')"><div class="endwhile">End While</div><div class="conector"></div></div></div>';
	
	if (while_text!="" && tipo!="end"){
	  $(elemento).after(x);
	}
	else if(tipo=="end"){
	  $(elemento).parent().after(x);
	}
	else{
		alert("No declaraste un while");
	}
}

function agregar_funcion(elemento, tipo) {
    var x;
	var funcion_text=prompt("Agrega funcion","Ejem: nombre(x, y)");
		x='<div class="elemento padre"><div class="elemento padre" onclick="agregar_elem(this)"> <div class="funcion">' + funcion_text + '</div><div class="conector"></div></div><div class="elemento padre" onclick="agregar_elem(this, \'end\')"><div class="endfuncion">End Funcion</div><div class="conector"></div></div>';
	
	if($(elemento).parent().attr('class') == "flowchart"){
		if (funcion_text!="" && tipo!="end"){
		  $(elemento).after(x);
		}
		else if(tipo=="end"){
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
	if (r==true && padre=="flowchart"){
		$(elemento).remove();
	}
	else if(r==true && $(elemento).attr('class') == 'elemento padre'){
		$(elemento).parent().remove();
	}
	else if(r==true && padre=="elemento padre"){
		$(elemento).remove();
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

function convertir(){
	var elementos = document.getElementsByClassName('elemento');
	codigo = "";
	for(var i=0; i<elementos.length; i++){ 
		if($(elementos[i]).children().attr('class') != 'elemento'){
			if($(elementos[i]).children().attr('class') == 'for'){
				console.log("for(" + $(elementos[i]).children().html() + "){");
				codigo = codigo + "for(" + $(elementos[i]).children().html() + "){";
			}
			else if($(elementos[i]).children().attr('class') == 'while'){
				console.log("while(" + $(elementos[i]).children().html() + "){");
				codigo = codigo + "while(" + $(elementos[i]).children().html() + "){";
			}
			else if($(elementos[i]).children().attr('class') == 'if'){
				console.log("if(" + $(elementos[i]).children().html() + "){");
				codigo = codigo + "if(" + $(elementos[i]).children().html() + "){";
			}
			else if($(elementos[i]).children().attr('class') == 'else'){
				console.log("else(" + $(elementos[i]).children().html() + "){");
				codigo = codigo + "else(" + $(elementos[i]).children().html() + "){";
			}
			else if($(elementos[i]).children().attr('class') == 'funcion'){
				console.log("function " + $(elementos[i]).children().html() + "){");
				codigo = codigo + "function " + $(elementos[i]).children().html() + "){";
			}
			else if($(elementos[i]).children().attr('class') == 'variable' || $(elementos[i]).children().attr('class') == 'operacion'){
				console.log(($(elementos[i]).children().html()) + ";");
				codigo = codigo + ($(elementos[i]).children().html()) + ";";
			}
			else if($(elementos[i]).children().attr('class') == 'estatuto' && $(elementos[i]).children().html() == "inicio"){
				console.log("program main(){");
				codigo = codigo + "program main(){";
			}
			else if($(elementos[i]).children().attr('class') == 'endfor' || $(elementos[i]).children().attr('class') == 'endwhile' || $(elementos[i]).children().attr('class') == 'endif' || $(elementos[i]).children().attr('class') == 'endfuncion' || $(elementos[i]).children().attr('class') == 'estatuto' && $(elementos[i]).children().html() == "fin"){
				console.log("}");
				codigo = codigo + "}";
			}
		}
	}
	codigo = codigo.replace('&lt;','<');
	codigo = codigo.replace('&gt;','>');
	codigo = codigo.replace('&lt;&gt;','<>');
	console.log(codigo);
}

function enviar(){
	$.post(
        "http://127.0.0.1:8080/", {data: codigo} );
}