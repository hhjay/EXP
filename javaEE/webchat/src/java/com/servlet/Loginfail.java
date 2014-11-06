package com.servlet;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Loginfail extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset=GB2312");
        PrintWriter out = response.getWriter();
        /* TODO output your page here */
        out.println("<html>");
        out.println("<head>");
        out.println("<title>登录失败</title>");
        out.println("</head>");
        out.println("<body>");
        out.println("<script type=\"text/javascript\">alert(\"登录失败，请重新登陆\");</script>");
        RequestDispatcher dispatcher=request.getRequestDispatcher("login.html");
        dispatcher.include(request, response);
        out.println("</body>");
        out.println("</html>");
        out.close();
    } 
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code."> 
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
