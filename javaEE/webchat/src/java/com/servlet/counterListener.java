package com.servlet;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

public class counterListener implements HttpSessionListener {
 
    public void sessionCreated(HttpSessionEvent evt) { 
        counter.counte++;
    }
    public void sessionDestroyed(HttpSessionEvent evt) { 
         counter.counte--;
    }
}