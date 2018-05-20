<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Onetalk extends CI_Controller {
    public function index() {
        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');
        $data = json_decode($raw, true);


        $userId = $data['userId'];
        $talkId = $data['talkId'];
        $userName = $data['userName'];

//        $query="select talk.id, talk.talkName from talk inner join tmember on talk.id=tmember.pid where tmember.member='$userName' and talk.talkName='$proName'" ;
//        $rawSelectData = DB::rawselect($query);

        $rawSelectData = DB::row('talk',['id','talkName','status'],['id' => $talkId]);
        if($rawSelectData == NULL) {
            return $this->json([
                'status' => -1,
                'message' => '没有对应群聊',
                'talkInfo' => [], //返回空数组
            ]);
        }
        else {
            //若查询到信息， 应返回一个数组
//            $id=$rawSelectData[0]->id;
//            $name=$rawSelectData[0]->talkName;
            $member = DB::select('tmember', ['member'], ['tid' => $talkId]);
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
                        'talkInfo' => [],
                    ]);
                }
            }
            else {
                foreach ($member as &$v) {
                    $v->userName = $v->member;
                    unset($v->member);
                }
            }
            $fileInfo= DB::select('filetalk',['filePath','name','uplodName','uplodID'],['talkID'=>$talkId]);
            $message = DB::select('message',['head_owner','kind','content','time','userid','username'],['talkid'=>$talkId]);
            return $this->json([
                'status' => 0,
                'message' => '已获项目信息',
                "talkInfo" => [
                    'member' => $member,
                    'name' => $rawSelectData->talkName,
                    'status' =>$rawSelectData->status,
                    'file' => $fileInfo,
                ],
                "receiveMessage" =>$message
            ]);
        }
    }
}





