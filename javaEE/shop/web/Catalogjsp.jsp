<%@page import="com.jsp.variable"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*"%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="main.css">
        <title>购物菜单</title>
    </head>
    <body background="images/lo-bg.png">
        <div class="main">
        <form action="Cartjsp.jsp" method="post"  background="images/car.jpg">
        <table border="0"width="100%">
            <tr> 
                <td align="left" valign="bottom">
                    <h2>欢迎_黄会杰_光临建议民大水果超市</h2>
                </td>
            </tr>
        </table>
        <form action="Cartjsp.jsp" method="post">
        <table cellspacing="5" cellpadding="5">
            <tr>
                <td align="center"><b>种类</b></td>
                <td align="center"><b>单价</b></td>
                <td align="center"><b>数量</b></td>
            </tr>
            <tr>
                <td align="center">苹果</td>
                <td align="center">2.5</td>
                <td align="center"><input type="text" name="appleAmount"></td>
            </tr>    
            <tr>
                <td align="center">香蕉</td>
                <td align="center">3.0</td>
                <td align="center"><input type="text" name="bananaAmount"></td>
            </tr>
            <tr>
                <td align="center">葡萄</td>
                <td align="center">8.0</td>
                <td align="center"><input type="text" name="grapeAmount"></td>
            </tr> 
            <tr>
                <td align="center">橘子</td>
                <td align="center">1.0</td>
                <td align="center"><input tppe="text" name="orangeAmount"></td>
            </tr> 
        </table>
            <input type="Submit" name="btnsubmit" value="放入购物车" class="btn">
        </form>
        </div>
    </body>
</html>
