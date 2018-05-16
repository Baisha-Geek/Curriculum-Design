<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Search extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

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
        else{
            $filePro = DB::select('file',['filePath','name'],['name'=>$fileName]);
            $fileTalk = DB::select('filetalk',['filePath','name'],['name'=>$fileName]);

//            $frontNumber = $data['userNumber'];
//            $documentList = array(
//                array("name"=>"doc1",
//                    "id"=>"1"),
//                array("name"=>"doc1",
//                    "id"=>"1"),
//            );
//            $projectInfo = DB::select('project', ['id','projectName','status'], ['creatPeo' => $frontNumber]);

            $this->json([
                'status'=>0,
                'documentTable'=>$filePro,
                'documentTable2'=>$fileTalk
            ]);
        }
    }
}
