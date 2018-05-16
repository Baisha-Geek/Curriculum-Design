<?php
/**
 * Created by PhpStorm.
 * User: 64980
 * Date: 2018/5/9
 * Time: 21:24
 */

defined('BASEPATH') OR exit('No direct script access allowed');

use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Endpro extends CI_Controller {
    public function index() {
        DB::getInstance();
        $raw = file_get_contents('php://input');
        $data = json_decode($raw,true);
//        status状态 0:已结束项目 -1:无此项目或用户权限不足
        if(DB::select('user',['*'],['id' => $data['userId'],'root' => 1] )==[]) {
            return $this->json([
                'status' => -1,
                'message' => '用户权限不足',
            ]);
        }
        else {
            if(DB::update('project',['status' => 1], ['id' => $data['proId']])==0) {
                return $this->json([
                    'status' => -2,
                    'message' => '无此项目或用户权限不足'
                ]);
            }
            else return $this->json([
                'status' => 0,
                'message' => '已结束项目'
            ]);
        }
    }
}