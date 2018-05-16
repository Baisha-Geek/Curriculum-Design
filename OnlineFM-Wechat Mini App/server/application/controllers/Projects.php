<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Projects extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);
        
        if($data['logged']===false){
            return $this->json([
                'status' => -1,
                'message' => '请先登录'
            ]);
        }

        $getStatus=$data['status'];
        $getName=$data['userName'];
        //先查询权限
        if(DB::select('user',['*'],['userName' => $getName, 'root' =>1]) != []) {
            //管理员权限
            $projectInfo = DB::select('project', ['id','projectName','creatName','status'], ['status' => $data['status']]);
            if($projectInfo != []) {
                return $this->json([
                    'status' => 0,
                    'message' => '已获得所有用户项目列表',
                    'projectTable' => $projectInfo,
                ]);
            }
            else {
                return $this->json([
                    'status' => -2,
                    'message' => '没有项目',
                    'projectTable' => [],
                ]);
            }

        }
        else {
            //非管理员权限
            $query="select project.id, project.projectName, project.creatName, project.status from project inner join pmember on project.id=pmember.pid where pmember.member='$getName' and project.status='$getStatus'" ;
            $projectInfo = DB::rawselect($query);
            if($projectInfo != []) {
                return $this->json([
                    'status' => 0,
                    'message' => '已获得该用户项目列表',
                    'projectTable' => $projectInfo,
                ]);
            }
            else {
                return $this->json([
                    'status' => -2,
                    'message' => '没有项目',
                    'projectTable' => [],
                ]);
            }
        }
    }
}

