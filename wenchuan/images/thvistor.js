$(document).ready(function(){
  getResData();
  function getResData(){
    jQuery.getJSON("/application/visits/visits.jsp?sid=th&r="+Math.random(), function(data){
	  /*$("#today").empty();
      $("#today").append(data[0].today);
      $("#arverage").empty();
      $("#arverage").append(data[0].arverage);*/
	  
      $("#total").empty();
      $("#total").append(data[0].total);
    });
  };
});