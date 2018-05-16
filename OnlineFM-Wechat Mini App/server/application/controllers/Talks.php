<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Talks extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);
        $getName = $data['userName'];
        $getStatus = $data['status'];
        if($data['logged']===false){
            return $this->json([
                'status' => -1,
                'message' => '请先登录'
            ]);
        }
        else{
            //先查询管理员权限
            if(DB::select('user',['*'],['userName' => $getName, 'root' => 1]) != []) {
                //显示所有
                $talkInfoAll = DB::select('talk',['id','talkName','creatName'],['status' => $getStatus]);
                if($talkInfoAll == []) {
                    return $this->json([
                        'status' => -2,
                        'message' => '目前未创建群聊',
                        'talkTable' => [],
                    ]);
                }
                else {
                    return $this->json([
                        'status' => 0,
                        'message' => '已获得全部用户群聊列表',
                        'talkTable' => $talkInfoAll,
                    ]);
                }
            }
            else {
                //非管理员权限

                $query="select talk.id, talk.talkName, talk.creatName, talk.status from talk inner join tmember on talk.id=tmember.pid where tmember.member='$getName' and talk.status='$getStatus'" ;
                $talkInfo = DB::rawselect($query);
                if($talkInfo != []) {
                    return $this->json([
                        'status' => 0,
                        'message' => '已获得该用户群聊列表',
                        'talkTable' => $talkInfo,
                    ]);
                }
                else {
                    return $this->json([
                        'status' => -2,
                        'message' => '没有群聊',
                        'talkTable' => [],
                    ]);
                }
            }

        }
    }
}

