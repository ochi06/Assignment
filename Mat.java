//AJG23001 Asuka Ochiai

//行列演算クラス
public class Mat {
  // コンストラクタ
  public Mat() {

  }

  // 行列 A を表示する．
  public void show(double[][] A) {
    System.out.println("---");
    for (int i = 0; i < A.length; i++) {
      for (int j = 0; j < A[0].length; j++) {
        System.out.print(A[i][j] + ", ");
      }
      System.out.println();
    }
    System.out.println("---");
  }
  
  //和を返却
  public double[][] add(double[][] A1, double[][] A2){
    int i,k;
    double[][] add;
    add = new double[A1.length][A1[0].length];

    for(i=0;i<A1.length;i++){
      for(k=0;k<A1[0].length;k++){
        add[i][k]=A1[i][k]+A2[i][k];
      }
    }
    return add;
  }
  
  //差を返却
  public double[][] sub(double[][] A1, double[][] A2){
    int i,k;
    double[][] sub;
    sub = new double[A1.length][A1[0].length];

    for(i=0;i<A1.length;i++){
      for(k=0;k<A1[0].length;k++){
        sub[i][k]=A1[i][k]-A2[i][k];
      }
    }
    return sub;
  }

  //要素ごとの積
  public double[][] mul(double[][] A1, double[][] A2){
    int i,k;
    double[][] mul;
    mul = new double[A1.length][A1[0].length];

    for(i=0;i<A1.length;i++){
      for(k=0;k<A1[0].length;k++){
        mul[i][k]=A1[i][k]*A2[i][k];
      }
    }
    return mul;
  }

  //要素ごとの除算
  public double[][] div(double[][] A1, double[][] A2){
    int i,k;
    double[][] div;
    div = new double[A1.length][A1[0].length];

    for(i=0;i<A1.length;i++){
      for(k=0;k<A1[0].length;k++){
        div[i][k]=A1[i][k]/A2[i][k];
      }
    }
    return div;
  }

  //スカラー倍
  public double[][] sc(double[][] A1, double s){
    int i,k;
    double[][] sc;
    sc = new double[A1.length][A1[0].length];

    for(i=0;i<A1.length;i++){
      for(k=0;k<A1[0].length;k++){
        sc[i][k]=A1[i][k]*s;
      }
    }
    return sc;
  }

  //転置行列
  public double[][] T(double[][] A1){
    int i,k;
    double[][] T;
    T = new double[A1[0].length][A1.length];

    for(i=0;i<A1[0].length;i++){
      for(k=0;k<A1.length;k++){
        T[i][k]=A1[k][i];
      }
    }
    return T;
  }

  //行列積
  public double[][] matmul(double[][] A1, double [][] A2){
    int i,k,j;
    double[][] matmul;
    matmul = new double[A1.length][A2[0].length];

    for(i=0;i<A1.length;i++){
      for(k=0;k<A2[0].length;k++){
        for(j=0;j<A1[0].length;j++){
          matmul[i][k]+=A1[i][j]*A2[j][k];
        }
      }
    }
    return matmul;
  }
}