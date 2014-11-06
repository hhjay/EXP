package com.jsp;
public class variable {
    private float appleAmount,applePrice;
    private float bananaAmount,bananaPrice;
    private float grapeAmount,grapePrice;   
    private float orangeAmount,orangePrice;    
    private float sumPrice;  
    
    public variable() {
        appleAmount=(float) 0.0;
        applePrice=(float) 2.5;
        bananaAmount=(float) 0.0;
        bananaPrice=(float) 3.0;
        grapeAmount=(float) 0.0;
        grapePrice=(float) 8.0;
        orangeAmount=(float) 0.0;
        orangePrice=(float) 1.0;
        sumPrice=(float) 0.0;
    }
    public float getAppleAmount() {
        return appleAmount;
    }
    public void setAppleAmount(float appleAmount) {
        this.appleAmount = appleAmount;
    }
    public float getApplePrice() {
        return applePrice;
    }
    public void setApplePrice(float applePrice) {
        this.applePrice = applePrice;
    }
    public float getBananaAmount() {
        return bananaAmount;
    }
    public void setBananaAmount(float bananaAmount) {
        this.bananaAmount = bananaAmount;
    }
    public float getBananaPrice() {
        return bananaPrice;
    }
    public void setBananaPrice(float bananaPrice) {
        this.bananaPrice = bananaPrice;
    }
    public float getGrapeAmount() {
        return grapeAmount;
    }
    public void setGrapeAmount(float grapeAmount) {
        this.grapeAmount = grapeAmount;
    }
    public float getGrapePrice() {
        return grapePrice;
    }
    public void setGrapePrice(float grapePrice) {
        this.grapePrice = grapePrice;
    }
    public float getOrangeAmount() {
        return orangeAmount;
    }
    public void setOrangeAmount(float orangeAmount) {
        this.orangeAmount = orangeAmount;
    }
    public float getOrangePrice() {
        return orangePrice;
    }
    public void setOrangePrice(float orangePrice) {
        this.orangePrice = orangePrice;
    }
    public float getsumPrice() {
        setsumPrice(appleAmount*applePrice+bananaAmount*bananaPrice+grapeAmount*grapePrice+orangeAmount*orangePrice);
        return sumPrice;
    }
    public void setsumPrice(float sumPrice) {
        this.sumPrice =sumPrice ;
    }
}
