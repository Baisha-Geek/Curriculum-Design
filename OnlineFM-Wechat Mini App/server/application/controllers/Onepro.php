<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Onepro extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);

        $frontProName = $data['proName'];

        $proUserName = DB::select('project', ['userName'], ['projectName' => $frontProName]);   
        $fileInfo = DB::select('file', ['id','fileName','filePath','uploadName'], ['projectName' => $frontProName]);

        //项目不存在
        if($proUserName  == NULL){
            $this->json([
                'status' => -1,
                'message' => '目前没有该项目'
            ]);
        }
        else{
            $this->json([
                    'status' => 0,
                    'message' => '已获得项目信息',
                    'projectInfo' => [
                        'name' => $frontProName,
                        'member' => $proUserName,
                        'file' => $fileInfo
                    ]
                    
                ]);
        }
    }
}





