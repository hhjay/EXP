package com.servlet;
import java.text.SimpleDateFormat;
import java.util.Date;

public class time {
    public static String getTimeShort(){   
    SimpleDateFormat timeformat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    Date contentTime=new Date();
    String dateString =timeformat.format(contentTime);
    return dateString;
    }
}