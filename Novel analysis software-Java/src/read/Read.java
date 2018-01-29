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
		    String pathname = "C:\\Users\\hu108\\Desktop\\java class\\��Ĺ�ʼ�.txt"; 
		    File filename = new File(pathname); 
		    InputStreamReader reader = new InputStreamReader( new FileInputStream(filename) ); // ����һ������������reader  
		    BufferedReader br = new BufferedReader(reader); 
		 
		    
		    String line = br.readLine();  
		    int linenum =0;
		    int count = 0;
		    while (line != null)
		    {  
		        line = br.readLine(); // һ�ζ���һ������  
		        linenum++;
		        if (line != null)
			    {
			        Pattern p = Pattern.compile("��а");
				    Matcher m = p.matcher(line); //p.matcher(line)�е�line����Ϊnull������ᷢ���쳣��
				    while(m.find())
				    {
					    count++;
					    System.out.println("Match number "+count);   
				    }
		        }
		    }  
		    System.out.print(linenum);
		 
		    
		    File writename = new File("C:\\Users\\hu108\\Desktop\\java class\\11.txt"); 
		    writename.createNewFile(); // �������ļ�  
		    BufferedWriter out = new BufferedWriter(new FileWriter(writename));  
		    out.write("�һ�д���ļ���\r\n"); // \r\n��Ϊ����  
		    out.flush(); // �ѻ���������ѹ���ļ�  
		    out.close(); // ���ǵùر��ļ�  
		    
		    
		} 
		catch (Exception e) {  
		    e.printStackTrace();  
		}  
		
		  
		       
	 }

}
