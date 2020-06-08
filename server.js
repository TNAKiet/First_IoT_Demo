PORT=2323;
var express = require("express");
var app = express();
ip=require("ip");
app.use(express.static("./public"));
app.set("view engine", "ejs");
app.set("views", "./views");

var server = require("http").Server(app);
var io = require("socket.io")(server);// goi thu vien socket io 
server.listen(PORT);
console.log("Server nodejs chay tai dia chi: "+ip.address()+":"+PORT);

io.on("connection", function(socket){
	
  console.log("Co nguoi ket noi:" +socket.id);
	
  socket.on("disconnect", function(){
    console.log(socket.id + " ngat ket noi!!!!!");
  });

socket.on("BatDen", function(data){
	socket.broadcast.emit("BatDen", data);
});
socket.on("TatDen", function(data){
	socket.broadcast.emit("TatDen", data);
});
socket.on("DenBat", function(data){
	console.log(data);
});
socket.on("DenTat",function(data){
	console.log(data);
});
});//lang nghe coi co ai ket noi

app.get("/", function(req, res){
 res.render("trangchu");
});