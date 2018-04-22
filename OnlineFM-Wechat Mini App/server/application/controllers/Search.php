<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Search extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);

        if($data['logged']===false){
            $this->json([
                'status' => -1,
                'message' => '请先登录'
            ]);
        }
        else{
//            $frontNumber = $data['userNumber'];
            $documentList = array(
                array("name"=>"doc1",
                    "id"=>"1"),
                array("name"=>"doc1",
                    "id"=>"1"),
            );
//            $projectInfo = DB::select('project', ['id','projectName','status'], ['creatPeo' => $frontNumber]);

            //项目不存在
            if($documentList  == NULL){
                $this->json([
                    'status' => -1,
                    'message' => '目前没有文档'
                ]);
            }
            else{
                $this->json([
                    'status' => 0,
                    'message' => '已获得文档列表',
                    'documentTable' => $documentList
                ]);
            }
        }
    }
}
