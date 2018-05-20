<?php
defined('BASEPATH') OR exit('No direct script access allowed');
// use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Search extends CI_Controller {
    public function index() {

        //连接数据库
        $con = mysqli_connect("localhost","root","123456wx","wxdesign"); 
        if (!$con) 
        { 
            die("连接错误: " . mysqli_connect_error()); 
        } 
      

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);

        $fileName = $data['fileName'];
        $userId=$data['userId'];

        if($data['logged']===false){
            $this->json([
                'status' => -1,
                'message' => '请先登录'
            ]);
        }

        if($fileName){  
          
           //数据库搜索
            $sqlpro = "SELECT filePath,name FROM `file` WHERE name LIKE '%$fileName%'";  
            $querypro = mysqli_query($con,$sqlpro);  
              
            $sqltalk = "SELECT filePath,name FROM `filetalk` WHERE name LIKE '%$fileName%'";  
            $querytalk = mysqli_query($con,$sqltalk);

            $filePro = mysqli_fetch_all($querypro,MYSQLI_ASSOC);
            $fileTalk = mysqli_fetch_all($querytalk,MYSQLI_ASSOC);
            //从file表单搜索
//            while($filePro = mysqli_fetch_all($querypro,MYSQLI_ASSOC)){
//                $this->json([
//                    'status'=>0,
//                    'message' => '搜索成功',
//                    'documentTable'=>$filePro
//                ]);
//            }
//
//            //从filetalk表单搜索
//            while($fileTalk = mysqli_fetch_all($querytalk,MYSQLI_ASSOC)){
//                $this->json([
//                    'status'=>0,
//                    'message' => '搜索成功',
//                    'documentTable2'=>$fileTalk
//                ]);
//            }
            $this->json([
                'status'=>0,
                'documentTable'=>$filePro,
                'documentTable2'=>$fileTalk
            ]);
        }  
    }
}


