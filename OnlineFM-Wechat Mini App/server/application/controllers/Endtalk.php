<?php
/**
 * Created by PhpStorm.
 * User: 64980
 * Date: 2018/5/6
 * Time: 18:54
 */

defined('BASEPATH') OR exit('No direct script access allowed');

use QCloud_WeApp_SDK\Mysql\Mysql as DB;


class Endtalk extends CI_Controller {
    public function index() {
        DB::getInstance();
        $raw = file_get_contents('php://input');
        $data = json_decode($raw,true);

//        status状态 0:已结束项目 -1:无此项目或权限不足
        $userName = $data['userName'] ;

        if(DB::select('user',['*'],['id' => $data['userId'],'root' => 1] )!=[]) {
//            管理员权限
            if(DB::update('talk',['status' => 1], ['id' => $data['talkId']])==0) {
                return $this->json([
                    'status' => -1,
                    'message' => '无此群聊'
                ]);
            }
            else{
                return $this->json([
                    'status' => 0,
                    'message' => '已结束群聊'
                ]);
            }
        }
        else {
            if(DB::update('talk',['status' => 1],['id' => $data['talkId'], 'creatName' => $userName])==0) {
                return $this->json([
                    'status' => -1,
                    'message' => '无此群聊或权限不足'
                ]);
            }
            else{
                return $this->json([
                    'status' => 0,
                    'message' => '已结束群聊'
                ]);
            }
        }
    }
}