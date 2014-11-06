package com.servlet;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Main extends HttpServlet {
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException 
    {
        response.setContentType("text/html;charset=GB2312");
        request.setCharacterEncoding("gb2312");
        String loginName=request.getParameter("loginName");
        if(loginName==null)
        {
            loginName=" ";
        }
        String password=request.getParameter("loginPwd");
        if(password==null)
        {
            password=" ";
        } 
        if(loginName.equals("黄会杰")&&password.equals("2012213516"))
        {
            request.getSession().setAttribute("loginName",loginName);
            RequestDispatcher dispatcher=request.getRequestDispatcher("webchat"); 
            dispatcher.forward(request, response);
        }
        else if(loginName.equals("周天")&&password.equals("2012213503"))
        {
             request.getSession().setAttribute("loginName",loginName);
             RequestDispatcher dispatcher=request.getRequestDispatcher("webchat"); 
             dispatcher.forward(request, response);
        }
        else if(loginName.equals("龚宽")&&password.equals("2012213506"))
        {
             request.getSession().setAttribute("loginName",loginName);
             RequestDispatcher dispatcher=request.getRequestDispatcher("webchat"); 
             dispatcher.forward(request, response);
        }
       else if(loginName.equals("邵野")&&password.equals("2012213493"))
        {
             request.getSession().setAttribute("loginName",loginName);
             RequestDispatcher dispatcher=request.getRequestDispatcher("webchat"); 
             dispatcher.forward(request, response);
        }
        else if(loginName.equals("田林勇")&&password.equals("2012213515"))
        {
             request.getSession().setAttribute("loginName",loginName);
             RequestDispatcher dispatcher=request.getRequestDispatcher("webchat"); 
             dispatcher.forward(request, response);
        }
        else
        {
            RequestDispatcher dispatcher=request.getRequestDispatcher("Loginfail");
            dispatcher.forward(request, response);
        }               
    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException 
    {
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
