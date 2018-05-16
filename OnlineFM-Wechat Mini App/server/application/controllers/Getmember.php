<?php
defined('BASEPATH') OR exit('No direct script access allowed');

use QCloud_WeApp_SDK\Mysql\Mysql as DB;

class Getmember extends CI_Controller {
    public function index() {
      DB::getInstance(); //数据库链接
        $raw = file_get_contents('php://input');
      // $data = json_decode($raw, true);
      $allmember = DB::select('user',['userName']);

      if($allmember==[]){
        $this->json([
          'status' => -1,
          'message' => '无可用名单',
          'member' => $allmember,
        ]);
      }
      else{
        $this->json([
          'status'=>0,
          'message'=>"已获得所有成员名单",
          'member'=>$allmember,
        ]);

      }
      // $member = array(
      //     array("name"=>"储向童","value"=>"储向童"),
      //     array("name"=>"唐崇鸾","value"=>"唐崇鸾"),
      //     array("name"=>"陈美妃","value"=>"陈美妃"),
      //     array("name"=>"胡学锋","value"=>"胡学锋"),
      //     array("name"=>"雷宇彤","value"=>"雷宇彤"),
      //     array("name"=>"王帆","value"=>"王帆"),
      //     array("name"=>"姚伊杨","value"=>"姚伊杨"),
      //     array("name"=>"陈陈","value"=>"陈陈"),
      //     array("name"=>"代官伶","value"=>"代官伶")
      // );

       
    }
}

