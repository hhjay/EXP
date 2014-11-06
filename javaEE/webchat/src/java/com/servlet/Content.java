package com.servlet;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Content extends HttpServlet {
    static String content = "";//<editor-fold defaultstate="collapsed" desc="comment"> ;
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=gb2312");
        request.setCharacterEncoding("gb2312");
        PrintWriter out = response.getWriter();
        try {
            String talkingtime =time.getTimeShort();
            content += (request.getSession().getAttribute("loginName") +"  "+talkingtime  + "\r\n");
            content+=(request.getParameter("talkingtext")+ "\r\n");
            RequestDispatcher dispatcher=request.getRequestDispatcher("webchat");
            dispatcher.forward(request,response);
        } finally {            
            out.close();
        }
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
