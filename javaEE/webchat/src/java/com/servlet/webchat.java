package com.servlet;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class webchat extends HttpServlet {
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String name=request.getParameter("loginName");
 //       String talkwords=(String)getServletContext().getAttribute("talking");
        out.println("<!DOCTYPE html>\n" +"<html>\n" +"<head>\n" +"<title>聊天界面</title>\n" +"<link rel=\"stylesheet\" type=\"text/css\" href=\"main.css\">");
        out.println("</head>"); 
        out.println("<div class=\"main\">\n" +"<div class=\"online\">\n" +"<p>聊天窗口</p>\n" +"<div class=\"num\">在线人数：\n" +counter.counte+
"<ul>\n" +"<li>黄会杰</li>\n" +"<li>龚  宽</li>\n" +"<li>周  天</li>\n" +"<li>邵  野</li>\n" +"<li>田林勇</li>\n" +"</ul>\n" +"</div>\n" +"</div>");
        out.println("<div class=\"con\">\n" +
"			<div class=\"out\">\n" +
"				<h5>聊天信息输出</h5>\n" +
"				<form action=\"Content\" method=\"post\">\n" +
"					<textarea name=\"talkingwindow\" style=\"overflow:auto\" class=\"outText\">"+Content.content+"</textarea>\n" +
"					<input name=\"talkingtext\"  class=\"inText\" />\n" +
"					<input type=\"submit\" align=\"right\" name=\"btn_submit\" value=\"提交\" class=\"sub\">\n" +
"				</form>\n" +
"			</div>\n" +
"		</div>\n" +
"	</div>"); 
        out.close();
    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        processRequest(request, response);
    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        processRequest(request, response);
    }
    public String getServletInfo() {
        return "Short description";
    } 
}