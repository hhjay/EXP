<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>购物车</title>
        <link rel="stylesheet" type="text/css" href="main.css">
    </head>
    <body background="images/lo-bg.png">  
        <div class="main">
            <div class="form">
        <%request.setCharacterEncoding("gb2312");%>
        <jsp:useBean id="variableID" scope="page" class="com.jsp.variable"/>
        <jsp:setProperty name="variableID" property="appleAmount" param="appleAmount"/>    
        <jsp:setProperty name="variableID" property="bananaAmount" param="bananaAmount" />        
        <jsp:setProperty name="variableID" property="grapeAmount" param="grapeAmount" />
        <jsp:setProperty name="variableID" property="orangeAmount" param="orangeAmount"/>
        <table border="0"width="100%">
            <tr> 
                <td align="left" valign="bottom">
                    <h2>您所选购的商品</h2>
                </td>
            </tr>
        </table>
                <table cellspacing="5" cellpadding="5">
            <tr>
                <td align="center"><b>品种</b></td>
                <td align="center"><b>单价（元/斤）</b></td>
                <td align="center"><b>重量（市斤）</b></td>
            </tr>
            <tr>
                <td align="center">苹果</td>                
                <td align="center"><jsp:getProperty name="variableID" property="applePrice"/></td>
                <td align="center"><jsp:getProperty name="variableID" property="appleAmount"/></td>
            </tr>    
            <tr>
                <td align="center">香蕉</td>
                <td align="center"><jsp:getProperty name="variableID" property="bananaPrice"/></td>
                <td align="center"><jsp:getProperty name="variableID" property="bananaAmount"/></td>
            </tr>
            <tr>
                <td align="center">葡萄</td>
                <td align="center"><jsp:getProperty name="variableID" property="grapePrice"/></td>
                <td align="center"><jsp:getProperty name="variableID" property="grapeAmount"/></td>
            </tr> 
            <tr>
                <td align="center">橘子</td>
                <td align="center"><jsp:getProperty name="variableID" property="orangePrice"/></td>
                <td align="center"><jsp:getProperty name="variableID" property="orangeAmount"/></td>
            </tr> 
                </table>
            <table cellspacing="5" cellpadding="5">
            <tr>
                <td align="center"><b>总价</b></td>
                <td align="center">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<jsp:getProperty name="variableID" property="sumPrice"/>&nbsp;&nbsp;元</td>
            </tr>          
         </table>
            </div>
        </div>
    </body>
</html>
