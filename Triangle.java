//AJG23001 asuka ochiai
public class Triangle extends Shape{
  double x1, y1, x2, y2, x3, y3;

  Triangle(double x1, double y1, double x2, double y2, double x3, double y3){
    this.x1=x1;
    this.y1=y1;
    this.x2=x2;
    this.y2=y2;
    this.x3=x3;
    this.y3=y3;
  };

  public String toString(){
    String s;
    s = "三角形：(" + x1 + ", " + y1 + "), (" + x2 + ", " + y2 + "), (" + x3 + ", " + y3 + ")";
    return s;
  }

  public double area(){
    double area;
    area=Math.abs((x1-x2)*(y3-y2)-(x3-x2)*(y1-y2))/2;
    return area;
  }

  public double perimeter(){
    double perimeter;
    perimeter=Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+Math.sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))+Math.sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    return perimeter;
  }
}