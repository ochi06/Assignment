public class Circle extends Shape{
  double x, y, radius;
  
  Circle(double x, double y, double radius){
    this.x=x;
    this.y=y;
    this.radius=radius;
  };

  public String toString(){
    String s;
    s = "円：(" + x + ", " + y + "), radius = " + radius;
    return s;
  }
  
  public double area(){
    double area;
    area = Math.PI * radius * radius;
    return area;
  }

  public double perimeter(){
    double perimeter;
    perimeter = 2 * Math.PI * radius;
    return perimeter;
  }
  
}
