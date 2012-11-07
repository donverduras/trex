var http = require("http");
var cont = 0;
var string = "program prueba(){}";

http.createServer(function (request, response) {
					request.on("end", function () {
										response.writeHead(200, { 'Content-Type': 'text/plain' });

					response.end('Hello HTTP!');
				 });
				 
				  	if(request.method === "POST") {
    					var data = "";

   						request.on("data", function(chunk) {
        									data += chunk;
        									console.log(data);
    								});
   
   					var fs = require('fs');
   					fs.writeFile('prueba.txt', string, function (err) {
  																if (err) throw err;
  																	console.log('It\'s saved!');
																});
   
					var exec = require('child_process').exec, child;
					child = exec('g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex',
  								 function (error, stdout, stderr) {
    								var execute = require('child_process').exec, trex;
									
									trex = execute('./Trex test.txt', function (error, stdout, stderr) {
    																	if(cont == 0){
    																		console.log(stdout);
    																		cont++;
    																	}
													});
							});
}).listen(8080);