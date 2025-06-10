public class Quadrangle extends Shape{
  double x1, y1, x2, y2, x3, y3, x4, y4;

  Quadrangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    this.x1=x1;
    this.y1=y1;
    this.x2=x2;
    this.y2=y2;
    this.x3=x3;
    this.y3=y3;
    this.x4=x4;
    this.y4=y4;
  }
  
  public String toString(){
    String s;
    s = "四角形：(" + x1 + ", " + y1 + "), (" + x2 + ", " + y2 + "), (" + x3 + ", " + y3 + "), (" + x4 + ", " + y4 + ")";
    return s;
  }

   public double area(){
     double area, s1, s2;

     s1=Math.abs((x1-x2)*(y3-y2)-(x3-x2)*(y1-y2))/2;
     s2=Math.abs((x1-x4)*(y3-y4)-(y1-y4)*(x3-x4))/2;
     area=s1+s2;
     return area;
   }

   public double perimeter(){
     double perimeter;
     perimeter=Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+Math.sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))+Math.sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4))+Math.sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1));
     return perimeter;
   }
}
