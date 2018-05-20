<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Deletefile extends CI_Controller {
    public function index() {

        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');  //从前端读取数据
        $data = json_decode($raw, true);         
       
        $frontfileId = $data['fileId'];
        $frontuploadId = $data['uploadId'];

        $fileInfo = DB::row('file', ['uplodID'], ['id' => $frontfileId]);

        //判断是否是文件的上传者
        if($fileInfo->uplodID == $frontuploadId){ 
            if(DB::delete('file', ['id' => $frontfileId,'uplodID' => $frontuploadId])){
                $this->json([
                    'status' => 0,
                    'message' => '删除成功'
                ]);
            } 
            else{
                $this->json([
                    'status' => -1,
                    'message' => '删除失败'
                ]);
            }      
        }
        else{
            $this->json([
                'status' => -2,
                'message' => '没有权限删除'
            ]);
        }
    }
}


