var socket = io("http://localhost:2323");

$(document).ready(function(){
	alert("hello");
	$("#btnON").click(function(){
		socket.emit("BatDen", "on");
	});
	$("#btnOFF").click(function(){
		socket.emit("TatDen", "off");
	});

});