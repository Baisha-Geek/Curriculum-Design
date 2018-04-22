<?php
defined('BASEPATH') OR exit('No direct script access allowed');

use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Demo extends CI_Controller {
    public function index() {

        DB::getInstance();

        $rows = DB::select('user', ['userName','userNumber','userPwd']);   //返回一个包含结果集中所有行的数组。
        $this->json([
            'code' => 0,
            'data' => [
                'msg' =>  $rows
            ]
        ]);
    }
}