<?php
defined('BASEPATH') OR exit('No direct script access allowed');

use QCloud_WeApp_SDK\Auth\LoginService as LoginService;
use QCloud_WeApp_SDK\Constants as Constants;

class Login extends CI_Controller {
    public function index() {
        $result = LoginService::login(); //该静态方法用于处理用户登录。
        
        if ($result['loginState'] === Constants::S_AUTH) { //登录成功
            $this->json([
              'status'=>2,
                'code' => 0,
                'data' => $result['userinfo']
            ]);
        } else {
            $this->json([
                'code' => -1,
                'error' => $result['error']
            ]);
        }
    }
}
