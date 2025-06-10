//https://www.omu.ac.jp/

//html取得
import java.net.URL;
import java.net.HttpURLConnection;
import java.io.InputStreamReader;
import java.io.BufferedReader;
//正規表現
import java.util.regex.Matcher;
import java.util.regex.Pattern;
//コレクション
import java.util.HashSet;
import java.util.TreeSet;


public class Main{
  public static void main(String[] args){
    try{
      //html取得
      URL url = new URL("https://www.omu.ac.jp/");
      HttpURLConnection http = (HttpURLConnection)url.openConnection();
      http.setRequestMethod("GET");
      http.connect();
      InputStreamReader isr = new InputStreamReader(http.getInputStream(), "UTF-8");
      BufferedReader br = new BufferedReader(isr);
      String line_buffer;
      
      //Patternインスタンス準備
      Pattern pattern_start1 = Pattern.compile("(?<=href)(.*)");
      Pattern pattern_start2 = Pattern.compile("http(.*)");
      Pattern pattern_end1 = Pattern.compile("(^.*?)(?=\")");
      Pattern pattern_end2 = Pattern.compile("(^.*?)'");


      //herfの含まれる行を取得
      HashSet<String> hash_set_line = new HashSet<String>();
      
      while(null != (line_buffer = br.readLine())){
        Matcher matcher_line = pattern_start1.matcher(line_buffer);
        while(matcher_line.find()){
          hash_set_line.add(matcher_line.group());
        }
      }
     

      //行からurlの取り出し
      HashSet<String> hash_set_url_long = new HashSet<String>();
      for(String s : hash_set_line){
        Matcher matcher_url_long = pattern_start2.matcher(s);

        if(matcher_url_long.find()){
          hash_set_url_long.add(matcher_url_long.group());
        }
      }

      TreeSet<String> tree_set_url = new TreeSet<String>();
      for(String u : hash_set_url_long){
          Matcher matcher_url1 = pattern_end1.matcher(u);
          Matcher matcher_url2 = pattern_end2.matcher(u);
          if(matcher_url1.find()){
            tree_set_url.add(matcher_url1.group());
          }else if(matcher_url2.find()){
            tree_set_url.add(matcher_url2.group());
          }
        
        }
      
      //各要素の表示
      System.out.println("Links in https://www.omu.ac.jp/");
      int i=1;
      for(String h : tree_set_url){
        System.out.println(i + ": " + h);
        i++;
      }

      br.close();
      isr.close();
      http.disconnect();
      
    }catch(Exception e){}
  }
}
