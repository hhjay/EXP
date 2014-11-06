<%@page contentType="text/html" pageEncoding="gb2312"%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=gb2312">
        <title>用户信息验证</title>
    </head>
        <% 
        java.sql.Connection conn; 
        java.lang.String strConn; 
        java.sql.PreparedStatement preparedStmt; 
        java.sql.ResultSet sqlRst;
        boolean flag = false;
        request.setCharacterEncoding("gb2312");
        %>
        <%
        try{
        Class.forName("com.mysql.jdbc.Driver").newInstance(); 
        conn= java.sql.DriverManager.getConnection("jdbc:mysql://localhost:8080","root",""); 
        String loginName= request.getParameter("loginName");
        String loginPwd= request.getParameter("loginPwd");
        preparedStmt =conn.prepareStatement("select loginName from studinfor_table where name ='"+loginName+"'and stu_id ='"+loginPwd+"'");
        sqlRst=preparedStmt.executeQuery (); 
        if(sqlRst.next()){
            flag=true;
            session.setAttribute("loginName",sqlRst.getString(1));
        }
        else{
            request.setAttribute("err","登录失败！");
        }
        %>        
        <%
        sqlRst.close();        
        preparedStmt.close ();      
        conn.close();        
        } catch (java.sql.SQLException e){
        out.println(e.toString());
        }
        %>      
        <%
        if(flag)
        {
        %>
        <jsp:forward page="Catalogjsp.jsp"/>
        <%
        }

        %>
    </body>
</html>