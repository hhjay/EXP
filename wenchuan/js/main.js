$(document).ready(function(){
    $.ajax({
        url: 'http://newborn2013.stuzone.com/huanghuijie/xinxigongkai/wenchuan.php',
        type: 'GET',
        dataType: 'jsonp',
        callback: 'callback',
        success: function(data) {
            // console.log(data);
            var $list = "";
            var $time = "";
            for(var href in data) {   
                $time = "<span>Data:"+data[href].substr(0,10) + "</span>";
                $list += $time + "<div class='floatLink'><a href='"+href+"'>"+data[href].substr(10,105)+"...</a></div>";
                // $list += $time;
            } 
        	$("#floatBody").html($list);
        },
        error: function(err) {
            console.log('err');
        }
    });
    $(".floatTitle").click(function(){
        $("#hhjFloat").hide();
    });
});