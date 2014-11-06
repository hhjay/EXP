<%@page contentType="text/html" pageEncoding="gb2312"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type"content="text/html;charset=gb2312">
    <title>Login</title>
    <style type="text/css">
        body{margin: 0px;padding: 0px;}
       		.lo-login{
			width: 100%;
			height: 900px;
			margin: 0px auto;
			background: url(images/lo-bg.png)repeat;
		}
		.lo-space{
			width: 100%;
			height: 100px;
		}
		#fm_login{
			width: 600px;
			height: 280px;
			margin: 0px auto;
			border-radius: 20px;
			background: white;
		}
		.lo-head{
			width: 300px;
			height: 50px;
			margin: 0px auto;
		}
		.lo-login p{
			width: 80%;
			margin: 30px auto;
		}
		#fm_login label,#fm_login input{
			margin: 0px auto;
			height: 25px;
			line-height: 25px;
		}
		#fm_login label{
			width: 100px;
			float: left;
		}
		#fm_login input{
			width: 200px;
		}
		.lo-btn{
			width: 50%;
			margin: 50px auto;
		}
    </style>
  </head>
  <body>
  <script type="text/javascript">alert("��¼ʧ�ܣ������µ�½");</script>
  <div class="lo-login">
	<div class="lo-space"></div>
	<form name="login" method="post" id="fm_login" action="Main">
		<div class="lo-head"></div>
		<p>
			<label for="loginName">��¼����</label>
			<input name="loginName" id="loginName" type="text" />
		</p>
		<p>
			<label for="loginPwd">��&nbsp;&nbsp;�룺</label>
			<input name="loginPwd" id="loginPwd"type="password" />
		</p>
		<div class="lo-btn">
			<button type="submit" id="ad_sub" name="ad_sub">��¼</button>
		</div>
	</form>	
</div>
    </body>
</html>