<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Projects extends CI_Controller {
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
            $frontName = $data['userName'];
            $projectInfo = DB::select('project', ['id','projectName','creatName','status'], ['userName' => $frontName]);  

            //项目不存在
            if($projectInfo  == NULL){
                $this->json([
                    'status' => -1,
                    'message' => '目前没有创建项目'
                ]);
            }
            else{
                $this->json([
                        'status' => 0,
                        'message' => '已获得用户项目列表',
                        'projectTable' => $projectInfo   
                    ]);
            }
        }
    }
}

