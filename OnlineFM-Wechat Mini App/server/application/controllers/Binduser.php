<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Binduser extends CI_Controller {
    public function index() {

        DB::getInstance(); //数据库连接

        $raw = file_get_contents('php://input');  //从前端读取数据
        $data = json_decode($raw, true);         
       
        if($data['logged']===false){
            $this->json([
                'status' => -1,
                'message' => '请先登录'
          ]);
        }
        else{
            $frontNumber = $data['number'];
            $frontPwd = $data['password'];
            $useInfo = DB::row('user', ['userName','userPwd','root'], ['userNumber' => $frontNumber]);  //返回得到一个对象，需要通过$object->key访问数据
            
            //用户不存在
            if($useInfo == NULL){
                $this->json([
                    'status' => -2,
                    'message' => '用户不存在'
                ]);
            }
            else{
                //密码是否正确
                if($useInfo->userPwd == $frontPwd){    //不能使用$useInfo['userPwd']
                    $this->json([
                        'status' => 0,
                        'message' => '成功绑定用户信息',
                        'data' => [
                            'name' => $useInfo->userName,
                            'number' => $frontNumber,
                            'authority' => $useInfo->root
                        ]
                    ]);
                }
                else{
                    $this->json([
                        'status' => -3,
                        'message' => '密码错误',
                    ]);
                }
            }      
        }
    }
}


