<?php
defined('BASEPATH') OR exit('No direct script access allowed');
use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Pwdmodify extends CI_Controller {
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
            $frontPwdFirst = $data['passwordfirst'];
            $frontPwdSecond = $data['passwordsecond'];
            
            //密码是否一致
            if($frontPwdFirst != $frontPwdSecond){
                $this->json([
                    'status' => -2,
                    'message' => '两次输入的密码不一致'
                ]);
            }
            else{
                if(DB::update('user', ['userPwd' => $frontPwdFirst], ['userNumber' => $frontNumber])){
                    $this->json([
                        'status' => 0,
                        'message' => '成功修改用户密码',
                    ]);
                }
                else{
                    $this->json([
                        'status' => -3,
                        'message' => '密码修改失败'
                    ]);
                }
            }      
        }
    }
}
