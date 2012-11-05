var http = require("http");

http.createServer(function (request, response) {
   request.on("end", function () {
      response.writeHead(200, {
         'Content-Type': 'text/plain'
      });
      // Send data and end response.
      response.end('Hello HTTP!');
   });
   
   var exec = require('child_process').exec,
    child;

	child = exec('g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex',
  				function (error, stdout, stderr) {
    				if(error==null){
    					var execute = require('child_process').exec, trex;

						trex = execute('./Trex test.txt',
  									function (error, stdout, stderr) {
    									if(error==null){
    										console.log(stdout);
    									}
									});
    				}
				});
}).listen(8080);