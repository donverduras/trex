var http = require("http");
var qs = require('querystring');
var cont = 0;
var string;
var finalString;
var data='';


http.createServer(function (request, response) {
	request.on("data", function(chunk) {
	data+=chunk;
	
	var json = qs.parse(data);
	string = json.data;
	
	finalString = string.toString('ascii',0,string.length);
	console.log(finalString);
	
	var fs = require('fs');
		fs.writeFile('test.txt', finalString, 'utf8' ,function (err) {
		if (err) throw err;
			//console.log('It\'s saved!');
			var exec = require('child_process').exec, child;
			child = exec('g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex',
			function (error, stdout, stderr) {
				//console.log("Compilo");
				var execute = require('child_process').exec, trex;
				
				trex = execute('./Trex test.txt', function (error, stdout, stderr) {
					if(cont == 0){
						//console.log(stdout);
						cont++;
						
						
						var executing = require('child_process').exec, vm;
				
						vm = executing('./VM', function (error, stdout, stderr) {
							console.log(stdout);
						});
					}
					});
				});		
			}
		);
	});
						
}).listen(8080);