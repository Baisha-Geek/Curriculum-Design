package read;

import java.io.File;  
import java.io.InputStreamReader;  
import java.io.BufferedReader;  
import java.io.BufferedWriter;  
import java.io.FileInputStream;  
import java.io.FileWriter;  
import java.io.FileReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;

public class Read {
	 public static void main(String[] args)
	 {
		try 
		{ 
		    String pathname = "C:\\Users\\hu108\\Desktop\\java class\\盗墓笔记.txt"; 
		    File filename = new File(pathname); 
		    InputStreamReader reader = new InputStreamReader( new FileInputStream(filename) ); // 建立一个输入流对象reader  
		    BufferedReader br = new BufferedReader(reader); 
		 
		    
		    String line = br.readLine();  
		    int linenum =0;
		    int count = 0;
		    while (line != null)
		    {  
		        line = br.readLine(); // 一次读入一行数据  
		        linenum++;
		        if (line != null)
			    {
			        Pattern p = Pattern.compile("吴邪");
				    Matcher m = p.matcher(line); //p.matcher(line)中的line不能为null，否则会发生异常；
				    while(m.find())
				    {
					    count++;
					    System.out.println("Match number "+count);   
				    }
		        }
		    }  
		    System.out.print(linenum);
		 
		    
		    File writename = new File("C:\\Users\\hu108\\Desktop\\java class\\11.txt"); 
		    writename.createNewFile(); // 创建新文件  
		    BufferedWriter out = new BufferedWriter(new FileWriter(writename));  
		    out.write("我会写入文件啦\r\n"); // \r\n即为换行  
		    out.flush(); // 把缓存区内容压入文件  
		    out.close(); // 最后记得关闭文件  
		    
		    
		} 
		catch (Exception e) {  
		    e.printStackTrace();  
		}  
		
		  
		       
	 }

}
