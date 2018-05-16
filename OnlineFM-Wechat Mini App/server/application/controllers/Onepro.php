<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Onepro extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);


        $userId = $data['userId'];
        $proId = $data['proId'];
        $userName = $data['userName'];
        $rawSelectData = DB::row('project',['id','projectName'],['id' => $proId]);
        if($rawSelectData == NULL) {
            return $this->json([
                'status' => -1,
                'message' => '没有对应项目',
                'projectInfo' => [], //返回空数组
            ]);
        }
        else {
            $fileInfo = DB::select('file',['filePath','name','uplodName','uplodID'],['projectID'=>$proId]);
            $member = DB::select('pmember', ['member'], ['pid' => $proId]);
            if (DB::select('user', ['*'], ['id' => $userId, 'root' => 1]) == []) {
                $flag = false;
                foreach ($member as &$v) {
                    $v->userName = $v->member;
                    unset($v->member);
                    if ($v->userName == $userName) {
                        $flag = true;
                    }
                }
                //二次权限认证
                if ($flag == false) {
                    return $this->json([
                        'status' => -2,
                        'message' => '用户权限不足',
                        'projectInfo' => [],
                    ]);
                }
            }
            else {
                foreach ($member as &$v) {
                    $v->userName = $v->member;
                    unset($v->member);
                };
            }
            return $this->json([
                'status' => 0,
                'message' => '已获项目信息',
                "projectInfo" => [
                    'member' => $member,
                    'proid' =>$proId,
                    'name' => $rawSelectData->projectName,
                    'file' => $fileInfo,
                ],
            ]);
        }
    }
}





